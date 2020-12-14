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

#include <INewDocumentCommandObserver.hpp>
#include <AbstractController/ISaveDocumentCommandReceiver.hpp>
#include <IExitCommandObserver.hpp>

#include <Windows/MainWindow.hpp>

#include <QApplication>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  QtApplicationView::QtApplicationView(Windows::MainWindow *mainWindow)
    : m_mainWindow(mainWindow),
      m_exitCommandObserver(nullptr),
      m_newDocumentCommandObserver(nullptr),
      m_saveDocumentCommandReceiver(nullptr)
  {
    m_newDocumentCommandObserverConn = QObject::connect(m_mainWindow, &Windows::MainWindow::newClicked, qApp, [=]() {
      if(this->m_newDocumentCommandObserver != nullptr) {
        this->m_newDocumentCommandObserver->onNewDocumentCommand();
      }
    });

    m_saveDocumentCommandReceiverConn = QObject::connect(m_mainWindow, &Windows::MainWindow::saveAsClicked, qApp, [=] {
      if(this->m_saveDocumentCommandReceiver != nullptr) {
        this->m_saveDocumentCommandReceiver->onSaveDocumentCommand();
      }
    });

    m_exitCommandObserverConn = QObject::connect(m_mainWindow, &Windows::MainWindow::exitClicked, qApp, [=]() {
      if(this->m_exitCommandObserver != nullptr) {
        this->m_exitCommandObserver->onExitCommand();
      }
    });
  }

  QtApplicationView::~QtApplicationView() {
    QObject::disconnect(m_newDocumentCommandObserverConn);
    QObject::disconnect(m_saveDocumentCommandReceiverConn);
    QObject::disconnect(m_exitCommandObserverConn);
  }

  void QtApplicationView::show() {
    m_mainWindow->show();
  }

  void QtApplicationView::close() {
    m_mainWindow->close();
  }

  void QtApplicationView::setNewDocumentCommandObserver(INewDocumentCommandObserver *observer) {
    m_newDocumentCommandObserver = observer;
  }

  void QtApplicationView::setSaveDocumentCommandReceiver(AbstractController::ISaveDocumentCommandReceiver *receiver) {
    m_saveDocumentCommandReceiver = receiver;
  }

  void QtApplicationView::setExitCommandObserver(IExitCommandObserver *observer) {
    m_exitCommandObserver = observer;
  }
}
