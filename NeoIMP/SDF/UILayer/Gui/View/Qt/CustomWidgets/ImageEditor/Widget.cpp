/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Widget.cpp
 * PURPOSE: Implements the Widget class.
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

#include "Widget.hpp"

#include "../../../../../../Common/FunctionListener.hpp"

namespace SDF::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor {
  Widget::Widget(AbstractModel::IRenderingService *renderingService,
                 AbstractModel::IGetViewCoordinatesService *getViewCoordinatesService,
                 QWidget *parent
                )
    : QWidget(parent),
      m_getViewCoordinatesService(getViewCoordinatesService),
      m_gridLayout(new QGridLayout(this)),
      m_horizontalRuler(new Impl::RulerWidget(::Qt::Horizontal, nullptr)),
      m_verticalRuler(new Impl::RulerWidget(::Qt::Vertical, nullptr)),
      m_renderDisplayWidget(new Impl::RenderDisplayWidget(renderingService, nullptr)),
      m_horizontalScroll(new QScrollBar(::Qt::Horizontal, nullptr)),
      m_verticalScroll(new QScrollBar(::Qt::Vertical, nullptr))
  {
    m_gridLayout->addWidget(m_horizontalRuler, 0, 1);
    m_gridLayout->addWidget(m_verticalRuler, 1, 0);
    m_gridLayout->addWidget(m_renderDisplayWidget, 1, 1);
    m_gridLayout->addWidget(m_verticalScroll, 1, 2);
    m_gridLayout->addWidget(m_horizontalScroll, 2, 1);
  }

  Widget::~Widget() {
    if(m_viewportUpdateConn) {
      m_viewportUpdateConn->disconnect();
    }
  }

  void
  Widget::setEditedImage(Common::Handle imageHandle) {
    printf("psize: %d %d\n", size().width(), size().height());
    if(m_viewportUpdateConn) {
      m_viewportUpdateConn->disconnect();
    }
    m_renderDisplayWidget->setDisplayedImage(imageHandle);
    m_renderDisplayWidget->setAll(
      m_getViewCoordinatesService->getViewingPointX(imageHandle),
      m_getViewCoordinatesService->getViewingPointY(imageHandle),
      m_getViewCoordinatesService->getViewingPointMagnification(imageHandle)
    );
    update();

    auto lis = std::shared_ptr<Common::IListener<float, float, float>>(
      new Common::FunctionListener<float, float, float>(
        [&](float x1, float y1, float mag) {
          if(m_renderDisplayWidget->viewportMag() != mag) {
            m_renderDisplayWidget->setAll(x1, y1, mag);
          } else {
            m_renderDisplayWidget->setViewportUpperLeft(x1, y1);
          }
        }
      )
    );

    m_viewportUpdateConn = m_getViewCoordinatesService->addViewingPointListener(imageHandle, lis);
    m_viewportUpdateConn->connect();
  }

  float
  Widget::viewportX1() const {
    return m_renderDisplayWidget->viewportX1();
  }

  float
  Widget::viewportY1() const {
    return m_renderDisplayWidget->viewportY1();
  }

  float
  Widget::viewportX2() const {
    return m_renderDisplayWidget->viewportX2();
  }

  float
  Widget::viewportY2() const {
    return m_renderDisplayWidget->viewportY2();
  }
}
