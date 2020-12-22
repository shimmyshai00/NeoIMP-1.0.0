/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ApplicationView.cpp
 * PURPOSE: The Qt-based application view object. This just wraps the main window.
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
#include <Observers/IApplicationViewObserver.hpp>

#include <QObject>

#include <algorithm>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  ApplicationView::ApplicationView(QPointer<Windows::MainWindow> mainWindow)
    : m_mainWindow(mainWindow)
  {
    QObject::connect(m_mainWindow, &Windows::MainWindow::newClicked, [=]() {
      for(Observers::IApplicationViewObserver *observer : m_observers) observer->onNewDocumentCommand();
    });

    QObject::connect(m_mainWindow, &Windows::MainWindow::saveAsClicked, [=]() {
      for(Observers::IApplicationViewObserver *observer : m_observers) observer->onSaveDocumentAsCommand();
    });

    QObject::connect(m_mainWindow, &Windows::MainWindow::exitClicked, [=]() {
      for(Observers::IApplicationViewObserver *observer : m_observers) observer->onExitCommand();
    });
  }

  void ApplicationView::show() {
    m_mainWindow->show();
  }

  void ApplicationView::close() {
    m_mainWindow->close();
  }

  void ApplicationView::addObserver(Observers::IApplicationViewObserver *observer) {
    if(std::find(m_observers.begin(), m_observers.end(), observer) == m_observers.end()) {
      m_observers.push_back(observer);
    }
  }

  void ApplicationView::removeObserver(Observers::IApplicationViewObserver *observer) {
    m_observers.erase(std::find(m_observers.begin(), m_observers.end(), observer));
  }
}
