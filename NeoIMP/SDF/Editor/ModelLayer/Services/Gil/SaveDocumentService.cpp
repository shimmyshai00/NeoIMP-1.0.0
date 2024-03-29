/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SaveDocumentService.cpp
 * PURPOSE: Implements the SaveDocumentService class.
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

#include "SaveDocumentService.hpp"

namespace SDF::Editor::ModelLayer::Services::Gil {
  SaveDocumentService::SaveDocumentService(
    AbstractData::IImagePersister<DomainObjects::Engine::Gil::Any_Image> *a_imageRepository
  )
    : m_imageRepository(a_imageRepository)
  {
  }

  void
  SaveDocumentService::saveDocument(
    Common::Handle a_imageHandle,
    std::string a_fileSpec,
    UILayer::AbstractModel::Defs::FileFormat a_fileFormat
  ) {
    using namespace UILayer;

    AbstractData::Format dataLayerFormat;
    switch(a_fileFormat) {
      case AbstractModel::Defs::FILE_FORMAT_PNG:
        dataLayerFormat = AbstractData::FORMAT_PNG;
        break;
      default:
        dataLayerFormat = AbstractData::FORMAT_PNG;
        break;
    }

    m_imageRepository->registerFileSpec(a_imageHandle, a_fileSpec, dataLayerFormat);
    m_imageRepository->persistImage(a_imageHandle);
  }
}
