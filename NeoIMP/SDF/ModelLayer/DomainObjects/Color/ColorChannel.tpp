/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorChannel.tpp
 * PURPOSE: Implementation of the color channel template.
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

#include <SDF/ModelLayer/DomainObjects/Color/ColorChannel.hpp>
#include <algorithm>

namespace SDF::ModelLayer::DomainObjects::Color {
  template<class StorageType, StorageType maxVal>
  ColorChannel<StorageType, maxVal>::ColorChannel() :
  m_val(0) {}

  template<class StorageType, StorageType maxVal>
  ColorChannel<StorageType, maxVal>::ColorChannel(StorageType val) :
  m_val(std::clamp<StorageType>(val, 0, maxVal)) {}

  template<class StorageType, StorageType maxVal>
  StorageType ColorChannel<StorageType, maxVal>::getValue() const {
    return m_val;
  }

  template<class StorageType, StorageType maxVal>
  void ColorChannel<StorageType, maxVal>::setValue(StorageType val) {
    m_val = std::clamp<StorageType>(val, 0, maxVal);
  }
}
