#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORMODELS_ALPHAIZE_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORMODELS_ALPHAIZE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Alphaize.hpp
 * PURPOSE: Defines the Alphaize template.
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

#include "../../../Exceptions.hpp"
#include "../IColorModel.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::ColorModels {
  // Class:      Alphaize
  // Purpose:    Applies a sort of decorator pattern to augment a color model with an alpha channel.
  //             In particular, permits ignoring of the alpha channel by a simple cast.
  // Parameters: BaseModelT - The data type of the unaugmented color model.
  //             AlphaPixelDataT - The data type of the alpha-augmented pixels.
  //             AlphaBits - The number of bits in the alpha channel.
  //             AlphaCombiner - An object to extend PixelDataT to AlphaPixelDataT, and also to rip
  //                             the alpha from an AlphaPixelDataT
  template<
    template<class PixelDataT, std::size_t ... BitDepths> class BaseModelT
    class AlphaPixelDataT, std::size_t AlphaBits,
    class AlphaCombiner
  >
  class Alphaize : public IColorModel<AlphaPixelDataT>,
                   public BaseModelT
  {
  private:
    const std::size_t c_numChannels;

    float m_alphaMin;
    float m_alphaMax;
  public:
    inline
    Alphaize(const BaseModelT &baseModel)
      : BaseModelT(baseModel),
        c_numChannels(BaseModelT::getNumChannels()+1)
    {
      m_alphaMin = 0.0f;
      m_alphaMax = static_cast<float>((1 << AlphaBits) - 1);
    }

    // NB: shadows, not overrides, BaseModelT - this is very important so we can ignore the alpha
    //     channel correctly
    inline std::size_t
    getNumChannels() const {
      return c_numChannels;
    }

    inline float
    getChannelMax(std::size_t channelNum) const {
#ifndef NDEBUG
      if(channelNum >= c_numChannels) {
        throw OutOfRangeException();
      }
#endif
      if(channelNum < c_numChannels-1) {
        return BaseModelT::getChannelMax(channelNum);

      } else {
        return m_alphaMax;
      }
    }

    inline float
    getChannelMin(std::size_t channelNum) const {
#ifndef NDEBUG
      if(channelNum >= c_numChannels-1) {
        throw OutOfRangeException();
      }
#endif
      if(channelNum < c_numChannels-1) {
        return BaseModelT::getChannelMin(channelNum);
      } else {
        return m_alphaMin;
      }
    }

    // Convenience added methods
    inline float
    getAlphaMax() const {
      return getChannelMax(c_numChannels-1);
    }

    inline float
    getAlphaMin() const {
      return getChannelMin(c_numChannels-1);
    }
    
    // NB: overrides IColorModel<AlphaPixelDataT> but SHOULD not override BaseModelT
    inline AlphaPixelDataT
    convertToPixel(float *values) const {
      AlphaCombiner ac;
      return ac.combine(BaseModelT::convertToPixel(values), values[c_numChannels-1]);
    }

    inline void
    convertPixelTo(AlphaPixelDataT px,
                   float *values
                  ) const
    {
      AlphaCombiner ac;
      std::pair<PixelDataT, float> splitPx = ac.split(px);

      BaseModelT::convertPixelTo(splitPx.first, values);
      values[c_numChannels-1] = splitPx.second;
    }
  };
}

#endif
