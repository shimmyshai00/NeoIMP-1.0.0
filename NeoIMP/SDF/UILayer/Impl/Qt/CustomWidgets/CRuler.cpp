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

#include <QPainter>
#include <iostream>

namespace SDF {
  namespace UILayer {
    namespace Impl::Qt::CustomWidgets {
      CRuler::CRuler(QWidget *parent, int snapPos, int rulerThickness)
      : QWidget(parent),
        m_snapPos(snapPos),
        m_rulerThickness(rulerThickness),
        m_unitIntervalPixels(100),
        m_numMinorTicks(4),
        m_viewCenterCoordinate(0)
        {
        }

      QSize CRuler::sizeHint() const {
        // The size is based on the ruler thickness and the size of the widget's parent, which it is meant to snap to.
        QWidget *p(dynamic_cast<QWidget *>(parent()));

        switch(m_snapPos) {
          case SnapAtTop:
            return QSize(p->width(), m_rulerThickness);
          case SnapAtLeft:
            return QSize(m_rulerThickness, p->height());
          case SnapAtRight:
            return QSize(m_rulerThickness, p->height());
          case SnapAtBottom:
            return QSize(p->width(), m_rulerThickness);
          default:
            return p->size();
        }
      }

      // Private members.
      void CRuler::paintEvent(QPaintEvent *event) {
        QPainter qp(this);

        drawWidget(qp);
      }

      void CRuler::drawWidget(QPainter &qp) {
        std::cout << "Painting ruler " << width() << " " << height() << std::endl;

        // NB: only because this is still being implemented
        if(m_snapPos != SnapAtTop) {
          return;
        }

        // Get size parameters.
        int widgetWidth(size().width());
        int widgetHeight(size().height());

        // Draw a nice background for the ruler.
        QColor bkgColor(255, 255, 255);
        QColor tickColor(0, 0, 0);

        qp.setPen(bkgColor);
        qp.setBrush(bkgColor);
        qp.drawRect(0, 0, widgetWidth, widgetHeight);

        // Draw the ruler ticks.
        if(m_snapPos == SnapAtTop) {
          int majorTickSize(widgetHeight / 2);
          int minorTickSize(widgetHeight / 4);

          for(int x(0); x < widgetWidth; ++x) {
            int viewportPos((x - widgetWidth / 2) + m_viewCenterCoordinate);

            qp.setPen(tickColor);
            if(viewportPos % m_unitIntervalPixels == 0) {
              qp.drawLine(x, widgetHeight, x, widgetHeight - majorTickSize);
            }
          }
        }
      }
    }
  }
}
