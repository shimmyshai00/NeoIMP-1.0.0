/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RenderDisplayWidget.cpp
 * PURPOSE: Implements the RenderDisplayWidget class.
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

#include "RenderDisplayWidget.hpp"

#include <QPaintEvent>
#include <QRegion>

#include <cmath>

namespace SDF::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor::Impl {
  RenderDisplayWidget::RenderDisplayWidget(AbstractModel::IRenderingService *renderingService,
                                           QWidget *parent
                                          )
    : QWidget(parent),
      m_renderingService(renderingService),
      m_imageHandle(Common::HANDLE_INVALID),
      m_renderHandle(Common::HANDLE_INVALID),
      m_viewUpperLeftX(0.0f),
      m_viewUpperLeftY(0.0f),
      m_viewMagnification(1.0f)
  {
  }

  RenderDisplayWidget::~RenderDisplayWidget() {
    if(m_renderHandle != Common::HANDLE_INVALID) {
      m_renderingService->deleteRendering(m_renderHandle);
      m_renderHandle = Common::HANDLE_INVALID;
    }
  }

  void
  RenderDisplayWidget::setDisplayedImage(Common::Handle imageHandle) {
    if(m_renderHandle != Common::HANDLE_INVALID) {
      m_renderingService->deleteRendering(m_renderHandle);
      m_renderHandle = Common::HANDLE_INVALID;
    }

    m_imageHandle = imageHandle;

    m_viewUpperLeftX = 0.0f;
    m_viewUpperLeftY = 0.0f;
    m_viewMagnification = 1.0f;
  }

  float
  RenderDisplayWidget::viewportX1() const {
    return m_viewUpperLeftX;
  }

  float
  RenderDisplayWidget::viewportY1() const {
    return m_viewUpperLeftY;
  }

  float
  RenderDisplayWidget::viewportX2() const {
    return m_viewUpperLeftX + ((size().width() - 1) / m_viewMagnification);
  }

  float
  RenderDisplayWidget::viewportY2() const {
    return m_viewUpperLeftY + ((size().height() - 1) / m_viewMagnification);
  }
}

namespace SDF::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor::Impl {
  void
  RenderDisplayWidget::paintEvent(QPaintEvent *event) {
    using AbstractModel::Defs::IRenderRegion;

    // This is the fun bit. First, render the image if it isn't already rendered.
    if(m_renderHandle == Common::HANDLE_INVALID) {
      // Needs rendering. Not memory efficient yet.
      m_renderHandle = m_renderingService->createStaticRendering(m_imageHandle);
    }

    // Now, figure out the viewport coordinates.
    // NB: no negatives handled yet!
    std::size_t m_intViewX1 = floor(viewportX1()); // make sure of full coverage
    std::size_t m_intViewY1 = floor(viewportY1());
    std::size_t m_intViewX2 = ceil(viewportX2());
    std::size_t m_intViewY2 = ceil(viewportY2());

    // Get the region of the *widget* that needs updating.
    QRegion widgetPaintRegion = event->region();

    // Loop through its rectangles.
    for(const QRect &rect : widgetPaintRegion) {

    }
  }
}
