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

#include "safeConnect.hpp"

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
        m_imageHandle(imageHandle),
        m_renderingHandle(AbstractModel::HANDLE_INVALID)
    {}

    int getImageWidth() {
      return m_documentAccessService->getDocumentWidthPx(m_imageHandle);
    }

    int getImageHeight() {
      return m_documentAccessService->getDocumentHeightPx(m_imageHandle);
    }

    QImage getImageRegion(const QRect &rect) {
      if(m_renderingHandle == AbstractModel::HANDLE_INVALID) {
        // Render the image first.
        m_renderingHandle = m_documentRenderService->renderImage(m_imageHandle);
      }

      const unsigned char *origin;
      std::ptrdiff_t rowStride;

      m_documentRenderService->getRenderedRegion(origin, rowStride, m_renderingHandle,
                                                 rect.x(),
                                                 rect.y(),
                                                 rect.x() + rect.width() - 1,
                                                 rect.y() + rect.height() - 1
                                                );

      return QImage(origin, rect.width(), rect.height(), rowStride, QImage::Format_RGB32);
    }
  private:
    AbstractModel::IDocumentAccessService *m_documentAccessService;
    AbstractModel::IDocumentRenderService *m_documentRenderService;

    AbstractModel::Handle m_imageHandle;
    AbstractModel::Handle m_renderingHandle;
  };
}

namespace SDF::UILayer::Gui::Qt::View {
  DocumentView::DocumentView(AbstractModel::IDocumentAccessService *documentAccessService,
                             AbstractModel::IDocumentRenderService *documentRenderService,
                             AbstractModel::IDocumentViewConfigService *documentViewConfigService,
                             AbstractModel::IToolBasedEditingService *toolBasedEditingService,
                             AbstractModel::Handle handleToView,
                             QWidget *parent)
    : QWidget(parent),
      m_documentViewConfigService(documentViewConfigService),
      m_toolBasedEditingService(toolBasedEditingService),
      m_documentHandle(handleToView),
      m_layout(new QBoxLayout(QBoxLayout::TopToBottom, this)),
      m_documentWidget(new CustomWidgets::DocumentWidget(this)),
      m_imageDataSource(new ImageDataSource(documentAccessService, documentRenderService, handleToView))
  {
    m_layout->addWidget(m_documentWidget, 0);
    m_documentWidget->setDataSource(m_imageDataSource);

    // Synchronize the viewport parameters with the ones stored in the model.
    m_documentWidget->setCenterX(documentViewConfigService->getDocumentCenterX(handleToView));
    m_documentWidget->setCenterY(documentViewConfigService->getDocumentCenterY(handleToView));
    m_documentWidget->setMagnification(documentViewConfigService->getDocumentMagnification(handleToView));

    // Use the right tool cursor.
    m_documentWidget->setTool(m_toolBasedEditingService->getActiveTool());

    // Observe for tool changes.
    m_toolBasedEditingService->attachObserver(this);
    m_documentViewConfigService->attachObserver(this);

    // Observe for editing click events. NB: STUBchitecture only for simple tools now
    safeConnect(m_documentWidget, &CustomWidgets::DocumentWidget::editorClickedAt, [=](float docX, float docY) {
      m_toolBasedEditingService->beginToolApplication(m_documentHandle);
      m_toolBasedEditingService->applyToolAtPoint(docX, docY);
    });

    safeConnect(m_documentWidget, &CustomWidgets::DocumentWidget::editorClickReleasedAt, [=](float docX, float docY) {
      m_toolBasedEditingService->finishToolApplication();
    });
  }

  DocumentView::~DocumentView() {
    m_toolBasedEditingService->removeObserver(this);
    m_documentViewConfigService->removeObserver(this);
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

  AbstractModel::Handle
  DocumentView::getViewedDocumentHandle() const {
    return m_documentHandle;
  }

  // Private members.
  void
  DocumentView::handleEvent(std::shared_ptr<AbstractModel::Events::ToolEvent> event) {
    printf("GOT\n");
    if(auto p = dynamic_cast<AbstractModel::Events::ActiveToolChangedEvent *>(event.get())) {
      handleActiveToolChangedEvent(p);
    }
  }

  void
  DocumentView::handleActiveToolChangedEvent(AbstractModel::Events::ActiveToolChangedEvent *event) {
    printf("ST\n");
    m_documentWidget->setTool(event->newTool);
  }

  void
  DocumentView::handleEvent(std::shared_ptr<AbstractModel::Events::ViewportEvent> event) {
    if(auto p = dynamic_cast<AbstractModel::Events::ViewCenterChangedEvent *>(event.get())) {
      handleViewCenterChangedEvent(p);
    } else if(auto p = dynamic_cast<AbstractModel::Events::ViewMagnificationChangedEvent *>(event.get())) {
      handleViewMagnificationChangedEvent(p);
    }
  }

  void
  DocumentView::handleViewCenterChangedEvent(AbstractModel::Events::ViewCenterChangedEvent *event) {
    if(event->documentHandle == m_documentHandle) {
      printf("recenter to %f %f\n", event->centerX, event->centerY);
      m_documentWidget->setCenterX(event->centerX);
      m_documentWidget->setCenterY(event->centerY);
    }
  }

  void
  DocumentView::handleViewMagnificationChangedEvent(AbstractModel::Events::ViewMagnificationChangedEvent *event) {
    printf("Mag\n");
    printf("hdl: %d %d\n", event->documentHandle, m_documentHandle);
    if(event->documentHandle == m_documentHandle) {
      m_documentWidget->setMagnification(event->magnification);
    }
  }
}
