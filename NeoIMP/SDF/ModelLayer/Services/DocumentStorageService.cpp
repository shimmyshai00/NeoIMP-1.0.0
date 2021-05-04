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

#include <AbstractData/IRepository.hpp>
#include <AbstractData/IFileSystemPersistenceController.hpp>

#include <AbstractDomain/IImage.hpp>
#include <AbstractDomain/IObjectMap.hpp>
#include <AbstractDomain/IDeltaEditor.hpp>

namespace SDF::ModelLayer::Services {
  DocumentStorageService::DocumentStorageService(
    AbstractData::IRepository<AbstractDomain::IImage> *imageRepository,
    AbstractData::IFileSystemPersistenceController<AbstractDomain::IImage, AbstractData::ImageFileFormat> *
      fileSystemPersistenceController,
    AbstractDomain::IObjectMap<AbstractDomain::IImage, AbstractDomain::IDeltaEditor> *deltaEditorMap,
    Interfaces::IFactory<AbstractDomain::IDeltaEditor, AbstractDomain::IImage *> *deltaEditorFactory
  )
    : m_imageRepository(imageRepository),
      m_fileSystemPersistenceController(fileSystemPersistenceController),
      m_deltaEditorMap(deltaEditorMap),
      m_deltaEditorFactory(deltaEditorFactory)
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
    UILayer::AbstractModel::Handle
      handle(m_fileSystemPersistenceController->load(fileName, AbstractData::FILE_FORMAT_PNG));

    // Create an editor for this image.
    AbstractDomain::IImage *imagePtr(m_imageRepository->retrieve(handle));
    std::unique_ptr<AbstractDomain::IDeltaEditor> deltaEditor(m_deltaEditorFactory->create(imagePtr));

    m_deltaEditorMap->linkTo(imagePtr, std::move(deltaEditor));

    return handle;
  }
}
