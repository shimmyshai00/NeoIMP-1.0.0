#ifndef SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_CLAYER_HPP
#define SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_CLAYER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CLayer.hpp
 * PURPOSE: Definition of the image layer class.
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

#include <SDF/ModelLayer/Iface/Param/EColorModel.hpp>
#include <SDF/ModelLayer/Iface/Param/EBitDepth.hpp>
#include <IAlphaOperation.hpp>
#include <IColorOperation.hpp>
#include <SDF/Common/TGrid.hpp>
#include <Color/ColorTypes.hpp>
#include <memory>

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    namespace DomainObjects {
      class CLayer {
      public:
        CLayer(int layerWidthPx, int layerHeightPx,
          SDF::ModelLayer::Iface::Param::EColorModel colorModel, SDF::ModelLayer::Iface::Param::EBitDepth bitDepth);

        int getLayerWidthPx() const;
        int getLayerHeightPx() const;

        void operateOnAlpha(int x, int y, IAlphaOperation &op);
        void operateOnColor(int x, int y, IColorOperation &op);
      private:
        int m_layerWidthPx;
        int m_layerHeightPx;

        SDF::ModelLayer::Iface::Param::EColorModel m_colorModel;
        SDF::ModelLayer::Iface::Param::EBitDepth m_bitDepth;

        // Grids for the different pixel formats. Only one of these will be active at a time.
        std::unique_ptr<SDF::Common::TGrid<Color::Alpha8>> m_alpha8Grid;
        std::unique_ptr<SDF::Common::TGrid<Color::Alpha10>> m_alpha10Grid;
        std::unique_ptr<SDF::Common::TGrid<Color::Alpha12>> m_alpha12Grid;
        std::unique_ptr<SDF::Common::TGrid<Color::Alpha16>> m_alpha16Grid;

        std::unique_ptr<SDF::Common::TGrid<Color::RGB24>> m_rgb24Grid;
        std::unique_ptr<SDF::Common::TGrid<Color::RGB30>> m_rgb30Grid;
        std::unique_ptr<SDF::Common::TGrid<Color::RGB36>> m_rgb36Grid;
        std::unique_ptr<SDF::Common::TGrid<Color::RGB48>> m_rgb48Grid;

        std::unique_ptr<SDF::Common::TGrid<Color::CMYK32>> m_cmyk32Grid;
        std::unique_ptr<SDF::Common::TGrid<Color::CMYK40>> m_cmyk40Grid;
        std::unique_ptr<SDF::Common::TGrid<Color::CMYK48>> m_cmyk48Grid;
        std::unique_ptr<SDF::Common::TGrid<Color::CMYK64>> m_cmyk64Grid;
      };
    }
  }
}

#endif
