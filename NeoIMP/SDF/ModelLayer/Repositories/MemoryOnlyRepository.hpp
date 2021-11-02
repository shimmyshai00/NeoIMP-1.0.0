#ifndef SDF_MODELLAYER_REPOSITORIES_MEMORYONLYREPOSITORY_HPP
#define SDF_MODELLAYER_REPOSITORIES_MEMORYONLYREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MemoryOnlyRepository.hpp
 * PURPOSE: Defines the MemoryOnlyRepository template.
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

#include "../DomainObjects/IDomainObject.hpp"
#include "../DomainObjects/Uid.hpp"

#include "IRepository.hpp"

#include <fruit/fruit.h>
#include <memory>
#include <map>

namespace SDF::ModelLayer::Repositories {
  // Class:      MemoryOnlyRepository
  // Purpose:    Defines a repository of domain objects that exists only in memory, with no mapping to persistent
  //             storage.
  // Parameters: T - The domain object type, which should inherit from DomainObjects::IDomainObject.
  template<class T>
  class MemoryOnlyRepository : public IRepository<T> {
  public:
    INJECT(MemoryOnlyRepository());

    DomainObjects::IDomainObject<T> *
    create(std::unique_ptr<DomainObjects::IDomainObject<T>> object);

    DomainObjects::IDomainObject<T> *
    retrieve(DomainObjects::Uid uid);

    void
    update(DomainObjects::Uid uid);

    void
    del(DomainObjects::Uid uid);
  private:
    std::map<int, std::unique_ptr<DomainObjects::IDomainObject<T>>> m_objectMap;
  };
}

#include "MemoryOnlyRepository.tpp"

#endif
