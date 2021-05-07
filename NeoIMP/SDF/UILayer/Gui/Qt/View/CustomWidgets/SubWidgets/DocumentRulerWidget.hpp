#ifndef SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_DOCUMENTRULERWIDGET_HPP
#define SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_DOCUMENTRULERWIDGET_HPP

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

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets::SubWidgets {
  class DocumentRulerWidget : public QWidget {
    Q_OBJECT
  public:
    // NB: This interface is kind of a mess. Not sure how to refine it best atm.
    DocumentRulerWidget(::Qt::Orientation orientation, QWidget *parent = nullptr);
    ~DocumentRulerWidget();

    QSize
    sizeHint() const;

    void
    setMajorTickInterval(int screenPixelsBetweenMajorTicks);

    void
    setNumMinorTicks(int numMinorTicksPerMajorTick);

    void
    setTranslation(float translation);

    void
    setMagnification(float magnification);
  private:
    ::Qt::Orientation m_orientation;
    float m_rulerThickness;

    float m_origin;
    float m_magnification;

    int m_screenPixelsBetweenMajorTicks;
    int m_numMinorTicksPerMajorTick;

    void
    paintEvent(QPaintEvent *event);
  private:
    int
    getRulerLength();

    int
    getRulerThickness();

    void
    paintWidgetBackground(QPainter &qp);

    void
    paintTicksAndLabels(QPainter &qp);

    void
    paintTickLabelAtScreenPos(QPainter &qp, int screenPos, int tickSize, const QString &label);
  };
}

#endif
