#ifndef SDF_MODELLAYER_IFACE_IDOCUMENTMEASUREMENTSSERVICE_HPP
#define SDF_MODELLAYER_IFACE_IDOCUMENTMEASUREMENTSSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IDocumentMeasurementsService.hpp
 * PURPOSE: The public interface for the document measurements service.
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

#include <Spec/EDimensionUnit.hpp>
#include <Spec/EResolutionUnit.hpp>

#include <string>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Services {
        class IDocumentMeasurementsService {
        public:
          virtual ~IDocumentMeasurementsService() {}

          virtual float convertDimensionUnits(float dim, Spec::EDimensionUnit fromUnit, Spec::EDimensionUnit toUnit) = 0;
          virtual float convertResolutionUnits(float res, Spec::EResolutionUnit fromUnit, Spec::EResolutionUnit toUnit) = 0;
        };
      }
    }
  }
}

#endif
