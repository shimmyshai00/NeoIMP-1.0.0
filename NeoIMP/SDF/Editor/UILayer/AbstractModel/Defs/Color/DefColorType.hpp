#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_DEFCOLORTYPE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_DEFCOLORTYPE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DefColorType.hpp
 * PURPOSE: Defines the DefColorType template.
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

namespace SDF::Editor::UILayer::AbstractModel::Defs::Color {
  // Class:      DefColorType
  // Purpose:    Defines a color type from a passed IColor partial implementation.
  // Parameters: ColorModel - The color model type being defined.
  //             ImplT - The implementation type, which must derive ultimately from IColor.
  template<EColorModel ColorModel, class ImplT>
  class DefColorType : public ImplT {
  public:
    
  }
}
#endif
