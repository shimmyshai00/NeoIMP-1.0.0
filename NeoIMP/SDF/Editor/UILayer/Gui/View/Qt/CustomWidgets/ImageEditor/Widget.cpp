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

#include "../../../../../../../Common/FunctionListener.hpp"

#include <cmath>

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor {
  Widget::Widget(
    AbstractModel::Metrics::IGetDocumentDimensionsService *getDocumentDimensionsService,
    AbstractModel::Viewing::IAddViewService *addViewService,
    AbstractModel::Viewing::IGetViewCoordinatesService *getViewCoordinatesService,
    AbstractModel::Viewing::IRenderingService *renderingService,
    QWidget *parent
  )
    : QWidget(parent),
      m_getDocumentDimensionsService(getDocumentDimensionsService),
      m_addViewService(addViewService),
      m_getViewCoordinatesService(getViewCoordinatesService),
      m_renderingService(renderingService),
      m_gridLayout(new QGridLayout(this)),
      m_horizontalRuler(new Impl::RulerWidget(::Qt::Horizontal, nullptr)),
      m_verticalRuler(new Impl::RulerWidget(::Qt::Vertical, nullptr)),
      m_renderDisplayWidget(new Impl::RenderDisplayWidget(renderingService, nullptr)),
      m_horizontalScroll(new QScrollBar(::Qt::Horizontal, nullptr)),
      m_verticalScroll(new QScrollBar(::Qt::Vertical, nullptr)),
      m_documentHandle(Common::HANDLE_INVALID),
      m_documentViewDataHandle(Common::HANDLE_INVALID)
  {
    m_gridLayout->addWidget(m_horizontalRuler, 0, 1);
    m_gridLayout->addWidget(m_verticalRuler, 1, 0);
    m_gridLayout->addWidget(m_renderDisplayWidget, 1, 1);
    m_gridLayout->addWidget(m_verticalScroll, 1, 2);
    m_gridLayout->addWidget(m_horizontalScroll, 2, 1);

    connect(m_horizontalScroll, &QScrollBar::sliderMoved, [&](int value) {
      m_hScrollEvent.trigger(m_documentHandle, m_hViewSlideCalc.getOnObjPosFromSlide(value));
    });
    connect(m_verticalScroll, &QScrollBar::sliderMoved, [&](int value) {
      m_vScrollEvent.trigger(m_documentHandle, m_vViewSlideCalc.getOnObjPosFromSlide(value));
    });
  }

  Widget::~Widget() {
    if(m_viewportUpdateConn) {
      m_viewportUpdateConn->disconnect();
    }
  }

  void
  Widget::setEditedImage(Common::Handle imageHandle) {
    using namespace UILayer::AbstractModel::Defs;

    printf("psize: %d %d\n", size().width(), size().height());
    if(m_viewportUpdateConn) {
      m_viewportUpdateConn->disconnect();
    }
    m_renderDisplayWidget->setDisplayedImage(imageHandle);
    m_documentHandle = imageHandle;

    // NB: TBA - delete old view
    m_documentViewDataHandle = m_addViewService->addView(m_documentHandle, 0.0f, 0.0f, 1.0f);

    m_renderDisplayWidget->setAll(
      m_getViewCoordinatesService->getViewingPointX(m_documentViewDataHandle),
      m_getViewCoordinatesService->getViewingPointY(m_documentViewDataHandle),
      m_getViewCoordinatesService->getViewingPointMagnification(m_documentViewDataHandle)
    );

    m_horizontalRuler->setAll(
      m_getViewCoordinatesService->getViewingPointX(m_documentViewDataHandle),
      m_getViewCoordinatesService->getViewingPointMagnification(m_documentViewDataHandle)
    );

    m_verticalRuler->setAll(
      m_getViewCoordinatesService->getViewingPointY(m_documentViewDataHandle),
      m_getViewCoordinatesService->getViewingPointMagnification(m_documentViewDataHandle)
    );

    float docWidth(m_getDocumentDimensionsService->getDocumentWidth(m_documentHandle,
      LENGTH_UNIT_PIXEL));
    float docHeight(m_getDocumentDimensionsService->getDocumentHeight(m_documentHandle,
      LENGTH_UNIT_PIXEL));

    float viewWidth(m_renderDisplayWidget->intrViewportWidth());
    float viewHeight(m_renderDisplayWidget->intrViewportHeight());
    float viewMag(m_renderDisplayWidget->viewportMag());

    float viewX1(m_renderDisplayWidget->viewportX1());
    float viewY1(m_renderDisplayWidget->viewportY1());

    m_hViewSlideCalc.setObjectLength(docWidth);
    m_hViewSlideCalc.setViewportByLengthAndMag(viewWidth, viewMag);

    m_vViewSlideCalc.setObjectLength(docHeight);
    m_vViewSlideCalc.setViewportByLengthAndMag(viewHeight, viewMag);

    m_horizontalScroll->setRange(m_hViewSlideCalc.getSlideMin(), m_hViewSlideCalc.getSlideMax());
    m_verticalScroll->setRange(m_vViewSlideCalc.getSlideMin(), m_vViewSlideCalc.getSlideMax());

    printf("hrange: %d %d\n", m_hViewSlideCalc.getSlideMin(), m_hViewSlideCalc.getSlideMax());
    printf("vrange: %d %d\n", m_vViewSlideCalc.getSlideMin(), m_vViewSlideCalc.getSlideMax());

    m_horizontalScroll->setPageStep(m_hViewSlideCalc.getPageStep());
    m_verticalScroll->setPageStep(m_vViewSlideCalc.getPageStep());

    m_horizontalScroll->setSliderPosition(m_hViewSlideCalc.getSlidePosFromOnObj(viewX1));
    m_verticalScroll->setSliderPosition(m_vViewSlideCalc.getSlidePosFromOnObj(viewY1));

    update();

    auto lis = std::shared_ptr<Common::IListener<float, float, float>>(
      new Common::FunctionListener<float, float, float>(
        [&](float x1, float y1, float mag) {
          if(m_renderDisplayWidget->viewportMag() != mag) {
            m_horizontalRuler->setAll(x1, mag);
            m_verticalRuler->setAll(y1, mag);
            m_renderDisplayWidget->setAll(x1, y1, mag);

            float viewWidth(m_renderDisplayWidget->intrViewportWidth());
            float viewHeight(m_renderDisplayWidget->intrViewportHeight());
            float viewMag(m_renderDisplayWidget->viewportMag());

            float viewX1(m_renderDisplayWidget->viewportX1());
            float viewY1(m_renderDisplayWidget->viewportY1());

            m_hViewSlideCalc.setViewportByLengthAndMag(viewWidth, viewMag);
            m_vViewSlideCalc.setViewportByLengthAndMag(viewHeight, viewMag);

            m_horizontalScroll->setRange(m_hViewSlideCalc.getSlideMin(),
              m_hViewSlideCalc.getSlideMax());
            m_verticalScroll->setRange(m_vViewSlideCalc.getSlideMin(),
              m_vViewSlideCalc.getSlideMax());

            m_horizontalScroll->setPageStep(m_hViewSlideCalc.getPageStep());
            m_verticalScroll->setPageStep(m_vViewSlideCalc.getPageStep());

            m_horizontalScroll->setSliderPosition(m_hViewSlideCalc.getSlidePosFromOnObj(viewX1));
            m_verticalScroll->setSliderPosition(m_vViewSlideCalc.getSlidePosFromOnObj(viewY1));
          } else {
            m_horizontalRuler->setViewportP1(x1);
            m_verticalRuler->setViewportP1(y1);
            m_renderDisplayWidget->setViewportUpperLeft(x1, y1);

            float viewX1(m_renderDisplayWidget->viewportX1());
            float viewY1(m_renderDisplayWidget->viewportY1());

            m_horizontalScroll->setSliderPosition(m_hViewSlideCalc.getSlidePosFromOnObj(viewX1));
            m_verticalScroll->setSliderPosition(m_vViewSlideCalc.getSlidePosFromOnObj(viewY1));
          }
        }
      )
    );

    m_viewportUpdateConn = m_getViewCoordinatesService->addViewingPointListener(
      m_documentViewDataHandle, lis);
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

  Common::PIConnection
  Widget::hookOnHScroll(std::unique_ptr<IController<Common::Handle, float>> controller) {
    return m_hScrollEvent.hook(std::move(controller));
  }

  Common::PIConnection
  Widget::hookOnVScroll(std::unique_ptr<IController<Common::Handle, float>> controller) {
    return m_vScrollEvent.hook(std::move(controller));
  }
}

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor {
  // Protected event handlers.
  void
  Widget::resizeEvent(QResizeEvent *event) {
    float viewWidth(m_renderDisplayWidget->intrViewportWidth());
    float viewHeight(m_renderDisplayWidget->intrViewportHeight());
    float viewMag(m_renderDisplayWidget->viewportMag());

    m_hViewSlideCalc.setViewportByLengthAndMag(viewWidth, viewMag);
    m_vViewSlideCalc.setViewportByLengthAndMag(viewHeight, viewMag);

    m_horizontalScroll->setRange(m_hViewSlideCalc.getSlideMin(), m_hViewSlideCalc.getSlideMax());
    m_verticalScroll->setRange(m_vViewSlideCalc.getSlideMin(), m_vViewSlideCalc.getSlideMax());

    m_horizontalScroll->setPageStep(m_hViewSlideCalc.getPageStep());
    m_verticalScroll->setPageStep(m_vViewSlideCalc.getPageStep());
  }
}
