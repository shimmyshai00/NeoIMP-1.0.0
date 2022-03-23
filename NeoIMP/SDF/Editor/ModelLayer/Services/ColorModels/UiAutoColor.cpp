/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiAutoColor.cpp
 * PURPOSE: Implements the UiAutoColor class.
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

#include "UiAutoColor.hpp"

namespace SDF::Editor::ModelLayer::Services::ColorModels {
  UiAutoPixel::UiAutoPixel(
    UILayer::AbstractModel::Defs::Color::EColorModel enumColorModel,
    const std::array<std::pair<float, float>, 5> &channelRanges
  )
    : m_enumColorModel(enumColorModel),
      m_numChannels(channelRanges.size())
  {
    for(std::size_t i(0); i < m_numChannels; ++i) {
      m_values[i] = 0.0f;
      m_minLimits[i] = channelRanges[i].first;
      m_maxLimits[i] = channelRanges[i].second;
    }
  }

  UILayer::AbstractModel::Defs::Color::EColorModel
  UiAutoPixel::getColorModel() const {
    return m_enumColorModel;
  }

  std::size_t
  UiAutoPixel::getNumChannels() const {
    return m_numChannels;
  }

  float
  UiAutoPixel::getChannelMin(std::size_t idx) const {
    return m_minLimits.at(idx);
  }

  float
  UiAutoPixel::getChannelMax(std::size_t idx) const {
    return m_maxLimits.at(idx);
  }

  float
  UiAutoPixel::get(std::size_t idx) const {
    return m_values.at(idx);
  }

  void
  UiAutoPixel::set(std::size_t idx, float val) {
    m_values.at(idx) = val;
  }
}

namespace SDF::Editor::ModelLayer::Services::ColorModels {
  UiAutoColor::UiAutoColor(const UILayer::AbstractModel::Defs::Color::IColor &protoPixel)
    : m_enumColorModel(protoPixel.getColorModel()),
      m_numChannels(protoPixel.getNumChannels())
  {
    for(std::size_t i(0); i < protoPixel.getNumChannels(); ++i) {
      m_channelRanges[i].first = protoPixel.getChannelMin(i);
      m_channelRanges[i].second = protoPixel.getChannelMax(i);
    }
  }

  std::size_t
  UiAutoColor::getNumChannels() const {
    return m_numChannels;
  }

  float
  UiAutoColor::getChannelMax(std::size_t channelNum) const {
    return m_channelRanges.at(channelNum).second;
  }

  float
  UiAutoColor::getChannelMin(std::size_t channelNum) const {
    return m_channelRanges.at(channelNum).first;
  }

  std::shared_ptr<UILayer::AbstractModel::Defs::Color::IColor>
  UiAutoColor::convertToPixel(float *values) const {
    // meh ... couldn't get rid of allocator overhead anyways
    std::shared_ptr<UILayer::AbstractModel::Defs::Color::IColor> rv(
      new UiAutoPixel(m_enumColorModel, m_channelRanges));

    // the floats come in in the range [0, 1]
    for(std::size_t i(0); i < getNumChannels(); ++i) {
      float channelWidth = m_channelRanges[i].second - m_channelRanges[i].first;

      rv->set(i, (values[i] * channelWidth) + m_channelRanges[i].first);
    }

    return rv;
  }

  void
  UiAutoColor::convertPixelTo(std::shared_ptr<UILayer::AbstractModel::Defs::Color::IColor> px,
                              float *values
                             ) const
  {
    for(std::size_t i(0); i < getNumChannels(); ++i) {
      float pxChannelWidth = px->getChannelMax(i) - px->getChannelMin(i);

      // again, in [0, 1], so we don't need to use our channel ranges here - they're only for
      // *synthesizing* an IColor the UI won't notice is a model object via the beauty of
      // abstraction
      values[i] = (px->get(i) - px->getChannelMin(i)) / pxChannelWidth;
    }
  }
}
