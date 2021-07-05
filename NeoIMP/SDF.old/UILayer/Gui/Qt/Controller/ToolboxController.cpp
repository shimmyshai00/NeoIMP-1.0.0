/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ToolboxController.hpp
 * PURPOSE: Implements the ToolboxController class.
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

#include <ToolboxController.hpp>

#include <AbstractModel/ToolConfig/IZoomToolCfgService.hpp>

#include <AbstractModel/IToolApplicationService.hpp>

namespace SDF::UILayer::Gui::Qt::Controller {
  ToolboxController::ToolboxController(AbstractModel::ToolConfig::IZoomToolCfgService *zoomToolCfgService,
                                       AbstractModel::IToolApplicationService *toolApplicationService
                                      )
    : m_zoomToolCfgService(zoomToolCfgService),
      m_toolApplicationService(toolApplicationService)
  {
  }

  void
  ToolboxController::handleEvent(std::shared_ptr<Events::GuiEvent> event) {
    printf("TBC\n");
    if(auto p = dynamic_cast<Events::SelectToolSelectedEvent *>(event.get())) { handleSelectToolSelectedEvent(p); }
    else if(auto p = dynamic_cast<Events::ZoomToolSelectedEvent *>(event.get())) { handleZoomToolSelectedEvent(p); }
    else if(auto p = dynamic_cast<Events::CageTransformToolSelectedEvent *>(event.get())) {
      handleCageTransformToolSelectedEvent(p);
    }
    else if(auto p = dynamic_cast<Events::ZoomToolModeChangeEvent *>(event.get())) { handleZoomToolModeChangeEvent(p); }
  }

  // Private members.
  void
  ToolboxController::handleSelectToolSelectedEvent(Events::SelectToolSelectedEvent *event) {
    m_toolApplicationService->setActiveTool(AbstractModel::Properties::TOOL_SELECT);
  }

  void
  ToolboxController::handleZoomToolSelectedEvent(Events::ZoomToolSelectedEvent *event) {
    m_toolApplicationService->setActiveTool(AbstractModel::Properties::TOOL_ZOOM);
  }

  void
  ToolboxController::handleCageTransformToolSelectedEvent(Events::CageTransformToolSelectedEvent *event) {
    m_toolApplicationService->setActiveTool(AbstractModel::Properties::TOOL_CAGE);
  }

  void
  ToolboxController::handleZoomToolModeChangeEvent(Events::ZoomToolModeChangeEvent *event) {
    using namespace AbstractModel::ToolConfig;

    if(event->newMode == Enum::ZOOM_IN) {
      m_zoomToolCfgService->setMode(Properties::ZOOM_IN);
    } else if(event->newMode == Enum::ZOOM_OUT) {
      m_zoomToolCfgService->setMode(Properties::ZOOM_OUT);
    } else if(event->newMode == Enum::ZOOM_EQUAL) {
      m_zoomToolCfgService->setMode(Properties::ZOOM_EQUAL);
    }
  }
}
