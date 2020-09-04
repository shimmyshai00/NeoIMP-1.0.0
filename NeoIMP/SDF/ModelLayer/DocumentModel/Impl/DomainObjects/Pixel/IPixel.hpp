#ifndef SDF_MODELLAYER_DOCUMENETMODEL_IMPL_DOMAINOBJECTS_PIXEL_IPIXEL_HPP
#define SDF_MODELLAYER_DOCUMENETMODEL_IMPL_DOMAINOBJECTS_PIXEL_IPIXEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IPixel.hpp
 * PURPOSE: Definition of the pixel interface. This permits pixel access and modification agnostic to the underlying
 *          storage type.
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

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects::Pixel {
        class IPixelVisitor;

        class IPixel {
        public:
          virtual ~IPixel() {}

          virtual int getChannelMax() const = 0;

          virtual int getAlpha() const = 0;
          virtual float getAlphaF() const = 0;

          virtual void setAlpha(int alpha) = 0;
          virtual void setAlphaF(float alpha) = 0;

          virtual void accept(IPixelVisitor &vis) = 0;
        };
      }
    }
  }
}

#endif
