#ifndef SDF_COMMON_MODEL_ICRUDREPOSITORY_HPP
#define SDF_COMMON_MODEL_ICRUDREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ICrudRepository.hpp
 * PURPOSE: Defines the ICrudRepository interface.
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

#include <memory>

namespace SDF::Common::Model {
  // Class:      ICrudRepository
  // Purpose:    Defines an interface for a simple "CRUD"-type repository that provides no special
  //             queries and no special persistence controls. Note that this has an ownership
  //             semantics.
  // Parameters: KeyT - The type of database key accepted by this repository.
  //             ObjT - The type of domain object held.
  template<class KeyT, class ObjT>
  class ICrudRepository {
  public:
    virtual ~ICrudRepository() = default;

    virtual bool
    has(KeyT key) = 0;

    virtual void
    insert(KeyT key, std::unique_ptr<ObjT> obj) = 0;

    virtual ObjT *
    retrieve(KeyT key) = 0;

    virtual void
    update(KeyT key, ObjT& obj) = 0;

    virtual void
    erase(KeyT key) = 0;
  };
}

#endif
