/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RulerWidget.cpp
 * PURPOSE: Implements the RulerWidget class.
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

#include "RulerWidget.hpp"

#include <QPainter>
#include <QColor>
#include <QPen>
#include <QBrush>

namespace SDF::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor::Impl {
  RulerWidget::RulerWidget(::Qt::Orientation orientation,
                           QWidget *parent
                          )
    : QWidget(parent),
      m_orientation(orientation),
      m_rulerThickness(10),
      m_majorTickInterval(50),
      m_minorTickInterval(10),
      m_minorTickThickness(5),
      m_viewP1(0.0f),
      m_viewMagnification(1.0f)
  {
  }

  QSize
  RulerWidget::sizeHint() const {
    QSize superHint = QWidget::sizeHint();
    if(superHint.isValid()) {
      // Incorporate the ruler thickness.
      if(m_orientation == ::Qt::Horizontal) {
        return QSize(m_rulerThickness, superHint.height());
      } else {
        return QSize(superHint.width(), m_rulerThickness);
      }
    } else {
      return superHint;
    }
  }

  int
  RulerWidget::thickness() const {
    return m_rulerThickness;
  }

  int
  RulerWidget::majorTickEvery() const {
    return m_majorTickInterval;
  }

  int
  RulerWidget::minorTickEvery() const {
    return m_minorTickInterval;
  }

  void
  RulerWidget::setThickness(int thickness) {
    m_rulerThickness = thickness;
    update();
  }

  void
  RulerWidget::setMajorTickEvery(int interval) {
    m_majorTickInterval = interval;
    update();
  }

  void
  RulerWidget::setMinorTickEvery(int interval) {
    m_minorTickInterval = interval;
    update();
  }

  float
  RulerWidget::getViewportP1() const {
    return m_viewP1;
  }

  float
  RulerWidget::getViewportP2() const {
    return m_viewP1 + ((size().width() - 1) / m_viewMagnification);
  }

  void
  RulerWidget::setViewportP1(float p1) {
    m_viewP1 = p1;
    update();
  }

  void
  RulerWidget::setViewportMagnification(float mag) {
    m_viewMagnification = mag;
    update();
  }

  void
  RulerWidget::setAll(float p1,
                      float mag
                     )
  {
    m_viewP1 = p1;
    m_viewMagnification = mag;
    update();
  }

  void
  RulerWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    // Color scheme (here, black-on-white; future: some cool dark scheme).
    QPen markingsPen(QColor(0, 0, 0));
    QBrush bkgBrush(QColor(255, 255, 255));
    painter.setPen(markingsPen);
    painter.setBrush(bkgBrush);

    // Draw the ruler background.
    QRect totalRect = rect();
    QRect updateRect = event->rect();
    painter.drawRect(updateRect);

    // Check if the requested rectangle contains borders.
  }
}
