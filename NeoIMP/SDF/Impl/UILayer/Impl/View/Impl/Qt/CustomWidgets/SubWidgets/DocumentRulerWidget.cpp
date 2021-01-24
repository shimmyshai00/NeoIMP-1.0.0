/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentRulerWidget.cpp
 * PURPOSE: Implementation of a custom Qt UI widget that draws a ruler on each side of the document.
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

#include <DocumentRulerWidget.hpp>
#include <cmath>
#include <iostream>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt::CustomWidgets::SubWidgets {
  DocumentRulerWidget::DocumentRulerWidget(::Qt::Orientation orientation, QWidget *parent)
  : QWidget(parent),
    m_orientation(orientation),
    m_rulerThickness(20),
    m_leftOrigin(0.0f),
    m_magnification(1.0f),
    m_objectH1(0.0f),
    m_objectH2(0.0f),
    m_scrollRangeMin(0),
    m_scrollRangeMax(100),
    m_screenPixelsBetweenMajorTicks(50),
    m_numMinorTicksPerMajorTick(5)
  {}

  DocumentRulerWidget::~DocumentRulerWidget() {}

  QSize DocumentRulerWidget::sizeHint() const {
    QSize baseSize(QWidget::sizeHint());

    switch(m_orientation) {
      default:
      case ::Qt::Horizontal:
        return QSize(baseSize.width(), m_rulerThickness);
      case ::Qt::Vertical:
        return QSize(m_rulerThickness, baseSize.height());
    }
  }

  void DocumentRulerWidget::setRulerThickness(int rulerThickness) {
    m_rulerThickness = rulerThickness;
    update();
  }

  void DocumentRulerWidget::setMajorTickInterval(int screenPixelsBetweenMajorTicks) {
    m_screenPixelsBetweenMajorTicks = screenPixelsBetweenMajorTicks;
    update();
  }

  void DocumentRulerWidget::setNumMinorTicks(int numMinorTicksPerMajorTick) {
    m_numMinorTicksPerMajorTick = numMinorTicksPerMajorTick;
    update();
  }

  void DocumentRulerWidget::setLeftOrigin(float leftOrigin) {
    m_leftOrigin = leftOrigin;
    update();
  }

  void DocumentRulerWidget::setMagnification(float magnification) {
    m_magnification = magnification;
    update();
  }

  void DocumentRulerWidget::measureObject(float objectH1, float objectH2) {
    m_objectH1 = objectH1;
    m_objectH2 = objectH2;
  }

  // Slots.
  void DocumentRulerWidget::setScrollRange(int min, int max) {
    m_scrollRangeMin = min;
    m_scrollRangeMax = max;
  }

  void DocumentRulerWidget::setScrollPosition(int value) {
    std::cout << "scroll" << std::endl;

    // At m_scrollRangeMin, the left origin should be such that m_objectH1 lies at the ruler left.
    // At m_scrollRangeMax, the left origin should be such that m_objectH2 lies at the ruler right.
    float rulerLength(getRulerLength());
    float objectSize(m_objectH2 - m_objectH1);
    int scrollRangeSize(m_scrollRangeMax - m_scrollRangeMin);
    if(scrollRangeSize != 0) {
      m_leftOrigin = m_objectH1 + ((objectSize - rulerLength)/scrollRangeSize)*(value - m_scrollRangeMin);
    } else {
      m_leftOrigin = m_objectH1;
    }
    
    std::cout << "object: " << m_objectH1 << " - " << m_objectH2 << std::endl;
    std::cout << "scrollRange: " << m_scrollRangeMin << " - " << m_scrollRangeMax << std::endl;
    std::cout << "LeftOrigin: " << m_leftOrigin << std::endl;
    update();
  }

  // Private members.
  // These two length methods are needed because which screen dimension (width or height) of the ruler is its "length"
  // and which is its "thickness" depend on its orientation.
  int DocumentRulerWidget::getRulerLength() {
    switch(m_orientation) {
      default:
      case ::Qt::Horizontal:
        return size().width();
      case ::Qt::Vertical:
        return size().height();
    }
  }

  int DocumentRulerWidget::getRulerThickness() {
    switch(m_orientation) {
      default:
      case ::Qt::Horizontal:
        return size().height();
      case ::Qt::Vertical:
        return size().width();
    }
  }

  // Painting routines.
  void DocumentRulerWidget::paintEvent(QPaintEvent *event) {
    QPainter qp(this);

    paintWidgetBackground(qp);
    paintTicksAndLabels(qp);
  }

  void DocumentRulerWidget::paintWidgetBackground(QPainter &qp) {
    // Draw a nice background for the ruler. TBA: we may eventually want to add theme support for the colors.
    QColor bkgColor(255, 255, 255);
    QColor tickColor(0, 0, 0);

    qp.setPen(tickColor);
    qp.setBrush(bkgColor);
    qp.drawRect(0, 0, size().width()-1, size().height()-1);
  }

  void DocumentRulerWidget::paintTicksAndLabels(QPainter &qp) {
    // Paint the ruler ticks on this ruler. To get a nice "scrolling" effect, we begin marking off ticks, not at the
    // ruler's screen left or top, but at the origin of the image coordinate space which the viewport of this ruler
    // references.

    // Step 1: Figure out where the image coordinate origin is in screen space, relative to the left or topmost part of
    // the widget.
    float widgetLength(getRulerLength());
    float screenSpaceOrigin(-m_leftOrigin * m_magnification);

    // Step 2: Figure out where the first minor tick should go, and the number of ticks.
    float minorTickScreenInterval((0.0f + m_screenPixelsBetweenMajorTicks) / m_numMinorTicksPerMajorTick);
    int leftmostMinorTickNumFromOrigin(ceil((-screenSpaceOrigin + 0.0f) / minorTickScreenInterval));
    int rightmostMinorTickNumFromOrigin(floor((-screenSpaceOrigin + widgetLength) / minorTickScreenInterval));
    float leftmostMinorTickPos(screenSpaceOrigin + (leftmostMinorTickNumFromOrigin * minorTickScreenInterval));

    // Step 3: Trace the ticks!
    QColor bkgColor(255, 255, 255);
    QColor tickColor(0, 0, 0);

    qp.setPen(tickColor);
    qp.setBrush(bkgColor);

    int majorTickHeight(m_rulerThickness);
    int minorTickHeight(m_rulerThickness / 4);

    int widgetWidth(size().width());
    int widgetHeight(size().height());

    for(int i(leftmostMinorTickNumFromOrigin); i <= rightmostMinorTickNumFromOrigin; ++i) {
      int tickScreenPos(floor(screenSpaceOrigin + (i * minorTickScreenInterval)));
      int tickSize((i % m_numMinorTicksPerMajorTick == 0) ? majorTickHeight : minorTickHeight);

      // Paint the tick.
      switch(m_orientation) {
        default:
        case ::Qt::Horizontal:
          qp.drawLine(tickScreenPos, widgetHeight - 1 - tickSize, tickScreenPos, widgetHeight - 1);
          break;
        case ::Qt::Vertical:
          qp.drawLine(widgetWidth - 1 - tickSize, tickScreenPos, widgetWidth - 1, tickScreenPos);
          break;
      }

      // Every major tick, paint a tick label.
      if(i % m_numMinorTicksPerMajorTick == 0) {
        paintTickLabelAtScreenPos(qp, tickScreenPos, tickSize, QString::number(i * minorTickScreenInterval));
      }
    }
  }

  void DocumentRulerWidget::paintTickLabelAtScreenPos(QPainter &qp, int screenPos, int tickSize, const QString &label) {
    // Paint a label at the given ruler position.
    QFont font("Arial", 8);
    QFontMetricsF fm(font);
    qp.setFont(font);

    int widgetWidth(size().width());
    int widgetHeight(size().height());

    switch(m_orientation) {
      default:
      case ::Qt::Horizontal:
        qp.drawText(screenPos + 2, widgetHeight - 1 - tickSize + fm.height(), label);
        break;
      case ::Qt::Vertical:
        qp.drawText(2, screenPos + fm.height(), label);
        break;
    }
  }
}
