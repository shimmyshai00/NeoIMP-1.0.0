#ifndef SDF_COMMON_LISTENERMAPCONTAINER_HPP
#define SDF_COMMON_LISTENERMAPCONTAINER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ListenerMapContainer.hpp
 * PURPOSE: Defines the ListenerMapContainer template.
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
#include <map>
#include <list>

namespace SDF::Common {
  // Class:      ListenerMapContainer
  // Purpose:    Defines a container class for holding listeners that functions like a std::map.
  // Parameters: KeyT - The type of key used to index the listener bundles.
  //             Args - The listener arguments.
  template<class KeyT, class ... Args>
  class ListenerMapContainer : public IListenable<Args...> {
  public:
    // Function:   addListener
    // Purpose:    Adds a listener to the container.
    // Parameters: key - The key to add this listener to.
    //             listener - The listener to add.
    // Returns:    A connection object to the listener.
    PIConnection
    addListener(KeyT key,
                std::shared_ptr<IListener<Args...>> listener
               );

    // Function:   notify
    // Purpose:    Invoke the stored listeners with a notification.
    // Parameters: key - The key indicating the listener batch to invoke.
    //             args - The arguments to pass to the listeners.
    // Returns:    None.
    void
    notify(KeyT key,
           Args... args
          );
  private:
    std::map<KeyT, std::list<std::shared_ptr<IListener<Args...>>>> m_listenerMap;
  };
}

#include "ListenerMapContainer.tpp"

#endif
