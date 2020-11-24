#ifndef SDF_MODELLAYER_DOMAINOBJECTS_COLOR_RGBCOLOR_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_COLOR_RGBCOLOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RGBColor.hpp
 * PURPOSE: Definition of the RGB color format template.
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

namespace SDF::ModelLayer::DomainObjects::Color {
  template<class StorageType, StorageType channelMaxVal>
  class RGBColor {
  public:
    RGBColor();
    RGBColor(StorageType r, StorageType g, StorageType b);
    ~RGBColor();

    StorageType getR() const;
    StorageType getG() const;
    StorageType getB() const;

    void setR(StorageType r);
    void setG(StorageType g);
    void setB(StorageType b);
  private:
    ColorChannel<StorageType, channelMaxVal> m_r;
    ColorChannel<StorageType, channelMaxVal> m_g;
    ColorChannel<StorageType, channelMaxVal> m_b;
  };
}

#include "SDF/ModelLayer/DomainObjects/Color/RGBColor.tpp"

#endif
