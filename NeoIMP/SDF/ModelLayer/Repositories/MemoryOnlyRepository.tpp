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
  template<class ObjectT>
  MemoryOnlyRepository<ObjectT>::MemoryOnlyRepository() {
  }

  template<class ObjectT>
  void
  MemoryOnlyRepository<ObjectT>::create(std::unique_ptr<ObjectT> object) {
    int id(object->getId());

    m_objectMap[id] = std::move(object);
  }

  template<class ObjectT>
  ObjectT *
  MemoryOnlyRepository<ObjectT>::retrieve(int id) {
    if(m_objectMap.find(id) == m_objectMap.end()) {
      throw ModelLayer::Exceptions::ObjectNotFoundException(id);
    } else {
      return m_objectMap[id].get();
    }
  }

  template<class ObjectT>
  void
  MemoryOnlyRepository<ObjectT>::update(int id) {
    // N/A
  }

  template<class ObjectT>
  void
  MemoryOnlyRepository<ObjectT>::del(int id) {
    if(m_objectMap.find(id) == m_objectMap.end()) {
      throw ModelLayer::Exceptions::ObjectNotFoundException(id);
    } else {
      m_objectMap.erase(id);
    }
  }
}

#endif
