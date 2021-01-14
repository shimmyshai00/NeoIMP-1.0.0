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

#include <UILayer/Exceptions/Exceptions.hpp>

#include <Windows/MainWindow.hpp>
#include <Events/Events.hpp>

#include <DocumentView.hpp>

#include <QObject>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  ApplicationView::ApplicationView()
    : m_mainWindow(new Windows::MainWindow),
      m_documentTabs(new QTabWidget)
  {
    // Hook events.
    QObject::connect(m_mainWindow, &Windows::MainWindow::newClicked, [=]() {
      dispatchEvent(Framework::MVCViewEvent { Events::NewCommand, 0 });
    });

    QObject::connect(m_mainWindow, &Windows::MainWindow::exitClicked, [=]() {
      dispatchEvent(Framework::MVCViewEvent { Events::ExitCommand, 0 });
    });

    m_mainWindow->addPrincipalWidget(m_documentTabs);
  }

  ApplicationView::~ApplicationView() {
    delete m_mainWindow;
  }

  void ApplicationView::show() {
    m_mainWindow->show();
  }

  void ApplicationView::close() {
    m_mainWindow->close();
  }

  void ApplicationView::addDocumentView(std::unique_ptr<BaseDocumentView> documentView) {
    // NB: don't like the use of downcast here, but it seems unavoidable without making the code messier
    auto *qtDocumentView = dynamic_cast<Qt::DocumentView *>(documentView.get());
    if(qtDocumentView == nullptr) {
      throw UILayer::Exceptions::IncompatibleWidgetSystemException("Qt");
    } else {
      qtDocumentView->addToTabWidget(m_documentTabs);
    }

    // Absorb the document view into this view's view hierarchy.
    attachChild(std::move(documentView));
  }
}
