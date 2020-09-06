#ifndef SDF_UILAYER_IMPL_QT_CUSTOMWIDGETS_CRULER_HPP
#define SDF_UILAYER_IMPL_QT_CUSTOMWIDGETS_CRULER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CRuler.hpp
 * PURPOSE: The Qt-based ruler widget, which is part of the image editor.
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

#include <QWidget>

namespace SDF {
  namespace UILayer {
    namespace Impl::Qt::CustomWidgets {
      class CRuler : public QWidget {
        Q_OBJECT
      public:
        CRuler(QWidget *parent = nullptr, int snapPos = SnapAtTop, int rulerThickness = 25);
        ~CRuler() {}

        QSize sizeHint() const;
      public:
        static constexpr int SnapAtTop = 0x0;
        static constexpr int SnapAtLeft = 0x1;
        static constexpr int SnapAtRight = 0x2;
        static constexpr int SnapAtBottom = 0x3;
      private:
        int m_snapPos;
        int m_rulerThickness;

        int m_unitIntervalPixels;
        int m_numMinorTicks;

        int m_viewCenterCoordinate;

        void paintEvent(QPaintEvent *event);
      private:
        void drawWidget(QPainter &qp);
        void paintMajorTick(QPainter &qp, int coord);
      };
    }
  }
}
#endif
