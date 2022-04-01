#ifndef SDF_COMMON_DATA_REPOSITORIES_CMEMORYONLYVALUEREPOSITORY_HPP
#define SDF_COMMON_DATA_REPOSITORIES_CMEMORYONLYVALUEREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CMemoryOnlyValueRepository.hpp
 * PURPOSE: Defines the CMemoryOnlyValueRepository template.
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

#include "../ICrudable.hpp"

#include <fruit/fruit.h>
#include <memory>
#include <map>

namespace SDF::Common::Data::Repositories {
  // Class:      CMemoryOnlyValueRepository
  // Purpose:    A version of the CMemoryOnlyRepository that does not take ownership of its inputs
  //             but only records their values.
  // Parameters: KeyT - The type of "database" key involved.
  //             ObjT - The domain object type held.
  template<class KeyT, class ObjT>
  class CMemoryOnlyValueRepository : public ICrudable<KeyT, ObjT> {
  public:
    INJECT(CMemoryOnlyValueRepository());

    bool
    has(KeyT a_key);

    void
    create(KeyT a_key, const ObjT &a_obj);

    void
    retrieve(KeyT a_key, ObjT &a_obj);

    void
    update(KeyT a_key, const ObjT &a_obj);

    void
    deleteO(KeyT a_key);
  private:
    std::map<KeyT, ObjT> m_objMap;
  };
}

#include "CMemoryOnlyValueRepository.tpp"

#endif
