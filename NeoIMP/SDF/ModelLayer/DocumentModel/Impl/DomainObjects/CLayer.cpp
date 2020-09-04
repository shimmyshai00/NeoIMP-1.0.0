/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CLayer.cpp
 * PURPOSE: Implementation of the layer class.
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

#include <Impl/DomainObjects/CLayer.hpp>

#include <Impl/DomainObjects/Pixel/PixelFormats.hpp>
#include <Impl/DomainObjects/Pixel/IPixelVisitor.hpp>

#include <Impl/DomainObjects/Raster/IRaster.hpp>
#include <Impl/DomainObjects/Raster/TRaster.hpp>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects {
        CLayer::CLayer(int width, int height, Spec::EColorModel colorModel, Spec::EBitDepth bitDepth)
        : m_colorModel(colorModel),
          m_bitDepth(bitDepth)
          {
            using namespace DocumentModel::Spec;
            using namespace Raster;

            if((width < 1) || (height < 1)) {
              throw BadLayerSizeException(width, height);
            }

            if((colorModel == COLOR_MODEL_RGB) && (bitDepth == BIT_DEPTH_8)) {
              m_raster = std::make_unique<TRaster<Pixel::RGB24>>(width, height);
            } else if((colorModel == COLOR_MODEL_RGB) && (bitDepth == BIT_DEPTH_10)) {
              m_raster = std::make_unique<TRaster<Pixel::RGB30>>(width, height);
            } else if((colorModel == COLOR_MODEL_RGB) && (bitDepth == BIT_DEPTH_12)) {
              m_raster = std::make_unique<TRaster<Pixel::RGB36>>(width, height);
            } else if((colorModel == COLOR_MODEL_RGB) && (bitDepth == BIT_DEPTH_16)) {
              m_raster = std::make_unique<TRaster<Pixel::RGB48>>(width, height);
            } else if((colorModel == COLOR_MODEL_CMYK) && (bitDepth == BIT_DEPTH_8)) {
              m_raster = std::make_unique<TRaster<Pixel::CMYK32>>(width, height);
            } else if((colorModel == COLOR_MODEL_CMYK) && (bitDepth == BIT_DEPTH_10)) {
              m_raster = std::make_unique<TRaster<Pixel::CMYK40>>(width, height);
            } else if((colorModel == COLOR_MODEL_CMYK) && (bitDepth == BIT_DEPTH_12)) {
              m_raster = std::make_unique<TRaster<Pixel::CMYK48>>(width, height);
            } else if((colorModel == COLOR_MODEL_CMYK) && (bitDepth == BIT_DEPTH_16)) {
              m_raster = std::make_unique<TRaster<Pixel::CMYK64>>(width, height);
            }
          }

        CLayer::~CLayer() {
        }

        int CLayer::getLayerWidthPx() const {
          return m_raster->getRasterWidthPx();
        }

        int CLayer::getLayerHeightPx() const {
          return m_raster->getRasterHeightPx();
        }

        Spec::EColorModel CLayer::getLayerColorModel() const {
          return m_colorModel;
        }

        Spec::EBitDepth CLayer::getLayerBitDepth() const {
          return m_bitDepth;
        }

        void CLayer::visitPixel(int x, int y, Pixel::IPixelVisitor &vis) {
          using namespace Raster;

          try {
            m_raster->visitPixel(x, y, vis);
          } catch(IRaster::OutOfBoundsException &e) {
            throw OutOfBoundsException(x, y, m_raster->getRasterWidthPx(), m_raster->getRasterHeightPx());
          }
        }
      }
    }
  }
}
