#ifndef SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_RASTER_TRASTER_HPP
#define SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_RASTER_TRASTER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    TRaster.hpp
 * PURPOSE: Definition of the pixel raster template.
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

#include <SDF/Exception.hpp>
#include <SDF/Common/TGrid.hpp>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects::Pixel {
        class IPixelVisitor;
      }

      namespace Impl::DomainObjects::Raster {
        template<class PixelType>
        class TRaster : public IRaster {
        public:
          TRaster(int width, int height);

          int getRasterWidthPx() const;
          int getRasterHeightPx() const;

          void visitPixel(int x, int y, Pixel::IPixelVisitor &vis);
        public:
          struct OutOfBoundsException : public SDF::Exception {
            OutOfBoundsException(int x, int y, int rasterWidth, int rasterHeight)
            : Exception("INTERNAL ERROR: Tried to access raster position (%d, %d) out of bounds", x, y)
            {
            }
          };
        private:
          Common::TGrid<PixelType> m_pixelGrid;
        };
      }
    }
  }
}

#include "SDF/ModelLayer/DocumentModel/Impl/DomainObjects/Raster/TRaster.tpp"

#endif
