/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CreateImageService.cpp
 * PURPOSE: Implements the CreateImageService class.
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "CreateImageService.hpp"

#include "../../../../Common/Overload.hpp"

#include "../../../UILayer/AbstractModel/Defs/Color/IColor.hpp"
#include "../../../UILayer/AbstractModel/Defs/Color/types.hpp"
#include "../../DomainObjects/Engine/Gil/MemoryEstimator.hpp"
#include "../../DomainObjects/Engine/Gil/ImplTraits.hpp"
#include "../../DomainObjects/Engine/Gil/ImageFactory.hpp"
#include "../../Metrics/LengthConvertible.hpp"
#include "../../Metrics/ResolutionConvertible.hpp"
#include "../Validators/ImageSpecValidator.hpp"
#include "uiPixelToGilPixel.hpp"

#include <boost/uuid/uuid_generators.hpp>

#include <boost/gil/typedefs.hpp>

namespace SDF::Editor::ModelLayer::Services::Gil {
  namespace Impl {
    // Preset background colors.
    // NB: too overloaded for RGB because some of these refer to "transparent", etc.? - TBA
    static const boost::gil::rgb8_pixel_t
      g_bkgRgbPresets[UILayer::AbstractModel::Defs::PRE_BACKGROUND_MAX] = {
        boost::gil::rgb8_pixel_t(255, 255, 255),
        boost::gil::rgb8_pixel_t(0, 0, 0),
        boost::gil::rgb8_pixel_t(255, 255, 255),
        boost::gil::rgb8_pixel_t(0, 0, 0)
      };
  }

  CreateImageService::CreateImageService(
    AbstractData::IImageRepository<DomainObjects::Engine::Gil::Any_Image> *imageRepository,
    Common::MessageSystem::IChannel<Messages::ImageAdded> *imageAddedMessageChannel
  )
    : m_uuid(boost::uuids::random_generator()()),
      m_imageRepository(imageRepository),
      m_imageAddedMessageChannel(imageAddedMessageChannel),
      m_nextNewDocumentNumber(1)
  {
  }

  boost::uuids::uuid
  CreateImageService::getUuid() const {
    return m_uuid;
  }

  std::size_t
  CreateImageService::getMemoryRequiredForOneLayer(
    const UILayer::AbstractModel::Defs::ImageSpec &spec
  ) const {
    using namespace UILayer::AbstractModel::Defs;
    using namespace UILayer::AbstractModel::Defs::Color;
    using namespace Metrics;
    using namespace DomainObjects;

    // Input validation.
    Validators::ImageSpecValidator val;
    auto result = val.validate(spec);
    if(result->isValid()) {
      // Convert the dimensions to pixels.
      LengthConvertible width(spec.width, spec.widthUnit, spec.resolution, spec.resolutionUnit);
      LengthConvertible height(spec.height, spec.heightUnit, spec.resolution, spec.resolutionUnit);

      std::size_t widthPx(width.in(LENGTH_UNIT_PIXEL));
      std::size_t heightPx(height.in(LENGTH_UNIT_PIXEL));

      // What type to use depends on the color model.
      if(spec.colorModel == COLOR_MODEL_RGB24_888) {
        return Engine::Gil::MemoryEstimator<Engine::Gil::RGB24_888_Image_Impl>::singleLayerEstimate(
          widthPx, heightPx);
      } else {
        throw "NOT YET IMPLEMENTED";
      }
    } else {
      // Bad spec given!
      result->throwFrom();
    }
  }

  Common::Handle
  CreateImageService::createFromSpec(const UILayer::AbstractModel::Defs::ImageSpec &spec) {
    using namespace UILayer::AbstractModel::Defs;
    using namespace UILayer::AbstractModel::Defs::Color;
    using namespace Metrics;
    using namespace DomainObjects;

    // Input validation.
    Validators::ImageSpecValidator val;
    auto result = val.validate(spec);
    if(result->isValid()) {
      // What type to use depends on the color model.
      std::unique_ptr<Engine::Gil::Any_Image> image;
      if(spec.colorModel == COLOR_MODEL_RGB24_888) {
        image = doConstructFromSpec<Engine::Gil::RGB24_888_Image_Impl>(spec);
      } else {
        throw "NOT YET IMPLEMENTED";
      }

      Common::Handle rv(m_imageRepository->insertImageAtNextAvailable(std::move(image)));

      Messages::ImageAdded msg(rv);
      m_imageAddedMessageChannel->publishMessage(getUuid(), msg);

      ++m_nextNewDocumentNumber;

      return rv;
    } else {
      // Worthless spec. Throw an exception
      result->throwFrom();
    }
  }
}

namespace SDF::Editor::ModelLayer::Services::Gil {
  // Private helper not safe to use elsewhere because it requires the GilSpecT to match the
  // color model in the spec.
  template<class GilSpecT>
  std::unique_ptr<DomainObjects::Engine::Gil::Any_Image>
  CreateImageService::doConstructFromSpec(const UILayer::AbstractModel::Defs::ImageSpec &spec) {
    using namespace UILayer::AbstractModel::Defs;
    using namespace UILayer::AbstractModel::Defs::Color;
    using namespace Metrics;
    using namespace DomainObjects;

    using namespace boost::gil;

    // Convert the dimensions to pixels.
    ResolutionConvertible res(spec.resolution, spec.resolutionUnit);
    LengthConvertible width(spec.width, spec.widthUnit, spec.resolution, spec.resolutionUnit);
    LengthConvertible height(spec.height, spec.heightUnit, spec.resolution, spec.resolutionUnit);

    std::string name("Untitled " + std::to_string(m_nextNewDocumentNumber));
    std::string fileSpec("");

    float resPpi(res.in(RESOLUTION_UNIT_PPI));
    std::size_t widthPx(width.in(LENGTH_UNIT_PIXEL));
    std::size_t heightPx(height.in(LENGTH_UNIT_PIXEL));

    typename GilSpecT::bkg_pixel_t bkgColor;
    if(spec.backgroundPreset == PRE_BACKGROUND_CUSTOM) {
      bkgColor = uiPixelToGilPixel3Component<typename GilSpecT::bkg_pixel_t>(*spec.backgroundColor);
    } else {
      color_convert(Impl::g_bkgRgbPresets[spec.backgroundPreset], bkgColor);
    }

    auto proto = Engine::Gil::ImageFactory<GilSpecT>().createU(
      name, fileSpec, widthPx, heightPx, resPpi, bkgColor);

    return std::make_unique<Engine::Gil::Any_Image>(std::move(*proto));
  }
}
