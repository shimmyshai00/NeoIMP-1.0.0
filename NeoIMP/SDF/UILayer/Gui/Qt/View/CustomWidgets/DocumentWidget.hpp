#ifndef SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_DOCUMENTWIDGET_HPP
#define SDF_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_DOCUMENTWIDGET_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentWidget.hpp
 * PURPOSE: Headers for a custom Qt UI widget for displaying and editing a document.
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

#include <SDF/UILayer/AbstractModel/Properties/Tool.hpp>

#include <QWidget>
#include <QGridLayout>
#include <QScrollBar>

#include <QEvent>
#include <QResizeEvent>
#include <QMetaObject>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets {
  namespace SubWidgets {
    class DocumentRulerWidget;
    class DocumentEditorWidget;
  }

  class IImageDataSource;

  class DocumentWidget : public QWidget {
    Q_OBJECT
  public:
    DocumentWidget(QWidget *parent = nullptr, ::Qt::WindowFlags f = ::Qt::WindowFlags());
    ~DocumentWidget() {}

    void setDataSource(IImageDataSource *dataSource);

    float centerX() const;
    float centerY() const;
    float magnification() const;

    void setCenterX(float centerX);
    void setCenterY(float centerY);
    void setMagnification(float magnification);

    void setTool(AbstractModel::Properties::Tool tool);
  signals:
    void editorClickedAt(float documentX, float documentY);
    void editorDraggedOnTo(float documentX, float documentY);
    void editorClickReleasedAt(float documentX, float documentY);
  protected:
    bool
    event(QEvent *event);

    void
    resizeEvent(QResizeEvent *event);
  private:
    QGridLayout *m_gridLayout;

    SubWidgets::DocumentRulerWidget *m_horizontalRuler;
    SubWidgets::DocumentRulerWidget *m_verticalRuler;

    QScrollBar *m_horizontalScrollBar;
    QScrollBar *m_verticalScrollBar;

    QMetaObject::Connection m_hsbValChangeConn;
    QMetaObject::Connection m_vsbValChangeConn;

    //QScrollArea *m_scrollArea;
    SubWidgets::DocumentEditorWidget *m_documentEditorWidget;

    void
    setTranslate(QPointF translate, bool noScrollUpdate = false);

    void
    setZoom(float zoom, bool noScrollUpdate = false);

    void
    centerViewAt(QPointF centerPoint, bool noScrollUpdate = false);

    void
    recalculateScrollBarRanges();

    void
    disconnectScrollHandlers();

    void
    connectScrollHandlers();

    void
    resetScrollBarValues();
  };
}

#endif
