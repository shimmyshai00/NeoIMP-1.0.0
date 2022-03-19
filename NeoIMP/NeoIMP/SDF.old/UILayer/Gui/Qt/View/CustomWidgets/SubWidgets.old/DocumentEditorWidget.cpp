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

#include <EditorWidget/BoxDecalWidget.hpp>
#include <EditorWidget/ImageDisplayWidget.hpp>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets::SubWidgets {
  DocumentEditorWidget::DocumentEditorWidget(QWidget *parent)
    : m_temporaryRectangleDecal(new EditorWidget::BoxDecalWidget()),
      m_imageDisplayWidget(new EditorWidget::ImageDisplayWidget()),
      m_stackedLayout(new QStackedLayout(this))
  {
    m_stackedLayout->setStackingMode(QStackedLayout::StackAll);
    m_stackedLayout->addWidget(m_temporaryRectangleDecal);
    m_stackedLayout->addWidget(m_imageDisplayWidget);

    m_temporaryRectangleDecal->setDecalRect(5, 5, 50, 50);
    m_temporaryRectangleDecal->setDecalVisibility(true);
  }

  QSize DocumentEditorWidget::sizeHint() const {
    return m_stackedLayout->sizeHint();
  }

  void DocumentEditorWidget::setDataSource(IImageDataSource *dataSource) {
    m_imageDisplayWidget->setDataSource(dataSource);
  }

  float DocumentEditorWidget::magnification() const {
    return m_imageDisplayWidget->magnification();
  }

  void DocumentEditorWidget::setMagnification(float newMagnification) {
    m_imageDisplayWidget->setMagnification(newMagnification);
    m_temporaryRectangleDecal->setMagnification(newMagnification);
    updateGeometry();
    adjustSize();
    update();
  }

  void DocumentEditorWidget::setCursorByTool(AbstractModel::Properties::Tool tool) {
    switch(tool) {
      case AbstractModel::Properties::TOOL_ZOOM: setCursor(::Qt::PointingHandCursor); break; // TBA - testing stub
      default: unsetCursor(); break;
    }
  }

  // Protected members.
  void DocumentEditorWidget::mousePressEvent(QMouseEvent *event) {
    // Calculate the image coordinates of where the mouse was clicked.
    float imagePosX(event->localPos().x() / magnification());
    float imagePosY(event->localPos().y() / magnification());

    // Trigger the relevant signal.
    clickedAt(imagePosX, imagePosY);
  }

  void DocumentEditorWidget::mouseMoveEvent(QMouseEvent *event) {
    // Calculate the image coordinates of where the mouse was clicked.
    float imagePosX(event->localPos().x() / magnification());
    float imagePosY(event->localPos().y() / magnification());

    // Trigger the relevant signal.
    draggedTo(imagePosX, imagePosY);
  }

  void DocumentEditorWidget::mouseReleaseEvent(QMouseEvent *event) {
    // Calculate the image coordinates of where the mouse was clicked.
    float imagePosX(event->localPos().x() / magnification());
    float imagePosY(event->localPos().y() / magnification());

    // Trigger the relevant signal.
    releasedAt(imagePosX, imagePosY);
  }
}
