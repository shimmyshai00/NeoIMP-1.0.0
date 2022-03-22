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
    std::size_t numChannels
  )
    : m_enumColorModel(enumColorModel),
      m_values(numChannels)
  {
  }

  EColorModel
  UiAutoPixel::getColorModel() const {
    return m_enumColorModel;
  }

  std::size_t
  UiAutoPixel::getNumChannels() const {
    return m_values.size();
  }

  float
  UiAutoPixel::getChannelMin(std::size_t idx) const {
    return 0.0f;
  }

  float
  UiAutoPixel::getChannelMax(std::size_t idx) const {
    return 1.0f;
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
  UiAutoColor::UiAutoColor(const IColor &protoPixel)
    : m_channelMinLimits(protoPixel.getNumChannels()),
      m_channelMaxLimits(protoPixel.getNumChannels())
  {
    for(std::size_t i(0); i < protoPixel.getNumChannels(); ++i) {
      m_channelMinLimits[i] = protoPixel.getChannelMin(i);
      m_channelMaxLimits[i] = protoPixel.getChannelMax(i);
    }
  }

  std::size_t
  UiAutoColor::getNumChannels() const {
    return m_channelMaxLimits.size();
  }

  float
  UiAutoColor::getChannelMax(std::size_t channelNum) const {
    return m_channelMaxLimits.at(channelNum);
  }

  float
  UiAutoColor::getChannelMin(std::size_t channelNum) const {
    return m_channelMinLimits.at(channelNum);
  }

  UiAutoPixel
  UiAutoColor::convertToPixel(float *values) const {
    // Simply "pass through" the values to the UiAutoPixel - that's the beauty of the [0, 1]
    // range!
    UiAutoPixel apx;
    for(std::size_t i(0); i < getNumChannels(); ++i) {
      apx.set(i, values[i]);
    }

    return apx;
  }

  void
  UiAutoColor::convertPixelTo(UiAutoPixel px,
                              float *values
                             ) const
  {
    // same thing, "pass back"
    for(std::size_t i(0); i < getNumChannels(); ++i) {
      values[i] = px.get(i);
    }
  }
}
