/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CImageDisplay.cpp
 * PURPOSE: Implementation of the Qt-based image display subwidget.
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

#include <Impl/Qt/CustomWidgets/CImageDisplay.hpp>

#include <SDF/ModelLayer/DocumentModel/include/Services/IDocumentImageDataService.hpp>
#include <SDF/ModelLayer/DocumentModel/include/Services/IPixelVisitor.hpp>

#include <Impl/Qt/CustomWidgets/CViewport2D.hpp>

#include <QSizePolicy>
#include <QPainter>
#include <QColor>

#include <iostream>

namespace SDF {
  namespace UILayer {
    namespace Impl::Qt::CustomWidgets {
      // Helper class.
      class CPixelDrawingVisitor : public ModelLayer::DocumentModel::Services::IPixelVisitor {
      public:
        CPixelDrawingVisitor(QPainter *qp)
        : m_qp(qp),
          m_plotX(0),
          m_plotY(0)
          {
          }

        void setPlotPos(int plotX, int plotY) {
          m_plotX = plotX;
          m_plotY = plotY;
        }

        void readOnlyVisitRGB(int a, int r, int g, int b, int max) {
          float rScaled((0.0f + r) / max * 255.0);
          float gScaled((0.0f + r) / max * 255.0);
          float bScaled((0.0f + r) / max * 255.0);

          m_qp->setPen(QColor(rScaled, gScaled, bScaled));
          m_qp->drawPoint(m_plotX, m_plotY);
        }

        void readOnlyVisitCMYK(int a, int c, int m, int y, int k, int max) {

        }
      private:
        QPainter *m_qp;

        int m_plotX;
        int m_plotY;
      };
    }
  }
}

namespace SDF {
  namespace UILayer {
    namespace Impl::Qt::CustomWidgets {
      CImageDisplay::CImageDisplay(QWidget *parent)
      : QWidget(parent),
        m_documentImageDataService(nullptr),
        m_documentHandle(-1), // nb: make special constant?
        m_viewCenterX(0),
        m_viewCenterY(0),
        m_magnificationFactor(1.0f)
      {
        setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
      }

      void CImageDisplay::injectWith(ModelLayer::DocumentModel::Services::IDocumentImageDataService *service) {
        m_documentImageDataService = service;
      }

      void CImageDisplay::setActiveDocument(ModelLayer::DocumentModel::DocumentHandle handle) {
        m_documentHandle = handle;
      }

      void CImageDisplay::paintEvent(QPaintEvent *event) {
        QPainter qp(this);

        drawWidget(qp);
      }

      void CImageDisplay::drawWidget(QPainter &qp) {
        //std::cout << "draw" << std::endl;
        if((m_documentImageDataService != nullptr) && (m_documentHandle != -1)) {
          //std::cout << "draw2" << std::endl;

          // inefficient stub!
          int imageWidthPx(m_documentImageDataService->getImageWidthInPixels(m_documentHandle));
          int imageHeightPx(m_documentImageDataService->getImageHeightInPixels(m_documentHandle));

          CPixelDrawingVisitor vis(&qp);
          
          for(int y(0); y < imageHeightPx; ++y) {
            for(int x(0); x < imageWidthPx; ++x) {
              vis.setPlotPos(x, y);
              m_documentImageDataService->visitLayerPixel(m_documentHandle, 0, x, y, vis);
            }
          }
        }
      }
    }
  }
}
