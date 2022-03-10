#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORMODELS_BASE_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORMODELS_BASE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Base.hpp
 * PURPOSE: Defines the Base template.
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

#include "../../../../Common/Meta.hpp"
#include "../../../Exceptions.hpp"
#include "../IColorModel.hpp"

#include <boost/mp11/integral.hpp>
#include <boost/mp11/list.hpp>

#include <cstddef>
#include <list>

namespace SDF::ModelLayer::DomainObjects::Engine::ColorModels {
  // Class:      Base
  // Purpose:    Provides a base implementation for defining most color models.
  // Parameters: PixelDataT - The pixel data type. Converters must be supplied by derived classes.
  //             BitCounts - The bit counts of the pixel data channels, in their proper order.
  template<class PixelDataT, std::size_t ... BitCounts>
  class Base : public IColorModelImpl<PixelDataT, BitCounts...> {
  private:
    typedef boost::mp11::mp_list_c<std::size_t, BitCounts...> channel_counts_type;
    static const std::size_t NUM_CHANNELS = boost::mp11::mp_size<channel_counts_type>::value;

    std::size_t m_channelBits[NUM_CHANNELS];
    float m_channelMins[NUM_CHANNELS]; // presumably unnecessary as it should always be 0, but one
                                       // could imagine maybe there is some reason one might want
                                       // to have an image format that can store physically
                                       // nonsensical "darker than black" or "anti" color values
                                       // with negative values (e.g. perhaps because of how it would
                                       // composite with sensible values to create cool effects?).
    float m_channelMaxes[NUM_CHANNELS];
  public:
    typedef PixelDataT pixel_type; // convenience for implementors

    inline
    Base() {
      std::list<std::size_t> bitDepths;
      Common::Meta::push_into<std::size_t, BitCounts...>(bitDepths);

      std::size_t idx = 0;
      for(const std::size_t &depth : bitDepths) {
        m_channelBits[idx] = depth;
        m_channelMins[idx] = 0.0f;
        m_channelMaxes[idx] = static_cast<float>((1 << depth) - 1);
        ++idx;
      }
    }

    std::size_t
    inline getNumChannels() const {
      return NUM_CHANNELS;
    }

    std::size_t
    inline getChannelBitDepth(std::size_t channelNum) const {
#ifndef NDEBUG
      if(channelNum >= NUM_CHANNELS) {
        throw OutOfRangeException();
      }
#endif
      return m_channelBits[channelNum];
    }

    float
    inline getChannelMinValue(std::size_t channelNum) const {
#ifndef NDEBUG
      if(channelNum >= NUM_CHANNELS) {
        throw OutOfRangeException();
      }
#endif
      return m_channelMins[channelNum];
    }

    float
    inline getChannelMaxValue(std::size_t channelNum) const {
#ifndef NDEBUG
      if(channelNum >= NUM_CHANNELS) {
        throw OutOfRangeException();
      }
#endif
      return m_channelMaxes[channelNum];
    }
  };
}

#endif
