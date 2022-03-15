#ifndef SDF_EDITOR_MODELLAYER_MESSAGESYSTEM_ISUBSCRIBER_HPP
#define SDF_EDITOR_MODELLAYER_MESSAGESYSTEM_ISUBSCRIBER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ISubscriber.hpp
 * PURPOSE: Defines the ISubscriber interface.
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

#include "../DomainObjects/IUUIDable.hpp"

#include <boost/uuid/uuid.hpp>

namespace SDF::Editor::ModelLayer::MessageSystem {
  template<class MessageT>
  class IChannel;

  // Class:      ISubscriber
  // Purpose:    Defines an interface for a subscriber to channel messages.
  // Parameters: MessageT - The type of message communicated.
  template<class MessageT>
  class ISubscriber : public DomainObjects::IUUIDable {
  public:
    virtual ~ISubscriber() = default;

    // Function:   receiveMessage
    // Purpose:    Receive a message from the channel.
    // Parameters: channel - The channel the message was received on.
    //             senderUuid - The UUID of the sending object.
    //             message - The message itself.
    virtual void
    receiveMessage(const IChannel<MessageT> *channel,
                   const boost::uuids::uuid senderUuid,
                   const MessageT &message
                  ) = 0;
  };
}

#endif
