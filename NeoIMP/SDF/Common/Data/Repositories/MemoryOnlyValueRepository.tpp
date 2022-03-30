#ifndef SDF_COMMON_DATA_REPOSITORIES_MEMORYONLYVALUEREPOSITORY_TPP
#define SDF_COMMON_DATA_REPOSITORIES_MEMORYONLYVALUEREPOSITORY_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MemoryOnlyValueRepository.tpp
 * PURPOSE: Implements the MemoryOnlyValueRepository template.
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
  MemoryOnlyValueRepository<KeyT, ObjT>::MemoryOnlyValueRepository() {
  }

  template<class KeyT, class ObjT>
  bool
  MemoryOnlyValueRepository<KeyT, ObjT>::has(KeyT key) {
    return (m_objMap.find(key) != m_objMap.end());
  }

  template<class KeyT, class ObjT>
  void
  MemoryOnlyValueRepository<KeyT, ObjT>::create(KeyT key, const ObjT &obj) {
    if(m_objMap.find(key) != m_objMap.end()) {
      throw Error::ObjectAlreadyExistsException(key);
    } else {
      m_objMap[key] = obj;
    }
  }

  template<class KeyT, class ObjT>
  void
  MemoryOnlyValueRepository<KeyT, ObjT>::retrieve(KeyT key, ObjT &obj) {
    if(m_objMap.find(key) == m_objMap.end()) {
      throw Error::ObjectNotFoundException(key);
    } else {
      obj = m_objMap[key];
    }
  }

  template<class KeyT, class ObjT>
  void
  MemoryOnlyValueRepository<KeyT, ObjT>::update(KeyT key, const ObjT &obj) {
    if(m_objMap.find(key) == m_objMap.end()) {
      throw Error::ObjectNotFoundException(key);
    } else {
      m_objMap[key] = obj;
    }
  }

  template<class KeyT, class ObjT>
  void
  MemoryOnlyValueRepository<KeyT, ObjT>::deleteO(KeyT key) {
    m_objMap.erase(key);
  }
}

#endif
