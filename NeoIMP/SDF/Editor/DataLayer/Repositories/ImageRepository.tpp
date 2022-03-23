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

#include "../../../Error/DataException.hpp"
#include "Exceptions.hpp"

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
      throw Error::ObjectNotFoundException<Common::Handle>(id);
    }
  }

  template<class ImageT>
  Common::Handle
  ImageRepository<ImageT>::insertImageAtNextAvailable(std::unique_ptr<ImageT> image) {
    Common::Handle id(getFirstFreeId());
    m_imageMap[id] = std::move(image);

    return id;
  }

  template<class ImageT>
  void
  ImageRepository<ImageT>::insertImage(Common::Handle id, std::unique_ptr<ImageT> image) {
    if(m_imageMap.find(id) != m_imageMap.end()) {
      throw Error::ObjectNotFoundException<Common::Handle>(id);
    } else {
      m_imageMap[id] = std::move(image);
    }

    // NB: could add autosave here?
  }

  template<class ImageT>
  void
  ImageRepository<ImageT>::persistImage(Common::Handle id) {
    if(m_imageMap.find(id) == m_imageMap.end()) {
      throw Error::ObjectNotFoundException<Common::Handle>(id);
    } else {
      if(m_fileSpecMap.find(id) == m_fileSpecMap.end()) {
        throw SaveParamsNotAssociatedException(id);
      } else {
        if(m_fileFormatMap.find(id) == m_fileFormatMap.end()) {
          // shouldn't happen but still ...
          throw SaveParamsNotAssociatedException(id);
        }

        switch(m_fileFormatMap[id]) {
          case ModelLayer::AbstractData::FORMAT_PNG:
            if(!m_pngImageMapper->has(m_fileSpecMap[id])) {
              m_pngImageMapper->insert(m_fileSpecMap[id], *m_imageMap[id]);
            } else {
              m_pngImageMapper->update(m_fileSpecMap[id], *m_imageMap[id]);
            }
            break;
          default:
            // shouldn't happen
            throw UnsupportedFormatException(m_fileFormatMap[id]);
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
    // Construct a default image. NB: tailor to file info? How could we read that here? The
    // DataMapper lacks the requisite functionality and it is unknown how to best square this with
    // the idea that DMs should not have a lot of interface cruft but should be simple-interfaced.
    auto p = std::make_unique<ImageT>();

    // Find a free ID in the repository to use for this image. */
    Common::Handle id(getFirstFreeId());

    // Read the image into the holder and inject it into the repository under this ID.
    switch(fileFormat) {
      case ModelLayer::AbstractData::FORMAT_PNG:
        if(!m_pngImageMapper->has(fileSpec)) {
          // Oops! File not found!
          throw Error::FileNotFoundException(fileSpec.c_str());
        } else {
          m_pngImageMapper->retrieve(fileSpec, *p);
        }
        break;
      default:
        throw UnsupportedFormatException(fileFormat);
    }

    m_imageMap[id] = std::move(p);
    registerFileSpec(id, fileSpec, fileFormat);

    return id;
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

  template<class ImageT>
  bool
  ImageRepository<ImageT>::hasAssociatedFile(Common::Handle id) const {
    if(m_imageMap.find(id) == m_imageMap.end()) {
      throw Error::ObjectNotFoundException(id);
    } else {
      return (m_fileSpecMap.find(id) != m_fileSpecMap.end());
    }
  }

  template<class ImageT>
  std::string
  ImageRepository<ImageT>::getFileSpecById(Common::Handle id) const {
    if(m_fileSpecMap.find(id) == m_fileSpecMap.end()) {
      throw SaveParamsNotAssociatedException(id);
    } else {
      return m_fileSpecMap.at(id);
    }
  }

  template<class ImageT>
  ModelLayer::AbstractData::EFormat
  ImageRepository<ImageT>::getFileFormatById(Common::Handle id) const {
    if(m_fileFormatMap.find(id) == m_fileFormatMap.end()) {
      throw SaveParamsNotAssociatedException(id);
    } else {
      return m_fileFormatMap.at(id);
    }
  }
}

namespace SDF::Editor::DataLayer::Repositories {
  // Private helper member.
  template<class ImageT>
  Common::Handle
  ImageRepository<ImageT>::getFirstFreeId() const {
    Common::Handle id(0);
    for(const auto &kvp : m_imageMap) {
      id = kvp.first+1; // see if there's a free ID after this one, i.e. a gap
      if(m_imageMap.find(id) == m_imageMap.end()) {
        break;
      }
    }

    return id;
  }
}

#endif
