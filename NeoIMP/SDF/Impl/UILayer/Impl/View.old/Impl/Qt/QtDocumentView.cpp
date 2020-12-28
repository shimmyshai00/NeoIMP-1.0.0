/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    QtDocumentView.cpp
 * PURPOSE: The Qt-based document view implementation.
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

#include <QtDocumentView.hpp>

#include <AbstractModel/Services/IImageInformationService.hpp>
#include <AbstractModel/Services/IImageRenderingService.hpp>
#include <CustomWidgets/IImageDataSource.hpp>
#include <AbstractController/IDocumentGainFocusObserver.hpp>

#include <Windows/MainWindow.hpp>
#include <CustomWidgets/DocumentWidget.hpp>

#include <QString>

#include <iostream>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  // Helper object
  class ImageDataSource : public CustomWidgets::IImageDataSource {
  public:
    ImageDataSource(
      AbstractModel::Services::IImageInformationService *imageInformationService,
      AbstractModel::Services::IImageRenderingService *imageRenderingService,
      ModelLayer::Handle imageHandle
    ) : m_imageInformationService(imageInformationService),
        m_imageRenderingService(imageRenderingService),
        m_imageHandle(imageHandle)
    {}

    int getImageWidth() {
      return m_imageInformationService->getImageWidth(m_imageHandle);
    }

    int getImageHeight() {
      return m_imageInformationService->getImageHeight(m_imageHandle);
    }

    const unsigned char *accessImageData(int x1, int y1, int x2, int y2) {
      return m_imageRenderingService->renderImageRegion(m_imageHandle, x1, y1, x2, y2);
    }
  private:
    AbstractModel::Services::IImageInformationService *m_imageInformationService;
    AbstractModel::Services::IImageRenderingService *m_imageRenderingService;

    ModelLayer::Handle m_imageHandle;
  };
}

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  QtDocumentView::QtDocumentView(
    AbstractModel::Services::IImageInformationService *imageInformationService,
    AbstractModel::Services::IImageRenderingService *imageRenderingService,
    Windows::MainWindow *mainWindow,
    CustomWidgets::DocumentWidget *documentWidget,
    int documentTabIndex,
    ModelLayer::Handle documentHandle
  )
    : m_imageInformationService(imageInformationService),
      m_imageRenderingService(imageRenderingService),
      m_mainWindow(mainWindow),
      m_documentWidget(documentWidget),
      m_documentTabIndex(documentTabIndex),
      m_imageDataSource(new ImageDataSource(imageInformationService, imageRenderingService, documentHandle)),
      m_documentGainFocusObserver(nullptr)
  {
    updateDocumentName(m_imageInformationService->getImageName(documentHandle));
    m_documentWidget->setDataSource(m_imageDataSource.get());

    m_documentGainFocusObserverConn = Windows::MainWindow::connect(
      m_mainWindow,
      &Windows::MainWindow::focusTabChanged,
      [=](int index) {
        if(index == m_documentTabIndex) {
          m_documentGainFocusObserver->onDocumentGainedFocus(documentHandle);
        }
      }
    );
  }

  QtDocumentView::~QtDocumentView() {
    Windows::MainWindow::disconnect(m_documentGainFocusObserverConn);
    m_documentWidget->setDataSource(nullptr);
  }

  void QtDocumentView::updateDocumentName(std::string documentName) {
    m_mainWindow->setTabTitle(m_documentTabIndex, QString(documentName.c_str()));
  }

  void QtDocumentView::setDocumentGainFocusObserver(AbstractController::IDocumentGainFocusObserver *observer) {
    m_documentGainFocusObserver = observer;
  }
}
