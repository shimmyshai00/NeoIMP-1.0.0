#ifndef SDF_UILAYER_ABSTRACTMODEL_IDOCUMENTDIMENSIONSSERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_IDOCUMENTDIMENSIONSSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IDocumentDimensionsService.hpp
 * PURPOSE: Defines the IDocumentDimensionsService interface.
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
  // Class:      IDocumentDimensionsService
  // Purpose:    Defines an interface for a model layer service to get document dimensions.
  // Parameters: None.
  class IDocumentDimensionsService {
  public:
    virtual ~IDocumentDimensionsService() = default;

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
  };
}

#endif
