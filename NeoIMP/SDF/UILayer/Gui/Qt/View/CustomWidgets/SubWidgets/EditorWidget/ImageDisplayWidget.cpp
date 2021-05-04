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
#include <iostream>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets::SubWidgets::EditorWidget {
  ImageDisplayWidget::ImageDisplayWidget(QWidget *parent)
    : QWidget(parent),
      m_dataSource(nullptr),
      m_magnification(1.0f)
  {}

  QSize
  ImageDisplayWidget::sizeHint() const {
    if(m_dataSource != nullptr) {
      return QSize(m_dataSource->getImageWidth() * m_magnification, m_dataSource->getImageHeight() * m_magnification);
    } else {
      return QSize(-1, -1);
    }
  }

  void
  ImageDisplayWidget::setDataSource(IImageDataSource *dataSource) {
    m_dataSource = dataSource;
  }

  float
  ImageDisplayWidget::magnification() const {
    return m_magnification;
  }

  void
  ImageDisplayWidget::setMagnification(float newMagnification) {
    m_magnification = newMagnification;
    updateGeometry();
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
      QRectF imageRect(0, 0, m_dataSource->getImageWidth() * m_magnification, m_dataSource->getImageHeight() * m_magnification);
      QRectF clipped(QRectF(rect).intersected(imageRect));

      // Draw the image data within the clipped rectangle.
      std::cout << "paint: " << clipped.width() << " " << clipped.height() << std::endl;
      if((clipped.width() > 0) && (clipped.height() > 0)) {
        int imageWidth(m_dataSource->getImageWidth());
        int imageHeight(m_dataSource->getImageHeight());

        const unsigned char *imageData(nullptr);
        std::ptrdiff_t rowStride(0);

        m_dataSource->accessImageData(imageData, rowStride, 0, 0, imageWidth-1, imageHeight-1);

        QRectF unmagClipped(
          clipped.x() / m_magnification, clipped.y() / m_magnification,
          clipped.width() / m_magnification, clipped.height() / m_magnification
        );

        QImage qImage(imageData, imageWidth, imageHeight, rowStride, QImage::Format_RGB32);
        qp.drawImage(clipped, qImage, unmagClipped);
      }
    }
  }
}
