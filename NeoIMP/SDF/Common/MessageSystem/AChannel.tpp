#ifndef SDF_COMMON_MESSAGESYSTEM_ACHANNEL_TPP
#define SDF_COMMON_MESSAGESYSTEM_ACHANNEL_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AChannel.tpp
 * PURPOSE: Implements the AChannel base template.
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
               ISubscriber<MessageT> *subscriber
              )
      : m_subscriberMap(subscriberMap),
        m_subscriber(subscriber)
    {
    }

    void
    connect() {
      if(m_subscriberMap->find(m_subscriber->getUuid()) == m_subscriberMap->end()) {
        (*m_subscriberMap)[m_subscriber->getUuid()] = m_subscriber;
      }
    }

    void
    disconnect() {
      m_subscriberMap->erase(m_subscriber->getUuid());
    }
  private:
    std::map<boost::uuids::uuid, ISubscriber<MessageT> *> *m_subscriberMap;
    ISubscriber<MessageT> *m_subscriber;
  };
}

namespace SDF::Common::MessageSystem {
  // Protected members.
  template<class MessageT>
  ISubscriber<MessageT> *
  AChannel<MessageT>::getSubscriber(boost::uuids::uuid uuid) {
    if(m_subscribers.find(uuid) != m_subscribers.end()) {
      return m_subscribers[uuid];
    } else {
      return nullptr;
    }
  }

  template<class MessageT>
  void
  AChannel<MessageT>::forEachSubscriber(
    std::function<void(std::pair<boost::uuids::uuid, ISubscriber<MessageT> *>)> func
  ) {
    for(std::pair<boost::uuids::uuid, ISubscriber<MessageT> *> kvp : m_subscribers) {
      func(kvp);
    }
  }
}

namespace SDF::Common::MessageSystem {
  template<class MessageT>
  PIConnection
  AChannel<MessageT>::subscribe(ISubscriber<MessageT> *subscriber)
  {
    return PIConnection(new Impl::Connection<MessageT>(&m_subscribers, subscriber));
  }
}

#endif
