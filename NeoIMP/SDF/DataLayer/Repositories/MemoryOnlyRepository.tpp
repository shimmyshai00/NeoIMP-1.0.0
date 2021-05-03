#ifndef SDF_DATALAYER_REPOSITORIES_MEMORYONLYREPOSITORY_TPP
#define SDF_DATALAYER_REPOSITORIES_MEMORYONLYREPOSITORY_TPP

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

#include <DataLayer/Exceptions/Exceptions.hpp>

namespace SDF::DataLayer::Repositories {
  template<class T>
  MemoryOnlyRepository<T>::MemoryOnlyRepository()
  {}

  template<class T>
  void
  MemoryOnlyRepository<T>::create(std::unique_ptr<T> object) {
    // Create a new entry in the repository.
    int objectId(object->getId());
    m_objectMap[objectId] = std::move(object);
  }

  template<class T>
  T *
  MemoryOnlyRepository<T>::retrieve(int objectId) {
    if(m_objectMap.find(objectId) == m_objectMap.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(objectId);
    } else {
      return m_objectMap[objectId].get();
    }
  }

  template<class T>
  void
  MemoryOnlyRepository<T>::update(T *object) {
    if(m_objectMap.find(object->getId()) == m_objectMap.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(object->getId());
    } else {
      // Nothing needs to be done here.
    }
  }

  template<class T>
  std::unique_ptr<T>
  MemoryOnlyRepository<T>::deleteEntry(int objectId) {
    if(m_objectMap.find(objectId) == m_objectMap.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(objectId);
    } else {
      std::unique_ptr<T> extractedObj(std::move(m_objectMap[objectId]));
      m_objectMap.erase(objectId);

      return std::move(extractedObj);
    }
  }
}

#endif
