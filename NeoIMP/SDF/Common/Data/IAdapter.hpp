#ifndef SDF_COMMON_DATA_IADAPTER_HPP
#define SDF_COMMON_DATA_IADAPTER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IAdapter.hpp
 * PURPOSE: Defines the IAdapter interface.
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
  // Class:      IAdapter
  // Purpose:    Adapts a specific external database interface to a common interface. Note that
  //             while this has a similar interface to the IDataMapper, semantically this represents
  //             a lower level: the movement of general data to/from a database, not specifically
  //             domain objects. This is, in effect, the "bottom level" of the program stack - the
  //             same IAdapter may be used by many different data mappers.
  // Parameters: KeyT - The key for each database entry.
  //             DataT - The type of data that can be entered.
  template<class KeyT, class DataT>
  class IAdapter {
  public:
    virtual ~IAdapter() = default;

    virtual bool
    exist(KeyT a_key) = 0;

    virtual void
    create(KeyT a_key) = 0;

    virtual void
    writeData(KeyT key, const DataT &a_data) = 0;

    virtual void
    readData(KeyT a_key, DataT &a_destination) = 0;

    virtual void
    erase(KeyT a_key) = 0;
  };
}

#endif
