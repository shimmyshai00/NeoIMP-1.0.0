#ifndef SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_COLOR_ICMYKCOLOR_HPP
#define SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_COLOR_ICMYKCOLOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ICMYKColor.hpp
 * PURPOSE: Definition of a type-agnostic interface for CMYK-format colors.
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

namespace SDF::ModelLayer::Impl::DocumentModel {
  namespace Impl {
    namespace DomainObjects::Color {
      class ICMYKColor {
      public:
        virtual ~ICMYKColor() {}

        virtual int getC() const = 0;
        virtual int getM() const = 0;
        virtual int getY() const = 0;
        virtual int getK() const = 0;

        virtual float getCf() const = 0;
        virtual float getMf() const = 0;
        virtual float getYf() const = 0;
        virtual float getKf() const = 0;

        virtual int getMaxC() const = 0;
        virtual int getMaxM() const = 0;
        virtual int getMaxY() const = 0;
        virtual int getMaxK() const = 0;

        virtual void setC(int c) = 0;
        virtual void setM(int m) = 0;
        virtual void setY(int y) = 0;
        virtual void setK(int k) = 0;

        virtual void setCf(float c) = 0;
        virtual void setMf(float m) = 0;
        virtual void setYf(float y) = 0;
        virtual void setKf(float k) = 0;
      };
    }
  }
}

#endif
