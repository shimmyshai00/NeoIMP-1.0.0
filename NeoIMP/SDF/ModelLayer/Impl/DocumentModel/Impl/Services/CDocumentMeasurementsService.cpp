/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CDocumentMeasurementsService.cpp
 * PURPOSE: Implementation of the document measurements service class.
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

#include <CDocumentMeasurementsService.hpp>
#include <Impl/DomainObjects/CUnitConverter.hpp>
#include <Impl/DomainObjects/Units.hpp>

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    namespace Services {
      CDocumentMeasurementsService::CDocumentMeasurementsService() {

      }

      float CDocumentMeasurementsService::convertDimensionUnits(float dim,
        SDF::ModelLayer::Iface::Param::EDimensionUnit fromUnit, SDF::ModelLayer::Iface::Param::EDimensionUnit toUnit) {
        using namespace Impl::DomainObjects;

        CUnitConverter docUnitConverter;

        return docUnitConverter.convertQuantity(dim,
          Units::dimUnitEnumMap.at(fromUnit), Units::dimUnitEnumMap.at(toUnit));
      }

      float CDocumentMeasurementsService::convertResolutionUnits(float res,
        SDF::ModelLayer::Iface::Param::EResolutionUnit fromUnit,
        SDF::ModelLayer::Iface::Param::EResolutionUnit toUnit) {
        using namespace Impl::DomainObjects;

        CUnitConverter resUnitConverter;

        return resUnitConverter.convertQuantity(res,
          Units::resUnitEnumMap.at(fromUnit), Units::resUnitEnumMap.at(toUnit));
      }

      std::string CDocumentMeasurementsService::getDimensionUnitSymbol(
        SDF::ModelLayer::Iface::Param::EDimensionUnit unit) {
        using namespace Impl::DomainObjects;

        return Units::dimUnitEnumMap.at(unit).unitSymbol;
      }

      std::string CDocumentMeasurementsService::getResolutionUnitSymbol(
        SDF::ModelLayer::Iface::Param::EResolutionUnit unit) {
        using namespace Impl::DomainObjects;

        return Units::resUnitEnumMap.at(unit).unitSymbol;
      }
    }
  }
}
