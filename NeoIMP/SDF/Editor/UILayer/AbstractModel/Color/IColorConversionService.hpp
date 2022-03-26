#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_COLOR_ICOLORCONVERSIONSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_COLOR_ICOLORCONVERSIONSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IColorConversionService.hpp
 * PURPOSE: Defines the IColorConversionService interface
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

#include <memory>
#include <string>

namespace SDF::Editor::UILayer:AbstractModel::Color {
  // Class:      IColorConversionService
  // Purpose:    Defines a service interface to convert UI-specified colors in a document's color
  //             space to those suitable for UI display.
  // Parameters: None.
  class IColorConversionService {
  public:
    virtual ~IColorConversionService() = default;

    // Function:   convertColor
    // Purpose:    Converts one IColor object into another.
    // Parameters: srcColor - The source color object.
    //             dstColor - The destination color object.
    // Returns:    None.
    virtual void
    convertColor(const Defs::Color::IColor &srcColor, Defs::Color::IColor &dstColor) = 0;
  };
}

#endif
