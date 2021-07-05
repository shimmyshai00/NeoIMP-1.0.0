#ifndef SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_EDITORWIDGET_BOXDECALWIDGET_HPP
#define SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_EDITORWIDGET_BOXDECALWIDGET_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    BoxDecalWidget.hpp
 * PURPOSE: Headers for a custom Qt UI widget that draws a simple box decal over an image being edited. These are meant
 *          for use with temporary selections such as zoom areas.
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
#include <QSize>
#include <QPainter>
#include <QPaintEvent>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets::SubWidgets::EditorWidget {
  class BoxDecalWidget : public QWidget {
    Q_OBJECT
  public:
    BoxDecalWidget(QWidget *parent = nullptr);
    ~BoxDecalWidget() {}

    QSize sizeHint() const;

    void setImageSize(int width, int height);
    void setMagnification(float newMagnification);

    void setDecalVisibility(bool visibility);
    void setDecalRect(int x1, int y1, int x2, int y2);
  private:
    int m_imageWidthPx;
    int m_imageHeightPx;

    float m_magnification;

    bool m_decalVisible;
    int m_x1, m_y1, m_x2, m_y2;

    void paintEvent(QPaintEvent *event);
  private:
    void paintWidgetRegion(QPainter &qp, QRect rect);
  };
}

#endif
