/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Emitter.hpp
 * PURPOSE: A simple dataflow base for MVC objects that emit messages.
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

#include <Emitter.hpp>

#include <IReceiver.hpp>

#include <algorithm>

namespace SDF::Impl::UILayer::Impl::Framework::Messaging {
  Emitter::Emitter() {}
  Emitter::~Emitter() {}

  void Emitter::connectTo(IReceiver *recv) {
    m_receivers.push_back(recv);
  }

  void Emitter::disconnect(IReceiver *recv) {
    m_receivers.erase(std::find(m_receivers.begin(), m_receivers.end(), recv));
  }

  void Emitter::emitMessage(std::string message) {
    for(auto recv : m_receivers) {
      recv->receiveMessage(message);
    }
  }
}
