#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_RESOLUTION_UNIT_LABELS_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_RESOLUTION_UNIT_LABELS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    resolution_unit_labels.hpp
 * PURPOSE: Defines the labels for resolution units.
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

#include "ResolutionUnit.hpp"

namespace SDF::Editor::UILayer::AbstractModel::Defs {
  // NB: The labels and symbols should appear in the same order the units do in the enum
  static const char *g_resolutionUnitLabels[RESOLUTION_UNIT_MAX] = {
    "per inch",
    "per centimeter",
    "per millimeter"
  };

  static const char *g_resolutionUnitSymbols[RESOLUTION_UNIT_MAX] = {
    "ppi",
    "px/mm",
    "px/cm"
  };
}

#endif
