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
#include <IExitCommandObserver.hpp>

#include <Windows/MainWindow.hpp>
#include <QtDocumentView.hpp>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  QtApplicationView::QtApplicationView() : m_exitCommandObserver(nullptr), m_newDocumentCommandObserver(nullptr) {}

  QPointer<QWidget> QtApplicationView::getQWidget() {
    return m_mainWindow.data();
  }

  void QtApplicationView::setContextView(IQtView *contextView) {
    // N/A for this top-level view.
  }

  void QtApplicationView::show() {
    if(!m_mainWindow) {
      m_mainWindow = new Windows::MainWindow();

      QWidget::connect(m_mainWindow, &Windows::MainWindow::newClicked, m_mainWindow, [=]() {
        if(this->m_newDocumentCommandObserver != nullptr) {
          this->m_newDocumentCommandObserver->onNewDocumentCommand();
        }
      });

      QWidget::connect(m_mainWindow, &Windows::MainWindow::exitClicked, m_mainWindow, [=]() {
        if(this->m_exitCommandObserver != nullptr) {
          this->m_exitCommandObserver->onExitCommand();
        }
      });
    }

    m_mainWindow->show();
  }

  void QtApplicationView::close() {
    if(m_mainWindow) {
      m_mainWindow->close();
    }
  }

  void QtApplicationView::setNewDocumentCommandObserver(INewDocumentCommandObserver *observer) {
    m_newDocumentCommandObserver = observer;
  }

  void QtApplicationView::setExitCommandObserver(IExitCommandObserver *observer) {
    m_exitCommandObserver = observer;
  }

  void QtApplicationView::addDocumentView(QtDocumentView *documentView) {
    m_mainWindow->addDocumentTab("Untitled", documentView->getQWidget().data());
  }
}
