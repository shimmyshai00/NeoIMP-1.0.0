#ifndef SDF_MODELLAYER_REPOSITORIES_MEMORYONLYREPOSITORY_TPP
#define SDF_MODELLAYER_REPOSITORIES_MEMORYONLYREPOSITORY_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MemoryOnlyRepository.tpp
 * PURPOSE: Implements the MemoryOnlyRepository template.
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

#include "../Exceptions/Exceptions.hpp"

namespace SDF::ModelLayer::Repositories {
  template<class ObjT>
  MemoryOnlyRepository<ObjT>::MemoryOnlyRepository() {
  }

  template<class ObjT>
  ObjT *
  MemoryOnlyRepository<ObjT>::insert(Common::Handle uid, std::unique_ptr<ObjT> obj) {
    if(m_objMap.find(uid) == m_objMap.end()) {
      ObjT *outPtr(obj.get());
      m_objMap[uid] = std::move(obj);
      return outPtr;
    } else {
      return nullptr;
    }
  }

  template<class ObjT>
  ObjT *
  MemoryOnlyRepository<ObjT>::retrieve(Common::Handle uid) {
    if(m_objMap.find(uid) == m_objMap.end()) {
      return nullptr;
    } else {
      return m_objMap[uid].get();
    }
  }

  template<class ObjT>
  void
  MemoryOnlyRepository<ObjT>::update(Common::Handle uid, ObjT *obj) {
    // N/A
  }

  template<class ObjT>
  void
  MemoryOnlyRepository<ObjT>::erase(Common::Handle uid) {
    m_objMap.erase(uid);
  }
}

#endif
