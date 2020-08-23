#ifndef SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_UNITS_HPP
#define SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_UNITS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Units.hpp
 * PURPOSE: Namespace with definitions of measuring units.
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

#include <SUnit.hpp>
#include <SDF/ModelLayer/Iface/Param/EDimensionUnit.hpp>
#include <SDF/ModelLayer/Iface/Param/EResolutionUnit.hpp>
#include <map>

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    namespace DomainObjects::Units {
      static const SUnit Pixel = { 1.0f, "px" };

      static const SUnit Millimeter = { 1.0f, "mm" };
      static const SUnit Point = { 25.4f / 72.0, "pt" };
      static const SUnit Pica = { 25.4f / 12.0, "pica" };
      static const SUnit Centimeter = { 10.0f, "cm" };
      static const SUnit Inch = { 25.4f, "in" };

      static const SUnit PerMillimeter { 1.0f, "per mm" };
      static const SUnit PerCentimeter { 0.1f, "per cm" };
      static const SUnit PerInch { 1.0f / 25.4, "per in" };

      static const std::map<SDF::ModelLayer::Iface::Param::EDimensionUnit, SUnit> dimUnitEnumMap = {
        { SDF::ModelLayer::Iface::Param::UNIT_MILLIMETER, Millimeter },
        { SDF::ModelLayer::Iface::Param::UNIT_POINT, Point },
        { SDF::ModelLayer::Iface::Param::UNIT_PICA, Pica },
        { SDF::ModelLayer::Iface::Param::UNIT_CENTIMETER, Centimeter },
        { SDF::ModelLayer::Iface::Param::UNIT_INCH, Inch }
      };

      static const std::map<SDF::ModelLayer::Iface::Param::EResolutionUnit, SUnit> resUnitEnumMap = {
        { SDF::ModelLayer::Iface::Param::UNIT_PIXELS_PER_INCH, PerInch },
        { SDF::ModelLayer::Iface::Param::UNIT_PIXELS_PER_CENTIMETER, PerCentimeter },
        { SDF::ModelLayer::Iface::Param::UNIT_PIXELS_PER_MILLIMETER, PerMillimeter }
      };
    }
  }
}

#endif
