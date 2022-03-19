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

//#include "../Exceptions/Exceptions.hpp"

namespace SDF::ModelLayer::Repositories {
  template<class T>
  MemoryOnlyRepository<T>::MemoryOnlyRepository() {
  }

  template<class T>
  DomainObjects::IDomainObject<T> *
  MemoryOnlyRepository<T>::create(std::unique_ptr<DomainObjects::IDomainObject<T>> object) {
    DomainObjects::IDomainObject<T> *rv(object.get());
    DomainObjects::Uid uid(object->getUid());

    m_objectMap[uid] = std::move(object);

    return rv;
  }

  template<class T>
  DomainObjects::IDomainObject<T> *
  MemoryOnlyRepository<T>::retrieve(DomainObjects::Uid uid) {
    if(m_objectMap.find(uid) == m_objectMap.end()) {
      return nullptr;
    } else {
      return m_objectMap[uid].get();
    }
  }

  template<class T>
  void
  MemoryOnlyRepository<T>::update(DomainObjects::Uid yid) {
    // N/A
  }

  template<class T>
  void
  MemoryOnlyRepository<T>::del(DomainObjects::Uid uid) {
    if(m_objectMap.find(uid) != m_objectMap.end()) {
      m_objectMap.erase(uid);
    }
  }
}

#endif
