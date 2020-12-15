/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ObjectMap.tpp
 * PURPOSE: A generic container for storing a group of domain objects in memory that can be retrieved by handle.
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

namespace SDF::Impl::ModelLayer::Impl::DomainObjects::Meta {
  template<class T>
  ObjectMap<T>::ObjectMap() : m_nextHandle(0) {}

  template<class T>
  T *ObjectMap<T>::find(Handle handle) {
    if(m_objMap.find(handle) == m_objMap.end()) {
      return nullptr;
    } else {
      return m_objMap[handle].get();
    }
  }

  template<class T>
  Handle ObjectMap<T>::add(std::unique_ptr<T> obj) {
    Handle handle(m_nextHandle++);
    m_objMap[handle] = std::move(obj);

    return handle;
  }

  template<class T>
  void ObjectMap<T>::remove(Handle handle) {
    m_objMap.erase(handle);
  }
}
