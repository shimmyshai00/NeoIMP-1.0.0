#ifndef SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_METRICS_IMPL_UNITSYSTEM_HPP
#define SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_METRICS_IMPL_UNITSYSTEM_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UnitSystem.hpp
 * PURPOSE: BOOST-based implementation of the unit system.
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

#include <boost/units/derived_dimension.hpp>
#include <boost/units/base_unit.hpp>
#include <boost/units/physical_dimensions/length.hpp>
#include <boost/units/make_system.hpp>
#include <boost/units/scaled_base_unit.hpp>
#include <boost/units/conversion.hpp>

namespace sdf::boost_detail {
  typedef boost::units::length_dimension length_dimension;
  typedef boost::units::derived_dimension<boost::units::length_base_dimension, -1>::type resolution_dimension;

  // Unit system for lengths based on arbitrary base unit.
  struct length_base_unit : boost::units::base_unit<length_base_unit, boost::units::length_dimension, 1> {};
  typedef boost::units::make_system<length_base_unit>::type sdf_system;

  // Base units for metric and customary systems. These should be equivalent to mm and in, respectively.
  struct millimeter_base_unit : boost::units::base_unit<millimeter_base_unit, length_dimension, 2> {};
  struct inch_base_unit : boost::units::base_unit<inch_base_unit, length_dimension, 3> {};

  // Scaled length units.
  struct centimeter_base_unit :
    boost::units::scaled_base_unit<millimeter_base_unit, boost::units::scale<10, boost::units::static_rational<1>>> {};
  struct point_base_unit :
    boost::units::scaled_base_unit<inch_base_unit, boost::units::scale<72, boost::units::static_rational<-1>>> {};
  struct pica_base_unit :
    boost::units::scaled_base_unit<inch_base_unit, boost::units::scale<6, boost::units::static_rational<-1>>> {};

  // Resolution units.
  struct resolution_base_unit : boost::units::base_unit<resolution_base_unit, resolution_dimension, 4> {};
  struct per_centimeter_base_unit : boost::units::base_unit<per_centimeter_base_unit, resolution_dimension, 5> {};
  struct per_inch_base_unit : boost::units::base_unit<per_inch_base_unit, resolution_dimension, 6> {};

  struct per_millimeter_base_unit :
    boost::units::scaled_base_unit<per_centimeter_base_unit,
      boost::units::scale<10, boost::units::static_rational<1>>> {};

  // Unit-type arbitrary units for quantities.
  typedef boost::units::unit<length_dimension, sdf_system> length;
  typedef boost::units::unit<resolution_dimension, sdf_system> resolution;
}

// Note: the arbitrary units of length and resolution should give factor 1 on multiplication to make arithmetic
//       consistent. We treat them as mm and ppmm respectively.
BOOST_UNITS_DEFINE_CONVERSION_FACTOR(sdf::boost_detail::millimeter_base_unit, sdf::boost_detail::length,
  float, 1.0f);
BOOST_UNITS_DEFINE_CONVERSION_FACTOR(sdf::boost_detail::inch_base_unit, sdf::boost_detail::length,
  float, 25.4f);
BOOST_UNITS_DEFINE_CONVERSION_FACTOR(sdf::boost_detail::inch_base_unit, sdf::boost_detail::millimeter_base_unit,
  float, 25.4f);

BOOST_UNITS_DEFINE_CONVERSION_FACTOR(sdf::boost_detail::per_centimeter_base_unit, sdf::boost_detail::resolution,
  float, 0.1f);
BOOST_UNITS_DEFINE_CONVERSION_FACTOR(sdf::boost_detail::per_inch_base_unit, sdf::boost_detail::resolution,
  float, 1.0f / 25.4f);
BOOST_UNITS_DEFINE_CONVERSION_FACTOR(sdf::boost_detail::per_inch_base_unit, sdf::boost_detail::per_centimeter_base_unit,
  float, 1.0f / 2.54f);

#endif
