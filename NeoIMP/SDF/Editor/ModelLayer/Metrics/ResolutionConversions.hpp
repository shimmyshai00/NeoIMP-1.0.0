#ifndef SDF_EDITOR_MODELLAYER_METRICS_RESOLUTIONCONVERSIONS_HPP
#define SDF_EDITOR_MODELLAYER_METRICS_RESOLUTIONCONVERSIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ResolutionConversions.hpp
 * PURPOSE: Defines a table of conversion factors for the various resolution units.
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

#include "../../UILayer/AbstractModel/Defs/EResolutionUnit.hpp"

namespace SDF::Editor::ModelLayer::Metrics {
  // Gives the sizes of the various units in PPI.
  static const double g_resolutionUnitSizes[UILayer::AbstractModel::Defs::RESOLUTION_UNIT_MAX] = {
    1.0,          // pixels per inch (PPI)
    2.54,         // pixels per cm
    25.4          // pixels per mm
  };
}

#endif
