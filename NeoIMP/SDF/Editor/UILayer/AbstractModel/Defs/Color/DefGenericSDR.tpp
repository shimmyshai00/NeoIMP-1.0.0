#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_GENERICSDR_TPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_GENERICSDR_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GenericSDR.tpp
 * PURPOSE: Implements the GenericSDR template.
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

#include <cmath>

namespace SDF::Editor::UILayer::AbstractModel::Defs::Color {
  template<EColorModel CM, std::size_t ... ChannelBits>
  GenericSDR<CM, ChannelBits...>::GenericSDR() {
  }

  template<EColorModel CM, std::size_t ... ChannelBits>
  EColorModel
  GenericSDR<CM, ChannelBits...>::getColorModel() const {
    return CM;
  }

  template<EColorModel CM, std::size_t ... ChannelBits>
  std::size_t
  GenericSDR<CM, ChannelBits...>::getNumChannels() const {
    return pak_t::num_vals;
  }

  template<EColorModel CM, std::size_t ... ChannelBits>
  int
  GenericSDR<CM, ChannelBits...>::getChannelMin(std::size_t channelIdx) const {
    return 0;
  }

  template<EColorModel CM, std::size_t ... ChannelBits>
  int
  GenericSDR<CM, ChannelBits...>::getChannelMax(std::size_t channelIdx) const {
    return (1 << pak_t::vals.at(channelIdx)) - 1;
  }

  template<EColorModel CM, std::size_t ... ChannelBits>
  int
  GenericSDR<CM, ChannelBits...>::getValue(std::size_t channelIdx) const {
    return m_values.at(channelIdx);
  }

  template<EColorModel CM, std::size_t ... ChannelBits>
  float
  GenericSDR<CM, ChannelBits...>::getValueF(std::size_t channelIdx) const {
    return (0.0f + m_values.at(channelIdx)) / getChannelMax(channelIdx);
  }

  template<EColorModel CM, std::size_t ... ChannelBits>
  void
  GenericSDR<CM, ChannelBits...>::setValue(std::size_t channelIdx, int value) {
    m_values.at(channelIdx) = std::clamp(value, 0, getChannelMax(channelIdx));
  }

  template<EColorModel CM, std::size_t ... ChannelBits>
  void
  GenericSDR<CM, ChannelBits...>::setValueF(std::size_t channelIdx, float value) {
    setValue(channelIdx, floor(value * getChannelMax(channelIdx) + 0.5f));
  }
}

#endif
