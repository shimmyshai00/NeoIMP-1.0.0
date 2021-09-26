#ifndef SDF_MODELLAYER_METRICS_RESOLUTIONIN_HPP
#define SDF_MODELLAYER_METRICS_RESOLUTIONIN_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    resolutionIn.hpp
 * PURPOSE: Defines the resolutionIn helper function.
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

#include "../Exceptions/Exceptions.hpp"
#include "ResolutionQuantity.hpp"
#include "ResolutionUnit.hpp"
#include "ResolutionUnits.hpp"

namespace SDF::ModelLayer::Metrics {
  // Function:   resolutionIn
  // Purpose:    Return the value of a resolution quantity in a given enumerated unit (i.e. denominates it).
  // Parameters: quantity - The resolution quantity to use.
  //             unit - The unit to get it in.
  // Returns:    The resolution in the given units.
  // Throws:     If an invalid unit was passed, throws Exceptions::InvalidUnitException.
  static float resolutionIn(resolution_quantity quantity, ResolutionUnit unit) {
    switch(unit) {
      case RESOLUTION_UNIT_PPI: return boost::units::quantity<ppi_unit>(quantity).value();
      case RESOLUTION_UNIT_PIXELS_PER_CM: return boost::units::quantity<ppcm_unit>(quantity).value();
      case RESOLUTION_UNIT_PIXELS_PER_MM: return boost::units::quantity<resolution>(quantity).value();
      default:
        throw Exceptions::InvalidUnitException("resolution", unit);
    }
  }
}

#endif
