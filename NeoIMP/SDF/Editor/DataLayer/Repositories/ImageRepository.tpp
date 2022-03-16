#ifndef SDF_EDITOR_DATALAYER_REPOSITORIES_IMAGEREPOSITORY_TPP
#define SDF_EDITOR_DATALAYER_REPOSITORIES_IMAGEREPOSITORY_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageRepository.hpp
 * PURPOSE: Defines the ImageRepository template.
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

#include "../Exceptions.hpp"

namespace SDF::Editor::DataLayer::Repositories {
  template<class ImageT>
  ImageRepository<ImageT>::ImageRepository(
    Common::Data::IDataMapper<std::string, ImageT> *pngImageMapper
  )
    : m_pngImageMapper(pngImageMapper)
  {
  }

  template<class ImageT>
  ImageT *
  ImageRepository<ImageT>::getImage(Common::Handle id) {
    if(m_imageMap.find(id) != m_imageMap.end()) {
      return m_imageMap[id].get();
    } else {
      throw ImageNotFoundException(id);
    }
  }

  template<class ImageT>
  void
  ImageRepository<ImageT>::insertImage(Common::Handle id, std::unique_ptr<ImageT> image) {
    printf("inserting with id %u\n", id);
    if(m_imageMap.find(id) != m_imageMap.end()) {
      throw ImageAlreadyInsertedException(id);
    } else {
      m_imageMap[id] = std::move(image);
    }

    // NB: could add autosave here?
  }

  template<class ImageT>
  void
  ImageRepository<ImageT>::persistImage(Common::Handle id) {
    if(m_imageMap.find(id) == m_imageMap.end()) {
      throw ImageNotFoundException(id);
    } else {
      if(m_fileSpecMap.find(id) == m_fileSpecMap.end()) {
        throw FileSpecNotFoundException();
      } else {
        switch(m_fileFormatMap[id]) {
          case ModelLayer::AbstractData::FORMAT_PNG:
            if(!m_pngImageMapper->has(m_fileSpecMap[id])) {
              m_pngImageMapper->insert(m_fileSpecMap[id], *m_imageMap[id]);
            } else {
              m_pngImageMapper->update(m_fileSpecMap[id], *m_imageMap[id]);
            }
            break;
          default:
            throw UnsupportedFormatException();
        }
      }
    }
  }

  template<class ImageT>
  Common::Handle
  ImageRepository<ImageT>::loadImageFromFile(
    std::string fileSpec,
    ModelLayer::AbstractData::EFormat fileFormat
  ) {
    // TBA
    throw "NOT YET IMPLEMENTED";
  }

  template<class ImageT>
  void
  ImageRepository<ImageT>::registerFileSpec(
    Common::Handle id,
    std::string fileSpec,
    ModelLayer::AbstractData::EFormat fileFormat
  ) {
    m_fileSpecMap[id] = fileSpec;
    m_fileFormatMap[id] = fileFormat;
  }
}

#endif
