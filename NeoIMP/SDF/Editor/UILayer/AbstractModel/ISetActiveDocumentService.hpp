#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_ISETACTIVEDOCUMENTSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_ISETACTIVEDOCUMENTSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ISetActiveDocumentService.hpp
 * PURPOSE: Defines the ISetActiveDocumentService interface.
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

namespace SDF::Editor::UILayer::AbstractModel {
  // Class:      ISetActiveDocumentService
  // Purpose:    Defines the interface for an MVC service to set which document is flagged as the
  //             active context for editing operations.
  // Parameters: None.
  class ISetActiveDocumentService {
  public:
    virtual ~ISetActiveDocumentService();

    // Function:   setActiveDocument
    // Purpose:    Sets the active document.
    // Parameters: handle - The handle of the document to declare active.
    // Returns:    None.
    virtual void
    setActiveDocument(Common::Handle handle) = 0;
  };
}

#endif
