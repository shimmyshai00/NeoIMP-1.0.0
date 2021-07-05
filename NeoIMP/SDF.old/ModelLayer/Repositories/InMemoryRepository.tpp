#ifndef SDF_MODELLAYER_REPOSITORIES_INMEMORYREPOSITORY_TPP
#define SDF_MODELLAYER_REPOSITORIES_INMEMORYREPOSITORY_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    InMemoryRepository.tpp
 * PURPOSE: Implements the InMemoryRepository template.
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

namespace SDF::ModelLayer::Repositories {
  template<class T>
  InMemoryRepository<T>::InMemoryRepository() {
  }

  template<class T>
  T *
  InMemoryRepository<T>::insert(std::unique_ptr<T> obj) {
    T *rv(obj.get());
    m_repositoryMap[obj->getId()] = std::move(obj);

    return rv;
  }

  template<class T>
  T *
  InMemoryRepository<T>::access(int id) {
    if(m_repositoryMap.find(id) == m_repositoryMap.end()) {
      // TBA
    } else {
      return m_repositoryMap[id];
    }
  }

  template<class T>
  void
  InMemoryRepository<T>::update(T *obj) {
    // N/A
  }

  template<class T>
  std::unique_ptr<T>
  InMemoryRepository<T>::delete(int id) {
    if(m_repositoryMap.find(id) == m_repositoryMap.end()) {
      // TBA
    } else {
      m_repositoryMap.erase(id);
    }
  }
}

#endif
