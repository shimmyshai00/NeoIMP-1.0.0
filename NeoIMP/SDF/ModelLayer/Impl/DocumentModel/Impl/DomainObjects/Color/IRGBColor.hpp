#ifndef SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_COLOR_IRGBCOLOR_HPP
#define SDF_MODELLAYER_IMPL_DOCUMENTMODEL_DOMAINOBJECTS_COLOR_IRGBCOLOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IRGBColor.hpp
 * PURPOSE: Definition of a type-agnostic interface for RGB colors.
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
      class IRGBColor {
      public:
        virtual ~IRGBColor() {}

        virtual int getR() const = 0;
        virtual int getG() const = 0;
        virtual int getB() const = 0;

        virtual float getRf() const = 0;
        virtual float getGf() const = 0;
        virtual float getBf() const = 0;

        virtual int getMaxR() const = 0;
        virtual int getMaxG() const = 0;
        virtual int getMaxB() const = 0;

        virtual void setR(int r) = 0;
        virtual void setG(int g) = 0;
        virtual void setB(int b) = 0;

        virtual void setRf(float r) = 0;
        virtual void setGf(float g) = 0;
        virtual void setBf(float b) = 0;
      };
    }
  }
}

#endif
