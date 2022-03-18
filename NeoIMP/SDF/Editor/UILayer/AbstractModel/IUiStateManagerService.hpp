#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_IUISTATEMANAGERSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_IUISTATEMANAGERSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IUiStateManagerService.hpp
 * PURPOSE: Defines the IUiStateManagerService interface.
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

#include "../../../Common/Handle.hpp"

#include <string>

namespace SDF::Editor::UILayer::AbstractModel {
  // Class:      IUiStateManagerService
  // Purpose:    Pushes cross-cutting and persistible user interface state (such as which document
  //             is selected as the target for editing operations, or what documents are presently
  //             open, either of which may be used by many UI elements) into the model layer so it
  //             is both contained away from other parts thereof while also being accessible to the
  //             data layer beneath. It is hard to decide whether this should be kept up in the UI
  //             layer or pushed down due to the potential for persistence of this data. Essentially
  //             a cheap "key-value" access database for all this stuff. The existence and placement
  //             of this object and information is meant for debate, discussion, and contention.
  // Parameters: None.
  class IUiStateManagerService {
  public:
    virtual ~IUiStateManagerService() = default;

    // Function:   add*Entry
    // Purpose:    Adds an entry to the database.
    // Parameters: uiKey - The key identifying the user interface in question.
    //             fieldKey - The key identifying the field in question.
    //             value - The value to assign.
    // Returns:    None.
    virtual void
    addHandleEntry(Common::Handle uiKey, std::string fieldKey, Common::Handle value) = 0;

    // Function:   get*Entry
    // Purpose:    Gets an entry from the database.
    // Parameters: uiKey - The key identifying the user interface in question.
    //             fieldKey - The key identifying the field in question.
    // Returns:    The value with the given keys, or throws if none.
    virtual Common::Handle
    getHandleEntry(Common::Handle uiKey, std::string fieldKey) = 0;
  };
}

#endif
