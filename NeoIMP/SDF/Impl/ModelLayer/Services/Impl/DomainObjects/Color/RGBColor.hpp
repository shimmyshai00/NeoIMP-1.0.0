#ifndef SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_COLOR_RGBCOLOR_HPP
#define SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_COLOR_RGBCOLOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RGBColor.hpp
 * PURPOSE: Defines a template for colors in the RGB color model.
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

namespace SDF::Impl::ModelLayer::Services::Impl::DomainObjects::Color {
  template<class ChannelType>
  class RGBColor {
  public:
    RGBColor();
    RGBColor(ChannelType r, ChannelType g, ChannelType b);

    ChannelType getR() const;
    ChannelType getG() const;
    ChannelType getB() const;

    void setR(ChannelType r);
    void setG(ChannelType g);
    void setB(ChannelType b);
  private:
    ChannelType m_r;
    ChannelType m_g;
    ChannelType m_b;
  };
}

#include "SDF/Impl/ModelLayer/Services/Impl/DomainObjects/Color/RGBColor.tpp"

#endif
