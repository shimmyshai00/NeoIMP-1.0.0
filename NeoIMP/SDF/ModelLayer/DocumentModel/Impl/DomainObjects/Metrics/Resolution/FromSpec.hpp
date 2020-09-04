#ifndef SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_METRICS_RESOLUTION_FROMSPEC_HPP
#define SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_METRICS_RESOLUTION_FROMSPEC_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FromSpec.hpp
 * PURPOSE: Declaration of function to convert a document spec unit specification to a resolution quantity.
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
#include <Impl/DomainObjects/Metrics/Resolution/Quantity.hpp>
#include <Spec/EResolutionUnit.hpp>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects::Metrics::Resolution {
        struct CannotConvertFromException : public SDF::Exception {
          CannotConvertFromException(Spec::EResolutionUnit specUnit)
          : Exception("INTERNAL ERROR: Cannot convert spec unit '%d' to quantity directly", specUnit)
          {
          }
        };

        static Quantity fromSpec(float val, Spec::EResolutionUnit specUnit) {
          using namespace Spec;

          switch(specUnit) {
            case UNIT_PIXELS_PER_INCH: return Quantity(val * Units::ppi);
            case UNIT_PIXELS_PER_CENTIMETER: return Quantity(val * Units::ppcm);
            case UNIT_PIXELS_PER_MILLIMETER: return Quantity(val * Units::ppmm);
            default:
              throw CannotConvertFromException(specUnit);
          }
        }
      }
    }
  }
}

#endif
