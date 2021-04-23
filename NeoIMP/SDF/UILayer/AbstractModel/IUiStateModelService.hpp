#ifndef SDF_UILAYER_ABSTRACTMODEL_IUISTATEMODELSERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_IUISTATEMODELSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IUiStateModelService.hpp
 * PURPOSE: Defines the IUiStateModelService interface.
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

#include <string>

namespace SDF::UILayer::AbstractModel {
  // Class:      IUiStateModelService
  // Purpose:    Provides a database to store editor UI state that doesn't otherwise fit with a specific UI element or
  //             sensibly could be considered to reflect a property of the domain model.
  // Parameters: StateT - The type of state this state model service serves.
  template<class StateT>
  class IUiStateModelService {
  public:
    virtual ~IUiStateModelService() = default;

    // Function:   getStateElement
    // Purpose:    Get a state element with a given key.
    // Parameters: key - The key to the state element.
    // Returns:    The requested state element.
    virtual StateT
    getStateElement(std::string key) = 0;

    // Function:   setStateElement
    // Purpose:    Set a state element to a given value. Creates a new element if this one does not exist already.
    // Parameters: key - The key to the element to set.
    //             value - The value to set it to.
    // Returns:    None.
    virtual void
    setStateElement(std::string key,
                    StateT value
                   ) = 0;
  };
}

#endif
