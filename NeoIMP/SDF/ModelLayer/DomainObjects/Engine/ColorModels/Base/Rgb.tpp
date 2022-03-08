#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORMODELS_BASE_RGB_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORMODELS_BASE_RGB_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RGB.tpp
 * PURPOSE: Implements the Rgb template.
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

#include "../../../../Exceptions.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::ColorModels::Base {
  template<class PixelDataT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
  Rgb<PixelDataT, BitsR, BitsG, BitsB>::Rgb() {
    m_bitDepths[0] = BitsR;
    m_bitDepths[1] = BitsG;
    m_bitDepths[2] = BitsB;

    m_channelMaxes[0] = (float)((1 << BitsR) - 1);
    m_channelMaxes[1] = (float)((1 << BitsG) - 1);
    m_channelMaxes[2] = (float)((1 << BitsB) - 1);
  }

  template<class PixelDataT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
  std::size_t
  Rgb<PixelDataT, BitsR, BitsG, BitsB>::getNumChannels() const {
    return 3;
  }

  template<class PixelDataT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
  std::size_t
  Rgb<PixelDataT, BitsR, BitsG, BitsB>::getChannelBitDepth(std::size_t channelNum) const {
#ifndef NDEBUG
    if(channelNum >= 3) {
      throw OutOfRangeException();
    }
#endif
    return m_bitDepths[channelNum];
  }

  template<class PixelDataT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
  float
  Rgb<PixelDataT, BitsR, BitsG, BitsB>::getChannelMinValue(std::size_t channelNum) const {
    return 0;
  }

  template<class PixelDataT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
  float
  Rgb<PixelDataT, BitsR, BitsG, BitsB>::getChannelMaxValue(std::size_t channelNum) const {
#ifndef NDEBUG
    if(channelNum >= 3) {
      throw OutOfRangeException();
    }
#endif
    return m_channelMaxes[channelNum];
  }
}

#endif
