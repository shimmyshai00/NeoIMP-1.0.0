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

#include <AbstractController/INewDocumentCommandObserver.hpp>
#include <AbstractController/ISaveDocumentCommandObserver.hpp>
#include <AbstractController/IExitCommandObserver.hpp>

#include <Windows/MainWindow.hpp>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  ApplicationView::ApplicationView()
    : m_mainWindow(new Windows::MainWindow)
  {
    m_newDocumentCommandNotifiableConn = QObject::connect(m_mainWindow, &Windows::MainWindow::newClicked, [=]() {
      m_newDocumentCommandNotifiable.notify();
    });

    m_saveDocumentCommandNotifiableConn = QObject::connect(m_mainWindow, &Windows::MainWindow::saveAsClicked, [=]() {
      m_saveDocumentCommandNotifiable.notify();
    });

    m_exitCommandNotifiableConn = QObject::connect(m_mainWindow, &Windows::MainWindow::exitClicked, [=]() {
      m_exitCommandNotifiable.notify();
    });
  }

  ApplicationView::~ApplicationView() {
    QObject::disconnect(m_newDocumentCommandNotifiableConn);
    QObject::disconnect(m_saveDocumentCommandNotifiableConn);
    QObject::disconnect(m_exitCommandNotifiableConn);
  }

  QPointer<Windows::MainWindow> ApplicationView::getQWidget() {
    return m_mainWindow;
  }

  void ApplicationView::show() {
    m_mainWindow->show();
  }

  void ApplicationView::close() {
    m_mainWindow->close();
  }

  Framework::IMVCObservable<> &ApplicationView::getNewDocumentCommandObservable() {
    return m_newDocumentCommandNotifiable;
  }

  Framework::IMVCObservable<> &ApplicationView::getSaveDocumentCommandObservable() {
    return m_saveDocumentCommandNotifiable;
  }

  Framework::IMVCObservable<> &ApplicationView::getExitCommandObservable() {
    return m_exitCommandNotifiable;
  }
}
