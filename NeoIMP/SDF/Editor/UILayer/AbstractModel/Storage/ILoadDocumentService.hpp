#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_STORAGE_ILOADDOCUMENTSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_STORAGE_ILOADDOCUMENTSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ILoadDocumentService.hpp
 * PURPOSE: Defines the ILoadDocumentService interface.
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
#include "../Defs/EFileFormat.hpp"

#include <string>

namespace SDF::Editor::UILayer::AbstractModel::Storage {
  // Class:      ILoadDocumentService
  // Purpose:    Defines a service interface for loading documents.
  // Parameters: None.
  class ILoadDocumentService {
  public:
    virtual ~ILoadDocumentService() = default;

    // Function:   loadDocument
    // Purpose:    Loads a document from persistent storage.
    // Parameters: fileSpec - The file spec to load.
    //             fileFormat - The file format to use for the load.
    // Returns:    A handle to the loaded document, or Common::HANDLE_INVALID if the load failed.
    //             (or throws exception)
    virtual Common::Handle loadDocument(
      std::string fileSpec,
      Defs::EFileFormat fileFormat
    ) = 0;
  };
}

#endif
