#ifndef SDF_IMPL_MODELLAYER_IMPL_DOMAINOBJECTS_META_OBJECTMAP_HPP
#define SDF_IMPL_MODELLAYER_IMPL_DOMAINOBJECTS_META_OBJECTMAP_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ObjectMap.hpp
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

#include <SDF/Impl/ModelLayer/Handle.hpp>

#include <fruit/fruit.h>

#include <map>
#include <memory>

namespace SDF::Impl::ModelLayer::Impl::DomainObjects::Meta {
  template<class T>
  class ObjectMap {
  public:
    INJECT(ObjectMap());

    T *find(Handle handle);
    Handle add(std::unique_ptr<T> obj);
    void remove(Handle handle);
  private:
    Handle m_nextHandle;
    std::map<Handle, std::unique_ptr<T>> m_objMap;
  };
}

#include "SDF/Impl/ModelLayer/Impl/DomainObjects/Meta/ObjectMap.tpp"

#endif
