#ifndef SDF_UILAYER_QT_VIEW_MAINWINDOW_HPP
#define SDF_UILAYER_QT_VIEW_MAINWINDOW_HPP

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

#include "../../../Pattenrns/IListener.hpp"
#include "Hook.hpp"

#include <QMainWindow>
#include <QAction>

#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace SDF::UILayer::Qt::View {
  // Class:      MainWindow
  // Purpose:    Defines the app's main window.
  // Parameters: None.
  class MainWindow : public QMainWindow {
    Q_OBJECT
  public:
    MainWindow(QObject *parent = nullptr);

    // Controller hooks.
    void
    hookNewMenuItem(std::unique_ptr<Patterns::IListener<bool>> controller);

    void
    hookExitMenuItem(std::unique_ptr<Patterns::IListener<bool>> controller);
  private:
    Ui::MainWindow *m_ui;

    QMetaObject::connection m_newMenuConn;
    QMetaObject::connection m_exitMenuConn;
  };
}

#endif
