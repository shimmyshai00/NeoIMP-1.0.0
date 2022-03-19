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

#include <SDF/UILayer/AbstractModel/Properties/Tool.hpp> // NB: right "level" or not?
#include <SDF/UILayer/Gui/Qt/View/CustomWidgets/SubWidgets/EditViewWidget/AbstractViewport.hpp>

#include <QWidget>

#include <QPointF>
#include <QRect>
#include <QRectF>

#include <QTransform>

#include <QPaintEvent>
#include <QPainter>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets {
  class IImageDataSource;

  namespace SubWidgets::EditViewWidget {
    // Class:      ImageDisplayWidget
    // Purpose:    Defines the image display widget. This widget shows a view onto rendered image data provided by a
    //             data source.
    // Parameters: None.
    class ImageDisplayWidget : public AbstractViewport {
      Q_OBJECT
    public:
      ImageDisplayWidget(QWidget *parent = nullptr);
      ~ImageDisplayWidget() {}

      void
      setDataSource(IImageDataSource *dataSource);
    signals:
      void
      clickedAt(float documentX, float documentY);

      void
      draggedTo(float documentX, float documentY);

      void
      releasedAt(float documentX, float documentY);
    protected:
      void
      mousePressEvent(QMouseEvent *event);

      void
      mouseMoveEvent(QMouseEvent *event);

      void
      mouseReleaseEvent(QMouseEvent *event);
    private:
      IImageDataSource *m_dataSource;

      void
      paintEvent(QPaintEvent *event);

      void
      paintWidgetRegion(QPainter &qp,
                        QRect rect
                       );
    };
  }
}

#endif
