#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_LENGTHUNITLABELS_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_LENGTHUNITLABELS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    LengthUnitLabels.hpp
 * PURPOSE: Defines the labels for length units.
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

#include "ELengthUnit.hpp"

namespace SDF::Editor::UILayer::AbstractModel::Defs {
  // NB: The labels and symbols should appear in the same order the units do in the enum
  static const char *g_lengthUnitLabels[LENGTH_UNIT_MAX] = {
    "pixels",
    "points",
    "millimeters",
    "picas",
    "centimeters",
    "inches"
  };

  static const char *g_lengthUnitSymbols[LENGTH_UNIT_MAX] = {
    "px",
    "pt",
    "mm",
    "pica",
    "cm",
    "in"
  };
}

#endif
