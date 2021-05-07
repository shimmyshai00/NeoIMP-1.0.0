/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentWidget.cpp
 * PURPOSE: Implementation of a custom Qt UI widget for displaying and editing a document.
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

#include <DocumentWidget.hpp>
#include <SubWidgets/DocumentRulerWidget.hpp>
#include <SubWidgets/DocumentEditorWidget.hpp>

#include <IImageDataSource.hpp>

#include <QSizePolicy>
#include <QScrollBar>
#include <QResizeEvent>

#include <cmath>

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets {
  // Helper method.
  int
  calcScrollBarRange(int zoomedImageDimen, int viewportDimen) {
    return std::max(0, zoomedImageDimen - viewportDimen);
  }
}

namespace SDF::UILayer::Gui::Qt::View::CustomWidgets {
  DocumentWidget::DocumentWidget(QWidget *parent, ::Qt::WindowFlags f)
    : QWidget(parent, f)
  {
    // The layout of this widget consists of two rulers on either side of the image display, and two scroll bars on
    // the opposite sides.
    m_gridLayout = new QGridLayout(this);
    m_horizontalRuler = new SubWidgets::DocumentRulerWidget(::Qt::Horizontal);
    m_verticalRuler = new SubWidgets::DocumentRulerWidget(::Qt::Vertical);
    m_horizontalScrollBar = new QScrollBar(::Qt::Horizontal);
    m_verticalScrollBar = new QScrollBar(::Qt::Vertical);

    m_documentEditorWidget = new SubWidgets::DocumentEditorWidget();

    m_gridLayout->addWidget(m_horizontalRuler, 0, 1);
    m_gridLayout->addWidget(m_verticalRuler, 1, 0);
    m_gridLayout->addWidget(m_documentEditorWidget, 1, 1);
    m_gridLayout->addWidget(m_horizontalScrollBar, 2, 1);
    m_gridLayout->addWidget(m_verticalScrollBar, 1, 2);

    // Connect scrolling methods.
    connectScrollHandlers();

    // Connect the inner editor pane interactor signals to their externalized counterparts.
    QObject::connect(m_documentEditorWidget, &SubWidgets::DocumentEditorWidget::clickedAt,
      this, &DocumentWidget::editorClickedAt);
    QObject::connect(m_documentEditorWidget, &SubWidgets::DocumentEditorWidget::draggedTo,
      this, &DocumentWidget::editorDraggedOnTo);
    QObject::connect(m_documentEditorWidget, &SubWidgets::DocumentEditorWidget::releasedAt,
      this, &DocumentWidget::editorClickReleasedAt);
  }

  void DocumentWidget::setDataSource(IImageDataSource *dataSource) {
    m_documentEditorWidget->setDataSource(dataSource);

    //m_horizontalRuler->setObject(0, dataSource->getImageWidth()-1);
    //m_verticalRuler->setObject(0, dataSource->getImageHeight()-1);
  }

  float DocumentWidget::centerX() const {
    QPolygonF viewportPolygon(m_documentEditorWidget->getViewportOnImage());
    QPointF viewportCenter(0.0f, 0.0f);

    for(auto point : viewportPolygon) {
      viewportCenter += point;
    }

    return (viewportCenter / viewportPolygon.size()).x();
  }

  float DocumentWidget::centerY() const {
    QPolygonF viewportPolygon(m_documentEditorWidget->getViewportOnImage());
    QPointF viewportCenter(0.0f, 0.0f);

    for(auto point : viewportPolygon) {
      viewportCenter += point;
    }

    return (viewportCenter / viewportPolygon.size()).y();
  }

  float DocumentWidget::magnification() const {
    return m_documentEditorWidget->zoom();
  }

  void DocumentWidget::setCenterX(float centerX) {
    centerViewAt(QPointF(centerX, centerY()));
  }

  void DocumentWidget::setCenterY(float centerY) {
    centerViewAt(QPointF(centerX(), centerY));
  }

  void DocumentWidget::setMagnification(float magnification) {
    QPointF curCenter(centerX(), centerY());

    setZoom(magnification);
    centerViewAt(curCenter);
  }

  void DocumentWidget::setTool(AbstractModel::Properties::Tool tool) {
    m_documentEditorWidget->setCursorByTool(tool);
  }

  bool
  DocumentWidget::event(QEvent *event) {
    if((event->type() == QEvent::StyleChange) || (event->type() == QEvent::LayoutRequest)) {
      recalculateScrollBarRanges();
      resetScrollBarValues();
    }

    return QWidget::event(event);
  }

  void
  DocumentWidget::resizeEvent(QResizeEvent *event) {
    recalculateScrollBarRanges();
    resetScrollBarValues();
  }

  // Private members.
  void
  DocumentWidget::setTranslate(QPointF translate, bool noScrollUpdate) {
    m_documentEditorWidget->setTranslate(translate);
    m_horizontalRuler->setTranslation(translate.x());
    m_verticalRuler->setTranslation(translate.y());

    if(!noScrollUpdate) {
      resetScrollBarValues();
    }
  }

  void
  DocumentWidget::setZoom(float zoom, bool noScrollUpdate) {
    m_documentEditorWidget->setZoom(zoom);
    m_horizontalRuler->setMagnification(zoom);
    m_verticalRuler->setMagnification(zoom);

    if(!noScrollUpdate) {
      recalculateScrollBarRanges();
      resetScrollBarValues();
    }
  }

  void
  DocumentWidget::centerViewAt(QPointF centerPoint, bool noScrollUpdate) {
    // Centers the view at the given *image* position under the current magnification.
    QPolygonF viewportPolygon(m_documentEditorWidget->getViewportOnImage());
    QPointF viewportCenterImg(0.0f, 0.0f);

    for(auto point : viewportPolygon) {
      viewportCenterImg += point;
    }

    viewportCenterImg /= viewportPolygon.size();
    QPointF newCenterImg(centerPoint);

    setTranslate(m_documentEditorWidget->translate() + (newCenterImg - viewportCenterImg), noScrollUpdate);
  }

  void
  DocumentWidget::recalculateScrollBarRanges() {
    int imageWidth(m_documentEditorWidget->getImageRect().width());
    int imageHeight(m_documentEditorWidget->getImageRect().height());

    int viewportWidth(m_documentEditorWidget->getViewportRect().width());
    int viewportHeight(m_documentEditorWidget->getViewportRect().height());

    printf("imageDim: %d x %d\n", imageWidth, imageHeight);
    printf("viewportDim: %d x %d\n", viewportWidth, viewportHeight);
    printf("rectDim: %d x %d\n", m_documentEditorWidget->rect().width(), m_documentEditorWidget->rect().height());

    m_horizontalScrollBar->setMinimum(0);
    m_horizontalScrollBar->setMaximum(calcScrollBarRange(imageWidth * m_documentEditorWidget->zoom(), viewportWidth));
    m_horizontalScrollBar->setPageStep(viewportWidth);

    m_verticalScrollBar->setMinimum(0);
    m_verticalScrollBar->setMaximum(calcScrollBarRange(imageHeight * m_documentEditorWidget->zoom(), viewportHeight));
    m_verticalScrollBar->setPageStep(viewportHeight);
  }

  void
  DocumentWidget::disconnectScrollHandlers() {
    disconnect(m_hsbValChangeConn);
    disconnect(m_vsbValChangeConn);
  }

  void
  DocumentWidget::connectScrollHandlers() {
    m_hsbValChangeConn = QObject::connect(m_horizontalScrollBar, &QScrollBar::sliderMoved, [=](int value) {
      // The scroll value is relative to the *zoomed* image rectangle. Get it in the normal one.
      QPointF translate(m_documentEditorWidget->translate());
      translate.setX(value / m_documentEditorWidget->zoom());

      setTranslate(translate, true);
    });

    m_vsbValChangeConn = QObject::connect(m_verticalScrollBar, &QScrollBar::sliderMoved, [=](int value) {
      QPointF translate(m_documentEditorWidget->translate());
      translate.setY(value / m_documentEditorWidget->zoom());

      setTranslate(translate, true);
    });
  }

  void
  DocumentWidget::resetScrollBarValues() {
    // The scroll bar value is just the amount of translation, zoomed.
    disconnectScrollHandlers();
    m_horizontalScrollBar->setValue(m_documentEditorWidget->translate().x() * m_documentEditorWidget->zoom());
    m_verticalScrollBar->setValue(m_documentEditorWidget->translate().y() * m_documentEditorWidget->zoom());

    if((m_horizontalScrollBar->value() == m_horizontalScrollBar->maximum()) ||
       (m_verticalScrollBar->value() == m_verticalScrollBar->maximum()))
    {
      // scrollbars saturated
      QPointF translate(m_horizontalScrollBar->value() / m_documentEditorWidget->zoom(),
                        m_verticalScrollBar->value() / m_documentEditorWidget->zoom()
                       );
      setTranslate(translate, true);
    }

    connectScrollHandlers();
  }
}
