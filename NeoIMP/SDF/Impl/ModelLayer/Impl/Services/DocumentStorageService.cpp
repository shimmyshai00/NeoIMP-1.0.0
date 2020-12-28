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

#include <ModelLayer/Exceptions/Exceptions.hpp>

#include <AbstractData/IImageRepository.hpp>
#include <AbstractData/IImageFileMap.hpp>
#include <DomainObjects/Image/AbstractImage.hpp>

#include <Framework/Handle.hpp>
#include <UILayer/AbstractModel/Properties/FileFormat.hpp>

namespace SDF::Impl::ModelLayer::Impl::Services {
  DocumentStorageService::DocumentStorageService(
    AbstractData::IImageRepository *imageRepository,
    AbstractData::IImageFileMap *imageFileMap
  )
    : m_imageRepository(imageRepository),
      m_imageFileMap(imageFileMap)
  {}

  void DocumentStorageService::saveDocument(
    std::string fileSpec, UILayer::AbstractModel::Properties::FileFormat fileFormat,
    Framework::Handle handle
  ) {
    // TBA
  }

  Framework::Handle DocumentStorageService::loadDocument(
    std::string fileSpec, UILayer::AbstractModel::Properties::FileFormat fileFormat
  ) {
    // TBA
    return -1;
  }
}
