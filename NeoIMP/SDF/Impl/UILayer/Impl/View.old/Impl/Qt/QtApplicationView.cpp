/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    QtApplicationView.cpp
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

#include <QtApplicationView.hpp>

#include <AbstractController/INewDocumentCommandObserver.hpp>
#include <AbstractController/ISaveDocumentCommandObserver.hpp>
#include <AbstractController/IExitCommandObserver.hpp>

#include <Windows/MainWindow.hpp>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  QtApplicationView::QtApplicationView(Windows::MainWindow *mainWindow)
    : m_mainWindow(mainWindow),
      m_newDocumentCommandObserver(nullptr),
      m_saveDocumentCommandObserver(nullptr),
      m_exitCommandObserver(nullptr)
  {
    m_newDocumentCommandObserverConn = QObject::connect(m_mainWindow, &Windows::MainWindow::newClicked, [=]() {
      if(this->m_newDocumentCommandObserver != nullptr) {
        this->m_newDocumentCommandObserver->onNewDocumentCommand();
      }
    });

    m_saveDocumentCommandObserverConn = QObject::connect(m_mainWindow, &Windows::MainWindow::saveAsClicked, [=]() {
      if(this->m_saveDocumentCommandObserver != nullptr) {
        this->m_saveDocumentCommandObserver->onSaveDocumentCommand();
      }
    });

    m_exitCommandObserverConn = QObject::connect(m_mainWindow, &Windows::MainWindow::exitClicked, [=]() {
      if(this->m_exitCommandObserver != nullptr) {
        this->m_exitCommandObserver->onExitCommand();
      }
    });
  }

  QtApplicationView::~QtApplicationView() {
    QObject::disconnect(m_newDocumentCommandObserverConn);
    QObject::disconnect(m_saveDocumentCommandObserverConn);
    QObject::disconnect(m_exitCommandObserverConn);
  }

  void QtApplicationView::show() {
    m_mainWindow->show();
  }

  void QtApplicationView::close() {
    m_mainWindow->close();
  }

  void QtApplicationView::setNewDocumentCommandObserver(AbstractController::INewDocumentCommandObserver *observer) {
    m_newDocumentCommandObserver = observer;
  }

  void QtApplicationView::setSaveDocumentCommandObserver(AbstractController::ISaveDocumentCommandObserver *receiver) {
    m_saveDocumentCommandObserver = receiver;
  }

  void QtApplicationView::setExitCommandObserver(AbstractController::IExitCommandObserver *observer) {
    m_exitCommandObserver = observer;
  }
}
