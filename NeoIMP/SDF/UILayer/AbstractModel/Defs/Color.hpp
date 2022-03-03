#ifndef SDF_UILAYER_ABSTRACTMODEL_DEFS_COLOR_HPP
#define SDF_UILAYER_ABSTRACTMODEL_DEFS_COLOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Color.hpp
 * PURPOSE: Provides convenience structs for moving color information to the model layer in small
 *          quantities. Due to performance considerations, interfaces involving large data moves
 *          should *not* use these types, but instead use specialized (and possibly unsafe!)
 *          methods - c.f. IRenderingService, requesting a raw buffer pointer with contract on the
 *          type of data contained.
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

#include "ColorChannel.hpp"

#include <variant>

namespace SDF::UILayer::AbstractModel::Defs {
  template<class ChannelT>
  struct RGBColor {
    ChannelT m_r;
    ChannelT m_g;
    ChannelT m_b;

    RGBColor(ChannelT r, ChannelT g, ChannelT b)
      : m_r(r), m_g(g), m_b(b)
    {}
  };

  template<class ChannelT>
  struct ARGBColor {
    ChannelT m_a;
    ChannelT m_r;
    ChannelT m_g;
    ChannelT m_b;

    ARGBColor(ChannelT a, ChannelT r, ChannelT g, ChannelT b)
      : m_a(a), m_r(r), m_g(g), m_b(b)
    {}
  };

  // Color definitions. There should be one (alpha and non-alpha) for each color model in
  // EColorModel.
  typedef RGBColor<Channel<8>> RGB888Color;
  typedef ARGBColor<Channel<8>> ARGB8888Color;

  typedef std::variant<
    RGB888Color,
    ARGB8888Color
  > AnyColor;
}

#endif
