/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Toolbox.cpp
 * PURPOSE: Implements the Toolbox class.
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

#include <Toolbox.hpp>

#include "QtResources/ui_Toolbox.h"

#include "../Events/ToolboxEvent.hpp"
#include "safeConnect.hpp"

#include "../Enum/ZoomToolMode.hpp"

#include <AbstractModel/ToolConfig/IZoomToolCfgService.hpp>

#include <QIcon>

namespace SDF::UILayer::Gui::Qt::View {
  Toolbox::Toolbox(AbstractModel::ToolConfig::IZoomToolCfgService *zoomToolCfgService,
                   std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> controller,
                   QWidget *parent
                  )
    : QDockWidget(parent),
      m_zoomToolCfgService(zoomToolCfgService),
      m_ui(new Ui::Toolchest),
      m_controller(std::move(controller))
  {
    m_ui->setupUi(this);

    // Hook tool buttons.
    safeConnect(static_cast<QAbstractButton *>(m_ui->selectionButton), &QAbstractButton::toggled, [=](bool checked) {
      if(checked) { m_controller->handleEvent(std::make_shared<Events::SelectToolSelectedEvent>()); }
    });

    safeConnect(static_cast<QAbstractButton *>(m_ui->zoomButton), &QAbstractButton::toggled, [=](bool checked) {
      if(checked) { m_controller->handleEvent(std::make_shared<Events::ZoomToolSelectedEvent>()); }
    });

    safeConnect(static_cast<QAbstractButton *>(m_ui->cageButton), &QAbstractButton::toggled, [=](bool checked) {
      if(checked) { m_controller->handleEvent(std::make_shared<Events::CageTransformToolSelectedEvent>()); }
    });

    // Create tool menus.
    m_ui->zoomButton->addToolMode(Enum::ZOOM_IN, QIcon(":/icons/Icons/magnifier_plus.png"), "Zoom In");
    m_ui->zoomButton->addToolMode(Enum::ZOOM_OUT, QIcon(":/icons/Icons/magnifier_minus.png"), "Zoom Out");
    m_ui->zoomButton->addToolMode(Enum::ZOOM_EQUAL, QIcon(":/icons/Icons/magnifier_equals.png"), "Zoom to 100%");

    // Hook menu events.
    safeConnect(m_ui->zoomButton, &CustomWidgets::ToolButtonWidget::modeSelected, [=](int mode) {
      std::shared_ptr<Events::ZoomToolModeChangeEvent> event(new Events::ZoomToolModeChangeEvent);
      event->newMode = static_cast<Enum::ZoomToolMode>(mode);

      m_controller->handleEvent(event);
    });

    // Observe model layer for events.
    m_zoomToolCfgService->attachObserver(this);
  }

  Toolbox::~Toolbox() {
    m_zoomToolCfgService->removeObserver(this);

    delete m_ui;
  }

  IGuiElement *
  Toolbox::getParent() {
    if(auto p = dynamic_cast<IGuiElement *>(parentWidget())) {
      return p;
    } else {
      return nullptr;
    }
  }

  void
  Toolbox::show() {
  }

  void
  Toolbox::close() {
  }

  // Private members.
  void
  Toolbox::handleEvent(std::shared_ptr<AbstractModel::Events::ZoomToolEvent> event) {
    if(auto e = dynamic_cast<AbstractModel::Events::ZoomToolModeChangedEvent *>(event.get())) {
      handleZoomToolModeChangedEvent(e);
    }
  }

  void
  Toolbox::handleZoomToolModeChangedEvent(AbstractModel::Events::ZoomToolModeChangedEvent *event) {
    m_ui->zoomButton->setToolMode(event->newMode);
  }
}
