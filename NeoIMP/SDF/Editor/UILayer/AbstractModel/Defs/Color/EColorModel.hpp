#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_ECOLORMODEL_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_ECOLORMODEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    EColorModel.hpp
 * PURPOSE: Enumerates the available color models.
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

#include <vector>

namespace SDF::Editor::UILayer::AbstractModel::Defs::Color {
  enum EColorModel {
    COLOR_MODEL_RGB24_888,
    COLOR_MODEL_MAX
  };
}

namespace SDF::Editor::UILayer::AbstractModel::Defs::Color {
  // A structured form of the above.
  enum EColorModelFamily {
    CM_FAMILY_RGB,
    CM_FAMILY_MAX
  };

  static const std::size_t NUM_RGB_FORMATS = 1;
  static const EColorModel g_colorModelsByFamily_Rgb[NUM_RGB_FORMATS] = {
    COLOR_MODEL_RGB24_888
  };
}

#endif
