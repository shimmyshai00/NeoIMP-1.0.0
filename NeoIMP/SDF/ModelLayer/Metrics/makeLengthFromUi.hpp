#ifndef SDF_MODELLAYER_METRICS_MAKELENGTHFROMUI_HPP
#define SDF_MODELLAYER_METRICS_MAKELENGTHFROMUI_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    makeLengthFromUi.hpp
 * PURPOSE: Defines the makeLengthFromUi helper function.
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

#include "../../UILayer/AbstractModel/Data/LengthUnit.hpp"
#include "../../UILayer/AbstractModel/Data/ResolutionUnit.hpp"
#include "../Exceptions/Exceptions.hpp"
#include "LengthQuantity.hpp"
#include "ResolutionQuantity.hpp"
#include "DimensionlessQuantity.hpp"
#include "DimensionlessUnits.hpp"
#include "LengthUnits.hpp"
#include "ResolutionUnits.hpp"
#include "makeResolutionFromUi.hpp"

namespace SDF::ModelLayer::Metrics {
  // Function:   makeLengthFromUi
  // Purpose:    Create a length quantity from a float and unit enumerated as in commands from the UI layer. This also
  //             permits entry in pixels, and thus requires supplying an associated resolution factor.
  // Parameters: quantity - The quantity amount to use.
  //             unit - The unit to use.
  //             resolution - The resolution to convert pixels to physical units with.
  //             resolutionUnit - The unit the resolution is given in.
  // Returns:    The length.
  // Throws:     If an invalid unit was passed, throws Exceptions::InvalidUnitException.
  static length_quantity makeLengthFromUi(float quantity,
                                          UILayer::AbstractModel::Data::LengthUnit unit,
                                          float resolution,
                                          UILayer::AbstractModel::Data::ResolutionUnit resolutionUnit
                                         )
  {
    using namespace UILayer::AbstractModel::Data;

    switch(unit) {
      case UNIT_PIXEL:
        return length_quantity((quantity * ones) / makeResolutionFromUi(resolution, resolutionUnit));
      case UNIT_MILLIMETER: return length_quantity(quantity * millimeters);
      case UNIT_POINT: return length_quantity(quantity * points);
      case UNIT_PICA: return length_quantity(quantity * picas);
      case UNIT_CENTIMETER: return length_quantity(quantity * centimeters);
      case UNIT_INCH: return length_quantity(quantity * inches);
      default:
        throw Exceptions::InvalidLengthUnitException(unit);
    }
  }
}

#endif
