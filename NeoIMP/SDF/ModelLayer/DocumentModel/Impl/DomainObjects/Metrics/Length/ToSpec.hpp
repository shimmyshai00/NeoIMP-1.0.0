#ifndef SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_METRICS_LENGTH_TOSPEC_HPP
#define SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_METRICS_LENGTH_TOSPEC_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ToSpec.hpp
 * PURPOSE: Declaration of function to convert a length quantity to a document spec unit.
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

#include <SDF/Exception.hpp>
#include <Impl/DomainObjects/Metrics/Length/Quantity.hpp>
#include <Impl/DomainObjects/Metrics/Length/Units.hpp>
#include <Spec/EDimensionUnit.hpp>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects::Metrics::Length {
        struct CannotConvertToException : public SDF::Exception {
          CannotConvertToException(Spec::EDimensionUnit specUnit)
          : Exception("INTERNAL ERROR: Cannot convert quantity to spec unit '%d' directly", specUnit)
          {
          }
        };

        static float toSpec(Quantity q, Spec::EDimensionUnit specUnit) {
          using namespace Spec;

          switch(specUnit) {
            case UNIT_MILLIMETER: return Metrics::Quantity<Units::Millimeters>(q).value();
            case UNIT_POINT: return Metrics::Quantity<Units::Points>(q).value();
            case UNIT_PICA: return Metrics::Quantity<Units::Picas>(q).value();
            case UNIT_CENTIMETER: return Metrics::Quantity<Units::Centimeters>(q).value();
            case UNIT_INCH: return Metrics::Quantity<Units::Inches>(q).value();
            default:
              throw CannotConvertToException(specUnit);
          }
        }
      }
    }
  }
}

#endif
