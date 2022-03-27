#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_COLOR_IUICOLORCONVERSIONSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_COLOR_IUICOLORCONVERSIONSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IUiColorConversionService.hpp
 * PURPOSE: Defines the IUiColorConversionService interface.
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

#include "../Defs/Color/IColor.hpp"
#include "../Defs/Color/EColorModel.hpp"
#include "../Defs/Color/EUiColorModel.hpp"

namespace SDF::Editor::UILayer::AbstractModel::Color {
  // Class:      IUiColorConversionService
  // Purpose:    Defines a service interface to convert one type of color into another.
  // Parameters: None.
  class IUiColorConversionService {
  public:
    virtual ~IUiColorConversionService() = default;

    // Function:   convertColorToUi
    // Purpose:    Converts the color named in src to a UI color in dst.
    // Parameters: srcColor - The color to convert.
    //             dstColor - The color object to receive the conversion result.
    // Returns:    None.
    virtual void
    convertColor(
      const Defs::Color::IColor<Defs::Color::EColorModel> &srcColor,
      Defs::Color::IColor<Defs::Color::EUiColorModel> &dstColor
    ) = 0;
  };
}

#endif
