/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ApplicationView.cpp
 * PURPOSE: The Qt-based application view.
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

#include <Framework/MVCViewCast.hpp>

#include <Windows/MainWindow.hpp>

#include <ViewFactory.hpp>
#include <DocumentView.hpp>

#include <QObject>
#include <iostream>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  ApplicationView::ApplicationView(ViewFactory *viewFactory)
    : m_mainWindow(new Windows::MainWindow),
      m_documentTabs(new QTabWidget),
      m_viewFactory(viewFactory)
  {
    QObject::connect(m_mainWindow, &Windows::MainWindow::newClicked, [=]() { onNewClicked(); });
    QObject::connect(m_mainWindow, &Windows::MainWindow::saveAsClicked, [=]() { onSaveAsClicked(); });
    QObject::connect(m_mainWindow, &Windows::MainWindow::exitClicked, [=]() { onExitClicked(); });

    m_mainWindow->addPrincipalWidget(m_documentTabs);
    m_mainWindow->show();
  }

  ApplicationView::~ApplicationView() {
    m_mainWindow->close();
    delete m_mainWindow;
  }

  // Protected members.
  void
  ApplicationView::onChildAdded(MVCViewNode *child) {
    if(auto *v = dynamic_cast<DocumentView *>(child)) {
      // Add this document view to the tab widget.
      v->addToTabWidget(m_documentTabs);
    }
  }

  void
  ApplicationView::onChildRemoved(MVCViewNode *child) {}

  void
  ApplicationView::onAttachAppModel() {
    safeConnect(getAppModel()->onDocumentAdded, [=](AbstractAppModel::Handle handle) {
      getViewHierarchy().addChildAtEnd(Framework::MVCViewCast(m_viewFactory->createDocumentView(handle)));
    });
  }
}
