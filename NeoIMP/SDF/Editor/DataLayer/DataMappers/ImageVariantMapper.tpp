#ifndef SDF_EDITOR_DATALAYER_DATAMAPPERS_IMAGEVARIANTMAPPER_TPP
#define SDF_EDITOR_DATALAYER_DATAMAPPERS_IMAGEVARIANTMAPPER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageVariantMapper.tpp
 * PURPOSE: Implements the ImageVariantMapper template.
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
#include "ApplyPersister.hpp"
#include "EDirection.hpp"

namespace SDF::Editor::DataLayer::DataMappers {
  template<class PersisterT, class ImageVariantT>
  ImageVariantMapper<PersisterT, ImageVariantT>::ImageVariantMapper(
    Common::Data::Adapters::IFilesystemAdapter *filesystemAdapter
  )
    : m_filesystemAdapter(filesystemAdapter)
  {
  }

  template<class PersisterT, class ImageVariantT>
  bool
  ImageVariantMapper<PersisterT, ImageVariantT>::has(std::string fileSpec) {
    Common::Data::Adapters::FilesystemKey fsk(fileSpec, 0, 0);
    return m_filesystemAdapter->exist(fsk);
  }

  template<class PersisterT, class ImageVariantT>
  void
  ImageVariantMapper<PersisterT, ImageVariantT>::insert(std::string fileSpec, ImageVariantT &obj) {
    if(has(fileSpec)) {
      throw FileSpecInUseException();
    }

    // Boost.GIL does not require direct interaction with the file system by us
    PersisterT persister(fileSpec, DIR_SAVE);
    applyPersister(persister, obj);
  }

  template<class PersisterT, class ImageVariantT>
  void
  ImageVariantMapper<PersisterT, ImageVariantT>::retrieve(std::string fileSpec, ImageVariantT &obj)
  {
    throw "NOT YET IMPLEMENTED";
  }

  template<class PersisterT, class ImageVariantT>
  void
  ImageVariantMapper<PersisterT, ImageVariantT>::update(std::string fileSpec, ImageVariantT &obj) {
    if(!has(fileSpec)) {
      throw FileSpecNotFoundException();
    }

    // Boost.GIL does not require direct interaction with the file system by us
    PersisterT persister(fileSpec, DIR_SAVE);
    applyPersister(persister, obj);
  }

  template<class PersisterT, class ImageVariantT>
  void
  ImageVariantMapper<PersisterT, ImageVariantT>::erase(std::string fileSpec) {
    throw "NOT YET IMPLEMENTED";
  }
}

#endif
