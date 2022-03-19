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

    connect(m_imageDisplayWidget, &EditViewWidget::ImageDisplayWidget::clickedAt,
            this, &DocumentEditorWidget::clickedAt
           );
    connect(m_imageDisplayWidget, &EditViewWidget::ImageDisplayWidget::draggedTo,
            this, &DocumentEditorWidget::draggedTo
           );
    connect(m_imageDisplayWidget, &EditViewWidget::ImageDisplayWidget::releasedAt,
            this, &DocumentEditorWidget::releasedAt
           );
  }

  void
  DocumentEditorWidget::setDataSource(IImageDataSource *dataSource) {
    m_imageDisplayWidget->setDataSource(dataSource);
    update();
  }

  float
  DocumentEditorWidget::translateX() const {
    return m_imageDisplayWidget->translateX();
  }

  float
  DocumentEditorWidget::translateY() const {
    return m_imageDisplayWidget->translateY();
  }

  QPointF
  DocumentEditorWidget::translate() const {
    return m_imageDisplayWidget->translate();
  }

  float
  DocumentEditorWidget::centerX() const {
    return m_imageDisplayWidget->getCenterXOnImage();
  }

  float
  DocumentEditorWidget::centerY() const {
    return m_imageDisplayWidget->getCenterYOnImage();
  }

  float
  DocumentEditorWidget::zoom() const {
    return m_imageDisplayWidget->zoom();
  }

  void
  DocumentEditorWidget::setTranslateX(float translateX) {
    m_imageDisplayWidget->setTranslateX(translateX);
    update();
  }

  void
  DocumentEditorWidget::setTranslateY(float translateY) {
    m_imageDisplayWidget->setTranslateY(translateY);
    update();
  }

  void
  DocumentEditorWidget::setTranslate(const QPointF &translate) {
    m_imageDisplayWidget->setTranslate(translate);
    update();
  }

  void
  DocumentEditorWidget::setCenterX(float centerX) {
    m_imageDisplayWidget->setCenterXOnImage(centerX);
    update();
  }

  void
  DocumentEditorWidget::setCenterY(float centerY) {
    m_imageDisplayWidget->setCenterYOnImage(centerY);
    update();
  }

  void
  DocumentEditorWidget::setZoom(float zoomFactor) {
    m_imageDisplayWidget->setZoom(zoomFactor);
    update();
  }

  void
  DocumentEditorWidget::setCursorByTool(AbstractModel::Properties::Tool tool) {
    switch(tool) {
      case AbstractModel::Properties::TOOL_ZOOM: setCursor(::Qt::PointingHandCursor); break; // TBA - testing stub
      default: unsetCursor(); break;
    }
  }
}
