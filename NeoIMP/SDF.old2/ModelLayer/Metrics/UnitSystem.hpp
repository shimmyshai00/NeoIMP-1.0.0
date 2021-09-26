#ifndef SDF_MODELLAYER_METRICS_UNITSYSTEM_HPP
#define SDF_MODELLAYER_METRICS_UNITSYSTEM_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UnitSystem.hpp
 * PURPOSE: Defines the unit systems for representing physical length-related quantities (versus pixels).
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

#include <boost/units/base_unit.hpp>
#include <boost/units/unit.hpp>

#include <boost/units/make_system.hpp>
#include <boost/units/physical_dimensions/length.hpp>

#include <boost/units/conversion.hpp>
#include <boost/units/static_constant.hpp>

namespace SDF::ModelLayer::Metrics {
  // The length base units for each unit system.
  struct millimeter_base_unit : boost::units::base_unit<millimeter_base_unit, boost::units::length_dimension, 1> {};
  struct point_base_unit : boost::units::base_unit<point_base_unit, boost::units::length_dimension, 2> {};

  // The unit systems.
  typedef boost::units::make_system<millimeter_base_unit>::type metric_unit_system;
  typedef boost::units::make_system<point_base_unit>::type typographic_unit_system;
}

// The basic conversion relation between the two systems.
BOOST_UNITS_DEFINE_CONVERSION_FACTOR(SDF::ModelLayer::Metrics::point_base_unit,
                                     SDF::ModelLayer::Metrics::millimeter_base_unit,
                                     float,
                                     25.4f / 72.0f
                                    );

#endif
