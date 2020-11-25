/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RGBColor.hpp
 * PURPOSE: Implementation of the RGB color format template.
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

#include <SDF/ModelLayer/DomainObjects/Color/RGBColor.hpp>

namespace SDF::ModelLayer::DomainObjects::Color {
  template<class ChannelType>
  RGBColor<ChannelType>::RGBColor() : m_r(0), m_g(0), m_b(0) {}

  template<class ChannelType>
  RGBColor<ChannelType>::RGBColor(ChannelType r, ChannelType g, ChannelType b) : m_r(r), m_g(g), m_b(b) {}

  template<class ChannelType>
  ChannelType RGBColor<ChannelType>::getR() const {
    return m_r.getValue();
  }

  template<class ChannelType>
  ChannelType RGBColor<ChannelType>::getG() const {
    return m_g.getValue();
  }

  template<class ChannelType>
  ChannelType RGBColor<ChannelType>::getB() const {
    return m_b.getValue();
  }

  template<class ChannelType>
  void RGBColor<ChannelType>::setR(ChannelType r) {
    m_r.setValue(r);
  }

  template<class ChannelType>
  void RGBColor<ChannelType>::setG(ChannelType g) {
    m_g.setValue(g);
  }

  template<class ChannelType>
  void RGBColor<ChannelType>::setB(ChannelType b) {
    m_b.setValue(b);
  }
}
