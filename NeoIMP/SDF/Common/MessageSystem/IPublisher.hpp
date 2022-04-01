#ifndef SDF_COMMON_MESSAGESYSTEM_IPUBLISHER_HPP
#define SDF_COMMON_MESSAGESYSTEM_IPUBLISHER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IPublisher.hpp
 * PURPOSE: Defines the IPublisher interface.
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

#include "../IUUIDable.hpp"
#include "IMessageDispatcher.hpp"

#include <boost/uuid/uuid.hpp>

namespace SDF::Common::MessageSystem {
  // Class:      IPublisher
  // Purpose:    Defines an interface for an object which publishes messages to a channel.
  // Parameters: MessageT - The type of message published.
  template<class MessageT>
  class IPublisher : public IUUIDable {
  public:
    virtual ~IPublisher() = default;

    // Function:   setDispatcher
    // Purpose:    Sets the message dispatcher this publisher uses.
    // Parameters: messageDispatcher - The message dispatcher to set.
    // Returns:    None.
    virtual void
    setDispatcher(IMessageDispatcher<MessageT> *a_messageDispatcher) = 0;
  };
}

#endif
