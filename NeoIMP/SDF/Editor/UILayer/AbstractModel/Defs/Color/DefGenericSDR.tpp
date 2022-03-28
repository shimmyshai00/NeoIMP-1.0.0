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
  template<EColorFormat CF, std::size_t ... ChannelBits>
  DefGenericSDR<CF, ChannelBits...>::DefGenericSDR() {
  }

  template<EColorFormat CF, std::size_t ... ChannelBits>
  EColorFormat
  DefGenericSDR<CF, ChannelBits...>::getColorFormat() const {
    return CF;
  }

  template<EColorFormat CF, std::size_t ... ChannelBits>
  std::size_t
  DefGenericSDR<CF, ChannelBits...>::getNumChannels() const {
    return pak_t::num_vals;
  }

  template<EColorFormat CF, std::size_t ... ChannelBits>
  int
  DefGenericSDR<CF, ChannelBits...>::getChannelMin(std::size_t channelIdx) const {
    return 0;
  }

  template<EColorFormat CF, std::size_t ... ChannelBits>
  int
  DefGenericSDR<CF, ChannelBits...>::getChannelMax(std::size_t channelIdx) const {
    return (1 << pak_t::vals.at(channelIdx)) - 1;
  }

  template<EColorFormat CF, std::size_t ... ChannelBits>
  int
  DefGenericSDR<CF, ChannelBits...>::getValue(std::size_t channelIdx) const {
    return m_values.at(channelIdx);
  }

  template<EColorFormat CF, std::size_t ... ChannelBits>
  float
  DefGenericSDR<CF, ChannelBits...>::getValueF(std::size_t channelIdx) const {
    return (0.0f + m_values.at(channelIdx)) / getChannelMax(channelIdx);
  }

  template<EColorFormat CF, std::size_t ... ChannelBits>
  void
  DefGenericSDR<CF, ChannelBits...>::setValue(std::size_t channelIdx, int value) {
    m_values.at(channelIdx) = std::clamp(value, 0, getChannelMax(channelIdx));
  }

  template<EColorFormat CF, std::size_t ... ChannelBits>
  void
  DefGenericSDR<CF, ChannelBits...>::setValueF(std::size_t channelIdx, float value) {
    setValue(channelIdx, floor(value * getChannelMax(channelIdx) + 0.5f));
  }
}

#endif
