#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_CUSTOMWIDGETS_SUBWIDGETS_DOCUMENTEDITORWIDGET_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_IMPL_QT_CUSTOMWIDGETS_SUBWIDGETS_DOCUMENTEDITORWIDGET_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentEditorWidget.hpp
 * PURPOSE: Headers for the custom Qt UI widget that actually displays an image document.
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

namespace SDF::Impl::UILayer {
  class IImageDataSource;

  namespace Impl::View::Impl::Qt::CustomWidgets::SubWidgets {
    class DocumentEditorWidget : public QWidget {
      Q_OBJECT
    public:
      DocumentEditorWidget(QWidget *parent = nullptr);
      ~DocumentEditorWidget() {}

      void setDataSource(IImageDataSource *dataSource);

      //void setViewport(float x1, float y1, float x2, float y2);
      //void setCenterMag(float centerX, float centerY, float mag);
    private:
      IImageDataSource *m_dataSource;

      float m_viewportX1;
      float m_viewportY1;
      float m_viewportX2;
      float m_viewportY2;

      void paintEvent(QPaintEvent *event);
    private:
      void paintWidgetRegion(QPainter &qp, QRect rect);
    };
  }
}

#endif
