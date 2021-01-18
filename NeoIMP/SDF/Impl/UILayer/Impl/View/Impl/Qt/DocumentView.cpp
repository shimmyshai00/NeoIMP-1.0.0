/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentView.cpp
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

#include <DocumentView.hpp>

/*
#include <Framework/MVCMessageEncoder.hpp>

#include <AbstractModel/Services/IImageInformationService.hpp>
#include <AbstractModel/Services/IImageRenderingService.hpp>
*/

#include <Windows/MainWindow.hpp>
#include <AbstractModel/Handle.hpp>

/*
#include <Controller/Messages.hpp>
*/

#include <CustomWidgets/DocumentWidget.hpp>
#include <CustomWidgets/IImageDataSource.hpp>

/*
namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  // Helper object
  class ImageDataSource : public CustomWidgets::IImageDataSource {
  public:
    ImageDataSource(
      AbstractModel::Services::IImageInformationService *imageInformationService,
      AbstractModel::Services::IImageRenderingService *imageRenderingService,
      AbstractModel::Handle imageHandle
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

    AbstractModel::Handle m_imageHandle;
  };
}
*/

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  DocumentView::DocumentView(AbstractAppModel::DocumentHandle handle)
    : m_documentWidget(new CustomWidgets::DocumentWidget)
  {}

  DocumentView::~DocumentView() {}

  void DocumentView::connectToModelObservables(AbstractAppModel::EditorModelObservables &observables) {}

  void DocumentView::addToTabWidget(QPointer<QTabWidget> tabWidget) {
    if(!m_tabWidget) {
      // TBA
      m_tabWidget = tabWidget;
      m_tabWidget->addTab(new QWidget(), "Doc");
    }
  }
}
