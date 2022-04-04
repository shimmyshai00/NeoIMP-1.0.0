#ifndef SDF_EDITOR_MODELLAYER_SERVICES_DOCUMENTNOTIFICATIONSERVICE_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_DOCUMENTNOTIFICATIONSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentNotificationService.hpp
 * PURPOSE: Defines the DocumentNotificationService class.
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

#include "../../../Common/MessageSystem/ISubscriber.hpp"
#include "../../../Common/MessageSystem/ISubscribable.hpp"
#include "../../../Common/IListener.hpp"
#include "../../../Common/IConnection.hpp"
#include "../../../Common/ListenerContainer.hpp"
#include "../../../Common/Handle.hpp"

#include "../../UILayer/AbstractModel/DocumentMgmt/IDocumentAddedService.hpp"

#include "Messages/ObjectChanges.hpp"

#include <boost/uuid/uuid.hpp>

#include <fruit/fruit.h>

namespace SDF::Editor::ModelLayer::Services {
  // Class:      DocumentNotificationService
  // Purpose:    Defines an MVC service to provide notifications related to the addition, removal,
  //             renaming, etc. of documents.
  // Parameters: None.
  class DocumentNotificationService :
    public UILayer::AbstractModel::DocumentMgmt::IDocumentAddedService,
    public Common::MessageSystem::ISubscriber<Messages::ImageAdded>
  {
  public:
    INJECT(DocumentNotificationService(
      Common::MessageSystem::ISubscribable<Messages::ImageAdded> *a_imageAddedMessageSource
    ));

    DocumentNotificationService(const DocumentNotificationService &) = delete;
    DocumentNotificationService(DocumentNotificationService &&) = delete;
    DocumentNotificationService &operator=(const DocumentNotificationService &) = delete;
    DocumentNotificationService &operator=(DocumentNotificationService &&) = delete;
    ~DocumentNotificationService();

    boost::uuids::uuid
    getUuid() const;

    Common::PIConnection
    addListener(std::shared_ptr<Common::IListener<Common::Handle>> a_listener);

    void
    receiveMessage(const boost::uuids::uuid a_senderUuid, const Messages::ImageAdded &a_message);
  private:
    boost::uuids::uuid m_uuid;

    Common::PIConnection m_documentAddedMessagesConnection;

    Common::ListenerContainer<Common::Handle> m_documentAddedListeners;
  };
}

#endif
