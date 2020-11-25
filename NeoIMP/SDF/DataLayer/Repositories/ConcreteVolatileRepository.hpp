#ifndef SDF_DATALAYER_REPOSITORIES_CONCRETEVOLATILEREPOSITORY_HPP
#define SDF_DATALAYER_REPOSITORIES_CONCRETEVOLATILEREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ConcreteVolatileRepository.hpp
 * PURPOSE: The concrete volatile-storage repository template.
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

#include <SDF/ModelLayer/Repository/IVolatileRepository.hpp>
#include <SDF/ModelLayer/Handle.hpp>

#include <fruit/fruit.h>
#include <map>


namespace SDF::DataLayer::Repositories {
  template<class ObjectType>
  class ConcreteVolatileRepository : public ModelLayer::Repository::IVolatileRepository<ObjectType> {
  public:
    INJECT(ConcreteVolatileRepository());
    ~ConcreteVolatileRepository();

    ModelLayer::Handle storeObject(std::unique_ptr<ObjectType> object);
    ObjectType *accessObject(ModelLayer::Handle handle);
    void deleteObject(ModelLayer::Handle handle);
  private:
    static ModelLayer::Handle s_nextHandle;
    std::map<ModelLayer::Handle, std::unique_ptr<ObjectType>> m_objectMap;
  };
}

#include "SDF/DataLayer/Repositories/ConcreteVolatileRepository.tpp"

#endif
