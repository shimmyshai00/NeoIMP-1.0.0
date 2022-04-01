#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_METRICS_ICONVERTLENGTHSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_METRICS_ICONVERTLENGTHSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IConvertLengthService.hpp
 * PURPOSE: Defines the IConvertLengthService interface.
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
#include "../Defs/LengthUnit.hpp"

#include <memory>

namespace SDF::Editor::UILayer::AbstractModel::Metrics {
  // Class:      IConvertLengthService
  // Purpose:    Defines a service interface to convert lengths specified in physical measuring
  //             units.
  // Parameters: None.
  class IConvertLengthService {
  public:
    virtual ~IConvertLengthService() = default;

    // Function:         createConvertibleLength
    // Purpose:          Processes a length into an object that can be easily "displayed" in a
    //                   variety of units.
    // Parameters:       length - The length quantity to convert.
    //                   lengthUnit - The units it is given in.
    //                   resolution - The resolution reference to convert from and to pixels.
    // Returns:          A convertible object that can give this length in any unit.
    // Throws (non-bug): InvalidUnitException
    virtual std::shared_ptr<Defs::IUnitConvertible<Defs::LengthUnit>>
    createConvertibleLength(
      float a_length,
      Defs::LengthUnit a_lengthUnit,
      Defs::IUnitConvertible<Defs::ResolutionUnit> *a_resolution
    ) = 0;
  };
}

#endif
