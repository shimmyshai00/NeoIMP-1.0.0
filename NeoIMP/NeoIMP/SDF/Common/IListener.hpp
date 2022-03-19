#ifndef SDF_COMMON_ILISTENER_HPP
#define SDF_COMMON_ILISTENER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IListener.hpp
 * PURPOSE: Defines the IListener interface.
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

namespace SDF::Common {
  // Class:      IListener
  // Purpose:    Defines an interface for objects which can "listen" to other objects. Essentially a
  //             function object interface for an observer pattern.
  // Parameters: Args - The arguments accepted by the listener.
  template<class ... Args>
  class IListener {
  public:
    virtual ~IListener() = default;

    // Function:   notify
    // Purpose:    Notifies the listener of an event (like a change).
    // Parmeters:  args - The arguments to notify with.
    // Returns:    None.
    virtual void
    notify(Args... args) = 0;
  };
}

#endif
