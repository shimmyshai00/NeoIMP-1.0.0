#ifndef SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_COLOR_TRGBCOLOR_HPP
#define SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_COLOR_TRGBCOLOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    TRGBColor.hpp
 * PURPOSE: Definition of a template for RGB format colors that lets us specify multiple widths.
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

#include <Impl/DomainObjects/Color/IRGBColor.hpp>
#include <Impl/DomainObjects/Color/TColorChannel.hpp>

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    namespace DomainObjects::Color {
      template<class T, unsigned int bitDepth>
      class TRGBColor : public Impl::DomainObjects::Color::IRGBColor {
      public:
        TRGBColor();
        TRGBColor(T r, T g, T b);

        int getR() const;
        int getG() const;
        int getB() const;

        float getRf() const;
        float getGf() const;
        float getBf() const;

        int getMaxR() const;
        int getMaxG() const;
        int getMaxB() const;

        void setR(int r);
        void setG(int g);
        void setB(int b);

        void setRf(float r);
        void setGf(float g);
        void setBf(float b);
      private:
        Impl::DomainObjects::Color::TColorChannel<T, bitDepth> r;
        Impl::DomainObjects::Color::TColorChannel<T, bitDepth> g;
        Impl::DomainObjects::Color::TColorChannel<T, bitDepth> b;
      };
    }
  }
}

#include "Impl/DomainObjects/Color/TRGBColor.tpp"

#endif
