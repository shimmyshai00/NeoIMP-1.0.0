#ifndef SDF_EDITOR_DATALAYER_DATAMAPPERS_IMAGEMAPPER_TPP
#define SDF_EDITOR_DATALAYER_DATAMAPPERS_IMAGEMAPPER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageMapper.tpp
 * PURPOSE: Implements the ImageMapper template.
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
  template<class PersisterT, class ImageT>
  ImageMapper<PersisterT, ImageT>::ImageMapper(
    Common::Data::Adapters::IFilesystemAdapter *filesystemAdapter
  )
    : m_filesystemAdapter(filesystemAdapter)
  {
  }

  template<class PersisterT, class ImageT>
  bool
  ImageMapper<PersisterT, ImageT>::has(std::string fileSpec) {
    Common::Data::Adapters::FilesystemKey fsk(fileSpec, 0, 0);
    return m_filesystemAdapter->exist(fsk);
  }

  template<class PersisterT, class ImageT>
  void
  ImageMapper<PersisterT, ImageT>::insert(std::string fileSpec, ImageT &obj) {
    if(has(fileSpec)) {
      throw FileSpecInUseException();
    }

    // Boost.GIL does not require direct interaction with the file system by us
    PersisterT persister(fileSpec, DIR_SAVE);
    applyPersister(persister, obj);
  }

  template<class PersisterT, class ImageT>
  void
  ImageMapper<PersisterT, ImageT>::retrieve(std::string fileSpec, ImageT &obj) {
    throw "NOT YET IMPLEMENTED";
  }

  template<class PersisterT, class ImageT>
  void
  ImageMapper<PersisterT, ImageT>::update(std::string fileSpec, ImageT &obj) {
    if(!has(fileSpec)) {
      throw FileSpecNotMappedException();
    }

    // Boost.GIL does not require direct interaction with the file system by us
    PersisterT persister(fileSpec, DIR_SAVE);
    applyPersister(persister, obj);
  }

  template<class PersisterT, class ImageT>
  void
  ImageMapper<PersisterT, ImageT>::erase(std::string fileSpec) {
    // NB: delete a file??? May be dangerous! what this should do, if anything, TBA
    throw "NOT YET IMPLEMENTED";
  }
}

#endif
