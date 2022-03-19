#ifndef SDF_MODELLAYER_DOMAINOBJECTS_OBJECTMAP_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_OBJECTMAP_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ObjectMap.tpp
 * PURPOSE: Implements the ObjectMap template.
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

#include <SDF/DataLayer/Exceptions/Exceptions.hpp>

#include <SDF/ModelLayer/AbstractData/IRepository.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/IDomainObject.hpp>

namespace SDF::ModelLayer::DomainObjects {
  template<class T, class U>
  ObjectMap<T, U>::ObjectMap(AbstractData::IRepository<U> *valueRepository)
    : m_valueRepository(valueRepository)
  {
  }

  template<class T, class U>
  void
  ObjectMap<T, U>::linkTo(Services::AbstractDomain::IDomainObject<T> *key, std::unique_ptr<U> value) {
    if(m_idMap.find(key->getId()) == m_idMap.end()) {
      m_idMap[key->getId()] = value->getId();

      // Add to the repository of not already present.
      try {
        m_valueRepository->retrieve(value->getId());
      } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
        m_valueRepository->create(std::move(value));
      }
    } else {
      // TBA: throw exception?
    }
  }

  template<class T, class U>
  void
  ObjectMap<T, U>::breakLink(Services::AbstractDomain::IDomainObject<T> *key) {
    if(m_idMap.find(key->getId()) != m_idMap.end()) {
      m_idMap.erase(key->getId());
    }
  }

  template<class T, class U>
  U *
  ObjectMap<T, U>::get(Services::AbstractDomain::IDomainObject<T> *key) {
    if(m_idMap.find(key->getId()) != m_idMap.end()) {
      try {
        return m_valueRepository->retrieve(m_idMap[key->getId()]);
      } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
        // not in the repository? Oops, then the mapping is broken and we need to update it.
        m_idMap.erase(key->getId());
        return nullptr;
      }
    } else {
      return nullptr;
    }
  }
}

#endif
