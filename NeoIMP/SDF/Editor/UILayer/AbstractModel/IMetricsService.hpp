#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_IMETRICSSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_IMETRICSSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IMetricsService.hpp
 * PURPOSE: Defines the IMetricsService interface.
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

#include "Defs/IUnitConvertible.hpp"

#include "Defs/ELengthUnit.hpp"
#include "Defs/EResolutionUnit.hpp"

#include <memory>

namespace SDF::Editor::UILayer::AbstractModel {
  // Class:      IMetricsService
  // Purpose:    Defines the interface for an MVC service that handles unit conversions and other
  //             measurement matters.
  // Parameters: None.
  class IMetricsService {
  public:
    virtual ~IMetricsService() = default;

    // Function:   createConvertibleLength
    // Purpose:    Creates a length quantity which is interchangeable amongst different units.
    // Parameters: length - The length to pack
    //             lengthUnit - The unit of length it is given in
    //             resolution - The resolution to use to convert to/from pixels.
    // Returns:    A convertible representing the length in general units.
    virtual std::shared_ptr<Defs::IUnitConvertible<Defs::ELengthUnit>>
    createConvertibleLength(float length,
                            Defs::ELengthUnit lengthUnit,
                            Defs::IUnitConvertible<Defs::EResolutionUnit> *resolution
                           ) = 0;

    // Function:   createConvertibleResolution
    // Purpose:    Creates a resolution quantity which is interchangeable amongst different units.
    // Parameters: resolution - The resolution to pack
    //             resUnit - The unit of resolution it is given in
    // Returns:    A convertible representing the resolution in general units.
    virtual std::shared_ptr<Defs::IUnitConvertible<Defs::EResolutionUnit>>
    createConvertibleResolution(float resolution,
                                Defs::EResolutionUnit resolutionUnit
                               ) = 0;
  };
}

#endif
