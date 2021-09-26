#ifndef SDF_MODELLAYER_SERVICES_MEASUREMENTCONVERSIONSERVICE_HPP
#define SDF_MODELLAYER_SERVICES_MEASUREMENTCONVERSIONSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MeasurementConversionService.hpp
 * PURPOSE: Defines the MeasurementConversionService class.
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

#include "../../UILayer/AbstractModel/Services/IMeasurementConversionService.hpp"
#include "../../UILayer/AbstractModel/Data/LengthUnit.hpp"
#include "../../UILayer/AbstractModel/Data/ResolutionUnit.hpp"

#include <fruit/fruit.h>

namespace SDF::ModelLayer::Services {
  // Class:      MeasurementConversionService
  // Purpose:    Implements a service to convert measurement units.
  // Parameters: None.
  class MeasurementConversionService : public UILayer::AbstractModel::Services::IMeasurementConversionService {
  public:
    INJECT(MeasurementConversionService());

    float
    convertLength(float length,
                  UILayer::AbstractModel::Data::LengthUnit lengthUnit,
                  float resolution,
                  UILayer::AbstractModel::Data::ResolutionUnit resolutionUnit,
                  UILayer::AbstractModel::Data::LengthUnit inUnit
                 );

    float
    convertResolution(float resolution,
                      UILayer::AbstractModel::Data::ResolutionUnit resolutionUnit,
                      UILayer::AbstractModel::Data::ResolutionUnit inUnit
                    );
  };
}

#endif
