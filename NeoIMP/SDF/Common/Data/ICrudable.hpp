#ifndef SDF_COMMON_DATA_ICRUDABLE_HPP
#define SDF_COMMON_DATA_ICRUDABLE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ICrudable.hpp
 * PURPOSE: Defines the ICrudable interface.
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

#include "IReadable.hpp"
#include "IWritable.hpp"

namespace SDF::Common::Data {
  // Class:      ICrudable
  // Purpose:    Defines an interface for objects that perform the whole suite of CRUD operations.
  // Parameters: KeyT - The type of key into the database.
  //             ObjT - The type of object stored.
  template<class KeyT, class ObjT>
  class ICrudable : public IReadable<KeyT, ObjT>,
                    public IWritable<KeyT, ObjT>
  {
  };
}

#endif
