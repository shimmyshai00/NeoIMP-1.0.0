#ifndef SDF_DATALAYER_DATAMAPPERS_GIL_PERSISTERS_IMAGEMAPPER_TPP
#define SDF_DATALAYER_DATAMAPPERS_GIL_PERSISTERS_IMAGEMAPPER_TPP

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

#include "../../Exceptions.hpp"
#include "Persisters/Apply.hpp"
#include "Persisters/Png.hpp"

namespace SDF::DataLayer::DataMappers::Gil {
  template<class PersisterT, class ImageEntityT>
  ImageMapper<PersisterT, ImageEntityT>::ImageMapper(Context::FileRegistry *fileRegistry)
    : m_fileRegistry(fileRegistry)
  {
  }

  template<class PersisterT, class ImageEntityT>
  void
  ImageMapper<PersisterT, ImageEntityT>::insert(Common::Handle uid, ImageEntityT *entity) {
    if(m_fileRegistry->hasFileUid(uid)) {
      throw EntityAlreadyInsertedException(uid);
    }

    m_fileRegistry->registerFileSpec(uid, entity->m_fileSpec);
    PersisterT persister(Persisters::DIR_SAVE);
    Persisters::apply(persister, *entity);
  }

  template<class PersisterT, class ImageEntityT>
  std::unique_ptr<ImageEntityT>
  ImageMapper<PersisterT, ImageEntityT>::retrieve(Common::Handle uid) {
    throw "NOT YET IMPLEMENTED";
  }

  template<class PersisterT, class ImageEntityT>
  void
  ImageMapper<PersisterT, ImageEntityT>::update(Common::Handle uid, ImageEntityT *entity) {
    if(!m_fileRegistry->hasFileUid(uid)) {
      throw EntityNotFoundException(uid);
    }

    m_fileRegistry->updateFileSpec(uid, entity->m_fileSpec);
    PersisterT persister(Persisters::DIR_SAVE);
    Persisters::apply(persister, *entity);
  }

  template<class PersisterT, class ImageEntityT>
  void
  ImageMapper<PersisterT, ImageEntityT>::erase(Common::Handle uid) {
    // Just forget about the file UID - no deletion!
    m_fileRegistry->forgetFileSpec(uid);
  }
}

#endif
