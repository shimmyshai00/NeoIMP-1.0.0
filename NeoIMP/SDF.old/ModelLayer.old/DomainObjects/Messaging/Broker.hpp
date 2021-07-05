#ifndef SDF_MODELLAYER_DOMAINOBJECTS_MESSAGING_BROKER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_MESSAGING_BROKER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Broker.hpp
 * PURPOSE: Defines the Broker template.
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

#include <SDF/Interfaces/IMessageBroker.hpp>

#include <SDF/Interfaces/IMessagePublisher.hpp>
#include <SDF/Interfaces/IMessageSubscriber.hpp>

#include <fruit/fruit.h>

#include <set>

namespace SDF::ModelLayer::DomainObjects::Messaging {
  // Class:   Broker
  // Purpose: Brokers messages among services. This allows services to communicate with each other in a loosely-
  //          coupled manner.
  template<class MessageT>
  class Broker : public Interfaces::IMessageBroker<MessageT> {
  public:
    INJECT(Broker());

    void addPublisher(Interfaces::IMessagePublisher<MessageT> *publisher);
    void addSubscriber(Interfaces::IMessageSubscriber<MessageT> *subscriber);

    void removePublisher(Interfaces::IMessagePublisher<MessageT> *publisher);
    void removeSubscriber(Interfaces::IMessageSubscriber<MessageT> *subscriber);

    void receiveMessage(Interfaces::IMessagePublisher<MessageT> *publisher,
                        std::shared_ptr<MessageT> message
                       );
  private:
    std::set<Interfaces::IMessagePublisher<MessageT> *> m_publishers;
    std::set<Interfaces::IMessageSubscriber<MessageT> *> m_subscribers;
  };
}

#include "SDF/ModelLayer/DomainObjects/Messaging/Broker.tpp"

#endif
