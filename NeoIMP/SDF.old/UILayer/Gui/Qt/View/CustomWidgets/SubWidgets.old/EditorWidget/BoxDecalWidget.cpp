/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    BoxDecalWidget.cpp
 * PURPOSE: Implementation of the custom Qt UI widget that draws a simple box decal over an image being edited. These
 *          are meant for use with temporary selections such as zoom areas.
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

#include <BoxDecalWidget.hpp>
#include <clippoly.hpp>
#include <iostream>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets::SubWidgets::EditorWidget {
  BoxDecalWidget::BoxDecalWidget(QWidget *parent)
    : m_imageWidthPx(0),
      m_imageHeightPx(0),
      m_magnification(1.0f),
      m_decalVisible(false),
      m_x1(0), m_y1(0), m_x2(0), m_y2(0)
  {}

  QSize
  BoxDecalWidget::sizeHint() const {
    return QSize(m_imageWidthPx * m_magnification, m_imageHeightPx * m_magnification);
  }

  void
  BoxDecalWidget::setImageSize(int width, int height) {
    m_imageWidthPx = width;
    m_imageHeightPx = height;
    updateGeometry();
    adjustSize();
    update();
  }

  void
  BoxDecalWidget::setMagnification(float newMagnification) {
    m_magnification = newMagnification;
    updateGeometry();
    adjustSize();
    update();
  }

  void
  BoxDecalWidget::setDecalVisibility(bool visibility) {
    m_decalVisible = true;
    update();
  }

  void
  BoxDecalWidget::setDecalRect(int x1, int y1, int x2, int y2) {
    int oldX1(m_x1), oldY1(m_y1), oldX2(m_x2), oldY2(m_y2);
    m_x1 = x1; m_y1 = y1; m_x2 = x2; m_y2 = y2;

    // Invalidate the old and new decal regions for redrawing.
    int oldWidth(oldX2 - oldX1 + 1);
    int oldHeight(oldY2 - oldY1 + 1);
    int newWidth(m_x2 - m_x1 + 1);
    int newHeight(m_y2 - m_y1 + 1);

    update(oldX1, oldY1, oldWidth, 1);
    update(oldX2, oldY1, 1, oldHeight);
    update(oldX1, oldY2, oldWidth, 1);
    update(oldX1, oldY1, 1, oldHeight);

    update(m_x1, m_y1, newWidth, 1);
    update(m_x2, m_y1, 1, newHeight);
    update(m_x1, m_y2, newWidth, 1);
    update(m_x1, m_y1, 1, newHeight);
  }

  // Private members.
  void
  BoxDecalWidget::paintEvent(QPaintEvent *event) {
    QPainter qp(this);

    paintWidgetRegion(qp, event->rect());
  }

  void
  BoxDecalWidget::paintWidgetRegion(QPainter &qp, QRect rect) {
    if(m_decalVisible) {
      // Create the decal polygon and clip it to the given rectangle.
      std::vector<QPoint> decalPoly;
      decalPoly.push_back(QPoint(m_x1, m_y1));
      decalPoly.push_back(QPoint(m_x2, m_y1));
      decalPoly.push_back(QPoint(m_x2, m_y2));
      decalPoly.push_back(QPoint(m_x1, m_y2));

      std::vector<QLine> clipped = clipPoly(decalPoly, rect);

      // Draw the clipped polygon.
      qp.drawLines(&clipped[0], clipped.size());
    }
  }
}
