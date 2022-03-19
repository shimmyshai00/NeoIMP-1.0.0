#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_METRICS_ICONVERTRESOLUTIONSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_METRICS_ICONVERTRESOLUTIONSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IConvertResolutionService.hpp
 * PURPOSE: Defines the IConvertResolutionService interface.
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

#include "../Defs/IUnitConvertible.hpp"
#include "../Defs/EResolutionUnit.hpp"

#include <memory>

namespace SDF::Editor::UILayer::AbstractModel::Metrics {
  // Class:      IConvertResolutionService
  // Purpose:    Defines a service interface to convert resolutions specified in physical measuring
  //             units.
  // Parameters: None.
  class IConvertResolutionService {
  public:
    virtual ~IConvertResolutionService() = default;

    // Function:   createConvertibleResolution
    // Purpose:    Processes a resoluton into an object that can be easily "displayed" in a variety of
    //             units.
    // Parameters: resolution - The resolution quantity to convert.
    //             resolutionUnit - The units it is given in.
    // Returns:    A convertible object that can give this resolution in any unit.
    virtual std::shared_ptr<Defs::IUnitConvertible<Defs::EResolutionUnit>>
    createConvertibleResolution(float resolution, Defs::EResolutionUnit resolutionUnit) = 0;
  };
}

#endif
