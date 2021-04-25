/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentStorageService.cpp
 * PURPOSE: Implements the DocumentStorageService class.
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

#include <DocumentStorageService.hpp>

#include <AbstractData/IFileSystemPersistenceController.hpp>
#include <AbstractDomain/IImage.hpp>

namespace SDF::ModelLayer::Services {
  DocumentStorageService::DocumentStorageService(
    AbstractData::IFileSystemPersistenceController<AbstractDomain::IImage, AbstractData::ImageFileFormat> *
      fileSystemPersistenceController
  )
    : m_fileSystemPersistenceController(fileSystemPersistenceController)
  {
  }

  void
  DocumentStorageService::saveDocument(std::string fileName,
                                       UILayer::AbstractModel::Properties::FileFormat fileFormat,
                                       UILayer::AbstractModel::Handle documentHandle
                                      )
  {
    m_fileSystemPersistenceController->assignFileSpec(documentHandle, fileName);
    m_fileSystemPersistenceController->setFileFormat(documentHandle, AbstractData::FILE_FORMAT_PNG); // TBA

    m_fileSystemPersistenceController->persist(documentHandle);
  }

  UILayer::AbstractModel::Handle
  DocumentStorageService::loadDocument(std::string fileName,
                                       UILayer::AbstractModel::Properties::FileFormat fileFormat
                                      )
  {
    return m_fileSystemPersistenceController->load(fileName, AbstractData::FILE_FORMAT_PNG); // TBA
  }
}
