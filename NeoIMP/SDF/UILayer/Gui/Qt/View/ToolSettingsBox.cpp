/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ToolSettingsBox.cpp
 * PURPOSE: Implements the ToolSettingsBox class.
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

#include "ToolSettingsBox.hpp"

#include <AbstractModel/IToolApplicationService.hpp>

#include "ZoomToolConfigPane.hpp"

namespace SDF::UILayer::Gui::Qt::View {
  ToolSettingsBox::ToolSettingsBox(AbstractModel::IToolApplicationService *toolApplicationService,
                                   QWidget *parent
                                  )
    : QDockWidget("Tool Settings", parent),
      m_toolApplicationService(toolApplicationService)
  {
    addConfigPane(AbstractModel::Properties::TOOL_ZOOM, new ZoomToolConfigPane);

    m_toolApplicationService->attachObserver(this);
  }

  ToolSettingsBox::~ToolSettingsBox() {
    m_toolApplicationService->removeObserver(this);
  }

  IGuiElement *
  ToolSettingsBox::getParent() {
    if(auto p = dynamic_cast<IGuiElement *>(parentWidget())) {
      return p;
    } else {
      return nullptr;
    }
  }

  void
  ToolSettingsBox::show() {
    QDockWidget::show();
  }

  void
  ToolSettingsBox::close() {
    QDockWidget::close();
  }

  // Private members.
  void
  ToolSettingsBox::addConfigPane(AbstractModel::Properties::Tool tool, QWidget *pane) {
    m_configPanes[tool] = pane;
  }

  void
  ToolSettingsBox::handleEvent(std::shared_ptr<AbstractModel::Events::ToolEvent> event) {
    if(auto p = dynamic_cast<AbstractModel::Events::ActiveToolChangedEvent *>(event.get())) {
      handleActiveToolChangedEvent(p);
    }
  }

  void
  ToolSettingsBox::handleActiveToolChangedEvent(AbstractModel::Events::ActiveToolChangedEvent *event) {
    if(m_configPanes.find(event->newTool) != m_configPanes.end()) {
      printf("sw\n");
      setWidget(m_configPanes[event->newTool]);
    }
  }
}
