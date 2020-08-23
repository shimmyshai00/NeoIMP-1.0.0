#ifndef SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_CDOCUMENT_HPP
#define SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_CDOCUMENT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CDocument.hpp
 * PURPOSE: Definition of the document class.
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

#include <SDF/ModelLayer/Iface/Param/SDocumentSpec.hpp>
#include <SDF/ModelLayer/Iface/Param/EDimensionUnit.hpp>
#include <SDF/ModelLayer/Iface/Param/EResolutionUnit.hpp>
#include <SDF/ModelLayer/Iface/Param/EColorModel.hpp>
#include <SDF/ModelLayer/Iface/Param/EBitDepth.hpp>
#include <IAlphaOperation.hpp>
#include <IColorOperation.hpp>
#include <CUnitConverter.hpp>
#include <CLayer.hpp>
#include <vector>
#include <memory>

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    namespace DomainObjects {
      class CDocument {
      public:
        static constexpr int c_maxDocumentWidthPx = 1048576; // 1 Tipx max size
        static constexpr int c_maxDocumentHeightPx = 1048576;
      public:
        CDocument(SDF::ModelLayer::Iface::Param::SDocumentSpec documentSpec);

        float getDocumentWidthInUnit(SDF::ModelLayer::Iface::Param::EDimensionUnit unit) const;
        float getDocumentHeightInUnit(SDF::ModelLayer::Iface::Param::EDimensionUnit unit) const;
        float getDocumentResolutionInUnit(SDF::ModelLayer::Iface::Param::EResolutionUnit unit) const;

        int getDocumentWidthPx() const;
        int getDocumentHeightPx() const;
        int getDocumentPpi() const;

        SDF::ModelLayer::Iface::Param::EColorModel getColorModel() const;
        SDF::ModelLayer::Iface::Param::EBitDepth getBitDepth() const;

        int getNumLayers() const;

        void createNewLayer();

        void operateOnAlpha(int layerNum, int x, int y, IAlphaOperation &op);
        void operateOnColor(int layerNum, int x, int y, IColorOperation &op);
      private:
        CUnitConverter m_resolutionUnitConverter;
        CUnitConverter m_dimensionUnitConverter;

        int m_documentWidthPx;
        int m_documentHeightPx;
        int m_documentPpi;

        SDF::ModelLayer::Iface::Param::EColorModel m_colorModel;
        SDF::ModelLayer::Iface::Param::EBitDepth m_bitDepth;

        // The layer stack is ordered from topmost down, so layer 0 is the last rendered.
        std::vector<std::unique_ptr<CLayer>> m_layerStack;

        int createDocumentWidthPx(SDF::ModelLayer::Iface::Param::SDocumentSpec documentSpec);
        int createDocumentHeightPx(SDF::ModelLayer::Iface::Param::SDocumentSpec documentSpec);
        int createDocumentPpi(SDF::ModelLayer::Iface::Param::SDocumentSpec documentSpec);
      };
    }
  }
}

#endif
