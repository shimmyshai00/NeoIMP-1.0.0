#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_STORAGE_IGETDOCUMENTFILEINFOSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_STORAGE_IGETDOCUMENTFILEINFOSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IGetDocumentFileInfoService.hpp
 * PURPOSE: Defines the IGetDocumentFileInfoService interface.
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
#include "../Defs/FileFormat.hpp"

#include <string>

namespace SDF::Editor::UILayer::AbstractModel::Storage {
  // Class:      IGetDocumentFileInfoService
  // Purpose:    Defines a service interface for getting the file information of previously-saved
  //             (or loaded) documents.
  // Parameters: None.
  class IGetDocumentFileInfoService {
  public:
    virtual ~IGetDocumentFileInfoService() = default;

    // Function:   wasDocumentPreviouslySaved
    // Purpose:    Returns whether the document has previously been saved or loaded and so is
    //             associated with a file spec.
    // Parameters: imageHandle - The handle of the document to check.
    // Returns:    Whether it has file spec.
    virtual bool
    wasDocumentPreviouslySaved(Common::Handle a_imageHandle) = 0;

    // Function:   getFileSpec
    // Purpose:    Gets the standing file spec of a document.
    // Parameters: imageHandle - The handle of the document to get the file spec for.
    // Returns:    The file spec for this document.
    virtual std::string
    getFileSpec(Common::Handle a_imageHandle) = 0;

    // Function:   getFileFormat
    // Purpose:    Gets the standing file format of a document.
    // Parameters: imageHandle - The handle of the document to get the file spec for.
    // Returns:    The file format for this document.
    virtual Defs::FileFormat
    getFileFormat(Common::Handle a_imageHandle) = 0;
  };
}

#endif
