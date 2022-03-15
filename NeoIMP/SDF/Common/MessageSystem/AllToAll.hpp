#ifndef SDF_COMMON_MESSAGESYSTEM_ALLTOALL_HPP
#define SDF_COMMON_MESSAGESYSTEM_ALLTOALL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AllToAll.hpp
 * PURPOSE: Defines the AllToAll template.
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

#include <fruit/fruit.h>

#include <map>

namespace SDF::Common::MessageSystem {
  // Class:      AllToAll
  // Purpose:    Provides a very simple publish/subscribe service that provides all-to-all
  //             messaging  of attached subscribers.
  // Parameters: MessageT - The type of message handled.
  template<class MessageT>
  class AllToAll : public IChannel<MessageT> {
  public:
    INJECT(AllToAll());

    void
    publishMessage(boost::uuids::uuid senderUuid,
                   const MessageT &message
                  );

    PIConnection
    subscribe(ISubscriber<MessageT> *subscriber,
              std::function<bool (const MessageT &)> filter
             );
  private:
    std::map<boost::uuids::uuid, ISubscriber<MessageT> *> m_subscribers;
    std::map<boost::uuids::uuid, std::function<bool (const MessageT &)>> m_filters;
  };
}

#include "AllToAll.tpp"

#endif
