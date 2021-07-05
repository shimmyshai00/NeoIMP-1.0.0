#ifndef SDF_UILAYER_GUI_MESSAGING_BROKER_TPP
#define SDF_UILAYER_GUI_MESSAGING_BROKER_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Broker.tpp
 * PURPOSE: Implements the Broker template.
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

#include "Broker.hpp"

namespace SDF::ModelLayer::DomainObjects::Messaging {
  // Note: this is a very simple broker; we might factor it out as a general broker implementation in the future.
  template<class MessageT>
  Broker<MessageT>::Broker() {}

  template<class MessageT>
  void Broker<MessageT>::addPublisher(Interfaces::IMessagePublisher<MessageT> *publisher) {
    m_publishers.insert(publisher);
    publisher->setBroker(this);
  }

  template<class MessageT>
  void Broker<MessageT>::addSubscriber(Interfaces::IMessageSubscriber<MessageT> *subscriber) {
    m_subscribers.insert(subscriber);
  }

  template<class MessageT>
  void Broker<MessageT>::removePublisher(Interfaces::IMessagePublisher<MessageT> *publisher) {
    m_publishers.erase(publisher);
    publisher->setBroker(nullptr);
  }

  template<class MessageT>
  void Broker<MessageT>::removeSubscriber(Interfaces::IMessageSubscriber<MessageT> *subscriber) {
    m_subscribers.erase(subscriber);
  }

  template<class MessageT>
  void Broker<MessageT>::receiveMessage(Interfaces::IMessagePublisher<MessageT> *publisher,
                                        std::shared_ptr<MessageT> message
                                       )
  {
    for(auto subscriber : m_subscribers) {
      if(subscriber->getUid() != publisher->getUid()) {
        // do not send this message to its sender, which would create an infinite loop!
        subscriber->receiveMessage(message);
      }
    }
  }
}

#endif
