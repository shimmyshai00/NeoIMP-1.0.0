#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_BOUNDS_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_BOUNDS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    bounds.hpp
 * PURPOSE: Defines various constants representing bounds of the editor model.
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

namespace SDF::Editor::UILayer::AbstractModel::Defs::Bounds {
  // This gives a bit more than 1 Gpx max limit
  static const std::size_t MAX_IMAGE_WIDTH = 32767;
  static const std::size_t MAX_IMAGE_HEIGHT = 32767;
}

#endif
