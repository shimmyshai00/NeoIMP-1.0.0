/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainWindow.cpp
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

#include "../../Controller/MainWindow/OnExit.hpp"

#include "Resources/ui_MainWindow.h"

namespace SDF::UILayer::Gui::View::Qt {
  MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_ui(new Ui::MainWindow)
  {
    m_ui->setupUi(this);

    connect(m_ui->actionE_xit, &QAction::triggered, [&](){ m_onExit.trigger(); });
  }

  MainWindow::~MainWindow() {
    delete m_ui;
  }

  Common::PIConnection
  MainWindow::hookOnExit(std::unique_ptr<IController<>> controller) {
    return m_onExit.hook(std::move(controller));
  }
}

namespace SDF::UILayer::Gui::View::Qt {
  MainWindow *
  MainWindowFactory::create(IViewManager<EViewType> *viewManager) {
    MainWindow *rv = new MainWindow();

    rv->hookOnExit(std::unique_ptr<IController<>>(new Controller::MainWindow::OnExit(viewManager)))
      ->connect();

    return rv;
  }
}