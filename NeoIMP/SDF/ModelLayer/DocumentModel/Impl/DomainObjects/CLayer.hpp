#ifndef SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_CLAYER_HPP
#define SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_CLAYER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CLayer.hpp
 * PURPOSE: Definition of the layer class.
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

#include <Spec/EColorModel.hpp>
#include <Spec/EBitDepth.hpp>

#include <memory>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects {
        namespace Pixel {
          class IPixelVisitor;
        }

        namespace Raster {
          class IRaster;
        }

        class CLayer {
        public:
          CLayer(int width, int height, Spec::EColorModel colorModel, Spec::EBitDepth bitDepth);
          ~CLayer();

          int getLayerWidthPx() const;
          int getLayerHeightPx() const;

          Spec::EColorModel getLayerColorModel() const;
          Spec::EBitDepth getLayerBitDepth() const;

          void visitPixel(int x, int y, Pixel::IPixelVisitor &vis);
        public:
          struct BadLayerSizeException : public SDF::Exception {
            BadLayerSizeException(int width, int height)
            : Exception("INTERNAL ERROR: Tried to create a layer with bad size [zero or negative] (%d, %d)", width, height)
            {
            }
          };

          struct OutOfBoundsException : public SDF::Exception {
            OutOfBoundsException(int width, int height, int layerWidthPx, int layerHeightPx)
            : Exception("INTERNAL ERROR: Tried to access a pixel outside a layer's bounds [(%d, %d) in layer of dimensions %d x %d]", width, height, layerWidthPx, layerHeightPx)
            {
            }
          };
        private:
          Spec::EColorModel m_colorModel;
          Spec::EBitDepth m_bitDepth;

          std::unique_ptr<Raster::IRaster> m_raster;
        };
      }
    }
  }
}

#endif
