/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorConversionService.cpp
 * PURPOSE: Implements the ColorConversionService class.
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

#include "UiColorConversionService.hpp"
#include "uiPixelToGilPixel.hpp"

#include "../../DomainObjects/Engine/Color/Conversion/Pipeline.hpp"
#include "../../DomainObjects/Engine/Color/ColorSpaces/IEC61966_2_1_sRGB.hpp"
#include "../../DomainObjects/Engine/Color/FundamentalSpaces/XyzD65.hpp"

#include "../Exceptions.hpp"

namespace SDF::Editor::ModelLayer::Services::Gil {
  UiColorConversionService::UiColorConversionService() {
  }

  void
  UiColorConversionService::convertColor(
    const UILayer::AbstractModel::Defs::Color::IColor<
      UILayer::AbstractModel::Defs::Color::EColorModel
    > &srcColor,
    UILayer::AbstractModel::Defs::Color::IColor<
      UILayer::AbstractModel::Defs::Color::EUiColorModel
    > &dstColor
  ) {
    using namespace UILayer::AbstractModel;
    using namespace DomainObjects;

    // Create a color conversion pipeline. Note: this *assumes* the UI is expecting sRGB - that's a
    // TBA if it isn't (also we should adjust to the document too - right now though we have only
    // sRGB docs, but we expect to expand the latter first).

    // P.S. ugly - but we have to map EColorModels to GIL formats SOMEWHERE ...
    switch(srcColor->getColorModel()) {
      case Defs::Color::COLOR_MODEL_RGB24_888:
        doPipeline<boost::gil::rgb8_pixel_t>(srcColor, dstColor); break;
      default:
        throw BadColorModelException(srcColor->getColorModel());
    };
  }
}

namespace SDF::Editor::ModelLayer::Services::Gil {
  // The private pipeline helper method.
  template<class GilPixelT>
  void
  UiColorConversionService::doRgbPipeline(
    const UILayer::AbstractModel::Defs::Color::IColor<
      UILayer::AbstractModel::Defs::Color::EColorModel
    > &srcColor,
    UILayer::AbstractModel::Defs::Color::IColor<
      UILayer::AbstractModel::Defs::Color::EUiColorModel
    > &dstColor
  ) {
    using namespace UILayer::AbstractModel;
    using namespace DomainObjects;

    GilPixelT gilPx = uiPixelToGilPixel<GilPixelT>(srcColor);

    Engine::Color::Conversion::Pipeline pipeline(
      std::make_shared<Engine::Gil::Color::RgbNormalizer<GilPixelT>>(),
      std::make_shared<Engine::Color::ColorSpaces::IEC61966_2_1_sRGB>(),
      std::make_shared<Engine::Color::ColorSpaces::IEC61966_2_1_sRGB>(),
      std::make_shared<Color::UiRgbUnnormalizer<Defs::Color::EUiColorModel>>()
    );

    pipeline.convertPixel(gilPx, dstColor);
  }
}
