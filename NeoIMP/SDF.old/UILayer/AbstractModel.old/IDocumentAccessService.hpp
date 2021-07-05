#ifndef SDF_UILAYER_ABSTRACTMODEL_IDOCUMENTACCESSSERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_IDOCUMENTACCESSSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IDocumentAccessService.hpp
 * PURPOSE: Defines the IDocumentAccessService interface.
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

#include <SDF/Interfaces/IObservable.hpp>

#include <SDF/UILayer/AbstractModel/Events/DocumentEvent.hpp>

#include <SDF/UILayer/AbstractModel/Handle.hpp>

#include <SDF/UILayer/AbstractModel/Properties/ColorModel.hpp>
#include <SDF/UILayer/AbstractModel/Properties/BitDepth.hpp>

#include <vector>
#include <string>

namespace SDF::UILayer::AbstractModel {
  // Class:      IDocumentAccessService
  // Purpose:    Defines an interface for the document-access service.
  // Parameters: None.
  class IDocumentAccessService : public Interfaces::IObservable<Events::DocumentEvent> {
  public:
    virtual ~IDocumentAccessService() = default;

    virtual std::vector<UILayer::AbstractModel::Handle>
    getActiveDocuments() = 0;

    // Function:   getDocumentName
    // Purpose:    Get the name of this document.
    // Parameters: handle - The handle to the document to make the request of.
    // Returns:    The name of the document with the given handle.
    virtual std::string
    getDocumentName(UILayer::AbstractModel::Handle handle) const = 0;

    // Function:   getDocumentWidthPx
    // Purpose:    Get the width of this document in pixels.
    // Parameters: handle - The handle to the document to make the request of.
    // Returns:    The width of the document with the given handle.
    virtual int
    getDocumentWidthPx(UILayer::AbstractModel::Handle handle) const = 0;

    // Function:   getDocumentWidthPx
    // Purpose:    Get the height of this document in pixels.
    // Parameters: handle - The handle to the document to make the request of.
    // Returns:    The height of the document with the given handle.
    virtual int
    getDocumentHeightPx(UILayer::AbstractModel::Handle handle) const = 0;

    // Function:   getDocumentResolutionPpi
    // Purpose:    Get the PPI (pixels-per-inch) resolution of this document in pixels.
    // Parameters: handle - The handle to the document to make the request of.
    // Returns:    The resolution of the document with the given handle.
    virtual float
    getDocumentResolutionPpi(UILayer::AbstractModel::Handle handle) const = 0;

    // Function:   getDocumentColorModel
    // Purpose:    Get the color model used by a document.
    // Parameters: handle - The handle to the document to make the request of.
    // Returns:    The color model of the document with the given handle.
    virtual Properties::ColorModel
    getDocumentColorModel(UILayer::AbstractModel::Handle handle) const = 0;

    // Function:   getDocumentBitDepth
    // Purpose:    Get the bit depth used by a document.
    // Parameters: handle - The handle to the document to make the request of.
    // Returns:    The bit depth of the document with the given handle.
    virtual Properties::BitDepth
    getDocumentBitDepth(UILayer::AbstractModel::Handle handle) const = 0;

    // Function:   getDocumentNumLayers
    // Purpose:    Get the number of layers in a this document.
    // Parameters: handle - The handle to the document to make the request of.
    // Returns:    The number of layers in the document with the given handle.
    virtual std::size_t
    getDocumentNumLayers(UILayer::AbstractModel::Handle handle) const = 0;
  };
}

#endif
