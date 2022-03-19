#ifndef SDF_IMPL_UILAYER_IMPL_GUI_IMPL_APPLICATIONMODEL_IMPL_METRICS_LENGTHUNITS_HPP
#define SDF_IMPL_UILAYER_IMPL_GUI_IMPL_APPLICATIONMODEL_IMPL_METRICS_LENGTHUNITS_HPP
/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    LengthUnits.hpp
 * PURPOSE: Defines the available length units.
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

#include <SDF/UILayer/Metrics/UnitSystem.hpp>

#include <boost/units/unit.hpp>
#include <boost/units/make_scaled_unit.hpp>
#include <boost/units/static_constant.hpp>

namespace SDF::UILayer::Metrics {
  // Length unit for quantities.
  typedef boost::units::unit<boost::units::length_dimension, metric_unit_system> length;
  typedef boost::units::unit<boost::units::length_dimension, typographic_unit_system> typographic_length;

  // Derived length units in the metric system.
  typedef boost::units::make_scaled_unit<length, boost::units::scale<10, boost::units::static_rational<1>>>::type centimeter_unit;

  // Derived length units in the typographic system.
  typedef boost::units::make_scaled_unit<typographic_length, boost::units::scale<12, boost::units::static_rational<1>>>::type pica_unit;
  typedef boost::units::make_scaled_unit<pica_unit, boost::units::scale<6, boost::units::static_rational<1>>>::type inch_unit;

  // Constants for easy use in expressions.
  BOOST_UNITS_STATIC_CONSTANT(millimeters, length);
  BOOST_UNITS_STATIC_CONSTANT(centimeters, centimeter_unit);

  BOOST_UNITS_STATIC_CONSTANT(points, typographic_length);
  BOOST_UNITS_STATIC_CONSTANT(picas, pica_unit);
  BOOST_UNITS_STATIC_CONSTANT(inches, inch_unit);
}

#endif
