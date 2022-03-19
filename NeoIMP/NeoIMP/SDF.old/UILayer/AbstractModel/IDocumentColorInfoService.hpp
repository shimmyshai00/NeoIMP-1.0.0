#ifndef SDF_UILAYER_ABSTRACTMODEL_IDOCUMENTCOLORINFOSERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_IDOCUMENTCOLORINFOSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IDocumentColorInfoService.hpp
 * PURPOSE: Defines the IDocumentColorInfoService interface.
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

#include <SDF/UILayer/AbstractModel/Properties/ColorModel.hpp>
#include <SDF/UILayer/AbstractModel/Properties/BitDepth.hpp>

namespace SDF::UILayer::AbstractModel {
  // Class:      IDocumentColorInfoService
  // Purpose:    Defines an interface for a model layer service to get color model information about a document.
  // Parameters: None.
  class IDocumentColorInfoService {
  public:
    virtual ~IDocumentColorInfoService() = default;

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
  };
}

#endif
