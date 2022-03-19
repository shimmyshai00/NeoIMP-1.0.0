#ifndef SDF_INTERFACES_IEVENTHANDLER_HPP
#define SDF_INTERFACES_IEVENTHANDLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IEventHandler.hpp
 * PURPOSE: Defines the IEventHandler interface.
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

namespace SDF::Interfaces {
  // Class:      IEventHandler
  // Purpose:    A general interface for event handlers.
  // Parameters: EventT - The type of event to handle.
  template<class EventT>
  class IEventHandler {
  public:
    virtual ~IEventHandler() = default;

    // Function:   handleEvent
    // Purpose:    Handle a given event.
    // Parameters: event - The event to handle.
    // Returns:    None.
    virtual void handleEvent(std::shared_ptr<EventT> event) = 0;
  };
}

#endif
