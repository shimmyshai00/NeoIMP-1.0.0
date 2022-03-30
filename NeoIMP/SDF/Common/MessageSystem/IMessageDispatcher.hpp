#ifndef SDF_COMMON_MESSAGESYSTEM_IMESSAGEDISPATCHER_HPP
#define SDF_COMMON_MESSAGESYSTEM_IMESSAGEDISPATCHER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IMessageDispatcher.hpp
 * PURPOSE: Defines the IMessageDispatcher base template.
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

#include <boost/uuid/uuid.hpp>

namespace SDF::Common::MessageSystem {
  // Class:      IMessageDispatcher
  // Purpose:    Provides an interface for objects which dispatch messages.
  // Parameters: MessageT - The type of message handled.
  template<class MessageT>
  class IMessageDispatcher {
  public:
    virtual ~IMessageDispatcher() = default;

    // Function:   dispatchMessage
    // Purpose:    Dispatches an issued message.
    // Parameters: senderUuid - The UUID of the sender of the message. Note that subscribers must
    //                          also supply a UUID, for in case they also want to act as publishers,
    //                          we need to prevent infinite recursive loops.
    //             message - The message to publish.
    // Returns:    None.
    virtual void
    dispatchMessage(boost::uuids::uuid senderUuid,
                    const MessageT &message
                   ) = 0;
  };
}

#endif
