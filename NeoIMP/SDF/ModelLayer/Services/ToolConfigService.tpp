#ifndef SDF_MODELLAYER_SERVICES_TOOLCONFIGSERVICE_TPP
#define SDF_MODELLAYER_SERVICES_TOOLCONFIGSERVICE_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ToolConfigService.tpp
 * PURPOSE: Implements the ToolConfigService template.
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

#include <SDF/ModelLayer/AbstractData/IRepository.hpp>

namespace SDF::ModelLayer::Services {
  template<class ToolT>
  ToolConfigService<ToolT>::ToolConfigService(
    AbstractData::IRepository<AbstractDomain::ITool> *toolRepository,
    Interfaces::IMessageBroker<Events::RepositoryUpdate<AbstractDomain::ITool>> *broker,
    int subscriberUid
  )
    : m_subscriberUid(subscriberUid),
      m_toolRepository(toolRepository),
      m_broker(nullptr)
  {
    broker->addSubscriber(this);
  }

  template<class ToolT>
  ToolConfigService<ToolT>::~ToolConfigService() {
    m_broker->removeSubscriber(this);
  }

  // Protected member.
  template<class ToolT>
  void
  ToolConfigService<ToolT>::toolUpdated() {
    m_toolRepository->update(m_tool);
  }

  // Private members.
  template<class ToolT>
  int
  ToolConfigService<ToolT>::getUid() const {
    return m_subscriberUid;
  }

  template<class ToolT>
  void
  ToolConfigService<ToolT>::receiveMessage(
    std::shared_ptr<Events::RepositoryUpdate<AbstractDomain::ITool>> message
  ) {
    if(auto p = dynamic_cast<Events::Created<AbstractDomain::ITool> *>(message.get())) {
      handleCreateMessage(p);
    }
  }

  template<class ToolT>
  void
  ToolConfigService<ToolT>::handleCreateMessage(Events::Created<AbstractDomain::ITool> *message) {
    // Check if the object added to the repository is the desired tool.
    AbstractDomain::ITool *tool(m_toolRepository->retrieve(message->objectId));
    if(ToolT *specificTool = dynamic_cast<ToolT *>(tool)) {
      m_tool = specificTool;
    }
  }
}

#endif
