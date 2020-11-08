#ifndef SDF_UILAYER_METRICS_LENGTH_UNITS_UNITS_HPP
#define SDF_UILAYER_METRICS_LENGTH_UNITS_UNITS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Units.hpp
 * PURPOSE: Definitions of the units for length quantities.
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

namespace SDF::UILayer::Metrics::Length::Units {
  // Unit enumeration.
  enum {
    LENGTH_UNIT_MILLIMETER,
    LENGTH_UNIT_POINT,
    LENGTH_UNIT_PICA,
    LENGTH_UNIT_CENTIMETER,
    LENGTH_UNIT_INCH,
    LENGTH_UNIT_MAX
  };

  // Unit definitions. We take the arbitrary base units to be millimeters.
  typedef Unit<1, 0> LengthUnit;
  static const LengthUnit Millimeter = LengthUnit(1.0f);
  static const LengthUnit Point = LengthUnit(0.3527778f);
  static const LengthUnit Pica = LengthUnit(4.233333f);
  static const LengthUnit Centimeter = LengthUnit(10.0f);
  static const LengthUnit Inch = LengthUnit(25.4f);

  // Unit names. NOTE: this may need to be revised later and put in a central database to support alternative languages.
  static const std::string names[LENGTH_UNIT_MAX] = {
    "millimeters",
    "points",
    "picas",
    "centimeters",
    "inches"
  };

  // Unit symbols.
  static const std::string symbols[LENGTH_UNIT_MAX] = {
    "mm",
    "pt",
    "pica",
    "cm",
    "in"
  };

  // Units in an indexable list.
  static const LengthUnit units[LENGTH_UNIT_MAX] = {
    Millimeter,
    Point,
    Pica,
    Centimeter,
    Inch
  };
};

#endif
