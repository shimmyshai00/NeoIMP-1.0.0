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

#include "../../Metrics/LengthConvertible.hpp"
#include "../../Metrics/ResolutionConvertible.hpp"
#include "../../Exceptions.hpp"

namespace SDF::ModelLayer::Services::Gil {
  CreateImageService::CreateImageService(
    Repositories::IRepository<DomainObjects::Engine::Gil::AnyGilImage> *imageRepository
  )
    : m_imageRepository(imageRepository),
      m_nextHandle(0)
  {
  }

  Common::Handle
  CreateImageService::createImage(UILayer::AbstractModel::Defs::ImageSpec spec) {
    using namespace UILayer::AbstractModel::Defs;
    using namespace Metrics;
    using namespace DomainObjects;

    // Input validation.
    if(spec.width == 0)
      throw InvalidImageWidthException(spec.width);

    if(spec.widthUnit == LENGTH_UNIT_MAX)
      throw InvalidLengthUnitException(spec.widthUnit);

    if(spec.height == 0)
      throw InvalidImageHeightException(spec.height);

    if(spec.heightUnit == LENGTH_UNIT_MAX)
      throw InvalidLengthUnitException(spec.heightUnit);

    if(spec.resolution <= 0.0f)
      throw InvalidImageResolutionException(spec.resolution);

    if(spec.resolutionUnit == RESOLUTION_UNIT_MAX)
      throw InvalidResolutionUnitException(spec.resolutionUnit);

    // Convert the dimensions to pixels.
    ResolutionConvertible res(spec.resolution, spec.resolutionUnit);
    LengthConvertible width(spec.width, spec.widthUnit, spec.resolution, spec.resolutionUnit);
    LengthConvertible height(spec.height, spec.heightUnit, spec.resolution, spec.resolutionUnit);

    std::string name("Untitled");
    std::string fileSpec("");

    float resPpi(res.in(RESOLUTION_UNIT_PPI));
    std::size_t widthPx(width.in(LENGTH_UNIT_PIXEL));
    std::size_t heightPx(height.in(LENGTH_UNIT_PIXEL));

    // What type to use depends on the combination of color model and bit depth parameters.
    std::unique_ptr<Engine::Gil::AnyGilImage> image;
    if((spec.colorModel == COLOR_MODEL_RGB) && (spec.bitDepth == BIT_DEPTH_8)) {
      Engine::Gil::RGB24_888_Image proto(name, fileSpec, widthPx, heightPx, resPpi,
        boost::gil::rgb8_pixel_t(127, 127, 127));
      image = std::make_unique<Engine::Gil::AnyGilImage>(std::move(proto));
    }

    Common::Handle rv(m_nextHandle++);
    m_imageRepository->insert(rv, std::move(image));

    return rv;
  }
}
