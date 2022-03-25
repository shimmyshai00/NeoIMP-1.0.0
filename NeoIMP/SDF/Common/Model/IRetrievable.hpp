#ifndef SDF_COMMON_MODEL_IRETRIEVABLE_HPP
#define SDF_COMMON_MODEL_IRETRIEVABLE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IRetrievable.hpp
 * PURPOSE: Defines the IRetrievable interface.
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

namespace SDF::Common::Model {
  // Class:      IRetrievable
  // Purpose:    Defines an interface for objects supporting the "retrieve" operation of persistent
  //             storage.
  // Parameters: KeyT - The type of key into the database.
  //             ObjT - The type of object stored.
  template<class KeyT, class ObjT>
  class IRetrievable {
  public:
    virtual ~IRetrievable() = default;

    // Function:   retrieve
    // Purpose:    Retrieves data from the database.
    // Parameters: key - The key to retrieve data from.
    //             obj - The object to hold the retrieved data.
    // Returns:    None.
    virtual void
    retrieve(KeyT key, ObjT &obj) = 0;
  };
}

#endif
