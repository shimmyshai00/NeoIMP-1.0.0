#ifndef SDF_UILAYER_METRICS_UNITSYMBOLS_HPP
#define SDF_UILAYER_METRICS_UNITSYMBOLS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UnitSymbols.hpp
 * PURPOSE: Definition of the symbols for the available measuring units.
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

#include <ELengthUnit.hpp>
#include <EResolutionUnit.hpp>

namespace SDF::UILayer::Metrics {
  static const char *g_lengthUnitSymbols[MAX_LENGTH_UNIT] = {
    "px",
    "pt",
    "mm",
    "pica",
    "cm",
    "in"
  };

  static const char *g_resolutionUnitSymbols[MAX_RESOLUTION_UNIT] = {
    "per in",
    "per cm",
    "per mm"
  };
}

#endif
