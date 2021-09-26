#ifndef SDF_MODELLAYER_METRICS_LENGTHIN_HPP
#define SDF_MODELLAYER_METRICS_LENGTHIN_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    lengthIn.hpp
 * PURPOSE: Defines the lengthIn helper function.
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
#include "LengthQuantity.hpp"
#include "LengthUnit.hpp"
#include "LengthUnits.hpp"

namespace SDF::ModelLayer::Metrics {
  // Function:   lengthIn
  // Purpose:    Return the value of a length quantity in a given enumerated unit (i.e. denominates it).
  // Parameters: quantity - The length quantity to use.
  //             unit - The unit to get it in.
  // Returns:    The length in the given units.
  // Throws:     If an invalid unit was passed, throws Exceptions::InvalidUnitException.
  static float lengthIn(length_quantity quantity, LengthUnit unit) {
    switch(unit) {
      case LENGTH_UNIT_MILLIMETER: return boost::units::quantity<Metrics::length>(quantity).value();
      case LENGTH_UNIT_POINT: return boost::units::quantity<Metrics::typographic_length>(quantity).value();
      case LENGTH_UNIT_PICA: return boost::units::quantity<Metrics::pica_unit>(quantity).value();
      case LENGTH_UNIT_CENTIMETER: return boost::units::quantity<Metrics::centimeter_unit>(quantity).value();
      case LENGTH_UNIT_INCH: return boost::units::quantity<Metrics::inch_unit>(quantity).value();
      default:
        throw Exceptions::InvalidUnitException("length", unit);
    }
  }
}

#endif
