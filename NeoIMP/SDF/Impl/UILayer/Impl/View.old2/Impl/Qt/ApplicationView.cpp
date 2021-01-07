/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ApplicationView.cpp
 * PURPOSE: Implementation of the ApplicationView class.
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

#include <ApplicationView.hpp>

#include <Windows/MainWindow.hpp>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  ApplicationView::ApplicationView()
    : m_mainWindow(new Windows::MainWindow)
  {
    using namespace Windows;
    using namespace Events;

    QObject::connect(m_mainWindow, &MainWindow::newClicked, [=]() { notifyObservers(COMMAND_NEW); });
    QObject::connect(m_mainWindow, &MainWindow::saveAsClicked, [=]() { notifyObservers(COMMAND_SAVE_AS); });
    QObject::connect(m_mainWindow, &MainWindow::exitClicked, [=]() { notifyObservers(COMMAND_EXIT); });
  }

  Windows::MainWindow *ApplicationView::getPresentation() {
    return m_mainWindow;
  }

  void ApplicationView::show() {
    m_mainWindow->show();
  }

  void ApplicationView::close() {
    m_mainWindow->close();
  }
}
