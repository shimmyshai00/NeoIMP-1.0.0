/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentNotificationService.cpp
 * PURPOSE: Implements the DocumentNotificationService class.
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

#include "DocumentNotificationService.hpp"

#include <boost/uuid/uuid_generators.hpp>

namespace SDF::Editor::ModelLayer::Services {
  DocumentNotificationService::DocumentNotificationService(
    Common::MessageSystem::ISubscribable<Messages::ImageAdded> *a_imageAddedMessageSource
  )
    : m_uuid(boost::uuids::random_generator()())
  {
    m_documentAddedMessagesConnection = a_imageAddedMessageSource->subscribe(this);
    m_documentAddedMessagesConnection->connect();
  }

  DocumentNotificationService::~DocumentNotificationService() {
    m_documentAddedMessagesConnection->disconnect();
  }

  boost::uuids::uuid
  DocumentNotificationService::getUuid() const {
    return m_uuid;
  }

  Common::PIConnection
  DocumentNotificationService::addListener(
    std::shared_ptr<Common::IListener<Common::Handle>> a_listener
  ) {
    return m_documentAddedListeners.addListener(a_listener);
  }

  void
  DocumentNotificationService::receiveMessage(
    const boost::uuids::uuid a_senderUuid,
    const Messages::ImageAdded &a_message
  ) {
    m_documentAddedListeners.notify(a_message.handle);
  }
}
