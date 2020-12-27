/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentView.cpp
 * PURPOSE: The Qt-based document view object.
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

#include <DocumentView.hpp>

/*#include <Observers/IApplicationViewObserver.hpp>*/
#include <AbstractModel/Services/IImageInformationService.hpp>
#include <AbstractModel/Services/IImageRenderingService.hpp>

#include <Windows/MainWindow.hpp>
#include <CustomWidgets/DocumentWidget.hpp>
#include <ModelImageDataSource.hpp>

#include <QObject>

#include <algorithm>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  DocumentView::DocumentView(
    AbstractModel::Services::IImageInformationService *imageInformationService,
    AbstractModel::Services::IImageRenderingService *imageRenderingService,
    QPointer<Windows::MainWindow> mainWindow,
    QPointer<CustomWidgets::DocumentWidget> documentWidget,
    ModelLayer::Handle documentHandle
  )
    : m_mainWindow(mainWindow),
      m_documentWidget(documentWidget),
      m_dataSource(new ModelImageDataSource(imageInformationService, imageRenderingService, documentHandle))
  {
    /*
    QObject::connect(m_mainWindow, &Windows::MainWindow::newClicked, [=]() {
      for(Observers::IApplicationViewObserver *observer : m_observers) observer->onNewDocumentCommand();
    });

    QObject::connect(m_mainWindow, &Windows::MainWindow::saveAsClicked, [=]() {
      for(Observers::IApplicationViewObserver *observer : m_observers) observer->onSaveDocumentAsCommand();
    });

    QObject::connect(m_mainWindow, &Windows::MainWindow::exitClicked, [=]() {
      for(Observers::IApplicationViewObserver *observer : m_observers) observer->onExitCommand();
    });
    */

    m_documentWidget->setDataSource(m_dataSource.get());
    int index(m_mainWindow->getDocumentTabIndex(m_documentWidget));
    m_mainWindow->setTabTitle(index, imageInformationService->getImageName(documentHandle).c_str());
  }

  DocumentView::~DocumentView() {
    m_documentWidget->setDataSource(nullptr);
  }

  void DocumentView::updateDocumentTitle(std::string newDocumentTitle) {
    int index(m_mainWindow->getDocumentTabIndex(m_documentWidget));
    m_mainWindow->setTabTitle(index, newDocumentTitle.c_str());
  }
}
