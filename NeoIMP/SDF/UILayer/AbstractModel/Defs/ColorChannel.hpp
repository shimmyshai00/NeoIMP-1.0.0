#ifndef SDF_UILAYER_ABSTRACTMODEL_DEFS_COLORCHANNEL_HPP
#define SDF_UILAYER_ABSTRACTMODEL_DEFS_COLORCHANNEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorChannel.hpp
 * PURPOSE: Provides a convenience type for moving small amounts of color data to and from the
 *          model layer for single color channels.
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

#include <cstddef>
#include <algorithm>

namespace SDF::UILayer::AbstractModel::Defs {
  // Basically just "clamps" its input to simulate pseudo types of arbitrary bitlength.
  template<std::size_t numBits>
  class Channel {
  public:
    Channel(unsigned int value)
      : m_value(std::min(value, s_valueMax))
    {
    }

    operator unsigned int() const {
      return m_value;
    }
  private:
    static unsigned int s_valueMax;

    unsigned int m_value;
  };

  template<std::size_t numBits>
  unsigned int Channel<numBits>::s_valueMax = (1 << numBits) - 1;
}

#endif
