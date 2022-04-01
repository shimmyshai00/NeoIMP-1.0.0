#ifndef SDF_COMMON_ILISTENABLE_HPP
#define SDF_COMMON_ILISTENABLE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IListenable.hpp
 * PURPOSE: Defines the IListenable interface.
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

#include "IListener.hpp"
#include "IConnection.hpp"

#include <memory>

namespace SDF::Common {
  // Class:      IListenable
  // Purpose:    Defines an interface for objects that can be listened to.
  // Parameters: Args - The arguments accepted by the listener.
  template<class ... Args>
  class IListenable {
  public:
    virtual ~IListenable() = default;

    // Function:   addListener
    // Purpose:    Adds a listener to the container.
    // Parameters: listener - The listener to add.
    // Returns:    A connection object to the listener.
    PIConnection
    addListener(std::shared_ptr<IListener<Args...>> a_listener);
  };
}

#endif
