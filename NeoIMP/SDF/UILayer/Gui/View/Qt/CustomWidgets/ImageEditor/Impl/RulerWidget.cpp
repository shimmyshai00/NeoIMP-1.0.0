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
#include <QFont>
#include <QFontMetrics>
#include <QRect>
#include <QPoint>
#include <QTextOption>

#include <cmath>

namespace SDF::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor::Impl {
  // A helper function that's needed because Qt's text painting functionality doesn't allow for
  // adjusting line spacing.
  void lineCorrectedPrint(QPainter &painter, const QString &str, QRect rect, int dLineSpc) {
    // Break the string into separate lines.
    QStringList lines = str.split('\n');

    // Print the lines, taking care to correct for the line spacing.
    QRect curPrintRect(rect);
    curPrintRect.adjust(0, dLineSpc, 0, 0);
    for(const QString &line : lines) {
      if(curPrintRect.isValid()) {
        QRect boundingBox;
        painter.drawText(curPrintRect, 0, line, &boundingBox);
        curPrintRect.adjust(0, boundingBox.height() + dLineSpc, 0, 0);
      }
    }
  }
}
namespace SDF::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor::Impl {
  RulerWidget::RulerWidget(::Qt::Orientation orientation,
                           QWidget *parent
                          )
    : QWidget(parent),
      m_orientation(orientation),
      m_rulerThickness(18),
      m_majorTickInterval(50),
      m_minorTickInterval(10),
      m_minorTickThickness(3),
      m_labelMargin(2),
      m_labelThickness(10),
      m_viewP1(0.0f),
      m_viewMagnification(1.0f)
  {
    if(m_orientation == ::Qt::Horizontal) {
      setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    } else {
      setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
    }
  }

  QSize
  RulerWidget::sizeHint() const {
    return QSize(m_rulerThickness, m_rulerThickness);
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
    return m_viewP1 + (size().width() / m_viewMagnification);
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

    // Font setup.
    QFont labelsFont("Helvetica");
    labelsFont.setPixelSize(m_labelThickness);
    painter.setFont(labelsFont);
    const int c_lineCorrection = -0.25*m_labelThickness; // NB! seems to work well for this font ON
                                                        // *THIS MACHINE*. THIS WILL NEED MORE WORK
                                                        // POSSIBLY FOR OTHERS.

    // Draw the ruler background.
    QRect totalRect = rect();
    QRect updateRect = event->rect();

    painter.setPen(::Qt::NoPen);
    painter.drawRect(updateRect);
    painter.setPen(markingsPen);

    // Check if the requested rectangle contains borders.
    if(updateRect.top() == totalRect.top()) {
      // Has upper border.
      painter.drawLine(updateRect.left(), updateRect.top(), updateRect.right(), updateRect.top());
    }

    if(updateRect.bottom() == totalRect.bottom()) {
      // Has lower border.
      painter.drawLine(updateRect.left(), updateRect.bottom(),
        updateRect.right(), updateRect.bottom());
    }

    if(updateRect.left() == totalRect.left()) {
      // Has left-hand border.
      painter.drawLine(updateRect.left(), updateRect.top(), updateRect.left(), updateRect.bottom());
    }

    if(updateRect.right() == totalRect.right()) {
      // Has right-hand border.
      painter.drawLine(updateRect.right(), updateRect.top(),
        updateRect.right(), updateRect.bottom());
    }

    // Now draw the ticks! This is the fun bit.
    // When positioning the ticks, we do *not* simply count from the left or top edge of the
    // *widget* - that would defeat the purpose of the ruler. Instead, we must count them starting
    // from the left or right of *image space*. Because we are assuming a fixed *screen* distance
    // between ticks, to minimize rounding error we perform the actual drawing in screen space, but
    // we have to go through image space to align the leftmost/topmost tick.
    float minorTickImageSpaceDist = (0.0f + m_minorTickInterval) / m_viewMagnification;
    float majorTickImageSpaceDist = (0.0f + m_majorTickInterval) / m_viewMagnification;

    // Get the "viewport" coordinates of the sides of the update rectangle.
    float localViewP1 = 0.0f;
    float localViewP2 = 0.0f;

    if(m_orientation == ::Qt::Horizontal) {
      localViewP1 = m_viewP1 + (updateRect.left() - totalRect.left()) / m_viewMagnification;
      localViewP2 = m_viewP1 + (updateRect.right() + 1 - totalRect.left()) / m_viewMagnification;
    } else {
      localViewP1 = m_viewP1 + (updateRect.top() - totalRect.top()) / m_viewMagnification;
      localViewP2 = m_viewP1 + (updateRect.bottom() + 1 - totalRect.top()) / m_viewMagnification;
    }

    // This is equivalent to
    //
    // float leftmostMinorTickImageSpacePos = ceil(localViewP1 / minorTickImageSpaceDist) *
    //  minorTickImageSpaceDist;
    // float leftmostMinorTickScreenPos = (leftmostMinorTickImageSpacePos - localViewP1) *
    //  m_viewMagnification;
    //
    // but we fold in the cancellation of m_viewMagnification to maximize numerical precision.
    // Use floor though so that we can ensure labels on the RIGHT side, even of invisible ticks
    int leftmostMinorTickScreenPos = floor(localViewP1 / minorTickImageSpaceDist) *
      m_minorTickInterval - (localViewP1 * m_viewMagnification);
    int leftmostMajorTickScreenPos = floor(localViewP1 / majorTickImageSpaceDist) *
      m_majorTickInterval - (localViewP1 * m_viewMagnification);

    // Now do the drawing!
    int minorTickScreenPos = leftmostMinorTickScreenPos;
    int majorTickScreenPos = leftmostMajorTickScreenPos;

    // For the labels. Essentially "leftmostMajorTickImageSpacePos".
    float counterBegin = floor(localViewP1 / majorTickImageSpaceDist) * majorTickImageSpaceDist;
    int counter = 0;

    if(m_orientation == ::Qt::Horizontal) {
      while(minorTickScreenPos < localViewP2) {
        painter.drawLine(minorTickScreenPos, totalRect.bottom(),
          minorTickScreenPos, totalRect.bottom() - m_minorTickThickness);

        minorTickScreenPos += m_minorTickInterval;
      }

      // Always draw at least one major tick even if it lies outside the update rectangle, to ensure
      // we get the label
      do {
        painter.drawLine(majorTickScreenPos, totalRect.bottom(),
          majorTickScreenPos, totalRect.top());

        // Draw in the labels.
        float imgSpacePos = counterBegin + counter*majorTickImageSpaceDist;
        QString labelStr(QString::number(imgSpacePos, 'f', 1)); // TBA: units

        QRect textDrawRect(
          majorTickScreenPos + m_labelMargin,
          totalRect.top() + m_labelMargin,
          majorTickScreenPos + m_majorTickInterval - m_labelMargin,
          totalRect.bottom() - m_minorTickThickness - m_labelMargin
        );

        lineCorrectedPrint(painter, labelStr, textDrawRect, c_lineCorrection);
        majorTickScreenPos += m_majorTickInterval;
        ++counter;
      } while(majorTickScreenPos < localViewP2);
    } else {
      while(minorTickScreenPos < localViewP2) {
        painter.drawLine(totalRect.right(), minorTickScreenPos,
          totalRect.right() - m_minorTickThickness, minorTickScreenPos);

        minorTickScreenPos += m_minorTickInterval;
      }

      do {
        painter.drawLine(totalRect.right(), majorTickScreenPos,
          totalRect.left(), majorTickScreenPos);

        // Draw in the labels.
        float imgSpacePos = counterBegin + counter*majorTickImageSpaceDist;
        QString labelStr(QString::number(imgSpacePos, 'f', 0)); // TBA: units
        QString funnyStr(labelStr);
        for(int i = 1; i < funnyStr.size(); i += 2)
          funnyStr.insert(i, '\n');

        QRect textDrawRect(
          totalRect.left() + m_labelMargin,
          majorTickScreenPos + m_labelMargin,
          totalRect.right() - m_minorTickThickness - m_labelMargin,
          majorTickScreenPos + m_majorTickInterval - m_labelMargin
        );

        lineCorrectedPrint(painter, funnyStr, textDrawRect, c_lineCorrection);

        majorTickScreenPos += m_majorTickInterval;
        ++counter;
      } while(majorTickScreenPos < localViewP2);
    }
  }
}
