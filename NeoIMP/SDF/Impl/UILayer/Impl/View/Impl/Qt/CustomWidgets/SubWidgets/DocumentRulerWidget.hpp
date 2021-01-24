#ifndef SDF_IMPL_UILAYER_VIEW_IMPL_QT_CUSTOMWIDGETS_SUBWIDGETS_DOCUMENTRULERWIDGET_HPP
#define SDF_IMPL_UILAYER_VIEW_IMPL_QT_CUSTOMWIDGETS_SUBWIDGETS_DOCUMENTRULERWIDGET_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentRulerWidget.hpp
 * PURPOSE: Headers for a custom Qt UI widget that draws a ruler on each side of the document.
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

#include <Qt>
#include <QSize>
#include <QWidget>
#include <QPainter>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt::CustomWidgets::SubWidgets {
  class DocumentRulerWidget : public QWidget {
    Q_OBJECT
  public:
    DocumentRulerWidget(::Qt::Orientation orientation, QWidget *parent = nullptr);
    ~DocumentRulerWidget();

    QSize sizeHint() const;

    void setRulerThickness(int rulerThickness);

    void setMajorTickInterval(int screenPixelsBetweenMajorTicks);
    void setNumMinorTicks(int numMinorTicksPerMajorTick);

    void setLeftOrigin(float leftOrigin);
    void setMagnification(float magnification);

    void measureObject(float objectH1, float objectH2);
  public slots:
    // for connecting to a scroll bar
    void setScrollRange(int min, int max);
    void setScrollPosition(int value);
  private:
    ::Qt::Orientation m_orientation;

    int m_rulerThickness;

    float m_leftOrigin;
    float m_magnification;

    float m_objectH1;
    float m_objectH2;

    int m_scrollRangeMin;
    int m_scrollRangeMax;

    int m_screenPixelsBetweenMajorTicks;
    int m_numMinorTicksPerMajorTick;

    int getRulerLength();
    int getRulerThickness();

    void paintEvent(QPaintEvent *event);
  private:
    void paintWidgetBackground(QPainter &qp);
    void paintTicksAndLabels(QPainter &qp);
    void paintTickLabelAtScreenPos(QPainter &qp, int screenPos, int tickSize, const QString &label);
  };
}

#endif
