#ifndef SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_COLOR_TCMYKCOLOR_HPP
#define SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_COLOR_TCMYKCOLOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    TCMYKColor.hpp
 * PURPOSE: Definition of a template for CMYK format colors that lets us specify multiple widths.
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

#include <Impl/DomainObjects/Color/ICMYKColor.hpp>
#include <Impl/DomainObjects/Color/TColorChannel.hpp>

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    namespace DomainObjects::Color {
      template<class T, unsigned int bitDepth>
      class TCMYKColor : public Impl::DomainObjects::Color::ICMYKColor {
      public:
        TCMYKColor();
        TCMYKColor(T c, T m, T y, T k);

        int getC() const;
        int getM() const;
        int getY() const;
        int getK() const;

        float getCf() const;
        float getMf() const;
        float getYf() const;
        float getKf() const;

        int getMaxC() const;
        int getMaxM() const;
        int getMaxY() const;
        int getMaxK() const;

        void setC(int c);
        void setM(int m);
        void setY(int y);
        void setK(int k);

        void setCf(float c);
        void setMf(float m);
        void setYf(float y);
        void setKf(float k);
      private:
        Impl::DomainObjects::Color::TColorChannel<T, bitDepth> c;
        Impl::DomainObjects::Color::TColorChannel<T, bitDepth> m;
        Impl::DomainObjects::Color::TColorChannel<T, bitDepth> y;
        Impl::DomainObjects::Color::TColorChannel<T, bitDepth> k;
      };
    }
  }
}

#include "Impl/DomainObjects/Color/TCMYKColor.tpp"

#endif
