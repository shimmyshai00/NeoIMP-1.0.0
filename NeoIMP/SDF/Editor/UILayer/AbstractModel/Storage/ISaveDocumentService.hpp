#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_STORAGE_ISAVEDOCUMENTSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_STORAGE_ISAVEDOCUMENTSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ISaveDocumentService.hpp
 * PURPOSE: Defines the ISaveDocumentService interface.
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
  // Class:      ISaveDocumentService
  // Purpose:    Defines a service interface for saving documents.
  // Parameters: None.
  class ISaveDocumentService {
  public:
    virtual ~ISaveDocumentService() = default;

    // Function:   saveDocument
    // Purpose:    Saves a document to persistent storage.
    // Parameters: imageHandle - The handle of the document to save.
    //             fileSpec - The file spec to save it under.
    //             fileFormat - The file format to use for the save.
    // Returns:    None.
    virtual void saveDocument(
      Common::Handle a_imageHandle,
      std::string a_fileSpec,
      Defs::FileFormat a_fileFormat
    ) = 0;
  };
}

#endif
