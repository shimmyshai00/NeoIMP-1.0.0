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

#include <INewDocumentCommandReceiver.hpp>
#include <IExitProgramCommandReceiver.hpp>

#include <Windows/MainWindow.hpp>

namespace SDF::UILayer::View::Qt {
  ApplicationView::ApplicationView()
    : m_newDocumentCommandReceiver(nullptr),
      m_exitProgramCommandReceiver(nullptr)
  {}

  QPointer<QWidget> ApplicationView::getQWidget() {
    return m_mainWindow.data();
  }

  void ApplicationView::setContextView(IQtView *contextView) {
    // N/A for this top-level view.
  }

  void ApplicationView::showApplicationView() {
    if(!m_mainWindow) {
      m_mainWindow = new Windows::MainWindow();

      QObject::connect(m_mainWindow, &Windows::MainWindow::newClicked, m_mainWindow, [=]() {
        if(m_newDocumentCommandReceiver != nullptr) m_newDocumentCommandReceiver->newDocument();
      });
      QObject::connect(m_mainWindow, &Windows::MainWindow::exitClicked, m_mainWindow, [=]() {
        if(m_exitProgramCommandReceiver != nullptr) m_exitProgramCommandReceiver->exitProgram();
      });
    }

    m_mainWindow->show();
  }

  void ApplicationView::closeApplicationView() {
    if(m_mainWindow) {
      m_mainWindow->close();
    }
  }

  void ApplicationView::setNewDocumentCommandReceiver(INewDocumentCommandReceiver *newDocumentCommandReceiver) {
    m_newDocumentCommandReceiver = newDocumentCommandReceiver;
  }

  void ApplicationView::setExitProgramCommandReceiver(IExitProgramCommandReceiver *exitProgramCommandReceiver) {
    m_exitProgramCommandReceiver = exitProgramCommandReceiver;
  }
}
