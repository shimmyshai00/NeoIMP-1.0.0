#ifndef SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_RASTER_IRASTER_HPP
#define SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_RASTER_IRASTER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IRaster.hpp
 * PURPOSE: Definition of the interface for a pixel raster.
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

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects::Pixel {
        class IPixelVisitor;
      }

      namespace Impl::DomainObjects::Raster {
        class IRaster {
        public:
          virtual ~IRaster() {}

          virtual int getRasterWidthPx() const = 0;
          virtual int getRasterHeightPx() const = 0;

          virtual void visitPixel(int x, int y, Pixel::IPixelVisitor &vis) = 0;
        public:
          struct OutOfBoundsException : public SDF::Exception {
            OutOfBoundsException(int x, int y)
            : Exception("INTERNAL ERROR: Tried to access raster position (%d, %d) that is outside the raster bounds", x, y)
            {
            }
          };
        };
      }
    }
  }
}

#endif
