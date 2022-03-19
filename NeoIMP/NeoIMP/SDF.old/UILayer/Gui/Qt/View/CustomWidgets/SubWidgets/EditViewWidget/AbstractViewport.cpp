/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AbstractViewport.cpp
 * PURPOSE: Defines the AbstractViewport class.
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

#include <AbstractViewport.hpp>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets::SubWidgets::EditViewWidget {
  AbstractViewport::AbstractViewport(QWidget *parent)
    : QWidget(parent),
      m_viewport(0, 0)
  {
  }

  AbstractViewport::~AbstractViewport() {
  }

  float
  AbstractViewport::translateX() const {
    return m_viewport.getTranslateX();
  }

  float
  AbstractViewport::translateY() const {
    return m_viewport.getTranslateY();
  }

  QPointF
  AbstractViewport::translate() const {
    return QPointF(m_viewport.getTranslateX(), m_viewport.getTranslateY());
  }

  float
  AbstractViewport::zoom() const {
    return m_viewport.getZoom();
  }

  float
  AbstractViewport::getCenterXOnImage() const {
    QSize thisSize(size());
    QPointF screenViewportCenter(thisSize.width() / 2.0f, thisSize.height() / 2.0f);

    return m_viewport.viewportToImage(screenViewportCenter).x();
  }

  float
  AbstractViewport::getCenterYOnImage() const {
    QSize thisSize(size());
    QPointF screenViewportCenter(thisSize.width() / 2.0f, thisSize.height() / 2.0f);

    return m_viewport.viewportToImage(screenViewportCenter).y();
  }

  void
  AbstractViewport::setTranslateX(float translateX) {
    m_viewport.setTranslateX(translateX);
  }

  void
  AbstractViewport::setTranslateY(float translateY) {
    m_viewport.setTranslateY(translateY);
  }

  void
  AbstractViewport::setTranslate(QPointF translate) {
    m_viewport.setTranslate(translate.x(), translate.y());

  }

  void
  AbstractViewport::setZoom(float zoom) {
    m_viewport.setZoom(zoom);
  }

  void
  AbstractViewport::setCenterXOnImage(float centerX) {
    QSize thisSize(size());
    QPointF screenViewportCenter(thisSize.width() / 2.0f, thisSize.height() / 2.0f);
    QPointF curViewportCenter(m_viewport.viewportToImage(screenViewportCenter));
    float xDisp(centerX - curViewportCenter.x());

    m_viewport.setTranslateX(m_viewport.getTranslateX() + xDisp);
  }

  void
  AbstractViewport::setCenterYOnImage(float centerY) {
    QSize thisSize(size());
    QPointF screenViewportCenter(thisSize.width() / 2.0f, thisSize.height() / 2.0f);
    QPointF curViewportCenter(m_viewport.viewportToImage(screenViewportCenter));
    float yDisp(centerY - curViewportCenter.y());

    m_viewport.setTranslateY(m_viewport.getTranslateY() + yDisp);
  }

  QTransform
  AbstractViewport::getImageToViewportTransform() const {
    return m_viewport.getImageToViewportTransform();
  }

  QTransform
  AbstractViewport::getViewportToImageTransform() const {
    return m_viewport.getViewportToImageTransform();
  }

  void
  AbstractViewport::resizeEvent(QResizeEvent *event) {
    QtViewportCalc oldViewport(m_viewport);

    m_viewport = QtViewportCalc(size());
    m_viewport.setTranslate(oldViewport.getTranslateX(), oldViewport.getTranslateY());
    m_viewport.setZoom(oldViewport.getZoom());
  }
}
