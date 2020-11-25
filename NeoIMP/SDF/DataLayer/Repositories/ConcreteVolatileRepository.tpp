/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ConcreteVolatileRepository.tpp
 * PURPOSE: Implementation of the concrete volatile-storage repository template.
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
  template<class ObjectType>
  ModelLayer::Handle ConcreteVolatileRepository<ObjectType>::s_nextHandle = 0;

  template<class ObjectType>
  ConcreteVolatileRepository<ObjectType>::ConcreteVolatileRepository() {}

  template<class ObjectType>
  ConcreteVolatileRepository<ObjectType>::~ConcreteVolatileRepository() {}

  template<class ObjectType>
  ModelLayer::Handle ConcreteVolatileRepository<ObjectType>::storeObject(std::unique_ptr<ObjectType> object) {
    m_objectMap[s_nextHandle] = std::move(object);
    return s_nextHandle++;
  }

  template<class ObjectType>
  ObjectType *ConcreteVolatileRepository<ObjectType>::accessObject(ModelLayer::Handle handle) {
    if(m_objectMap.find(handle) == m_objectMap.end()) {
      throw Exceptions::ResourceNotFoundException(handle);
    }

    return m_objectMap[handle].get();
  }

  template<class ObjectType>
  void ConcreteVolatileRepository<ObjectType>::deleteObject(ModelLayer::Handle handle) {
    m_objectMap.erase(handle);
  }
}
