#ifndef SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_PIXEL_IRGBPIXEL_HPP
#define SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_PIXEL_IRGBPIXEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IRGBPixel.hpp
 * PURPOSE: Definition of the pixel interface for an RGB format pixel.
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

#include <Impl/DomainObjects/Pixel/IPixel.hpp>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects::Color {
        class CRGBColor;
      }

      namespace Impl::DomainObjects::Pixel {
        class IPixelVisitor;

        class IRGBPixel : public IPixel {
        public:
          virtual ~IRGBPixel() {}

          virtual int getChannelMax() const = 0;

          virtual int getAlpha() const = 0;
          virtual int getR() const = 0;
          virtual int getG() const = 0;
          virtual int getB() const = 0;

          virtual float getAlphaF() const = 0;
          virtual float getRF() const = 0;
          virtual float getGF() const = 0;
          virtual float getBF() const = 0;

          virtual Color::CRGBColor getColor() const = 0;

          virtual void setAlpha(int alpha) = 0;
          virtual void setR(int r) = 0;
          virtual void setG(int g) = 0;
          virtual void setB(int b) = 0;

          virtual void setAlphaF(float alpha) = 0;
          virtual void setRF(float r) = 0;
          virtual void setGF(float g) = 0;
          virtual void setBF(float b) = 0;

          virtual void setWithColor(Color::CRGBColor color) = 0;

          virtual void accept(IPixelVisitor &vis) = 0;
        };
      }
    }
  }
}

#endif
