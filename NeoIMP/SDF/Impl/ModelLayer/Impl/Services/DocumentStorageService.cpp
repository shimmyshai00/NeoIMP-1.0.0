/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentStorageService.cpp
 * PURPOSE: The document storage service implementation.
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

#include <MemoryLayer/Exceptions/Exceptions.hpp>
#include <ModelLayer/Exceptions/Exceptions.hpp>

#include <AbstractMemory/Repositories/IImageRepository.hpp>
#include <AbstractMemory/Persistence/IImagePersistenceMap.hpp>
#include <AbstractMemory/Persistence/IImagePersister.hpp>

#include <DomainObjects/Image/AbstractImage.hpp>

namespace SDF::Impl::ModelLayer::Impl::Services {
  DocumentStorageService::DocumentStorageService(AbstractMemory::Repositories::IImageRepository *imageRepository,
                                                 AbstractMemory::Persistence::IImagePersistenceMap *imagePersistenceMap,
                                                 AbstractMemory::Persistence::IImagePersister *imagePersister
                                                )
    : m_imageRepository(imageRepository),
      m_imagePersistenceMap(imagePersistenceMap),
      m_imagePersister(imagePersister)
  {}

  void
  DocumentStorageService::saveDocument(std::string fileSpec,
                                       DataLayer::Properties::FileFormat fileFormat,
                                       AppModelLayer::AbstractModel::Handle handle
                                      )
  {
    try {
      m_imagePersistenceMap->assignFileSpec(handle, fileSpec);
      m_imagePersistenceMap->assignFileFormat(handle, fileFormat);

      m_imagePersister->persistImage(handle);
    } catch(MemoryLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::InvalidHandleException(handle);
    }
  }

  AppModelLayer::AbstractModel::Handle
  DocumentStorageService::loadDocument(std::string fileSpec,
                                       DataLayer::Properties::FileFormat fileFormat
                                      )
  {
    // TBA
    return -1;
  }
}
