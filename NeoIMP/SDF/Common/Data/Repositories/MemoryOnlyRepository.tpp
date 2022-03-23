#ifndef SDF_COMMON_DATA_REPOSITORIES_MEMORYONLYREPOSITORY_TPP
#define SDF_COMMON_DATA_REPOSITORIES_MEMORYONLYREPOSITORY_TPP

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

#include "../../../Error/DataException.hpp"

namespace SDF::Common::Data::Repositories {
  template<class KeyT, class ObjT>
  MemoryOnlyRepository<KeyT, ObjT>::MemoryOnlyRepository() {
  }

  template<class KeyT, class ObjT>
  bool
  MemoryOnlyRepository<KeyT, ObjT>::has(KeyT key) {
    return (m_objMap.find(key) != m_objMap.end());
  }

  template<class KeyT, class ObjT>
  void
  MemoryOnlyRepository<KeyT, ObjT>::insert(KeyT key, std::unique_ptr<ObjT> obj) {
    if(m_objMap.find(key) != m_objMap.end()) {
      throw Error::ObjectAlreadyExistsException(key);
    } else {
      m_objMap[key] = std::move(obj);
    }
  }

  template<class KeyT, class ObjT>
  ObjT *
  MemoryOnlyRepository<KeyT, ObjT>::retrieve(KeyT key) {
    if(m_objMap.find(key) == m_objMap.end()) {
      throw Error::ObjectNotFoundException(key);
    } else {
      return m_objMap[key].get();
    }
  }

  template<class KeyT, class ObjT>
  void
  MemoryOnlyRepository<KeyT, ObjT>::update(KeyT key, ObjT& obj) {
    // N/A
  }

  template<class KeyT, class ObjT>
  void
  MemoryOnlyRepository<KeyT, ObjT>::erase(KeyT key) {
    m_objMap.erase(key);
  }
}

#endif
