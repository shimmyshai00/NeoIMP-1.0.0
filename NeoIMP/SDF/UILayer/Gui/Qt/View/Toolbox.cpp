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

namespace SDF::UILayer::Gui::Qt::View {
  Toolbox::Toolbox(std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> controller,
                   QWidget *parent
                  )
    : QDockWidget(parent),
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
  }

  Toolbox::~Toolbox() {
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
}
