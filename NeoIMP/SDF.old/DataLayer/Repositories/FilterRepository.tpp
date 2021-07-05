#ifndef SDF_DATALAYER_REPOSIOTIRES_FILTERREPOSITORY_TPP
#define SDF_DATALAYER_REPOSIOTIRES_FILTERREPOSITORY_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FilterRepository.tpp
 * PURPOSE: Implements the FilterRepository template.
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

namespace SDF::DataLayer::Repositories {
  template<class SuperT, class T>
  FilterRepository<SuperT, T>::FilterRepository(ModelLayer::AbstractData::IRepository<SuperT> *superRepository)
    : m_superRepository(superRepository)
  {
    // Get the objects of the given subtype from the passed repository.
    std::vector<int> ids(m_superRepository->getIds());

    for(int id : ids) {
      if(auto p = dynamic_cast<T *>(m_superRepository->retrieve(id))) {
        m_filter[id] = p;
      }
    }
  }

  template<class SuperT, class T>
  std::vector<int>
  FilterRepository<SuperT, T>::getIds() const {
    std::vector<int> rv;

    for(auto obj : m_filter) {
      rv.push_back(obj.first);
    }

    return rv;
  }

  template<class SuperT, class T>
  void
  FilterRepository<SuperT, T>::create(std::unique_ptr<T> object) {
    T *objPtr = object.get();

    m_superRepository->create(std::move(object));
    m_filter[objPtr->getId()] = objPtr;
  }

  template<class SuperT, class T>
  T *
  FilterRepository<SuperT, T>::retrieve(int objectId) {
    if(m_filter.find(objectId) == m_filter.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(objectId);
    } else {
      return m_filter[objectId];
    }
  }

  template<class SuperT, class T>
  void
  FilterRepository<SuperT, T>::update(T *object) {
    if(m_filter.find(object->getId()) == m_filter.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(object->getId());
    } else {
      m_superRepository->update(object);
    }
  }

  template<class SuperT, class T>
  std::unique_ptr<T>
  FilterRepository<SuperT, T>::deleteEntry(int objectId) {
    if(m_filter.find(objectId) == m_filter.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(objectId);
    } else {
      std::unique_ptr<SuperT> rvPre(m_superRepository->deleteEntry(objectId));
      m_filter.erase(objectId);

      std::unique_ptr<T> rv(static_cast<T *>(rvPre.release()));
      return std::move(rv);
    }
  }
}

#endif
