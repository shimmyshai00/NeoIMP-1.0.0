#ifndef SDF_COMMON_DATA_IOWNINGRETRIEVABLE_HPP
#define SDF_COMMON_DATA_IOWNINGRETRIEVABLE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IOwningRetrievable.hpp
 * PURPOSE: Defines the IOwningRetrievable interface.
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
  // Class:      IOwningRetrievable
  // Purpose:    Defines the owning analogue of IRetrievable. Since such an object keeps a memory
  //             copy, this provides access to the owned copy for consistency with IOwningCreatable.
  // Parameters: KeyT - The type of key into the database.
  //             ObjT - The type of object stored.
  template<class KeyT, class ObjT>
  class IOwningRetrievable {
  public:
    virtual ~IOwningRetrievable() = default;

    // Function:   retrieve
    // Purpose:    Retrieves data from the database.
    // Parameters: key - The key to retrieve data from.
    // Returns:    The object with the given key.
    virtual ObjT *
    retrieve(KeyT a_key) = 0;
  };
}

#endif
