/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentView.cpp
 * PURPOSE: Implements the DocumentView class.
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

#include <AbstractModel/IDocumentAccessService.hpp>
#include <AbstractModel/IDocumentRenderService.hpp>
#include <AbstractModel/Handle.hpp>

#include <CustomWidgets/IImageDataSource.hpp>

namespace SDF::UILayer::Gui::Qt::View {
  // Helper object
  class ImageDataSource : public CustomWidgets::IImageDataSource {
  public:
    ImageDataSource(
      AbstractModel::IDocumentAccessService *documentAccessService,
      AbstractModel::IDocumentRenderService *documentRenderService,
      AbstractModel::Handle imageHandle
    ) : m_documentAccessService(documentAccessService),
        m_documentRenderService(documentRenderService),
        m_imageHandle(imageHandle)
    {}

    int getImageWidth() {
      return m_documentAccessService->getDocumentWidthPx(m_imageHandle);
    }

    int getImageHeight() {
      return m_documentAccessService->getDocumentHeightPx(m_imageHandle);
    }

    void accessImageData(const unsigned char *&origin,
                         std::ptrdiff_t &rowStride,
                         int x1, int y1, int x2, int y2
                        )
    {
      m_documentRenderService->getRenderedRegion(origin, rowStride, m_imageHandle, x1, y1, x2, y2);
    }
  private:
    AbstractModel::IDocumentAccessService *m_documentAccessService;
    AbstractModel::IDocumentRenderService *m_documentRenderService;

    AbstractModel::Handle m_imageHandle;
  };
}

namespace SDF::UILayer::Gui::Qt::View {
  DocumentView::DocumentView(AbstractModel::IDocumentAccessService *documentAccessService,
                             AbstractModel::IDocumentRenderService *documentRenderService,
                             AbstractModel::Handle handleToView,
                             QWidget *parent)
    : m_documentWidget(new CustomWidgets::DocumentWidget(this)),
      m_imageDataSource(new ImageDataSource(documentAccessService, documentRenderService, handleToView))
  {
    m_documentWidget->setDataSource(m_imageDataSource);
  }

  IGuiElement *
  DocumentView::getParent() {
    if(auto p = dynamic_cast<IGuiElement *>(parentWidget())) {
      return p;
    } else {
      return nullptr;
    }
  }

  void
  DocumentView::show() {
  }

  void
  DocumentView::close() {
  }
}
