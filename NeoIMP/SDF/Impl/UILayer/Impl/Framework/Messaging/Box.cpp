/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Box.cpp
 * PURPOSE: Provides a base for a box, which can contain internal emitting components wired to an external emitter.
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

#include <Box.hpp>

namespace SDF::Impl::UILayer::Impl::Framework::Messaging {
  Box::Box() : m_innerReceiver(new InnerReceiver(this)) {}
  Box::~Box() {}

  Box::InnerReceiver::InnerReceiver(Box *box) : m_box(box) {}
  void Box::InnerReceiver::receiveMessage(std::string message) {
    m_box->emitMessage(message);
  }
}
