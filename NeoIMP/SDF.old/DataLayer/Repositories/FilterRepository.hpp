#ifndef SDF_DATALAYER_REPOSITORIES_FILTERREPOSITORY_HPP
#define SDF_DATALAYER_REPOSITORIES_FILTERREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FilterRepository.hpp
 * PURPOSE: Defines the FilterRepository template.
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

#include <fruit/fruit.h>

#include <memory>
#include <vector>
#include <map>

namespace SDF::DataLayer::Repositories {
  // Class:      FilterRepository
  // Purpose:    Filter a given repository into one containing only objects of a subtype of the original type.
  // Parameters: SuperT - The supertype of the objects in the repository.
  //             T - The type of objects in the repository, which should be a subtype of SuperT.
  template<class SuperT, class T>
  class FilterRepository : public ModelLayer::AbstractData::IRepository<T> {
  public:
    INJECT(FilterRepository(ModelLayer::AbstractData::IRepository<SuperT> *superRepository));

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
    ModelLayer::AbstractData::IRepository<SuperT> *m_superRepository;
    std::map<int, T *> m_filter;
  };
}

#include "FilterRepository.tpp"

#endif
