/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    TRaster.tpp
 * PURPOSE: Implementation of the pixel raster template.
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

#include <Impl/DomainObjects/Raster/TRaster.hpp>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects::Raster {
        template<class PixelType>
        TRaster<PixelType>::TRaster(int width, int height)
        : m_pixelGrid(width, height)
        {
        }

        template<class PixelType>
        int TRaster<PixelType>::getRasterWidthPx() const {
          return m_pixelGrid.getWidth();
        }

        template<class PixelType>
        int TRaster<PixelType>::getRasterHeightPx() const {
          return m_pixelGrid.getHeight();
        }

        template<class PixelType>
        void TRaster<PixelType>::visitPixel(int x, int y, Pixel::IPixelVisitor &vis) {
          if(((x < 0) || (x >= m_pixelGrid.getWidth())) || ((y < 0) || (y >= m_pixelGrid.getHeight()))) {
            throw OutOfBoundsException(x, y, m_pixelGrid.getWidth(), m_pixelGrid.getHeight());
          }

          m_pixelGrid(x, y).accept(vis);
        }
      }
    }
  }
}
