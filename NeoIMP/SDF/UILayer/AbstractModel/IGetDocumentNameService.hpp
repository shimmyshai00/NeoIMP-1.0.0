#ifndef SDF_UILAYER_ABSTRACTMODEL_IGETDOCUMENTNAMESERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_IGETDOCUMENTNAMESERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IGetDocumentNameService.hpp
 * PURPOSE: Defines the IGetDocumentNameService interface.
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

#include "../../Common/Handle.hpp"

#include <string>

namespace SDF::UILayer::AbstractModel {
  // Class:      IDocumentNameService
  // Purpose:    Defines the interface for an MVC service that gets the names of documents.
  // Parameters: None.
  class IGetDocumentNameService {
  public:
    virtual ~IGetDocumentNameService() = default;

    // Function:   getDocumentName
    // Purpose:    Get the name of an image document.
    // Parameters: documentHandle - The handle to the image document.
    // Returns:    The name as a string.
    virtual std::string
    getDocumentName(Common::Handle documentHandle) = 0;
  };
}


#endif
