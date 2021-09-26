#ifndef SDF_UILAYER_ABSTRACTMODEL_SERVICES_IMEASUREMENTCONVERSIONSERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_SERVICES_IMEASUREMENTCONVERSIONSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IMeasurementConversionService.hpp
 * PURPOSE: Defines the IMeasurementConversionService interface.
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

#include "../Data/LengthUnit.hpp"
#include "../Data/ResolutionUnit.hpp"

namespace SDF::UILayer::AbstractModel::Services {
  // Class:      IMeasurementConversionService
  // Purpose:    Defines the interface for a service to convert measurements made in different measuring units.
  // Parameters: None.
  class IMeasurementConversionService {
  public:
    virtual ~IMeasurementConversionService() = default;

    // Function:   convertLength
    // Purpose:    Convert a length quantity from one measurement unit to another.
    // Parameters: length - The length to convert.
    //             lengthUnit - The unit it is given in.
    //             resolution - The resolution used for the conversion.
    //             resolutionUnit - The unit the resolution is given in.
    //             inUnit - The unit to convert the length into.
    // Returns:    The converted value in unit inUnit.
    virtual float
    convertLength(float length,
                  Data::LengthUnit lengthUnit,
                  float resolution,
                  Data::ResolutionUnit resolutionUnit,
                  Data::LengthUnit inUnit
                 ) = 0;

    // Function:   convertResolution
    // Purpose:    Convert a resolution quantity from one measurement unit to another.
    // Parameters: resolution - The resolution to convert.
    //             resolutionUnit - The unit it is given in.
    //             inUnit - The unit to convert the resolution into.
    // Returns:    The converted value in unit inUnit.
    virtual float
    convertResolution(float resolution,
                      Data::ResolutionUnit resolutionUnit,
                      Data::ResolutionUnit inUnit
                     ) = 0;
  };
}

#endif
