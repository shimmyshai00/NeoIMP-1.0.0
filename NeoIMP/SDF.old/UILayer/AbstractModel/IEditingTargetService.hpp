#ifndef SDF_UILAYER_ABSTRACTMODEL_IEDITINGTARGETSERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_IEDITINGTARGETSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IEditingTargetService.hpp
 * PURPOSE: Defines the IEditingTargetService interface.
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

#include <SDF/UILayer/AbstractModel/Handle.hpp>

namespace SDF::UILayer::AbstractModel {
  // Class:      IEditingTargetService
  // Purpose:    Defines an interface for a model layer service to set the document that to be subject to editing
  //             operations with the other services. This is a tricky bit of state to fit into the MVC factorization
  //             since it could be argued also to technically be a UI state on the main editor view, but we want to
  //             ideally keep views independent of each other. Ideally we'd use an MVVM factorization for this type of
  //             app, but alas C++ does not provide nice ways to do data binding.
  // Parameters: None.
  class IEditingTargetService {
  public:
    virtual ~IEditingTargetService() = default;

    // Function:   getEditingTargetDocumentHandle
    // Purpose:    Get the handle of the document currently selected for editing.
    // Parameters: None.
    // Returns:    The document handle.
    virtual Handle
    getEditingTargetDocumentHandle() const = 0;

    // Function:   setEditingTargaetDocumentHandle
    // Purpose:    Set the handle of the document currently selected for editing.
    // Parameters: handle - The handle of the document to edit.
    // Returns:    None.
    virtual void
    setEditingTargaetDocumentHandle(Handle handle) = 0;
  };
}

#endif
