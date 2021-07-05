#ifndef SDF_INTERFACES_IMESSAGEPUBLISHER_HPP
#define SDF_INTERFACES_IMESSAGEPUBLISHER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IMessagePublisher.hpp
 * PURPOSE: Defines the IMessagePublisher interface.
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

namespace SDF::Interfaces {
  template<class MessageT>
  class IMessageBroker;

  // Class:      IMessagePublisher
  // Purpose:    Defines an interface for message publishers. A message publisher publishes a message using an
  //             intermediary broker to a variety of message subscribers.
  // Parameters: MessageT - The type of message involved.
  template<class MessageT>
  class IMessagePublisher {
  public:
    virtual ~IMessagePublisher() = default;

    // Function:   getUid
    // Purpose:    Gets the unique ID of this message publisher.
    // Parameters: None.
    // Returns:    None.
    virtual int getUid() const = 0;

    // Function:   setBroker
    // Purpose:    Sets the broker to be used by this message publisher. The publisher will send its messages to the
    //             given broker.
    // Parameters: broker - The broker to use.
    // Returns:    None.
    virtual void setBroker(IMessageBroker<MessageT> *broker) = 0;
  };
}

#endif
