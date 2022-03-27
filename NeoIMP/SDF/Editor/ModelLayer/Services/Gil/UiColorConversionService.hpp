#ifndef SDF_EDITOR_MODELLAYER_SERVICES_GIL_UICOLORCONVERSIONSERVICE_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_GIL_UICOLORCONVERSIONSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiColorConversionService.hpp
 * PURPOSE: Defines the UiColorConversionService class.
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

#include "../../../UILayer/AbstractModel/Defs/Color/IColor.hpp"
#include "../../../UILayer/AbstractModel/Color/IUiColorConversionService.hpp"
#include "../../AbstractData/IBuiltinColorSpaceRepository.hpp"
#include "../ColorSpaces/UiRevColorSpace.hpp"

#include <fruit/fruit.h>
#include <memory>
#include <string>

namespace SDF::Editor::ModelLayer::Services::Gil {
  // Class:      UiColorConversionService
  // Purpose:    Provides an MVC service to convert colors from image to UI space.
  // Parameters: None.
  class UiColorConversionService :
    public UILayer::AbstractModel::Color::IUiColorConversionService
  {
  public:
    INJECT(UiColorConversionService(
      ModelLayer::AbstractData::IBuiltinColorSpaceRepository<
        ModelLayer::AbstractData::Gil::RgbColorSpace<boost::gil::rgb8_pixel_t>
      > *builtinColorSpaces_RGB24_888
    ));

    void
    convertColor(
      const UILayer::AbstractModel::Defs::Color::IColor<
        UILayer::AbstractModel::Defs::Color::EColorModel
      > &srcColor,
      const UILayer::AbstractModel::Defs::Color::IColor<
        UILayer::AbstractModel::Defs::Color::EUiColorModel
      > &dstColor
    );
  private:
    ModelLayer::AbstractData::IBuiltinColorSpaceRepository<
      ModelLayer::AbstractData::Gil::RgbColorSpace<boost::gil::rgb8_pixel_t>
    > *m_builtinColorSpaces_RGB24_888;

    // STUB: extend to repository?
    ColorSpaces::UiRevColorSpace m_uiAssumed;
  };
}

#endif
