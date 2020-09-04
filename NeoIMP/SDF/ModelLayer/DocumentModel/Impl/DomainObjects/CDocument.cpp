/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CDocument.cpp
 * PURPOSE: Implementation of the document class.
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

#include <Impl/DomainObjects/CDocument.hpp>

#include <Impl/DomainObjects/Pixel/IPixelVisitor.hpp>
#include <Impl/DomainObjects/Metrics/Dimensionless/Quantity.hpp>

#include <Impl/DomainObjects/CLayer.hpp>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects {
        CDocument::CDocument(int width, int height,
          Metrics::Resolution::Quantity resolution,
          Spec::EColorModel colorModel, Spec::EBitDepth bitDepth)
          : m_documentWidthPx(width),
            m_documentHeightPx(height),
            m_documentWidthPhys(Metrics::Dimensionless::Quantity(width) / resolution),
            m_documentHeightPhys(Metrics::Dimensionless::Quantity(height) / resolution),
            m_documentResolution(resolution),
            m_colorModel(colorModel),
            m_bitDepth(bitDepth),
            m_layerStack(0)
            {
              if((m_documentWidthPx < 1) || (m_documentHeightPx < 1)) {
                throw BadDocumentSizeException(m_documentWidthPx, m_documentHeightPx);
              } else if((m_documentWidthPx > c_maxDocumentWidthPx) || (m_documentHeightPx > c_maxDocumentHeightPx)) {
                throw DocumentSizeTooBigException(m_documentWidthPx, m_documentHeightPx);
              }

              m_layerStack.push_back(std::make_unique<CLayer>(m_documentWidthPx, m_documentHeightPx,
                m_colorModel, m_bitDepth));
            }

        CDocument::CDocument(Metrics::Length::Quantity widthPhys, Metrics::Length::Quantity heightPhys,
          Metrics::Resolution::Quantity resolution,
          Spec::EColorModel colorModel, Spec::EBitDepth bitDepth)
          : m_documentWidthPx(Metrics::Dimensionless::DimlessVal(widthPhys * resolution)),
            m_documentHeightPx(Metrics::Dimensionless::DimlessVal(heightPhys * resolution)),
            m_documentWidthPhys(widthPhys),
            m_documentHeightPhys(heightPhys),
            m_documentResolution(resolution),
            m_colorModel(colorModel),
            m_bitDepth(bitDepth),
            m_layerStack(0)
            {
              m_layerStack.push_back(std::make_unique<CLayer>(m_documentWidthPx, m_documentHeightPx,
                m_colorModel, m_bitDepth));
            }

        CDocument::CDocument(int width, Metrics::Length::Quantity heightPhys, Metrics::Resolution::Quantity resolution,
          Spec::EColorModel colorModel, Spec::EBitDepth bitDepth)
          : m_documentWidthPx(width),
            m_documentHeightPx(Metrics::Dimensionless::DimlessVal(heightPhys * resolution)),
            m_documentWidthPhys(Metrics::Dimensionless::Quantity(width) / resolution),
            m_documentHeightPhys(heightPhys),
            m_documentResolution(resolution),
            m_colorModel(colorModel),
            m_bitDepth(bitDepth),
            m_layerStack(0)
            {
              m_layerStack.push_back(std::make_unique<CLayer>(m_documentWidthPx, m_documentHeightPx,
                m_colorModel, m_bitDepth));
            }

        CDocument::CDocument(Metrics::Length::Quantity widthPhys, int height, Metrics::Resolution::Quantity resolution,
          Spec::EColorModel colorModel, Spec::EBitDepth bitDepth)
          : m_documentWidthPx(Metrics::Dimensionless::DimlessVal(widthPhys * resolution)),
            m_documentHeightPx(height),
            m_documentWidthPhys(widthPhys),
            m_documentHeightPhys(Metrics::Dimensionless::Quantity(height) / resolution),
            m_documentResolution(resolution),
            m_colorModel(colorModel),
            m_bitDepth(bitDepth),
            m_layerStack(0)
            {
              m_layerStack.push_back(std::make_unique<CLayer>(m_documentWidthPx, m_documentHeightPx,
                m_colorModel, m_bitDepth));
            }

        CDocument::~CDocument() {
        }

        int CDocument::getDocumentWidthPx() const {
          return m_documentWidthPx;
        }

        int CDocument::getDocumentHeightPx() const {
          return m_documentHeightPx;
        }

        Metrics::Length::Quantity CDocument::getDocumentWidthPhys() const {
          return m_documentWidthPhys;
        }

        Metrics::Length::Quantity CDocument::getDocumentHeightPhys() const {
          return m_documentHeightPhys;
        }

        Metrics::Resolution::Quantity CDocument::getDocumentResolution() const {
          return m_documentResolution;
        }

        Spec::EColorModel CDocument::getDocumentColorModel() const {
          return m_colorModel;
        }

        Spec::EBitDepth CDocument::getDocumentBitDepth() const {
          return m_bitDepth;
        }

        int CDocument::getNumLayers() const {
          return m_layerStack.size();
        }

        void CDocument::createNewLayer(int layerWidthPx, int layerHeightPx) {
          m_layerStack.push_back(std::make_unique<CLayer>(layerWidthPx, layerHeightPx, m_colorModel, m_bitDepth));
        }

        void CDocument::createNewLayer(Metrics::Length::Quantity layerWidthPhys, Metrics::Length::Quantity layerHeightPhys) {
          m_layerStack.push_back(std::make_unique<CLayer>(
            Metrics::Dimensionless::DimlessVal(layerWidthPhys * m_documentResolution),
            Metrics::Dimensionless::DimlessVal(layerHeightPhys * m_documentResolution),
            m_colorModel, m_bitDepth));
        }

        void CDocument::visitPixel(int layerNum, int x, int y, Pixel::IPixelVisitor &vis) {
          if((layerNum < 0) || (layerNum >= m_layerStack.size())) {
            throw LayerNotFoundException(layerNum, m_layerStack.size());
          } else {
            try {
              m_layerStack[layerNum]->visitPixel(x, y, vis);
            } catch(CLayer::OutOfBoundsException &e) {
              throw OutOfBoundsException(layerNum, x, y);
            }
          }
        }
      }
    }
  }
}
