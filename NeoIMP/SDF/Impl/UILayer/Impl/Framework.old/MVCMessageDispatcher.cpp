/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCMessageDispatcher.cpp
 * PURPOSE: Definition of a message dispatcher, which dispatches messages to a pre-set set of recipients.
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

#include <MVCMessageDispatcher.hpp>
#include <algorithm>
#include <iostream>

namespace SDF::Impl::UILayer::Impl::Framework {
  MVCMessageDispatcher::MVCMessageDispatcher() {}

  void MVCMessageDispatcher::receiveMessage(void *sender, std::string message) {
    std::cout << "dispatcher " << this << " dispatching message: " << message << std::endl;
    for(IMVCMessageReceiver *recv : m_messageReceivers) {
      std::cout << " recv ... ";
      if(recv != sender) {
        recv->receiveMessage(this, message);
        std::cout << "ack" << std::endl;
      } else {
        std::cout << std::endl;
      }
    }
  }

  void MVCMessageDispatcher::addMessageReceiver(IMVCMessageReceiver *receiver) {
    m_messageReceivers.push_back(receiver);
  }

  void MVCMessageDispatcher::removeMessageReceiver(IMVCMessageReceiver *receiver) {
    m_messageReceivers.erase(std::find(m_messageReceivers.begin(), m_messageReceivers.end(), receiver));
  }
}
