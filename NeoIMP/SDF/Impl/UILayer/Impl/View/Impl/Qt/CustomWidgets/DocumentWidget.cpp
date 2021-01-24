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

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt::CustomWidgets {
  DocumentWidget::DocumentWidget(QWidget *parent, ::Qt::WindowFlags f)
    : QWidget(parent, f)
  {
    // The layout of this widget consists of two rulers on either side of the image display.
    m_gridLayout = new QGridLayout(this);
    m_horizontalRuler = new SubWidgets::DocumentRulerWidget(::Qt::Horizontal);
    m_verticalRuler = new SubWidgets::DocumentRulerWidget(::Qt::Vertical);

    m_scrollArea = new QScrollArea();
    m_scrollArea->setBackgroundRole(QPalette::Dark);
    m_documentEditorWidget = new SubWidgets::DocumentEditorWidget();
    m_scrollArea->setWidget(m_documentEditorWidget);

    m_gridLayout->addWidget(m_horizontalRuler, 0, 1);
    m_gridLayout->addWidget(m_verticalRuler, 1, 0);
    m_gridLayout->addWidget(m_scrollArea, 1, 1);

    // Connect the rulers to the scroll bars.
    QObject::connect(m_scrollArea->horizontalScrollBar(), &QScrollBar::rangeChanged, m_horizontalRuler, &SubWidgets::DocumentRulerWidget::setScrollRange);
    QObject::connect(m_scrollArea->horizontalScrollBar(), &QScrollBar::valueChanged, m_horizontalRuler, &SubWidgets::DocumentRulerWidget::setScrollPosition);
    QObject::connect(m_scrollArea->verticalScrollBar(), &QScrollBar::rangeChanged, m_verticalRuler, &SubWidgets::DocumentRulerWidget::setScrollRange);
    QObject::connect(m_scrollArea->verticalScrollBar(), &QScrollBar::valueChanged, m_verticalRuler, &SubWidgets::DocumentRulerWidget::setScrollPosition);
  }

  void DocumentWidget::setDataSource(IImageDataSource *dataSource) {
    m_documentEditorWidget->setDataSource(dataSource);
    m_documentEditorWidget->setMinimumSize(m_documentEditorWidget->sizeHint());

    m_horizontalRuler->measureObject(0, dataSource->getImageWidth()-1);
    m_verticalRuler->measureObject(0, dataSource->getImageHeight()-1);
  }
}
