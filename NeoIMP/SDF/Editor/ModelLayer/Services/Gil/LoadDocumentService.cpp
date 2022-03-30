/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    LoadDocumentService.cpp
 * PURPOSE: Implements the LoadDocumentService class.
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

#include "LoadDocumentService.hpp"

#include "../fileFormatMap.hpp"
#include "../Exceptions.hpp"

#include <filesystem>

namespace SDF::Editor::ModelLayer::Services::Gil {
  LoadDocumentService::LoadDocumentService(
    AbstractData::IImageLoader<DomainObjects::Engine::Gil::Any_Image> *imageLoader,
    AbstractData::IImageRetriever<DomainObjects::Engine::Gil::Any_Image> *imageRetriever
  )
    : m_imageLoader(imageLoader),
      m_imageRetriever(imageRetriever)
  {
  }

  Common::Handle
  LoadDocumentService::loadDocument(
    std::string fileSpec,
    UILayer::AbstractModel::Defs::EFileFormat fileFormat
  ) {
    if(fileFormat >= UILayer::AbstractModel::Defs::FILE_FORMAT_MAX) {
      throw BadFileFormatException(fileFormat);
    }

    AbstractData::EFormat dataLayerFormat = g_fileFormatMapULtoDL[fileFormat];

    Common::Handle rv(m_imageLoader->loadImageFromFile(fileSpec, dataLayerFormat));

    // Name the image after its filename. NB: should this go in this layer?
    std::string name(std::filesystem::path(fileSpec).filename());
    m_imageRetriever->retrieve(rv)->setName(name);

    return rv;
  }
}
