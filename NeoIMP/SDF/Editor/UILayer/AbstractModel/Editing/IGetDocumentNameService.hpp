#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_EDITING_IGETDOCUMENTNAMESERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_EDITING_IGETDOCUMENTNAMESERVICE_HPP

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

#include "../../../../Common/Handle.hpp"

#include <string>

namespace SDF::Editor::UILayer::AbstractModel::Editing {
  // Class:      IGetDocumentNameService
  // Purpose:    Defines a service interface to obtain the name of a document.
  // Parameters: None.
  class IGetDocumentNameService {
  public:
    virtual ~IGetDocumentNameService() = default;

    // Function:   getDocumentName
    // Purpose:    Gets the name of a document.
    // Parameters: handle - The document handle to get the name for.
    // Returns:    The name of the given document.
    virtual std::string
    getDocumentName(Common::Handle a_handle) = 0;
  };
}

#endif
