#ifndef SDF_COMMON_LISTENERMAPCONTAINER_TPP
#define SDF_COMMON_LISTENERMAPCONTAINER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ListenerMapContainer.tpp
 * PURPOSE: Implements the ListenerMapContainer template.
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
    template<class KeyT, class ... Args>
    class MapConnection : public IConnection {
    public:
      MapConnection(std::map<KeyT, std::list<std::shared_ptr<IListener<Args...>>>> *listenerMap,
                    KeyT key,
                    std::shared_ptr<IListener<Args...>> listener
                   )
        : m_connected(false),
          m_listenerMap(listenerMap),
          m_key(key),
          m_listener(listener)
      {
      }

      void
      connect() {
        if(!m_connected) {
          m_listenerMap->emplace(m_key, std::list<std::shared_ptr<IListener<Args...>>>());
          (*m_listenerMap)[m_key].push_back(m_listener);
          m_listenerPos = (*m_listenerMap)[m_key].end(); m_listenerPos--;
          m_connected = true;
        }
      }

      void
      disconnect() {
        if(m_connected) {
          (*m_listenerMap)[m_key].erase(m_listenerPos);
          if((*m_listenerMap)[m_key].empty()) {
            m_listenerMap->erase(m_key);
          }

          m_connected = false;
        }
      }
    private:
      bool m_connected;
      std::map<KeyT, std::list<std::shared_ptr<IListener<Args...>>>> *m_listenerMap;
      KeyT m_key;
      typename std::list<std::shared_ptr<IListener<Args...>>>::iterator m_listenerPos;
      std::shared_ptr<IListener<Args...>> m_listener;
    };
  }

  template<class KeyT, class ... Args>
  PIConnection
  ListenerMapContainer<KeyT, Args...>::addListener(KeyT key,
                                                   std::shared_ptr<IListener<Args...>> listener
                                                  )
  {
    return PIConnection(new Impl::MapConnection<KeyT, Args...>(&m_listenerMap, key, listener));
  }

  template<class KeyT, class ... Args>
  void
  ListenerMapContainer<KeyT, Args...>::notify(KeyT key,
                                              Args... args
                                             )
  {
    if(m_listenerMap.find(key) != m_listenerMap.end()) {
      for(const auto &lis : m_listenerMap[key]) {
        lis->notify(args...);
      }
    }
  }
}

#endif
