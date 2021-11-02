#ifndef SDF_PATTERNS_ICONNECTION_HPP
#define SDF_PATTERNS_ICONNECTION_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IConnection.hpp
 * PURPOSE: Defines the IConnection interface.
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

namespace SDF::Patterns {
  // Class:      IConnection
  // Purpose:    Provides an interface for objects representing connections between other objects.
  // Parameters: None.
  class IConnection {
  public:
    virtual ~IConnection() = default;

    // Function:   connect
    // Purpose:    Connect the two objects.
    // Parameters: None.
    // Returns:    None.
    virtual void
    connect() = 0;

    // Function:   disconnect
    // Purpose:    Disconnect the two objects.
    // Parameters: None.
    // Returns:    None.
    virtual void
    disconnect() = 0;
  };
}

#endif