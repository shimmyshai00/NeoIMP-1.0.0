#ifndef SDF_COMMON_DATA_IOWNINGCREATABLE_HPP
#define SDF_COMMON_DATA_IOWNINGCREATABLE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IOwningCreatable.hpp
 * PURPOSE: Defines the IOwningCreatable interface.
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

namespace SDF::Common::Data {
  // Class:      IOwningCreatable
  // Purpose:    Defines an interface for the create method of storage objects which also take
  //             in-memory ownership of the objects stored in them.
  // Parameters: KeyT - The type of key into the database.
  //             ObjT - The type of object stored.
  template<class KeyT, class ObjT>
  class IOwningCreatable {
  public:
    virtual ~IOwningCreatable() = default;

    // Function:   create
    // Purpose:    Creates a new entry in the database.
    // Parameters: key - The key to add the entry under.
    //             obj - The initial data to add to this entry.
    // Returns:    A non-owning reference to the added object.
    virtual ObjT *
    create(KeyT a_key, std::unique_ptr<ObjT> a_obj) = 0;
  };
}

#endif
