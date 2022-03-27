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

#include <array>

namespace SDF::Editor::ModelLayer::Services::Gil {
  UiColorConversionService::UiColorConversionService(
    ModelLayer::AbstractData::IBuiltinColorSpaceRepository<
      ModelLayer::AbstractData::Gil::RgbColorSpace<boost::gil::rgb8_pixel_t>
    > *builtinColorSpaces_RGB24_888,
  )
    : m_builtinColorSpaces_RGB24_888(builtinColorSpaces_RGB24_888),
      m_uiAssumed(
        std::make_shared<ModelLayer::DomainObjects::Engine::ColorSpaces::Maps::IEC61966_sRGB>()
      ) // STUBby: just *assume* the UI uses sRGB
  {
  }

  void
  UiColorConversionService::convertColor(
    const UILayer::AbstractModel::Defs::Color::IColor<
      UILayer::AbstractModel::Defs::Color::EColorModel
    > &srcColor,
    const UILayer::AbstractModel::Defs::Color::IColor<
      UILayer::AbstractModel::Defs::Color::EUiColorModel
    > &dstColor
  ) {
    using namespace UILayer::AbstractModel::Defs;
    using namespace DomainObjects::ModelLayer::Engine;

    std::array<float, 3> fundamentalValues;
    float colorModelValues[5]; // nb: not enough?
    m_fwdCM.pixelToValues(srcColor, colorModelValues);

    switch(srcColor.getColorModel()) {
      case Color::COLOR_MODEL_RGB24_888:

    }
  }
}
