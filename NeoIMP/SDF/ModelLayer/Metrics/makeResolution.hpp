#ifndef SDF_MODELLAYER_METRICS_MAKERESOLUTION_HPP
#define SDF_MODELLAYER_METRICS_MAKERESOLUTION_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    makeResolution.hpp
 * PURPOSE: Defines the makeResolution helper function.
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
  // Function:   makeResolution
  // Purpose:    Create a resolution quantity from a float and enumerated unit.
  // Parameters: quantity - The quantity amount to use.
  //             unit - The unit to use.
  // Returns:    The resolution.
  // Throws:     If an invalid unit was passed, throws Exceptions::InvalidUnitException.
  static resolution_quantity makeResolution(float quantity, ResolutionUnit unit) {
    switch(unit) {
      case RESOLUTION_UNIT_PPI: return resolution_quantity(quantity * pixels_per_inch);
      case RESOLUTION_UNIT_PIXELS_PER_CM: return resolution_quantity(quantity * pixels_per_centimeter);
      case RESOLUTION_UNIT_PIXELS_PER_MM: return resolution_quantity(quantity * pixels_per_millimeter);
      default:
        throw Exceptions::InvalidUnitException("resolution", unit);
    }
  }
}

#endif
