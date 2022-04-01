#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_DEFGENERICSDR_TPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_DEFGENERICSDR_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DefGenericSDR.tpp
 * PURPOSE: Implements the DefGenericSDR template.
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
#include <algorithm>

namespace SDF::Editor::UILayer::AbstractModel::Defs::Color {
  template<ColorFormat CF, std::size_t ... ChannelBits>
  DefGenericSDR<CF, ChannelBits...>::DefGenericSDR() {
  }

  template<ColorFormat CF, std::size_t ... ChannelBits>
  ColorFormat
  DefGenericSDR<CF, ChannelBits...>::getColorFormat() const {
    return CF;
  }

  template<ColorFormat CF, std::size_t ... ChannelBits>
  std::size_t
  DefGenericSDR<CF, ChannelBits...>::getNumChannels() const {
    return pak_t::num_vals;
  }

  template<ColorFormat CF, std::size_t ... ChannelBits>
  int
  DefGenericSDR<CF, ChannelBits...>::getChannelMin(std::size_t a_channelIdx) const {
    return 0;
  }

  template<ColorFormat CF, std::size_t ... ChannelBits>
  int
  DefGenericSDR<CF, ChannelBits...>::getChannelMax(std::size_t a_channelIdx) const {
    return (1 << pak_t::vals.at(a_channelIdx)) - 1;
  }

  template<ColorFormat CF, std::size_t ... ChannelBits>
  int
  DefGenericSDR<CF, ChannelBits...>::getValue(std::size_t a_channelIdx) const {
    return m_values.at(a_channelIdx);
  }

  template<ColorFormat CF, std::size_t ... ChannelBits>
  float
  DefGenericSDR<CF, ChannelBits...>::getValueF(std::size_t a_channelIdx) const {
    return (0.0f + m_values.at(a_channelIdx)) / getChannelMax(a_channelIdx);
  }

  template<ColorFormat CF, std::size_t ... ChannelBits>
  void
  DefGenericSDR<CF, ChannelBits...>::setValue(std::size_t a_channelIdx, int a_value) {
    m_values.at(a_channelIdx) = std::clamp(a_value, 0, getChannelMax(a_channelIdx));
  }

  template<ColorFormat CF, std::size_t ... ChannelBits>
  void
  DefGenericSDR<CF, ChannelBits...>::setValueF(std::size_t a_channelIdx, float a_value) {
    setValue(a_channelIdx, floor(a_value * getChannelMax(a_channelIdx) + 0.5f));
  }
}

#endif
