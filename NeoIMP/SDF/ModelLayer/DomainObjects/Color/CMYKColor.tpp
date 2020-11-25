/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CMYKColor.hpp
 * PURPOSE: Implementation of the CMYK color format template.
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

#include <SDF/ModelLayer/DomainObjects/Color/CMYKColor.hpp>

namespace SDF::ModelLayer::DomainObjects::Color {
  template<class ChannelType>
  CMYKColor<ChannelType>::CMYKColor() : m_c(0), m_m(0), m_y(0), m_k(0) {}

  template<class ChannelType>
  CMYKColor<ChannelType>::CMYKColor(ChannelType c, ChannelType m, ChannelType y, ChannelType k) : m_c(c), m_m(m), m_y(y), m_k(k) {}

  template<class ChannelType>
  ChannelType CMYKColor<ChannelType>::getC() const {
    return m_c.getValue();
  }

  template<class ChannelType>
  ChannelType CMYKColor<ChannelType>::getM() const {
    return m_m.getValue();
  }

  template<class ChannelType>
  ChannelType CMYKColor<ChannelType>::getY() const {
    return m_y.getValue();
  }

  template<class ChannelType>
  ChannelType CMYKColor<ChannelType>::getK() const {
    return m_k.getValue();
  }

  template<class ChannelType>
  void CMYKColor<ChannelType>::setC(ChannelType c) {
    m_c.setValue(c);
  }

  template<class ChannelType>
  void CMYKColor<ChannelType>::setM(ChannelType m) {
    m_m.setValue(m);
  }

  template<class ChannelType>
  void CMYKColor<ChannelType>::setY(ChannelType y) {
    m_y.setValue(y);
  }

  template<class ChannelType>
  void CMYKColor<ChannelType>::setK(ChannelType k) {
    m_k.setValue(k);
  }
}
