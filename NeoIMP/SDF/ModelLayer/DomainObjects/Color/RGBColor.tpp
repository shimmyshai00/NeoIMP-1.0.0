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
  template<class StorageType, StorageType channelMaxVal>
  RGBColor::RGBColor() : m_r(0), m_g(0), m_b(0) {}

  template<class StorageType, StorageType channelMaxVal>
  RGBColor::RGBColor(StorageType r, StorageType g, StorageType b) : m_r(r), m_g(g), m_b(b) {}

  template<class StorageType, StorageType channelMaxVal>
  RGBColor::~RGBColor() {}

  template<class StorageType, StorageType channelMaxVal>
  StorageType RGBColor::getR() const {
    return m_r.getValue();
  }

  template<class StorageType, StorageType channelMaxVal>
  StorageType RGBColor::getG() const {
    return m_g.getValue();
  }

  template<class StorageType, StorageType channelMaxVal>
  StorageType RGBColor::getB() const {
    return m_b.getValue();
  }

  template<class StorageType, StorageType channelMaxVal>
  void RGBColor::setR(StorageType r) {
    m_r.setValue(r);
  }

  template<class StorageType, StorageType channelMaxVal>
  void RGBColor::setG(StorageType g) {
    m_g.setValue(g);
  }

  template<class StorageType, StorageType channelMaxVal>
  void RGBColor::setB(StorageType b) {
    m_b.setValue(b);
  }
}
