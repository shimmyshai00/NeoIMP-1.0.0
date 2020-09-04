#ifndef SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_COLOR_CRGBCOLOR_HPP
#define SDF_MODELLAYER_DOCUMENTMODEL_IMPL_DOMAINOBJECTS_COLOR_CRGBCOLOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CRGBColor.hpp
 * PURPOSE: Definition of the color class for an RGB color value. Note that there is a difference between color values
 *          and pixels (under the Pixel directory/namespace). Color values are used for communicating color information
 *          within the program, while pixels are part of a raster. Materially, color values always have the maximum
 *          supported bit depth, but pixels can store at a variety of different bit depths to save memory.
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
      namespace Impl::DomainObjects::Color {
        class CRGBColor {
        public:
          CRGBColor(int r, int g, int b);

          int getChannelMax() const; // Get the maximum value that can go in each channel.

          int getR() const;
          int getG() const;
          int getB() const;

          float getRF() const;
          float getGF() const;
          float getBF() const;

          void setR(int r);
          void setG(int g);
          void setB(int b);

          void setRF(float r);
          void setGF(float g);
          void setBF(float b);
        private:
          static constexpr int c_channelMax = 65535;

          int m_r;
          int m_g;
          int m_b;
        };
      }
    }
  }
}

#endif
