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
  template<class StorageType, StorageType channelMaxVal>
  CMYKColor::CMYKColor() : m_c(0), m_m(0), m_y(0), m_k(channelMaxVal) {}

  template<class StorageType, StorageType channelMaxVal>
  CMYKColor::CMYKColor(StorageType c, StorageType m, StorageType y, StorageType k) : m_c(c), m_m(m), m_y(y), m_k(k) {}

  template<class StorageType, StorageType channelMaxVal>
  CMYKColor::~CMYKColor() {}

  template<class StorageType, StorageType channelMaxVal>
  StorageType CMYKColor::getC() const {
    return m_c.getValue();
  }

  template<class StorageType, StorageType channelMaxVal>
  StorageType CMYKColor::getM() const {
    return m_m.getValue();
  }

  template<class StorageType, StorageType channelMaxVal>
  StorageType CMYKColor::getY() const {
    return m_y.getValue();
  }

  template<class StorageType, StorageType channelMaxVal>
  StorageType CMYKColor::getK() const {
    return m_k.getValue();
  }

  template<class StorageType, StorageType channelMaxVal>
  void CMYKColor::setC(StorageType c) {
    m_c.setValue(c);
  }

  template<class StorageType, StorageType channelMaxVal>
  void CMYKColor::setM(StorageType m) {
    m_m.setValue(m);
  }

  template<class StorageType, StorageType channelMaxVal>
  void CMYKColor::setY(StorageType y) {
    m_y.setValue(y);
  }

  template<class StorageType, StorageType channelMaxVal>
  void CMYKColor::setK(StorageType k) {
    m_k.setValue(k);
  }
}
