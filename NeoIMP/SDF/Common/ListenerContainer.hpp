#ifndef SDF_COMMON_LISTENERCONTAINER_HPP
#define SDF_COMMON_LISTENERCONTAINER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ListenerContainer.hpp
 * PURPOSE: Defines the ListenerContainer template.
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

#include "IConnection.hpp"
#include "IListenable.hpp"
#include "IListener.hpp"

#include <memory>
#include <list>

namespace SDF::Common {
  // Class:      ListenerContainer
  // Purpose:    Defines a container class for holding listeners.
  // Parameters: Args - The listener arguments.
  template<class ... Args>
  class ListenerContainer : public IListenable<Args...> {
  public:
    // Function:   addListener
    // Purpose:    Adds a listener to the container.
    // Parameters: listener - The listener to add.
    // Returns:    A connection object to the listener.
    PIConnection
    addListener(std::shared_ptr<IListener<Args...>> a_listener);

    // Function:   notify
    // Purpose:    Invoke the stored listeners with a notification.
    // Parameters: args - The arguments to pass to the listeners.
    // Returns:    None.
    void
    notify(Args... a_args);
  private:
    std::list<std::shared_ptr<IListener<Args...>>> m_listeners;
  };
}

#include "ListenerContainer.tpp"

#endif
