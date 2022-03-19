#ifndef SDF_INTERFACES_IMESSAGEBROKER_HPP
#define SDF_INTERFACES_IMESSAGEBROKER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IMessageBroker.hpp
 * PURPOSE: Defines the IMessageBroker interface.
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
  template<class MessageT>
  class IMessagePublisher;

  template<class MessageT>
  class IMessageSubscriber;

  // Class:      IMessageBroker
  // Purpose:    Defines an interface for objects which broker messages from publishers amongst subscribers.
  // Parameters: MessageT - The type of message handled.
  template<class MessageT>
  class IMessageBroker {
  public:
    virtual ~IMessageBroker() = default;

    // Function:   addPublisher
    // Purpose:    Registers a new publisher with the broker. This is needed to be able to correctly match publishers
    //             and subscribers so that objects that have dual role can be identified so as not to get into an
    //             infinite loop of sending and receiving messages to/from themselves.
    // Parameters: publisher - The publisher to add.
    // Returns:    None.
    virtual void addPublisher(IMessagePublisher<MessageT> *publisher) = 0;

    // Function:   addSubscriber
    // Purpose:    Registers a subscriber with the broker, so it can receive messages therefrom.
    // Parameters: subscriber - The subscriber to add.
    // Returns:    None.
    virtual void addSubscriber(IMessageSubscriber<MessageT> *subscriber) = 0;

    // Function:   removePublisher
    // Purpose:    Removes a publisher from the broker's registry.
    // Parameters: publisher - The publisher to remove.
    // Returns:    None.
    virtual void removePublisher(IMessagePublisher<MessageT> *publisher) = 0;

    // Function:   removeSubscriber
    // Purpose:    Removes a subscriber from the broker's registry.
    // Parameters: subscriber - The subscriber to remove.
    // Returns:    None.
    virtual void removeSubscriber(IMessageSubscriber<MessageT> *subscriber) = 0;

    // Function:   receiveMessage
    // Purpose:    Receives a message from the given publisher and passes it on to the subscribers.
    // Parameters: publisher - The publisher of the message.
    //             message - The message to send.
    // Returns:    None.
    virtual void receiveMessage(IMessagePublisher<MessageT> *publisher, std::shared_ptr<MessageT> message) = 0;
  };
}

#endif
