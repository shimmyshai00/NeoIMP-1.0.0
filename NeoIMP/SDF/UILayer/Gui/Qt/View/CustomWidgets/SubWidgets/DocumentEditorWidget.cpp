/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentEditorWidget.cpp
 * PURPOSE: Implementation of the custom Qt UI widget that provides the interactive pane for editing the document. This
 *          layers the image together with various editing decals.
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

#include <DocumentEditorWidget.hpp>

#include <EditViewWidget/ImageDisplayWidget.hpp>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets::SubWidgets {
  DocumentEditorWidget::DocumentEditorWidget(QWidget *parent)
    : m_imageDisplayWidget(new EditViewWidget::ImageDisplayWidget()),
      m_stackedLayout(new QStackedLayout(this))
  {
    m_stackedLayout->setStackingMode(QStackedLayout::StackAll);
    m_stackedLayout->addWidget(m_imageDisplayWidget);
  }

  void
  DocumentEditorWidget::setDataSource(IImageDataSource *dataSource) {
    m_imageDisplayWidget->setDataSource(dataSource);
    update();
  }

  QPointF
  DocumentEditorWidget::translate() const {
    return m_imageDisplayWidget->translate();
  }

  float
  DocumentEditorWidget::zoom() const {
    return m_imageDisplayWidget->zoom();
  }

  void
  DocumentEditorWidget::setTranslate(const QPointF &translate) {
    m_imageDisplayWidget->setTranslate(translate);
    update();
  }

  void
  DocumentEditorWidget::setZoom(float zoomFactor) {
    m_imageDisplayWidget->setZoom(zoomFactor);
    update();
  }

  QRect
  DocumentEditorWidget::getImageRect() const {
    return m_imageDisplayWidget->getImageRect();
  }

  QRect
  DocumentEditorWidget::getViewportRect() const {
    return m_imageDisplayWidget->getViewportRect();
  }

  QPolygonF
  DocumentEditorWidget::getViewportOnImage(bool closed) const {
    return m_imageDisplayWidget->getViewportOnImage();
  }

  void
  DocumentEditorWidget::setCursorByTool(AbstractModel::Properties::Tool tool) {
    switch(tool) {
      case AbstractModel::Properties::TOOL_ZOOM: setCursor(::Qt::PointingHandCursor); break; // TBA - testing stub
      default: unsetCursor(); break;
    }
  }

  // Protected members.
  void
  DocumentEditorWidget::mousePressEvent(QMouseEvent *event) {
    // Calculate the image coordinates of where the mouse was clicked.
    QPointF imagePos(m_imageDisplayWidget->getImageCoordinatesOf(event->localPos()));

    // Trigger the relevant signal.
    clickedAt(imagePos.x(), imagePos.y());
  }

  void
  DocumentEditorWidget::mouseMoveEvent(QMouseEvent *event) {
    // Calculate the image coordinates of where the mouse was clicked.
    QPointF imagePos(m_imageDisplayWidget->getImageCoordinatesOf(event->localPos()));

    // Trigger the relevant signal.
    draggedTo(imagePos.x(), imagePos.y());
  }

  void
  DocumentEditorWidget::mouseReleaseEvent(QMouseEvent *event) {
    // Calculate the image coordinates of where the mouse was clicked.
    QPointF imagePos(m_imageDisplayWidget->getImageCoordinatesOf(event->localPos()));

    // Trigger the relevant signal.
    releasedAt(imagePos.x(), imagePos.y());
  }
}
