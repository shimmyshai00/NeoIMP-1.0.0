#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_GENERICSDR_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_GENERICSDR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GenericSDR.hpp
 * PURPOSE: Defines the GenericSDR template.
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

#include "EColorModel.hpp"
#include "IColor.hpp"

#include <boost/mp11/integral.hpp>
#include <boost/mp11/list.hpp>

#include <cstddef>
#include <list>
#include <exception>
#include <stdexcept>

namespace SDF::Editor::UILayer::AbstractModel::Defs::Color {
  // Class:      GenericSDR
  // Purpose:    Defines a generic short-dynamic-range (SDR) color value.
  // Parameters: colorModel - The color model repersented.
  //             channelBits - The number of bits per channel.
  template<EColorModel colorModel, std::size_t ... channelBits>
  class GenericSDR : public IColor {
  private:
    typedef boost::mp11::mp_list_c<std::size_t, channelBits...> channel_counts_type;
    static const std::size_t NUM_CHANNELS = boost::mp11::mp_size<channel_counts_type>::value;

    int m_channelMaxLimits[NUM_CHANNELS];
    int m_values[NUM_CHANNELS];
  public:
    GenericSDR() {
      std::list<std::size_t> bitDepths;
      Common::Meta::push_into<std::size_t, channelBits...>(bitDepths);

      std::size_t idx = 0;
      for(const std::size_t &depth : bitDepths) {
        m_channelMaxLimits[idx] = static_cast<float>((1 << depth) - 1);
        m_values[idx] = 0;
        ++idx;
      }
    }

    virtual ~GenericSDR() = 0;

    EColorModel
    getColorModel() const {
      return colorModel;
    }

    std::size_t
    getNumChannels() const {
      return NUM_CHANNELS;
    }

    float
    getChannelMin(std::size_t idx) const {
      return 0.0f;
    }

    float
    getChannelMax(std::size_t idx) const {
      if(idx >= NUM_CHANNELS)
        throw std::out_of_range("color channel index");

      return(m_channelMaxLimits[idx]);
    }

    float
    get(std::size_t idx) const {
      if(idx >= NUM_CHANNELS)
        throw std::out_of_range("color channel index");

      return(m_values[idx]);
    }

    int
    getInt(std::size_t idx) const {
      if(idx >= NUM_CHANNELS)
        throw std::out_of_range("color channel index");

      return(m_values[idx]);
    }

    void
    set(std::size_t idx, float val) {
      if(idx >= NUM_CHANNELS)
        throw std::out_of_range("color channel index");

      m_values[idx] = val;
    }
  };
}

namespace SDF::Editor::UILayer::AbstractModel::Defs::Color {
  template<EColorModel colorModel, std::size_t ... channelBits>
  GenericSDR<colorModel, channelBits...>::~GenericSDR() {}
}

#endif
