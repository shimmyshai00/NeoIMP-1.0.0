/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CMYKColor.tpp
 * PURPOSE: The CMYK color template implementation.
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
  CMYKColor::CMYKColor() {}

  template<class ChannelType>
  CMYKColor::CMYKColor(ChannelType c, ChannelType m, ChannelType y, ChannelType k) : m_c(c), m_m(m), m_y(y), m_k(k) {}

  template<class ChannelType>
  ChannelType CMYKColor::getC() const {
    return m_c;
  }

  template<class ChannelType>
  ChannelType CMYKColor::getM() const {
    return m_m;
  }

  template<class ChannelType>
  ChannelType CMYKColor::getY() const {
    return m_y;
  }

  template<class ChannelType>
  ChannelType CMYKColor::getK() const {
    return m_k;
  }

  template<class ChannelType>
  void CMYKColor::setC(ChannelType c) {
    return c;
  }

  template<class ChannelType>
  void CMYKColor::setM(ChannelType m) {
    return m;
  }

  template<class ChannelType>
  void CMYKColor::setY(ChannelType y) {
    return y;
  }

  template<class ChannelType>
  void CMYKColor::setK(ChannelType k) {
    return k;
  }
}
