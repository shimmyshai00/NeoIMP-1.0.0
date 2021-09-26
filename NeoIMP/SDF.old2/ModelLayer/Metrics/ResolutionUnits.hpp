#ifndef SDF_MODELLAYER_METRICS_RESOLUTIONUNITS_HPP
#define SDF_MODELLAYER_METRICS_RESOLUTIONUNITS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ResolutionUnits.hpp
 * PURPOSE: Defines the available resolution units.
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

#include "UnitSystem.hpp"

#include <boost/units/derived_dimension.hpp>
#include <boost/units/unit.hpp>
#include <boost/units/scaled_base_unit.hpp>
#include <boost/units/make_scaled_unit.hpp>

#include <boost/units/static_constant.hpp>

namespace SDF::ModelLayer::Metrics {
  // Define the derived resolution dimension.
  typedef boost::units::derived_dimension<boost::units::length_base_dimension, -1>::type resolution_dimension;

  // Resolution unit for quantities.
  typedef boost::units::unit<resolution_dimension, metric_unit_system> resolution;
  typedef boost::units::unit<resolution_dimension, typographic_unit_system> typographic_resolution;

  // Derived resolution units in the metric system.
  typedef boost::units::make_scaled_unit<resolution, boost::units::scale<10, boost::units::static_rational<-1>>>::type ppcm_unit;

  // Derived resolution units in the typographic system.
  typedef boost::units::make_scaled_unit<typographic_resolution, boost::units::scale<72, boost::units::static_rational<-1>>>::type ppi_unit;

  // Constants for easy use in expressions.
  BOOST_UNITS_STATIC_CONSTANT(pixels_per_millimeter, resolution);
  BOOST_UNITS_STATIC_CONSTANT(pixels_per_centimeter, ppcm_unit);

  BOOST_UNITS_STATIC_CONSTANT(pixels_per_point, typographic_resolution);
  BOOST_UNITS_STATIC_CONSTANT(pixels_per_inch, ppi_unit);
}

#endif
