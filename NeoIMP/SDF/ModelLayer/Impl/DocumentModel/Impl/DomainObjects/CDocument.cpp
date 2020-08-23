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

#include <CDocument.hpp>
#include <Units.hpp>
#include <cassert>

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    namespace DomainObjects {
      CDocument::CDocument(SDF::ModelLayer::Iface::Param::SDocumentSpec documentSpec)
      : m_documentWidthPx(createDocumentWidthPx(documentSpec)),
        m_documentHeightPx(createDocumentHeightPx(documentSpec)),
        m_documentPpi(createDocumentPpi(documentSpec)),
        m_layerStack(0)
        {
          createNewLayer();
        }

      float CDocument::getDocumentWidthInUnit(SDF::ModelLayer::Iface::Param::EDimensionUnit unit) const {
        return m_dimensionUnitConverter.convertQuantity(static_cast<float>(m_documentWidthPx) / m_documentPpi,
          Units::Inch, Units::dimUnitEnumMap.at(unit));
      }

      float CDocument::getDocumentHeightInUnit(SDF::ModelLayer::Iface::Param::EDimensionUnit unit) const {
        return m_dimensionUnitConverter.convertQuantity(static_cast<float>(m_documentHeightPx) / m_documentPpi,
          Units::Inch, Units::dimUnitEnumMap.at(unit));
      }

      float CDocument::getDocumentResolutionInUnit(SDF::ModelLayer::Iface::Param::EResolutionUnit unit) const {
        return m_resolutionUnitConverter.convertQuantity(m_documentPpi,
          Units::PerInch, Units::resUnitEnumMap.at(unit));
      }

      int CDocument::getDocumentWidthPx() const {
        return m_documentWidthPx;
      }

      int CDocument::getDocumentHeightPx() const {
        return m_documentHeightPx;
      }

      int CDocument::getDocumentPpi() const {
        return m_documentPpi;
      }

      SDF::ModelLayer::Iface::Param::EColorModel CDocument::getColorModel() const {
        return m_colorModel;
      }

      SDF::ModelLayer::Iface::Param::EBitDepth CDocument::getBitDepth() const {
        return m_bitDepth;
      }

      int CDocument::getNumLayers() const {
        return m_layerStack.size();
      }

      void CDocument::createNewLayer() {
        // nb: needs to be on front
        m_layerStack.push_back(std::make_unique<CLayer>(m_documentWidthPx, m_documentHeightPx,
          m_colorModel, m_bitDepth));
      }

      void CDocument::operateOnAlpha(int layerNum, int x, int y, Impl::DomainObjects::IAlphaOperation &op) {
        assert((0 <= layerNum) && (layerNum < m_layerStack.size()));
        assert((0 <= x) && (x < m_documentWidthPx));
        assert((0 <= y) && (y < m_documentHeightPx));

        m_layerStack[layerNum]->operateOnAlpha(x, y, op);
      }

      void CDocument::operateOnColor(int layerNum, int x, int y, Impl::DomainObjects::IColorOperation &op) {
        assert((0 <= layerNum) && (layerNum < m_layerStack.size()));
        assert((0 <= x) && (x < m_documentWidthPx));
        assert((0 <= y) && (y < m_documentHeightPx));

        m_layerStack[layerNum]->operateOnColor(x, y, op);
      }

      // Private members.
      int CDocument::createDocumentWidthPx(SDF::ModelLayer::Iface::Param::SDocumentSpec documentSpec) {
        using namespace SDF::ModelLayer::Iface::Param;

        if(documentSpec.widthUnit == UNIT_PIXEL) {
          return documentSpec.documentWidthPx;
        } else {
          float nInches(m_dimensionUnitConverter.convertQuantity(documentSpec.documentWidth,
            Units::dimUnitEnumMap.at(documentSpec.widthUnit), Units::Inch));
          float nPpi(m_resolutionUnitConverter.convertQuantity(documentSpec.documentResolution,
            Units::resUnitEnumMap.at(documentSpec.resolutionUnit), Units::PerInch));

          return nInches * nPpi;
        }
      }

      int CDocument::createDocumentHeightPx(SDF::ModelLayer::Iface::Param::SDocumentSpec documentSpec) {
        using namespace SDF::ModelLayer::Iface::Param;

        if(documentSpec.heightUnit == UNIT_PIXEL) {
          return documentSpec.documentHeightPx;
        } else {
          float nInches(m_dimensionUnitConverter.convertQuantity(documentSpec.documentHeight,
            Units::dimUnitEnumMap.at(documentSpec.heightUnit), Units::Inch));
          float nPpi(m_resolutionUnitConverter.convertQuantity(documentSpec.documentResolution,
            Units::resUnitEnumMap.at(documentSpec.resolutionUnit), Units::PerInch));

          return nInches * nPpi;
        }
      }

      int CDocument::createDocumentPpi(SDF::ModelLayer::Iface::Param::SDocumentSpec documentSpec) {
        return m_resolutionUnitConverter.convertQuantity(documentSpec.documentResolution,
          Units::resUnitEnumMap.at(documentSpec.resolutionUnit), Units::PerInch);
      }
    }
  }
}
