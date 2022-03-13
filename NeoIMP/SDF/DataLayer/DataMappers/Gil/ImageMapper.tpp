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

#include "Persisters/Png.hpp"

namespace SDF::DataLayer::DataMappers::Gil {
  template<class GilBkgImageT, class GilImageT, class PersisterT>
  ImageMapper<GilBkgImageT, GilImageT, PersisterT>::ImageMapper(Context::FileRegistry *fileRegistry)
    : m_fileRegistry(fileRegistry)
  {
  }

  template<class GilBkgImageT, class GilImageT, class PersisterT>
  void
  ImageMapper<GilBkgImageT, GilImageT, PersisterT>::insert(Common::Handle uid, entity_t *entity) {
    if(m_fileRegistry->hasFileSpec(uid)) {
      throw EntityAlreadyInsertedException(uid);
    }

    m_fileRegistry.registerFileSpec(uid, entity->m_fileSpec);
    PersisterT persister(entity->m_fileSpec, Persisters::DIR_SAVE);
    persister(*entity);
  }

  template<class GilBkgImageT, class GilImageT, class PersisterT>
  std::unique_ptr<entity_t>
  ImageMapper<GilBkgImageT, GilImageT, PersisterT>::retrieve(Common::Handle uid) {
    throw "NOT YET IMPLEMENTED";
  }

  template<class GilBkgImageT, class GilImageT, class PersisterT>
  void
  ImageMapper<GilBkgImageT, GilImageT, PersisterT>::update(Common::Handle uid, entity_t *entity) {
    if(!m_fileRegistry->hasFileSpec(uid)) {
      throw EntityNotFoundException(uid);
    }

    m_fileRegistry->updateFileSpec(uid, entity->m_fileSpec);
    PersisterT persister(entity->m_fileSpec, Persisters::DIR_SAVE);
    persister(*entity);
  }

  template<class GilBkgImageT, class GilImageT, class PersisterT>
  void
  ImageMapper<GilBkgImageT, GilImageT, PersisterT>::erase(Common::Handle uid) {
    // Just forget about the file UID - no deletion!
    m_fileRegistry->forgetFileSpec(uid);
  }
}

#endif
