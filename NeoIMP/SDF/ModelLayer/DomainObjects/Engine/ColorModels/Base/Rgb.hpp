#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORMODELS_BASE_RGB_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORMODELS_BASE_RGB_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RGB.hpp
 * PURPOSE: Defines the Rgb template.
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

#include "../../IColorModel.hpp"

#include <cstddef>

namespace SDF::ModelLayer::DomainObjects::Engine::ColorModels::Base {
  // Class:      Rgb
  // Purpose:    Defines a family of RGB-based color models. The bit depths of each channel can be
  //             specified independently.
  // Parameters: PixelDataT - The pixel data type. Converters must be supplied by derived classes.
  //             BitsR - The number of bits in the Red channel.
  //             BitsG - The number of bits in the Green channel.
  //             BitsB - The number of bits in the Blue channel.
  template<class PixelDataT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
  class Rgb : public IColorModelImpl<PixelDataT> {
  public:
    inline Rgb();

    std::size_t
    inline getNumChannels() const;

    std::size_t
    inline getChannelBitDepth(std::size_t channelNum) const;

    float
    inline getChannelMinValue(std::size_t channelNum) const;

    float
    inline getChannelMaxValue(std::size_t channelNum) const;
  private:
    std::size_t m_bitDepths[3];
    float m_channelMaxes[3];
  };
}

#include "Rgb.tpp"

#endif
