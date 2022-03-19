/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    QtViewportCalc.cpp
 * PURPOSE: Implements the QtViewportCalc class.
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

#include <QtViewportCalc.hpp>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets::SubWidgets::EditViewWidget {
  QtViewportCalc::QtViewportCalc(int width, int height)
    : m_width(width),
      m_height(height),
      m_translateX(0.0f),
      m_translateY(0.0f),
      m_zoom(1.0f)
  {
  }

  QtViewportCalc::QtViewportCalc(const QSize &size)
    : m_width(size.width()),
      m_height(size.height()),
      m_translateX(0.0f),
      m_translateY(0.0f),
      m_zoom(1.0f)
  {
  }

  float
  QtViewportCalc::getTranslateX() const {
    return m_translateX;
  }

  float
  QtViewportCalc::getTranslateY() const {
    return m_translateY;
  }

  float
  QtViewportCalc::getZoom() const {
    return m_zoom;
  }

  void
  QtViewportCalc::setTranslateX(float xDisp) {
    m_translateX = xDisp;
    m_translateXXfm = QTransform().translate(xDisp, 0);
    m_translateXfm = m_translateYXfm * m_translateXXfm;
  }

  void
  QtViewportCalc::setTranslateY(float yDisp) {
    m_translateY = yDisp;
    m_translateYXfm = QTransform().translate(0, yDisp);
    m_translateXfm = m_translateYXfm * m_translateXXfm;
  }

  void
  QtViewportCalc::setTranslate(float xDisp, float yDisp) {
    m_translateX = xDisp;
    m_translateY = yDisp;

    m_translateXXfm = QTransform().translate(xDisp, 0);
    m_translateYXfm = QTransform().translate(0, yDisp);
    m_translateXfm = QTransform().translate(xDisp, yDisp);
  }

  void
  QtViewportCalc::setZoom(float magnif) {
    m_zoom = magnif;
    m_zoomXfm = QTransform().scale(magnif, magnif);
  }

  QPointF
  QtViewportCalc::viewportToImage(const QPointF &object) const {
    return getViewportToImageTransform().map(object);
  }

  QPolygonF
  QtViewportCalc::viewportToImage(const QRectF &object) const {
    return getViewportToImageTransform().map(QPolygonF(object));
  }

  QPointF
  QtViewportCalc::imageToViewport(const QPointF &object) const {
    return getImageToViewportTransform().map(object);
  }

  QPolygonF
  QtViewportCalc::imageToViewport(const QRectF &object) const {
    return getImageToViewportTransform().map(QPolygonF(object));
  }

  QTransform
  QtViewportCalc::getViewportToImageTransform() const {
    return m_translateXfm * m_zoomXfm.inverted();
  }

  QTransform
  QtViewportCalc::getImageToViewportTransform() const {
    return m_zoomXfm * m_translateXfm.inverted();
  }
}
