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

#include "../../DomainObjects/Engine/Gil/Color/RgbNormalizer.hpp"

#include "../../DomainObjects/Engine/Color/Conversion/Pipeline.hpp"
#include "../../DomainObjects/Engine/Color/ColorSpaces/IEC61966_2_1_sRGB.hpp"
#include "../../DomainObjects/Engine/Color/FundamentalSpaces/XyzD65.hpp"

#include "../Color/UiRgbUnnormalizer.hpp"

#include "../Exceptions.hpp"

#include <boost/gil/typedefs.hpp>

namespace SDF::Editor::ModelLayer::Services::Gil {
  UiColorConversionService::UiColorConversionService() {
  }

  void
  UiColorConversionService::convertColor(
    const UILayer::AbstractModel::Defs::Color::IColor<
      UILayer::AbstractModel::Defs::Color::EColorFormat
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

    // P.S. ugly - but we have to map EColorFormat to GIL formats SOMEWHERE ...
    switch(srcColor.getColorFormat()) {
      case Defs::Color::COLOR_FMT_RGB24_888:
        doRgbPipeline<boost::gil::rgb8_pixel_t>(srcColor, dstColor); break;
      default:
        throw BadColorFormatException(srcColor.getColorFormat());
    };
  }
}

namespace SDF::Editor::ModelLayer::Services::Gil {
  // The private pipeline helper method.
  template<class GilPixelT>
  void
  UiColorConversionService::doRgbPipeline(
    const UILayer::AbstractModel::Defs::Color::IColor<
      UILayer::AbstractModel::Defs::Color::EColorFormat
    > &srcColor,
    UILayer::AbstractModel::Defs::Color::IColor<
      UILayer::AbstractModel::Defs::Color::EUiColorModel
    > &dstColor
  ) {
    using namespace UILayer::AbstractModel;
    using namespace DomainObjects;

    GilPixelT gilPx = uiPixelToGilPixel3Component<GilPixelT>(srcColor);

    Engine::Gil::Color::RgbNormalizer<GilPixelT> sn;
    Engine::Color::ColorSpaces::IEC61966_2_1_sRGB scs;
    Engine::Color::ColorSpaces::IEC61966_2_1_sRGB dcs;
    Services::Color::UiRgbUnnormalizer dn;

    Engine::Color::Conversion::Pipeline pipeline(&sn, &scs, &dcs, &dn);

    pipeline.convertPixel(gilPx, dstColor);
  }
}
