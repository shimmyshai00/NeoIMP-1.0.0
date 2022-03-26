#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_RGB_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_RGB_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RGB.hpp
 * PURPOSE: Defines the RGB class.
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

#include "../../../../../Error/GeneralException.hpp"

#include "IColor.hpp"
#include "EBitDepth.hpp"

namespace SDF::Editor::UILayer::AbstractModel::Defs::Color {
  // Class:      RGB
  // Purpose:    Defines an RGB color value.
  // Parameters: None.
  class RGB : public IColor {
  public:
    // Function:   RGB
    // Purpose:    Construct a new RGB color.
    // Parameters: bitDepth - The bit depth to use.
    //             r, g, b - The color components.
    RGB(EBitDepth bitDepth, int r, int g, int b)
      : m_bitDepth(bitDepth),
        m_r(r),
        m_g(g),
        m_b(b)
    {
    }

    EColorModel
    getColorModel() const {
      return COLOR_MODEL_RGB;
    }

    EBitDepth
    getBitDepth() const {
      return m_bitDepth;
    }

    std::size_t
    getNumChannels() const {
      return 3;
    }

    float
    getChannelMin(std::size_t channel) const {
      return 0.0f;
    }

    float
    getChannelMax(std::size_t channel) const {
      return 0.0f + ((1U << g_bitDepthMapping[m_bitDepth]) - 1);
    }

    float
    get(std::size_t channel) const {
      if(channel == 0) return m_r;
      if(channel == 1) return m_g;
      if(channel == 2) return m_b;

      throw SDF::Error::OutOfBoundsException();
    }

    void
    set(std::size_t channel, float val) {
      if(channel == 0) m_r = std::clamp(floor(val + 0.5f), getChannelMin(0), getChannelMax(0));
      if(channel == 1) m_g = std::clamp(floor(val + 0.5f), getChannelMin(1), getChannelMax(1));
      if(channel == 2) m_b = std::clamp(floor(val + 0.5f), getChannelMin(2), getChannelMax(2));

      throw SDF::Error::OutOfBoundsException();
    }
  private:
    EBitDepth m_bitDepth;

    int m_r, m_g, m_b;
  }
}

#endif
