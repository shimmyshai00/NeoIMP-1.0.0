#ifndef SDF_UILAYER_GUI_VIEW_QT_MAINWINDOW_HPP
#define SDF_UILAYER_GUI_VIEW_QT_MAINWINDOW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainWindow.hpp
 * PURPOSE: Defines the MainWindow class.
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

#include "../../../../Patterns/IConnection.hpp"
#include "../../Controller/IGuiController.hpp"
#include "../IMainWindow.hpp"
#include "IQtView.hpp"

#include "../../Controller/MainWindow/Exit.hpp"
#include "QtView.hpp"
#include "QtEvent.hpp"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace SDF::UILayer::Gui::View::Qt {
  // Class:      MainWindow
  // Purpose:    Implements the main window using Qt.
  // Parameters: None.
  class MainWindow : public QtView<QMainWindow>, public IMainWindow {
    Q_OBJECT
  public:
    MainWindow(IQtView *parent = nullptr);
    ~MainWindow();

    std::string
    getViewId() const { return "MainWindow"; }

    Patterns::PIConnection
    hookOnExit(std::unique_ptr<Mvc::IController<>> controller);
  private:
    Ui::MainWindow *m_ui;

    QtEvent<> m_onExitEvent;
  public:
    // Factory method.
    static MainWindow *create(IQtView *parent,
                              Controller::IGuiController *guiController
                             )
    {
      MainWindow *rv(new MainWindow(nullptr));

      std::unique_ptr<Mvc::IController<>> onExitController
        (new Controller::MainWindow::Exit(guiController));

      rv->hookOnExit(std::move(onExitController))->connect();

      return rv;
    }
  };
}

#endif
