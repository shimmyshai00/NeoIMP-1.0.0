/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ToolBasedEditingService.cpp
 * PURPOSE: Implements the ToolBasedEditingService class.
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

#include <ToolBasedEditingService.hpp>

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

  ToolBasedEditingService::ToolBasedEditingService(AbstractData::IRepository<AbstractDomain::IImage> *imageRepository,
                                                   AbstractData::IRepository<AbstractDomain::ITool> *toolRepository,
                                                   AbstractDomain::IObjectMap<AbstractDomain::IImage,
                                                                              AbstractDomain::IDeltaEditor
                                                                             > *deltaEditorMap,
                                                   Interfaces::IFactory<AbstractDomain::ITool,
                                                                        Properties::Tool
                                                                       > *toolFactory,
                                                   Interfaces::IMessageBroker<AbstractDomain::Defs::ImageChange> *
                                                    messageBroker
                                                  )
    : m_imageRepository(imageRepository),
      m_toolRepository(toolRepository),
      m_deltaEditorMap(deltaEditorMap),
      m_broker(nullptr),
      m_activeTool(Properties::TOOL_MAX)
  {
    addTool(Properties::TOOL_ZOOM, toolFactory->create(Properties::TOOL_ZOOM));

    messageBroker->addPublisher(this);
  }

  ToolBasedEditingService::~ToolBasedEditingService() {
    m_broker->removePublisher(this);
  }

  void
  ToolBasedEditingService::attachObserver(Interfaces::IEventHandler<Events::ToolEvent> *observer) {
    m_observers.push_back(observer);
  }

  void
  ToolBasedEditingService::removeObserver(Interfaces::IEventHandler<Events::ToolEvent> *observer) {
    m_observers.erase(std::find(m_observers.begin(), m_observers.end(), observer));
  }

  Properties::Tool
  ToolBasedEditingService::getActiveTool() const {
    return m_activeTool;
  }

  void
  ToolBasedEditingService::setActiveTool(Properties::Tool tool) {
    m_activeTool = tool;

    std::shared_ptr<Events::ActiveToolChangedEvent> event(new Events::ActiveToolChangedEvent);
    event->newTool = tool;
    for(auto observer : m_observers) {
      observer->handleEvent(event);
    }
  }

  void
  ToolBasedEditingService::beginToolApplication(Handle handle) {
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
  ToolBasedEditingService::applyToolAtPoint(float x, float y) {
    if(m_toolIdMap.find(m_activeTool) != m_toolIdMap.end()) { // for unadded tools
      int toolId(m_toolIdMap[m_activeTool]);
      m_toolRepository->retrieve(toolId)->applyAt(x, y);
    }
  }

  void
  ToolBasedEditingService::finishToolApplication() {
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
  ToolBasedEditingService::getUid() const {
    return SERVICE_TOOL_BASED_EDITING;
  }

  void
  ToolBasedEditingService::receiveMessage(std::shared_ptr<AbstractDomain::Defs::ImageChange> message) {
    if(m_broker != nullptr) {
      m_broker->receiveMessage(this, message);
    }
  }

  void
  ToolBasedEditingService::setBroker(Interfaces::IMessageBroker<AbstractDomain::Defs::ImageChange> *broker) {
    m_broker = broker;
  }

  void
  ToolBasedEditingService::addTool(Properties::Tool toolLabel,
                                   std::unique_ptr<AbstractDomain::ITool> tool
                                  )
  {
    int toolId(tool->getId());

    m_toolRepository->create(std::move(tool));
    m_toolIdMap[toolLabel] = toolId;
  }
}
