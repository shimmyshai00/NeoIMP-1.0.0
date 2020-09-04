#ifndef SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_PIXEL_TCMYKPIXEL_HPP
#define SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_PIXEL_TCMYKPIXEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    TCMYKPixel.hpp
 * PURPOSE: Definition for the CMYK pixel template.
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

#include <Impl/DomainObjects/Pixel/ICMYKPixel.hpp>

namespace SDF {
  namespace ModelLayer {
    namespace DocumentModel {
      namespace Impl::DomainObjects::Color {
        class CCMYKColor;
      }

      namespace Impl::DomainObjects::Pixel {
        template<class ValueType, ValueType maxVal>
        class TCMYKPixel : public ICMYKPixel {
        public:
          TCMYKPixel();
          TCMYKPixel(ValueType c, ValueType m, ValueType y, ValueType k);
          TCMYKPixel(ValueType alpha, ValueType c, ValueType m, ValueType y, ValueType k);
          TCMYKPixel(Color::CCMYKColor color);
          TCMYKPixel(ValueType alpha, Color::CCMYKColor color);

          int getChannelMax() const;

          int getAlpha() const;
          int getC() const;
          int getM() const;
          int getY() const;
          int getK() const;

          float getAlphaF() const;
          float getCF() const;
          float getMF() const;
          float getYF() const;
          float getKF() const;

          Color::CCMYKColor getColor() const;

          void setAlpha(int alpha);
          void setC(int c);
          void setM(int m);
          void setY(int y);
          void setK(int k);

          void setAlphaF(float alpha);
          void setCF(float c);
          void setMF(float m);
          void setYF(float y);
          void setKF(float k);

          void setWithColor(Color::CCMYKColor color);

          void accept(IPixelVisitor &vis);
        private:
          ValueType m_alpha;
          ValueType m_c;
          ValueType m_m;
          ValueType m_y;
          ValueType m_k;
        };
      }
    }
  }
}

#include "SDF/ModelLayer/DocumentModel/Impl/DomainObjects/Pixel/TCMYKPixel.tpp"

#endif
