#ifndef SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_EDITVIEWWIDGET_SELECTIONDECALWIDGET_HPP
#define SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_SUBWIDGETS_EDITVIEWWIDGET_SELECTIONDECALWIDGET_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SelectionDecalWidget.hpp
 * PURPOSE: Defines the SelectionDecalWidget class.
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
    // Class:      SelectionDecalWidget
    // Purpose:    Draws a selection decal on an image.
    // Parameters: None.
    class SelectionDecalWidget : public QWidget {
      Q_OBJECT
    public:
      ImageDisplayWidget(QWidget *parent = nullptr);
      ~ImageDisplayWidget() {}

      void
      setDataSource(IImageDataSource *dataSource);

      QPointF
      translate() const;

      float
      zoom() const;

      void
      setTranslate(const QPointF &translate);

      void
      setZoom(float zoomFactor);

      QRect
      getImageRect() const;

      QRect
      getViewportRect() const;

      QPolygonF
      getViewportOnImage(bool closed = false) const;

      QPointF
      getImageCoordinatesOf(QPointF viewportPoint) const;
    private:
      IImageDataSource *m_dataSource;

      QPointF m_translation;
      float m_magnification;

      void
      paintEvent(QPaintEvent *event);
    private:
      QTransform
      makeTransformToImage() const;

      void
      paintWidgetRegion(QPainter &qp,
                        QRect rect
                       );
    };
  }
}

#endif
