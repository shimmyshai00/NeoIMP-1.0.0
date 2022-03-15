#ifndef SDF_COMMON_MESSAGESYSTEM_ALLTOALL_TPP
#define SDF_COMMON_MESSAGESYSTEM_ALLTOALL_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AllToAll.tpp
 * PURPOSE: Implements the AllToAll template.
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

namespace SDF::Common::MessageSystem::Impl {
  template<class MessageT>
  class Connection : public IConnection {
  public:
    Connection(std::map<boost::uuids::uuid, ISubscriber<MessageT> *> *subscriberMap,
               std::map<boost::uuids::uuid, std::function<bool (const MessageT &)>> *filterMap,
               ISubscriber<MessageT> *subscriber,
               std::function<bool (const MessageT &)> filter
              )
      : m_subscriberMap(subscriberMap),
        m_filterMap(filterMap),
        m_subscriber(subscriber),
        m_filter(filter)
    {
    }

    void
    connect() {
      if(m_subscriberMap->find(m_subscriber->getUuid()) == m_subscriberMap->end()) {
        (*m_subscriberMap)[m_subscriber->getUuid()] = m_subscriber;
        (*m_filterMap)[m_subscriber->getUuid()] = m_filter;
      }
    }

    void
    disconnect() {
      m_subscriberMap->erase(m_subscriber->getUuid());
      m_filterMap->erase(m_subscriber->getUuid());
    }
  private:
    std::map<boost::uuids::uuid, ISubscriber<MessageT> *> *m_subscriberMap;
    std::map<boost::uuids::uuid, std::function<bool (const MessageT &)>> *m_filterMap;
    ISubscriber<MessageT> *m_subscriber;
    std::function<bool (const MessageT &)> m_filter;
  };
}

namespace SDF::Common::MessageSystem {
  template<class MessageT>
  AllToAll<MessageT>::AllToAll() {
  }

  template<class MessageT>
  void
  AllToAll<MessageT>::publishMessage(boost::uuids::uuid senderUuid,
                                     const MessageT &message
                                    )
  {
    for(const auto &kvp : m_subscribers) {
      if(kvp.first != senderUuid) {
        if(m_filters[kvp.first](message)) {
          kvp.second->receiveMessage(this, senderUuid, message);
        }
      }
    }
  }

  template<class MessageT>
  PIConnection
  AllToAll<MessageT>::subscribe(ISubscriber<MessageT> *subscriber,
                                std::function<bool (const MessageT &)> filter
                               )
  {
    return PIConnection(new Impl::Connection<MessageT>(&m_subscribers, &m_filters, subscriber,
      filter));
  }
}

#endif
