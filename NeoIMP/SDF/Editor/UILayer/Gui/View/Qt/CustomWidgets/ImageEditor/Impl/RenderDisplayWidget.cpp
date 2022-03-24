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
#include <QPainter>
#include <QRegion>
#include <QTransform>

#include <cmath>

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor::Impl {
  RenderDisplayWidget::RenderDisplayWidget(
    AbstractModel::Viewing::IRenderingService *renderingService,
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

    printf("size: %d %d\n", size().width(), size().height());

    update();
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
    return m_viewUpperLeftX + (size().width() / m_viewMagnification);
  }

  float
  RenderDisplayWidget::viewportY2() const {
    return m_viewUpperLeftY + (size().height() / m_viewMagnification);
  }

  float
  RenderDisplayWidget::intrViewportWidth() const {
    return size().width();
  }

  float
  RenderDisplayWidget::intrViewportHeight() const {
    return size().height();
  }

  float
  RenderDisplayWidget::viewportWidth() const {
    return size().width() / m_viewMagnification;
  }

  float
  RenderDisplayWidget::viewportHeight() const {
    return size().height() / m_viewMagnification;
  }

  float
  RenderDisplayWidget::viewportMag() const {
    return m_viewMagnification;
  }

  void
  RenderDisplayWidget::setViewportX1(float x1) {
    m_viewUpperLeftX = x1;
    update();
  }

  void
  RenderDisplayWidget::setViewportY1(float y1) {
    m_viewUpperLeftY = y1;
    update();
  }

  void
  RenderDisplayWidget::setViewportUpperLeft(float x1, float y1) {
    m_viewUpperLeftX = x1;
    m_viewUpperLeftY = y1;
    update();
  }

  void
  RenderDisplayWidget::setViewportMag(float mag) {
    m_viewMagnification = mag;
    update();
  }

  void
  RenderDisplayWidget::setAll(float x1, float y1, float mag) {
    m_viewUpperLeftX = x1;
    m_viewUpperLeftY = y1;
    m_viewMagnification = mag;
    update();
  }
}

namespace SDF::Editor::UILayer::Gui::View::Qt::CustomWidgets::ImageEditor::Impl {
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

    // Obtain this region from the renderer.
    std::shared_ptr<IRenderRegion> renderRegion(m_renderingService->getRegion(m_renderHandle,
      m_intViewX1, m_intViewY1, m_intViewX2, m_intViewY2));

    // Create a list of QImages covering the region. Note that because these QImages don't have to
    // store data themselves, this is fairly cheap.
    std::vector<std::pair<QPoint, QImage>> qImagesAndPositions;
    renderRegion->traverse([=, &qImagesAndPositions](IRenderRegion::TileElement el) {
      qImagesAndPositions.push_back(std::make_pair(
        QPoint(el.xOrigin, el.yOrigin),
        QImage(el.originPtr, el.width, el.height, el.rowStride, QImage::Format_RGB32)
      ));
    });

    // Next, harness QPainter's transformation functionality to build a mapping of this region into
    // the widget. In particular, we want to transform the rectangle (viewportX1(), viewportY1())-
    // (viewportX2(), viewportY2()) into (0, 0)-(size().width(),size().height()). That is, we
    // are treating the initial QPainter space as image space, so we then can blit rectangles to it
    // corresponding to pieces of the image to be drawn. Note that order of the transformations
    // matters!
    QPainter painter(this);
    painter.setBrush(QBrush(QColor(45, 45, 45)));
    // FOUND BUG: dammit, Qt's matrix transforms compose BACKWARDS, i.e. thy don't compose in the
    // order in which the commands are sent, but the opposite!
    painter.scale(m_viewMagnification, m_viewMagnification);
    painter.translate(-viewportX1(), -viewportY1());
    // NB: we could add rotate in the future! <- this would be NIFTY

    QTransform inverseTransform;
    inverseTransform.translate(viewportX1(), viewportY1());
    inverseTransform.scale(1.0f / m_viewMagnification, 1.0f / m_viewMagnification);

    // Get the region of the *widget* that needs updating.
    QRegion widgetPaintRegion = event->region();

    // Loop through its rectangles. NB: this is not yet set up to handle view rotations
    for(const QRect &rect : widgetPaintRegion) {
      // Obtain what this rectangle corresponds to in *image* space via the inverse transform. That
      // way, when drawn, it maps out correctly given the set transform in the QPainter.
      QRectF srcRectF = inverseTransform.mapRect(rect);

      // Go through the QImages and blit the ones covering this rectangle.
      for(const auto &imagePair : qImagesAndPositions) {
        QRectF qImageSrcRectF(imagePair.first, imagePair.second.size());
        if(qImageSrcRectF.intersects(srcRectF)) {
          QRectF cropRectF = srcRectF.intersected(qImageSrcRectF);
          cropRectF.translate(-qImageSrcRectF.left(), -qImageSrcRectF.top());
          painter.drawImage(srcRectF.topLeft(), imagePair.second, cropRectF);
        }
      }
    }
  }
}
