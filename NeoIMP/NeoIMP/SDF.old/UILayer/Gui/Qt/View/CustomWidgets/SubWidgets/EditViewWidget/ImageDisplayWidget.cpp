/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageDisplayWidget.cpp
 * PURPOSE: Implementation of the custom Qt UI widget that actually displays an image document.
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

#include <ImageDisplayWidget.hpp>

#include <IImageDataSource.hpp>

#include <QResizeEvent>
#include <QCursor>
#include <QTransform>

#include <iostream>
#include <cmath>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets::SubWidgets::EditViewWidget {
  ImageDisplayWidget::ImageDisplayWidget(QWidget *parent)
    : AbstractViewport(parent),
      m_dataSource(nullptr)
  {
  }

  void
  ImageDisplayWidget::setDataSource(IImageDataSource *dataSource) {
    m_dataSource = dataSource;
  }

  // Private members.
  void
  ImageDisplayWidget::paintEvent(QPaintEvent *event) {
    QPainter qp(this);

    paintWidgetRegion(qp, event->rect());
  }

  void
  ImageDisplayWidget::paintWidgetRegion(QPainter &qp, QRect rect) {
    printf("TotalPaint: %d %d\n", this->rect().width(), this->rect().height());
    if(m_dataSource != nullptr) {
      // The passed rectangle, rect, will be a piece of the render viewport, which is of size equal to the widget
      // rectangle. Transform this rectangle to the corresponding region on the image.
      QTransform imageToViewportTransform(getImageToViewportTransform());
      QTransform viewportToImageTransform(getViewportToImageTransform());
      QPolygonF rectOnImage(viewportToImageTransform.map(QPolygonF(QRectF(rect))));

      // Round down and up the on-image rectangle to make sure we can get full coverage at a sub-pixel level.
      QRectF rectOnImageBbox(rectOnImage.boundingRect());
      QRect rectOnImageBboxRounded(floor(rectOnImageBbox.x()),
                                   floor(rectOnImageBbox.y()),
                                   ceil(rectOnImageBbox.width()),
                                   ceil(rectOnImageBbox.height()));

      // Get the image data for this region.
      QImage overlappedImage(m_dataSource->getImageRegion(rectOnImageBboxRounded));

      // Translate the image rectangle to cover rectOnImageBboxRounded, then pull back through the viewport transform
      // to get the on-screen rectangle.
      QTransform overlappedImageRectToROIBR;
      overlappedImageRectToROIBR.translate(rectOnImageBboxRounded.x(), rectOnImageBboxRounded.y());

      QTransform pullbackToScreen(imageToViewportTransform * overlappedImageRectToROIBR);

      // Render!
      qp.setTransform(pullbackToScreen);
      qp.drawImage(0, 0, overlappedImage);
    }
  }

  // Protected members.
  void
  ImageDisplayWidget::mousePressEvent(QMouseEvent *event) {
    // Calculate the image coordinates of where the mouse was clicked.
    QPointF imagePos(getViewportToImageTransform().map(event->localPos()));

    // Trigger the relevant signal.
    clickedAt(imagePos.x(), imagePos.y());
  }

  void
  ImageDisplayWidget::mouseMoveEvent(QMouseEvent *event) {
    // Calculate the image coordinates of where the mouse was clicked.
    QPointF imagePos(getViewportToImageTransform().map(event->localPos()));

    // Trigger the relevant signal.
    draggedTo(imagePos.x(), imagePos.y());
  }

  void
  ImageDisplayWidget::mouseReleaseEvent(QMouseEvent *event) {
    // Calculate the image coordinates of where the mouse was clicked.
    QPointF imagePos(getViewportToImageTransform().map(event->localPos()));

    // Trigger the relevant signal.
    releasedAt(imagePos.x(), imagePos.y());
  }
}
