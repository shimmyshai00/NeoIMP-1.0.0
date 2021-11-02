#ifndef SDF_PATTERNS_ILISTENER_HPP
#define SDF_PATTERNS_ILISTENER_HPP

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

namespace SDF::Patterns {
  // Class:      IListener
  // Purpose:    Defines an interface for event listeners.
  // Parameters: EventT - The type of event to listen to.
  template<class EventT>
  class IListener {
  public:
    virtual ~IListener() = default;

    // Function:   onEvent
    // Purpose:    Called when an event occurs.
    // Parameters: event - The event to handle.
    // Returns:    None.
    virtual void
    onEvent(std::shared_ptr<EventT> event) = 0;
  };
}

#endif
