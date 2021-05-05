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

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets::SubWidgets::EditViewWidget {
  ImageDisplayWidget::ImageDisplayWidget(QWidget *parent)
    : m_dataSource(nullptr),
      m_translation(0.0f, 0.0f),
      m_magnification(1.0f)
  {
  }

  void
  ImageDisplayWidget::setDataSource(IImageDataSource *dataSource) {
    m_dataSource = dataSource;
  }

  void
  ImageDisplayWidget::setTranslate(const QPointF &translate) {
    m_translation = translate;
  }

  void
  ImageDisplayWidget::setZoom(float zoomFactor) {
    m_magnification = zoomFactor;
  }

  // Private members.
  void
  ImageDisplayWidget::paintEvent(QPaintEvent *event) {
    QPainter qp(this);

    paintWidgetRegion(qp, event->rect());
  }

  void
  ImageDisplayWidget::paintWidgetRegion(QPainter &qp, QRect rect) {
    if(m_dataSource != nullptr) {
      // The passed rectangle, rect, will be a piece of the render viewport, which is of size equal to the widget
      // rectangle. Transform this rectangle to the corresponding region on the image.

      // Create the transform. Note: this transform is meant to transform viewport coordinates TO image coordinates.
      QTransform xfm(QTransform()
        .translate(m_translation.x(), m_translation.y())
        .scale(1.0f / m_magnification, 1.0f / m_magnification)
      );

      // Transform the rectangle.
      QRect renderRegionBoundingRect(xfm.mapRect(rect));

      // Intersect this bounding rectangle with the image space rectangle to avoid out-of-bounds access.
      QRect imageSpaceImageRect(0, 0, m_dataSource->getImageWidth()-1, m_dataSource->getImageHeight()-1);
      renderRegionBoundingRect = imageSpaceImageRect.intersected(renderRegionBoundingRect);

      // Traverse the bounding region and render it onto the screen in a tiled manner.
      // NB: just use one tile for now - will not work for extremely large images (> 32768x32768)
      QImage srcImage(m_dataSource->getImageRegion(renderRegionBoundingRect));
      QTransform invXfm(QTransform()
        .scale(m_magnification, m_magnification)
      );

      qp.setTransform(invXfm);
      qp.drawImage(QPointF(0.0, 0.0), srcImage);
    }
  }
}
