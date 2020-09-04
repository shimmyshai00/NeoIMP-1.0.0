#ifndef SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_METRICS_LENGTH_UNITS_HPP
#define SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_METRICS_LENGTH_UNITS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Units.hpp
 * PURPOSE: Definition of length units for document size measurement.
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

#include <Impl/DomainObjects/Metrics/Impl/UnitSystem.hpp>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects::Metrics::Length::Units {
        typedef sdf::boost_detail::length Any;
        typedef sdf::boost_detail::millimeter_base_unit::unit_type Millimeters;
        typedef sdf::boost_detail::point_base_unit::unit_type Points;
        typedef sdf::boost_detail::pica_base_unit::unit_type Picas;
        typedef sdf::boost_detail::centimeter_base_unit::unit_type Centimeters;
        typedef sdf::boost_detail::inch_base_unit::unit_type Inches;

        static const Millimeters mm;
        static const Points pt;
        static const Picas pica;
        static const Centimeters cm;
        static const Inches in;
      }
    }
  }
}

#endif
