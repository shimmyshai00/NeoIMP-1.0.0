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

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt::CustomWidgets::SubWidgets {
  DocumentRulerWidget::DocumentRulerWidget(::Qt::Orientation orientation, QWidget *parent)
  : QWidget(parent),
    m_orientation(orientation),
    m_rulerThickness(24),
    m_imageSpaceX1(0.0f),
    m_imageSpaceX2(100.0f),
    m_screenPixelsBetweenMajorTicks(100),
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
  }

  void DocumentRulerWidget::setMajorTickInterval(int screenPixelsBetweenMajorTicks) {
    m_screenPixelsBetweenMajorTicks = screenPixelsBetweenMajorTicks;
  }

  void DocumentRulerWidget::setNumMinorTicks(int numMinorTicksPerMajorTick) {
    m_numMinorTicksPerMajorTick = numMinorTicksPerMajorTick;
  }

  void DocumentRulerWidget::setImageSpaceInterval(float x1, float x2) {
    m_imageSpaceX1 = x1;
    m_imageSpaceX2 = x2;
  }

  void DocumentRulerWidget::setImageSpaceCenterMag(float center, float mag) {
    m_imageSpaceX1 = center - ((0.0f + getRulerLength()) / (2.0 * mag));
    m_imageSpaceX2 = center + ((0.0f + getRulerLength()) / (2.0 * mag));
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
    float viewportLength(m_imageSpaceX2 - m_imageSpaceX1);
    float widgetLength(getRulerLength());

    float screenSpaceOrigin(-m_imageSpaceX1 / viewportLength * widgetLength);

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
