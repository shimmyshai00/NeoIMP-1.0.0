#ifndef SDF_UILAYER_METRICS_MAKELENGTH_HPP
#define SDF_UILAYER_METRICS_MAKELENGTH_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    makeLength.hpp
 * PURPOSE: Defines the makeLength helper function.
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

#include <SDF/UILayer/Exceptions/Exceptions.hpp>
#include <SDF/UILayer/Metrics/LengthQuantity.hpp>
#include <SDF/UILayer/Metrics/LengthUnit.hpp>
#include <SDF/UILayer/Metrics/LengthUnits.hpp>

namespace SDF::UILayer::Metrics {
  // Function:   makeLength
  // Purpose:    Create a length quantity from a float and enumerated unit.
  // Parameters: quantity - The quantity amount to use.
  //             unit - The unit to use.
  // Returns:    The length.
  // Throws:     If an invalid unit was passed, throws Exceptions::InvalidUnitException.
  static length_quantity makeLength(float quantity, LengthUnit unit) {
    switch(unit) {
      case LENGTH_UNIT_MILLIMETER: return length_quantity(quantity * millimeters);
      case LENGTH_UNIT_POINT: return length_quantity(quantity * points);
      case LENGTH_UNIT_PICA: return length_quantity(quantity * picas);
      case LENGTH_UNIT_CENTIMETER: return length_quantity(quantity * centimeters);
      case LENGTH_UNIT_INCH: return length_quantity(quantity * inches);
      default:
        throw Exceptions::InvalidUnitException("length", unit);
    }
  }
}

#endif
