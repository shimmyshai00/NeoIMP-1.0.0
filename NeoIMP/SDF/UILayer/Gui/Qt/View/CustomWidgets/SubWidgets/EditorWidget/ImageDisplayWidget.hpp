#ifndef SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_IMAGEDISPLAYWIDGET_HPP
#define SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_IMAGEDISPLAYWIDGET_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageDisplayWidget.hpp
 * PURPOSE: Headers for the custom Qt UI widget that actually displays an image document. We combine this with a
 *          QScrollArea widget and DocumentRulerWidget widgets to create the full editor. This widget is designed to
 *          overlay things like selection decals atop an image and to permit magnification.
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

#include <QPaintEvent>
#include <QPainter>
#include <QRect>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets {
  class IImageDataSource;

  namespace SubWidgets::EditorWidget {
    class ImageDisplayWidget : public QWidget {
      Q_OBJECT
    public:
      ImageDisplayWidget(QWidget *parent = nullptr);
      ~ImageDisplayWidget() {}

      QSize sizeHint() const;

      void setDataSource(IImageDataSource *dataSource);
      void setMagnification(float newMagnification);
    private:
      IImageDataSource *m_dataSource;

      float m_magnification;

      void paintEvent(QPaintEvent *event);
    private:
      void paintWidgetRegion(QPainter &qp, QRect rect);
    };
  }
}

#endif
