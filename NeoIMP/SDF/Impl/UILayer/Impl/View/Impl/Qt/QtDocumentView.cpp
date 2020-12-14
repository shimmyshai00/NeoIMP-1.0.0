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

#include <CustomWidgets/DocumentWidget.hpp>

#include <QApplication>

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
    CustomWidgets::DocumentWidget *documentWidget
  )
    : m_imageInformationService(imageInformationService),
      m_imageRenderingService(imageRenderingService),
      m_documentWidget(documentWidget),
      m_imageDataSource(nullptr)
  {}

  // nb: put under auspice of controller instead?
  void QtDocumentView::showDocument(ModelLayer::Handle handle) {
    m_imageDataSource = std::make_unique<ImageDataSource>(m_imageInformationService, m_imageRenderingService, handle);
    m_documentWidget->setDataSource(m_imageDataSource.get());
  }
}
