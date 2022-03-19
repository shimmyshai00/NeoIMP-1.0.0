#ifndef SDF_COMMON_DATA_IDATAMAPPER_HPP
#define SDF_COMMON_DATA_IDATAMAPPER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IDataMapper.hpp
 * PURPOSE: Defines the IDataMapper interface.
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

namespace SDF::Common::Data {
  // Class:      IDataMapper
  // Purpose:    Defines an interface for a data mapper (object to move data between persistent
  //             storage and memory without regard to which database system is used).
  // Parameters: KeyT - The type of database key accepted by this mapper.
  //             ObjT - The type of domain object mapped into the persistent storage.
  template<class KeyT, class ObjT>
  class IDataMapper {
  public:
    virtual ~IDataMapper() = default;

    // The usual database access methods (CRUD).
    virtual bool
    has(KeyT key) = 0;

    virtual void
    insert(KeyT key, ObjT &obj) = 0;

    virtual void
    retrieve(KeyT key, ObjT &obj) = 0;

    virtual void
    update(KeyT key, ObjT& obj) = 0;

    virtual void
    erase(KeyT key) = 0;
  };
}

#endif
