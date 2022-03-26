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

#include "ColorConversionService.hpp"

#include "../../../UILayer/AbstractModel/Defs/Color/colorSpaces.hpp"
#include "../../DomainObjects/Engine/Gil/"

namespace SDF::Editor::ModelLayer::Services::Gil {
  ColorConversionService::ColorConversionService(
    ModelLayer::AbstractData::IBuiltinColorSpaceRepository<
      ModelLayer::AbsractData::EBuiltinRgbColorSpace,
      boost::gil::rgb8_pixel_t,
      ModelLayer::DomainObjects::Engine::ColorSpaces::Fundamental::XyzD65
    > *builtinColorSpaces_RGB24_888
  )
    : m_builtinColorSpaces_RGB24_888(builtinColorSpaces_RGB24_888)
  {
  }

  std::shared_ptr<Defs::Color::IColor>
  ColorConversionService::getFormatColor(Common::Handle documentHandle) const {
    
  }

  std::shared_ptr<UILayer::AbstractModel::Defs::Color::IColor>
  ColorConversionService::convertColor(
    const UILayer::AbstractModel::Defs::Color::IColor &srcColor,
    std::string srcColorSpace
  ) {
    using namespace UILayer::AbstractModel;

    // NB: very STUBby for now
    if((srcColor->getColorModel() == Defs::Color::COLOR_MODEL_RGB) &&
       (srcColor->getBitDepth() == BIT_DEPTH_8)) {
      m_builtinColorSpaces_RGB24_888.retrieve(srcColorSpace);
    } else {
      throw "NOT YET IMPLEMENTED";
    }
  }
}
