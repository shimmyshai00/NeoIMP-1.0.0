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
    Common::Data::ICrudable<std::string, ImageT> *a_pngImageMapper
  )
    : m_pngImageMapper(a_pngImageMapper)
  {
  }

  template<class ImageT>
  Common::Handle
  ImageRepository<ImageT>::retainImageAtAutoID(std::unique_ptr<ImageT> a_image) {
    Common::Handle candId(0);
    while(m_imageMap.find(candId) != m_imageMap.end()) {
      ++candId;
    }

    m_imageMap[candId] = std::move(a_image);

    // NB: could add autosave here?

    return candId;
  }

  template<class ImageT>
  ImageT *
  ImageRepository<ImageT>::retrieve(Common::Handle a_id) {
    if(m_imageMap.find(a_id) != m_imageMap.end()) {
      return m_imageMap[a_id].get();
    } else {
      throw Error::ObjectNotFoundException<Common::Handle>(a_id);
    }
  }

  template<class ImageT>
  Common::Handle
  ImageRepository<ImageT>::loadImageFromFile(
    std::string a_fileSpec,
    ModelLayer::AbstractData::Format a_fileFormat
  ) {
    // Construct a default image. NB: tailor to file info? How could we read that here? The
    // DataMapper lacks the requisite functionality and it is unknown how to best square this with
    // the idea that DMs should not have a lot of interface cruft but should be simple-interfaced.
    auto p = std::make_unique<ImageT>();

    // Find a free ID in the repository to use for this image. */
    Common::Handle id(getFirstFreeId());

    // Read the image into the holder and inject it into the repository under this ID.
    switch(a_fileFormat) {
      case ModelLayer::AbstractData::FORMAT_PNG:
        if(!m_pngImageMapper->has(a_fileSpec)) {
          // Oops! File not found!
          throw Error::FileNotFoundException(a_fileSpec.c_str());
        } else {
          m_pngImageMapper->retrieve(a_fileSpec, *p);
        }
        break;
      default:
        throw UnsupportedFormatException(a_fileFormat);
    }

    m_imageMap[id] = std::move(p);
    registerFileSpec(id, a_fileSpec, a_fileFormat);

    return id;
  }

  template<class ImageT>
  void
  ImageRepository<ImageT>::registerFileSpec(
    Common::Handle id,
    std::string a_fileSpec,
    ModelLayer::AbstractData::Format a_fileFormat
  ) {
    m_fileSpecMap[id] = a_fileSpec;
    m_fileFormatMap[id] = a_fileFormat;
  }

  template<class ImageT>
  void
  ImageRepository<ImageT>::persistImage(Common::Handle a_id) {
    if(m_imageMap.find(a_id) == m_imageMap.end()) {
      throw Error::ObjectNotFoundException<Common::Handle>(a_id);
    } else {
      if(m_fileSpecMap.find(a_id) == m_fileSpecMap.end()) {
        throw SaveParamsNotAssociatedException(a_id);
      } else {
        if(m_fileFormatMap.find(a_id) == m_fileFormatMap.end()) {
          // shouldn't happen but still ...
          throw SaveParamsNotAssociatedException(a_id);
        }

        switch(m_fileFormatMap[a_id]) {
          case ModelLayer::AbstractData::FORMAT_PNG:
            if(!m_pngImageMapper->has(m_fileSpecMap[a_id])) {
              m_pngImageMapper->create(m_fileSpecMap[a_id], *m_imageMap[a_id]);
            } else {
              m_pngImageMapper->update(m_fileSpecMap[a_id], *m_imageMap[a_id]);
            }
            break;
          default:
            // shouldn't happen
            throw UnsupportedFormatException(m_fileFormatMap[a_id]);
        }
      }
    }
  }

  template<class ImageT>
  bool
  ImageRepository<ImageT>::hasAssociatedFile(Common::Handle a_id) const {
    if(m_imageMap.find(a_id) == m_imageMap.end()) {
      throw Error::ObjectNotFoundException(a_id);
    } else {
      return (m_fileSpecMap.find(a_id) != m_fileSpecMap.end());
    }
  }

  template<class ImageT>
  std::string
  ImageRepository<ImageT>::getFileSpecById(Common::Handle a_id) const {
    if(m_fileSpecMap.find(a_id) == m_fileSpecMap.end()) {
      throw SaveParamsNotAssociatedException(a_id);
    } else {
      return m_fileSpecMap.at(a_id);
    }
  }

  template<class ImageT>
  ModelLayer::AbstractData::Format
  ImageRepository<ImageT>::getFileFormatById(Common::Handle a_id) const {
    if(m_fileFormatMap.find(a_id) == m_fileFormatMap.end()) {
      throw SaveParamsNotAssociatedException(a_id);
    } else {
      return m_fileFormatMap.at(a_id);
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
