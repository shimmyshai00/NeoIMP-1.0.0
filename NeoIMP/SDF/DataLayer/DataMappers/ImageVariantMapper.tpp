#ifndef SDF_DATALAYER_DATAMAPPERS_IMAGEVARIANTMAPPER_TPP
#define SDF_DATALAYER_DATAMAPPERS_IMAGEVARIANTMAPPER_TPP

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

#include "../../ModelLayer/AbstractData/Entity/ImageVariant.hpp"
#include "../Exceptions.hpp"
#include "ApplyPersister.hpp"
#include "EDirection.hpp"

namespace SDF::DataLayer::DataMappers {
  template<class PersisterT, class ImageVariantT>
  ImageVariantMapper<PersisterT, ImageVariantT>::ImageVariantMapper(Context::FileRegistry *
                                                                      fileRegistry
                                                                   )
    : m_fileRegistry(fileRegistry)
  {
  }

  template<class PersisterT, class ImageVariantT>
  void
  ImageVariantMapper<PersisterT, ImageVariantT>::insert(Common::Handle uid, ImageVariantT *entity) {
    using namespace ModelLayer::AbstractData;

    if(m_fileRegistry->hasFileUid(uid)) {
      throw EntityAlreadyInsertedException(uid);
    }

    m_fileRegistry->registerFileSpec(uid,
      Entity::visitEntity([](auto && e) { return e.m_fileSpec; }, *entity));
    PersisterT persister(DIR_SAVE);
    applyPersister(persister, *entity);
  }

  template<class PersisterT, class ImageVariantT>
  std::unique_ptr<ImageVariantT>
  ImageVariantMapper<PersisterT, ImageVariantT>::retrieve(Common::Handle uid) {
    throw "NOT YET IMPLEMENTED";
  }

  template<class PersisterT, class ImageVariantT>
  void
  ImageVariantMapper<PersisterT, ImageVariantT>::update(Common::Handle uid, ImageVariantT *entity) {
    using namespace ModelLayer::AbstractData;

    if(!m_fileRegistry->hasFileUid(uid)) {
      throw EntityNotFoundException(uid);
    }

    m_fileRegistry->updateFileSpec(uid,
      Entity::visitEntity([](auto && e) { return e.m_fileSpec; }, *entity));
    PersisterT persister(DIR_SAVE);
    applyPersister(persister, *entity);
  }

  template<class PersisterT, class ImageVariantT>
  void
  ImageVariantMapper<PersisterT, ImageVariantT>::erase(Common::Handle uid) {
    // Just forget about the file UID - no deletion!
    m_fileRegistry->forgetFileSpec(uid);
  }
}

#endif
