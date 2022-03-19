#ifndef SDF_COMMON_MESSAGESYSTEM_ICHANNEL_HPP
#define SDF_COMMON_MESSAGESYSTEM_ICHANNEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IChannel.hpp
 * PURPOSE: Defines the IChannel interface.
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

#include "../IConnection.hpp"
#include "ISubscriber.hpp"

#include <boost/uuid/uuid.hpp>

#include <functional>

namespace SDF::Common::MessageSystem {
  // Class:      IChannel
  // Purpose:    Defines a message channel in the publish/subscribe messaging system.
  // Parameters: MessageT - The type of message used in this message *system*.
  template<class MessageT>
  class IChannel {
  public:
    virtual ~IChannel() = default;

    // Function:   publishMessage
    // Purpose:    Publishes a message onto the channel.
    // Parameters: senderUuid - The UUID of the sender of the message. Note that subscribers must
    //                          also supply a UUID, for in case they also want to act as publishers,
    //                          we need to prevent infinite recursive loops.
    //             message - The message to publish.
    // Returns:    None.
    virtual void
    publishMessage(boost::uuids::uuid senderUuid,
                   const MessageT &message
                  ) = 0;

    // Function:   subscribe
    // Purpose:    Subscribes to messages published onto this channel.
    // Parameters: subscriber - The object subscribing.
    //             filter - A function object for further filtering messages of interest.
    // Returns:    A connection handle for the subscription.
    virtual PIConnection
    subscribe(ISubscriber<MessageT> *subscriber,
              std::function<bool (const MessageT &)> filter = [](const MessageT &) {return true;}
             ) = 0;
  };
}

#endif
