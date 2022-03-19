#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_EDITOR_DATAMODEL_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_EDITOR_DATAMODEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DataModel.hpp
 * PURPOSE: Defines the DataModel class.
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

#include "../../../../Common/Handle.hpp"
#include "ViewAnchor.hpp"

#include <fruit/fruit.h>

#include <string>
#include <map>

namespace SDF::Editor::ModelLayer::DomainObjects::Editor {
  // Class:   DataModel
  // Purpose: Stores and manages editor application state as a single source of truth.
  class DataModel {
  public:
    INJECT(DataModel());

    // Function:   createDocumentRecord
    // Purpose:    Creates a new record in the data model for a document's application state.
    // Parameters: documentHandle - The handle to create for.
    // Returns:    None.
    void
    createDocumentRecord(Common::Handle documentHandle);

    // Function:   deleteDocumentRecord
    // Purpose:    Deletes the record of a document's application state.
    // Parameters: documentHandle - The handle to delete for.
    // Returns:    None.
    void
    deleteDocumentRecord(Common::Handle documentHandle);

    // Function:   getActiveDocument
    // Purpose:    Gets the handle of the document marked as active for editing.
    // Parameters: None.
    // Returns:    The handle of the marked document, or Common::HANDLE_INVALID if none marked.
    Common::Handle
    getActiveDocument() const;

    // Function:   setActiveDocument
    // Purpose:    Sets the handle of the document marked as active for editing.
    // Parameters: activeDocumentHandle - The new handle to set.
    // Returns:    None.
    void
    setActiveDocument(Common::Handle activeDocumentHandle);

    // Function:   getDocumentName
    // Purpose:    Gets the editing name of a document.
    // Parameters: documentHandle - The handle to the document.
    // Returns:    The name of this document.
    std::string
    getDocumentName(Common::Handle documentHandle);

    // Function:   setDocumentName
    // Purpose:    Sets the editing name of a document.
    // Parameters: documentHandle - The handle to the document.
    //             name - The name to set it to have.
    // Returns:    None.
    void
    setDocumentName(Common::Handle documentHandle, std::string name);

    // Function:   addViewToDocument
    // Purpose:    Adds a new set of view coordinates to a document. They will initialize to (0, 0)
    //             with a magnification of 1.0.
    // Parameters: documentHandle - The handle to the document.
    // Returns:    A handle to the new view.
    Common::Handle
    addViewToDocument(Common::Handle documentHandle);

    // Function:   destroyView
    // Purpose:    Removes a view from the data model.
    // Parameters: viewHandle - The handle to the view.
    // Returns:    None.
    void
    destroyView(Common::Handle viewHandle);

    // Function:   getViewAnchorX
    // Purpose:    Gets the X-coordinate of a view's anchor point.
    // Parameters: viewHandle - The handle of the view to get the anchor for.
    // Returns:    The desired coordinate.
    float
    getViewAnchorX(Common::Handle viewHandle) const;

    // Function:   getViewAnchorY
    // Purpose:    Gets the Y-coordinate of a view's anchor point.
    // Parameters: viewHandle - The handle of the view to get the anchor for.
    // Returns:    The desired coordinate.
    float
    getViewAnchorY(Common::Handle viewHandle) const;

    // Function:   getViewAnchorMag
    // Purpose:    Gets the magnification of a view's anchor point.
    // Parameters: viewHandle - The handle of the view to get the anchor for.
    // Returns:    The desired magnification.
    float
    getViewAnchorMag(Common::Handle viewHandle) const;

    // Function:   setViewAnchorX
    // Purpose:    Sets the X-coordinate of a view's anchor point.
    // Parameters: viewHandle - The handle of the view to set the anchor on.
    //             x - The X-coordinate to set to.
    // Returns:    None.
    void
    setViewAnchorX(Common::Handle viewHandle, float x);

    // Function:   setViewAnchorY
    // Purpose:    Sets the Y-coordinate of a view's anchor point.
    // Parameters: viewHandle - The handle of the view to set the anchor on.
    //             y - The Y-coordinate to set to.
    // Returns:    None.
    void
    setViewAnchorY(Common::Handle viewHandle, float y);

    // Function:   setViewAnchorMag
    // Purpose:    Sets the magnification of a view's anchor point.
    // Parameters: viewHandle - The handle of the view to set the anchor on.
    //             mag - The magnification to set to.
    // Returns:    None.
    void
    setViewAnchorMag(Common::Handle viewHandle, float mag);

    // Function:   setViewAnchorXY
    // Purpose:    Set both coordinates simultaneously - useful for when there are active listeners
    //             to avoid too much triggering.
    // Parameters: viewHandle - The handle of the view to set the anchor coordinates on.
    //             x, y - The coorinates to set.
    // Returns:    None.
    void
    setViewAnchorXY(Common::Handle viewHandle, float x, float y);

    // Function:   setViewAnchorAll
    // Purpose:    Sets the entire view anchor.
    // Parameters: viewHandle - The handle of the view to set the anchor coordinates on.
    //             x, y - The new position.
    //             mag - The new magnification.
    // Returns:    None.
    void
    setViewAnchorAll(Common::Handle viewHandle, float x, float y, float mag);
  private:
    Common::Handle m_activeDocumentHandle;
    Common::Handle m_nextViewKey;

    std::map<Common::Handle, std::string> m_documentNames;
    std::map<Common::Handle, ViewAnchor> m_documentViews; // note: NOT keyed to the document!
  };
}

#endif
