/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CRuler.cpp
 * PURPOSE: Implementation of the Qt-based ruler widget.
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

#include <Impl/Qt/CustomWidgets/CRuler.hpp>

#include <Impl/Qt/CustomWidgets/CViewport1D.hpp>

#include <QPainter>

#include <iostream>
#include <cmath>

namespace SDF {
  namespace UILayer {
    namespace Impl::Qt::CustomWidgets {
      CRuler::CRuler(QWidget *parent, int orientation, int rulerThickness)
      : QWidget(parent),
        m_orientation(orientation),
        m_rulerThickness(rulerThickness),
        m_minorTickIntervalScreenPixels(20),
        m_majorTickEvery(5),
        m_viewCenterInImageSpace(0.0f),
        m_magnificationFactor(1.0f)
        {
          switch(m_orientation) {
            case HorizontalOrientation:
              setMinimumHeight(rulerThickness);
              break;
            case VerticalOrientation:
              setMinimumWidth(rulerThickness);
              break;
          }
        }

      QSize CRuler::sizeHint() const {
        // The size is based on the ruler thickness and the size of the widget's layout, which it is meant to snap to.
        if(layout() != nullptr) {
          switch(m_orientation) {
            case HorizontalOrientation:
              return QSize(QWidget::sizeHint().width(), m_rulerThickness);
            case VerticalOrientation:
              return QSize(m_rulerThickness, QWidget::sizeHint().height());
            default:
              return QSize();
          }
        } else {
          return QWidget::sizeHint();
        }
      }

      // Private members.
      void CRuler::paintEvent(QPaintEvent *event) {
        QPainter qp(this);

        drawWidget(qp);
      }

      void CRuler::drawWidget(QPainter &qp) {
        /*
        // NB: only because this is still being implemented
        if(m_snapPos != SnapAtTop) {
          return;
        }
        */

        // Get size parameters.
        int widgetWidth(size().width());
        int widgetHeight(size().height());

        // Draw a nice background for the ruler.
        QColor bkgColor(255, 255, 255);
        QColor tickColor(0, 0, 0);

        qp.setPen(bkgColor);
        qp.setBrush(bkgColor);
        qp.drawRect(0, 0, widgetWidth, widgetHeight);

        // Draw the ruler ticks. First, create a viewport for the ruler.
        int majorTickSize(m_rulerThickness);
        int minorTickSize(m_rulerThickness / 3);

        int rulerScreenLength(getWidgetScreenLength());

        Detail::CViewport1D rulerViewport(m_viewCenterInImageSpace, rulerScreenLength, m_magnificationFactor);

        // The idea now is to consider the ticks as a grid overlain in image space, with the viewport providing a
        // window on that grid, and its origin at the space's origin. Since the distance between ticks is defined on
        // the viewport, and not on image space, we have to find the size of each tick interval in image space.
        float minorTickStepInImageSpace((0.0f + m_minorTickIntervalScreenPixels) / m_magnificationFactor);

        // Now figure out where the viewport left and right are in units of ticks.
        int viewportLeftTicks(
          rulerViewport.getImageSpaceCoordOfViewportPoint(0.0f) / minorTickStepInImageSpace);
        int viewportRightTicks(
          rulerViewport.getImageSpaceCoordOfViewportPoint(rulerScreenLength) / minorTickStepInImageSpace);

        // Now draw these ticks.
        for(int tickNum(viewportLeftTicks); tickNum < viewportRightTicks; ++tickNum) {
          float tickImageSpaceCoord((0.0f + tickNum) * minorTickStepInImageSpace);
          int tickViewportCoord(rulerViewport.getViewportCoordOfImageSpacePoint(tickImageSpaceCoord));
          if((tickViewportCoord >= 0) && (tickViewportCoord < rulerScreenLength)) {
            if((tickNum % m_majorTickEvery) == 0) {
              paintTickAtScreenPos(qp, tickViewportCoord, majorTickSize);
              paintTickLabelAtScreenPos(qp, tickViewportCoord, majorTickSize,
                QString::number(static_cast<int>(floor(tickImageSpaceCoord + 0.5f))));
            } else {
              paintTickAtScreenPos(qp, tickViewportCoord, minorTickSize);
            }
          }
        }

        // Finally, draw the ruler border.
        qp.drawLine(0, 0, widgetWidth - 1, 0);
        qp.drawLine(widgetWidth - 1, 0, widgetWidth - 1, widgetHeight - 1);
        qp.drawLine(widgetWidth - 1, widgetHeight - 1, 0, widgetHeight - 1);
        qp.drawLine(0, widgetHeight - 1, 0, 0);
      }

      int CRuler::getWidgetScreenLength() {
        // Get the length of the widget in screen pixels. Which dimension (width or height) this is depends on how it
        // is oriented.
        switch(m_orientation) {
          case HorizontalOrientation: return size().width();
          case VerticalOrientation: return size().height();
        }

        return std::max(size().width(), size().height());
      }

      void CRuler::paintTickAtScreenPos(QPainter &qp, int screenCoord, int tickSize) {
        // Paint a tick on the ruler at the given screen coordinate along the length of the ruler width and with the
        // given size.
        QColor tickColor(0, 0, 0);
        qp.setPen(tickColor);

        int widgetWidth(size().width());
        int widgetHeight(size().height());

        switch(m_orientation) {
          case HorizontalOrientation:
            qp.drawLine(screenCoord, widgetHeight - tickSize, screenCoord, widgetHeight);
            break;
          case VerticalOrientation:
            qp.drawLine(widgetWidth - tickSize, screenCoord, widgetWidth, screenCoord);
            break;
        }
      }

      void CRuler::paintTickLabelAtScreenPos(QPainter &qp, int screenCoord, int tickSize, const QString &label) {
        // Paint a label at the given ruler position.
        QFont font("Arial", 8);
        QFontMetricsF fm(font);
        qp.setFont(font);

        int widgetWidth(size().width());
        int widgetHeight(size().height());

        switch(m_orientation) {
          case HorizontalOrientation:
            qp.drawText(screenCoord + 4, widgetHeight - tickSize + 10, label);
            break;
          case VerticalOrientation:
            qp.drawText(0, screenCoord + 10, label);
            break;
        }
      }
    }
  }
}
