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

#include <Impl/Services/CDocumentMeasurementsService.hpp>

#include <Impl/DomainObjects/Metrics/Length/Units.hpp>
#include <Impl/DomainObjects/Metrics/Length/Quantity.hpp>
#include <Impl/DomainObjects/Metrics/Length/FromSpec.hpp>
#include <Impl/DomainObjects/Metrics/Length/ToSpec.hpp>

#include <Impl/DomainObjects/Metrics/Resolution/Units.hpp>
#include <Impl/DomainObjects/Metrics/Resolution/Quantity.hpp>
#include <Impl/DomainObjects/Metrics/Resolution/FromSpec.hpp>
#include <Impl/DomainObjects/Metrics/Resolution/ToSpec.hpp>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::Services {
        CDocumentMeasurementsService::CDocumentMeasurementsService() {

        }

        float CDocumentMeasurementsService::convertDimensionUnits(float dim,
          Spec::EDimensionUnit fromUnit, Spec::EDimensionUnit toUnit) {
            using namespace DomainObjects::Metrics;

            return Length::toSpec(Length::fromSpec(dim, fromUnit), toUnit);
          }

        float CDocumentMeasurementsService::convertResolutionUnits(float res,
          Spec::EResolutionUnit fromUnit, Spec::EResolutionUnit toUnit) {
            using namespace DomainObjects::Metrics;

            return Resolution::toSpec(Resolution::fromSpec(res, fromUnit), toUnit);
          }
      }
    }
  }
}
