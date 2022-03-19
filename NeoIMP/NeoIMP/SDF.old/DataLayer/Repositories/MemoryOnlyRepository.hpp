#ifndef SDF_DATALAYER_REPOSITORIES_MEMORYONLYREPOSITORY_HPP
#define SDF_DATALAYER_REPOSITORIES_MEMORYONLYREPOSITORY_HPP

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

#include <SDF/ModelLayer/AbstractData/IRepository.hpp>

#include <memory>
#include <map>
#include <vector>

namespace SDF::DataLayer::Repositories {
  // Class:      MemoryOnlyRepository
  // Purpose:    Provides a repository of domain objects that exists solely in RAM, with no persistent backing store.
  // Parameters: T - The type of domain object held.
  template<class T>
  class MemoryOnlyRepository : public ModelLayer::AbstractData::IRepository<T> {
  public:
    // Function:   MemoryOnlyRepository
    // Purpose:    Construct a new memory-only repository.
    // Parameters: None.
    INJECT(MemoryOnlyRepository());

    std::vector<int>
    getIds() const;

    void
    create(std::unique_ptr<T> object);

    T *
    retrieve(int objectId);

    void
    update(T *object);

    std::unique_ptr<T>
    deleteEntry(int objectId);
  private:
    std::map<int, std::unique_ptr<T>> m_objectMap;
  };
}

#include "SDF/DataLayer/Repositories/MemoryOnlyRepository.tpp"

#endif
