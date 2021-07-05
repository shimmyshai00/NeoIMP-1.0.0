/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainWindow.hpp
 * PURPOSE: Implements the MainWindow class.
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

#include "MainWindow.hpp"

#include "QtResources/ui_MainWindow.h"
#include "safeConnect.hpp"

namespace SDF::UILayer::QtApplication::View {
  MainWindow::MainWindow(std::unique_ptr<Controller::IController<Events::MainWindowEvent>> controller,
                         QWidget *parent
                        )
    : QMainWindow(parent),
      m_ui(new Ui::MainWindow),
      m_controller(std::move(controller))
  {
    m_ui->setupUi(this);

    safeConnect(m_ui->actionE_xit, &QAction::triggered, m_controller.get(), new Events::MainWindowExitMenuEvent);
  }

  QMainWindow *
  MainWindow::getQWidget() {
    return this;
  }
}
