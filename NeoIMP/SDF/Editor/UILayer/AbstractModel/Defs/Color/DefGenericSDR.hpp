#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_DEFGENERICSDR_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_DEFGENERICSDR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DefGenericSDR.hpp
 * PURPOSE: Defines the DefGenericSDR template.
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

#include "../../../../../Common/Meta.hpp"
#include "IColor.hpp"
#include "EColorModel.hpp"

#include <array>

namespace SDF::Editor::UILayer::AbstractModel::Defs::Color {
  // Class:      DefGenericSDR
  // Purpose:    Provides a generic template for defining short-dynamic range (SDR) color types.
  // Parameters: CM - The color model type being defined.
  //             ChannelBits - The bits in each channel.
  template<EColorModel CM, std::size_t ... ChannelBits>
  class DefGenericSDR : public IColor<EColorModel> {
  public:
    DefGenericSDR();

    EColorModel
    getColorModel() const;

    std::size_t
    getNumChannels() const;

    int
    getChannelMin(std::size_t channelIdx) const;

    int
    getChannelMax(std::size_t channelIdx) const;

    int
    getValue(std::size_t channelIdx) const;

    float
    getValueF(std::size_t channelIdx) const;

    void
    setValue(std::size_t channelIdx, int value);

    void
    setValueF(std::size_t channelIdx, float value);
  private:
    typedef Common::Meta::dynamic_pack<std::size_t, ChannelBits...> pak_t;

    std::array<int, pak_t::num_vals> m_values;
  };
}

#include "DefGenericSDR.tpp"

#endif
