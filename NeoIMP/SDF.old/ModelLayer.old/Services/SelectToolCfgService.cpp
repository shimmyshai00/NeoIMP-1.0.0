/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SelectToolCfgService.cpp
 * PURPOSE: Implements the SelectToolCfgService class.
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

#include "SelectToolCfgService.hpp"

#include <AbstractData/IRepository.hpp>
#include <AbstractDomain/Tools/ISelectTool.hpp>
#include <AbstractDomain/ITool.hpp>

#include <BrokerId.hpp>

namespace SDF::ModelLayer::Services {
  SelectToolCfgService::SelectToolCfgService(
    AbstractData::IRepository<AbstractDomain::ITool> *toolRepository,
    Interfaces::IMessageBroker<Events::RepositoryUpdate<AbstractDomain::ITool>> *broker
  )
    : ToolConfigService(toolRepository, broker, SERVICE_SELECT_TOOL_CONFIG)
  {
  }

  void
  SelectToolCfgService::attachObserver(
    Interfaces::IEventHandler<UILayer::AbstractModel::Events::SelectToolEvent> *observer
  ) {
    m_observers.push_back(observer);
  }

  void
  SelectToolCfgService::removeObserver(
    Interfaces::IEventHandler<UILayer::AbstractModel::Events::SelectToolEvent> *observer
  ) {
    m_observers.erase(std::find(m_observers.begin(), m_observers.end(), observer));
  }

  void
  SelectToolCfgService::setMode(UILayer::AbstractModel::ToolConfig::Properties::SelectMode mode) {
    using UILayer::AbstractModel::Events::SelectToolModeChangedEvent;

    printf("sel mode changed to: %d\n", mode);

    m_tool->setMode(mode);
    toolUpdated();

    std::shared_ptr<SelectToolModeChangedEvent> event(new SelectToolModeChangedEvent);
    event->newMode = mode;

    for(auto obs : m_observers) {
      obs->handleEvent(event);
    }
  }

  UILayer::AbstractModel::ToolConfig::Properties::SelectMode
  SelectToolCfgService::getMode() const {
    return m_tool->getMode();
  }
}
