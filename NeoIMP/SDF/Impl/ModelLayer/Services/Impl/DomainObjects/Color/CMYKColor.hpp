#ifndef SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_COLOR_CMYKCOLOR_HPP
#define SDF_IMPL_MODELLAYER_SERVICES_IMPL_DOMAINOBJECTS_COLOR_CMYKCOLOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CMYKColor.hpp
 * PURPOSE: Defines a template for colors in the CMYK color model.
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
  class CMYKColor {
  public:
    CMYKColor();
    CMYKColor(ChannelType c, ChannelType m, ChannelType y, ChannelType k);

    ChannelType getC() const;
    ChannelType getM() const;
    ChannelType getY() const;
    ChannelType getK() const;

    void setC(ChannelType c);
    void setM(ChannelType m);
    void setY(ChannelType y);
    void setK(ChannelType k);
  private:
    ChannelType m_c;
    ChannelType m_m;
    ChannelType m_y;
    ChannelType m_k;
  };
}

#include "SDF/Impl/ModelLayer/Services/Impl/DomainObjects/Color/CMYKColor.tpp"

#endif
