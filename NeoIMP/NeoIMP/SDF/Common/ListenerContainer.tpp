#ifndef SDF_COMMON_LISTENERCONTAINER_TPP
#define SDF_COMMON_LISTENERCONTAINER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ListenerContainer.tpp
 * PURPOSE: Implements the ListenerContainer template.
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

namespace SDF::Common {
  namespace Impl {
    template<class ... Args>
    class Connection : public IConnection {
    public:
      Connection(std::list<std::shared_ptr<IListener<Args...>>> *list,
                 std::shared_ptr<IListener<Args...>> listener
                )
        : m_connected(false),
          m_list(list),
          m_listener(listener)
      {
      }

      void
      connect() {
        if(!m_connected) {
          m_list->push_back(m_listener);
          m_insertedWhere = m_list->end(); m_insertedWhere--;
          m_connected = true;
        }
      }

      void
      disconnect() {
        if(m_connected) {
          m_list->erase(m_insertedWhere);
          m_connected = false;
        }
      }
    private:
      bool m_connected;
      std::list<std::shared_ptr<IListener<Args...>>> *m_list;
      typename std::list<std::shared_ptr<IListener<Args...>>>::iterator m_insertedWhere;
      std::shared_ptr<IListener<Args...>> m_listener;
    };
  }

  template<class ... Args>
  PIConnection
  ListenerContainer<Args...>::addListener(std::shared_ptr<IListener<Args...>> listener) {
    return PIConnection(new Impl::Connection<Args...>(&m_listeners, listener));
  }

  template<class ... Args>
  void
  ListenerContainer<Args...>::notify(Args... args) {
    for(const auto &listener : m_listeners) {
      listener->notify(args...);
    }
  }
}

#endif
