#ifndef SD_UILAYER_ABSTRACTMODEL_ISAVEDOCUMENTSERVICE_HPP
#define SD_UILAYER_ABSTRACTMODEL_ISAVEDOCUMENTSERVICE_HPP

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

#include <UILayer/AbstractModel/Handle.hpp>
#include <UILayer/AbstractModel/Properties/FileFormat.hpp>

#include <string>

namespace SDF::UILayer::AbstractModel {
  // Class:      ISaveDocumentService
  // Purpose:    Defines an interface for a model layer service to save documents to disk.
  // Parameters: None.
  class ISaveDocumentService {
  public:
    virtual ~ISaveDocumentService() = default;

    virtual void
    saveDocument(std::string fileName,
                 AbstractModel::Properties::FileFormat fileFormat,
                 AbstractModel::Handle documentHandle
                ) = 0;
  };
}

#endif
