#ifndef SDF_UILAYER_METRICS_RESOLUTION_UNITS_UNITS_HPP
#define SDF_UILAYER_METRICS_RESOLUTION_UNITS_UNITS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Units.hpp
 * PURPOSE: Definitions of the units for resolution quantities.
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

#include <SDF/UILayer/Metrics/Unit.hpp>

namespace SDF::UILayer::Metrics::Resolution::Units {
  // Unit enumeration.
  enum {
    RESOLUTION_UNIT_PPI,
    RESOLUTION_UNIT_PPCM,
    RESOLUTION_UNIT_PPMM
  };

  // Unit definitions. We take the arbitrary base units to be pixels per inch (PPI).
  typedef Unit<-1, 0> ResolutionUnit;
  static const ResolutionUnit PixelsPerInch = ResolutionUnit(1.0f);
  static const ResolutionUnit PixelsPerCentimeter = ResolutionUnit(2.54f);
  static const ResolutionUnit PixelsPerMillimeter = ResolutionUnit(25.4f);
};

#endif
