#ifndef SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_PIXEL_TRGBPIXEL_HPP
#define SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_PIXEL_TRGBPIXEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    TRGBPixel.hpp
 * PURPOSE: Definition for the RGB pixel template.
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

#include <Impl/DomainObjects/Pixel/IRGBPixel.hpp>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects::Color {
        class CRGBColor;
      }

      namespace Impl::DomainObjects::Pixel {
        template<class ValueType, ValueType maxVal>
        class TRGBPixel : public IRGBPixel {
        public:
          TRGBPixel();
          TRGBPixel(ValueType r, ValueType g, ValueType b);
          TRGBPixel(ValueType alpha, ValueType r, ValueType g, ValueType b);
          TRGBPixel(Color::CRGBColor color);
          TRGBPixel(ValueType alpha, Color::CRGBColor color);

          int getChannelMax() const;

          int getAlpha() const;
          int getR() const;
          int getG() const;
          int getB() const;

          float getAlphaF() const;
          float getRF() const;
          float getGF() const;
          float getBF() const;

          Color::CRGBColor getColor() const;

          void setAlpha(int alpha);
          void setR(int r);
          void setG(int g);
          void setB(int b);

          void setAlphaF(float alpha);
          void setRF(float r);
          void setGF(float g);
          void setBF(float b);

          void setWithColor(Color::CRGBColor color);

          void accept(IPixelVisitor &vis);
        private:
          ValueType m_alpha;
          ValueType m_r;
          ValueType m_g;
          ValueType m_b;
        };
      }
    }
  }
}

#include "SDF/ModelLayer/DocumentModel/Impl/DomainObjects/Pixel/TRGBPixel.tpp"

#endif
