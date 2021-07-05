/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ToolApplicationService.cpp
 * PURPOSE: Implements the ToolApplicationService class.
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

#include <ToolApplicationService.hpp>

#include <ModelLayer/Exceptions/Exceptions.hpp>
#include <DataLayer/Exceptions/Exceptions.hpp>

#include <AbstractData/IRepository.hpp>
#include <AbstractDomain/IObjectMap.hpp>

#include <AbstractDomain/IImage.hpp>
#include <AbstractDomain/ITool.hpp>
#include <AbstractDomain/IDeltaEditor.hpp>
#include <AbstractDomain/IImageDelta.hpp>

#include "BrokerId.hpp"

namespace SDF::ModelLayer::Services {
  using namespace UILayer::AbstractModel;

  ToolApplicationService::ToolApplicationService(AbstractData::IRepository<AbstractDomain::IImage> *imageRepository,
                                                 AbstractData::IRepository<AbstractDomain::ITool> *toolRepository,
                                                 AbstractDomain::IObjectMap<AbstractDomain::IImage,
                                                                            AbstractDomain::IDeltaEditor
                                                                           > *deltaEditorMap,
                                                 Interfaces::IFactory<AbstractDomain::ITool,
                                                                      Properties::Tool
                                                                     > *toolFactory,
                                                 Interfaces::IMessageBroker<AbstractDomain::Defs::ImageChange> *
                                                  imageChangeBroker,
                                                 Interfaces::IMessageBroker<
                                                  Events::RepositoryUpdate<AbstractDomain::ITool>
                                                 > *toolCreateBroker
                                                )
    : m_imageRepository(imageRepository),
      m_toolRepository(toolRepository),
      m_deltaEditorMap(deltaEditorMap),
      m_imageChangeBroker(nullptr),
      m_toolCreateBroker(nullptr),
      m_activeTool(Properties::TOOL_MAX)
  {
    imageChangeBroker->addPublisher(this);
    toolCreateBroker->addPublisher(this);

    addTool(Properties::TOOL_ZOOM, toolFactory->create(Properties::TOOL_ZOOM));
  }

  ToolApplicationService::~ToolApplicationService() {
    m_imageChangeBroker->removePublisher(this);
    m_toolCreateBroker->removePublisher(this);
  }

  void
  ToolApplicationService::attachObserver(
    Interfaces::IEventHandler<UILayer::AbstractModel::Events::ToolEvent> *observer
  ) {
    m_observers.push_back(observer);
  }

  void
  ToolApplicationService::removeObserver(
    Interfaces::IEventHandler<UILayer::AbstractModel::Events::ToolEvent> *observer
  ) {
    m_observers.erase(std::find(m_observers.begin(), m_observers.end(), observer));
  }

  Properties::Tool
  ToolApplicationService::getActiveTool() const {
    return m_activeTool;
  }

  void
  ToolApplicationService::setActiveTool(Properties::Tool tool) {
    m_activeTool = tool;

    std::shared_ptr<UILayer::AbstractModel::Events::ActiveToolChangedEvent>
      event(new UILayer::AbstractModel::Events::ActiveToolChangedEvent);

    event->newTool = tool;
    for(auto observer : m_observers) {
      observer->handleEvent(event);
    }
  }

  void
  ToolApplicationService::beginToolApplication(Handle handle) {
    try {
      if(m_toolIdMap.find(m_activeTool) != m_toolIdMap.end()) { // for unadded tools
        int toolId(m_toolIdMap[m_activeTool]);
        AbstractDomain::IImage *imageDocument(m_imageRepository->retrieve(handle));

        m_toolRepository->retrieve(toolId)->beginApplication(imageDocument);
      }
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  void
  ToolApplicationService::applyToolAtPoint(float x, float y) {
    if(m_toolIdMap.find(m_activeTool) != m_toolIdMap.end()) { // for unadded tools
      int toolId(m_toolIdMap[m_activeTool]);
      m_toolRepository->retrieve(toolId)->applyAt(x, y);
    }
  }

  void
  ToolApplicationService::finishToolApplication() {
    if(m_toolIdMap.find(m_activeTool) != m_toolIdMap.end()) { // for unadded tools
      int toolId(m_toolIdMap[m_activeTool]);
      std::pair<AbstractDomain::IImage *, std::unique_ptr<AbstractDomain::IImageDelta>>
        delta(m_toolRepository->retrieve(toolId)->commit());

      // Apply the delta to the given image via the delta editor, passing the messages describing the edits on to the
      // broker.
      m_deltaEditorMap->get(delta.first)->applyDelta(std::move(delta.second), this);
    }
  }

  // Private members.
  int
  ToolApplicationService::getUid() const {
    return SERVICE_TOOL_BASED_EDITING;
  }

  void
  ToolApplicationService::receiveMessage(std::shared_ptr<AbstractDomain::Defs::ImageChange> message) {
    if(m_imageChangeBroker != nullptr) {
      m_imageChangeBroker->receiveMessage(this, message);
    }
  }

  void
  ToolApplicationService::setBroker(Interfaces::IMessageBroker<AbstractDomain::Defs::ImageChange> *broker) {
    m_imageChangeBroker = broker;
  }

  void
  ToolApplicationService::setBroker(
    Interfaces::IMessageBroker<Events::RepositoryUpdate<AbstractDomain::ITool>> *broker
  ) {
    m_toolCreateBroker = broker;
  }

  void
  ToolApplicationService::addTool(Properties::Tool toolLabel,
                                  std::unique_ptr<AbstractDomain::ITool> tool
                                 )
  {
    int toolId(tool->getId());

    m_toolRepository->create(std::move(tool));
    m_toolIdMap[toolLabel] = toolId;

    // Inform of the change in the repository.
    std::shared_ptr<Events::Created<AbstractDomain::ITool>> message(new Events::Created<AbstractDomain::ITool>);
    message->objectId = toolId;
    m_toolCreateBroker->receiveMessage(this, message);
  }
}
