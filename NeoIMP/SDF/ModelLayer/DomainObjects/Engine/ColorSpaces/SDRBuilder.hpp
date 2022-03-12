#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_SDRBUILDER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_SDRBUILDER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SDRBuilder.hpp
 * PURPOSE: Provides further templates to build SDR spaces with mixins.
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


#include "../ColorModels/Categories.hpp"
#include "SDRBase.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::ColorSpaces {
  // Class:      SDRBuilderNoAlpha
  // Purpose:    Builds an SDR color space without alpha channel using a mixin mapping.
  // Parameters: PixelDataT - The pixel data type.
  //             FundamentalTraitsT - The fundamental space traits class.
  //             MapT - The map object, usually a struct with two members called "fundamentalToNrml"
  //                    and "nrmlToFundamental".
  //             BitDepths - The bit depths of the channels.
  template<class PixelDataT, class FundamentalTraitsT, class MapT, std::size_t ... BitDepths>
  class SDRBuilderNoAlpha : public SDRBase<PixelDataT, FundamentalTraitsT, BitDepths...> {
  public:
    // Function:   SDRBuilderNoAlpha
    // Purpose:    Construct with a given color model.
    SDRBuilderNoAlpha(const ColorModels::Base<PixelDataT, BitDepths...> *colorModel)
      : SDRBase<PixelDataT, FundamentalTraitsT, BitDepths...>(colorModel)
    {}
  protected:
    void
    nrmlToFundamental(float *nrml,
                      float *fs
                     ) const
    {
      MapT().nrmlToFundamental(nrml, fs);
    }

    void
    fundamentalToNrml(float *fs,
                      float *nrml
                     ) const
    {
      printf("F2N\n");
      MapT().fundamentalToNrml(fs, nrml);
      printf("nrmlV: %f %f %f\n", nrml[0], nrml[1], nrml[2]);
    }
  };
}

namespace SDF::ModelLayer::DomainObjects::Engine::ColorSpaces {
  // Class:      SDRBuilderWithAlpha
  // Purpose:    Builds an SDR color space with an alpha channel using a mixin mapping. The alpha
  //             channel is appended to the usual inputs/outputs, so it can be easily passed or
  //             ignored.
  // Parameters: AlphaPixelT - The alpha-enabled pixel data type.
  //             FundamentalTraitsT - The fundamental space traits class.
  //             MapT - The map object, same as above: the alpha channel is mapped internally,
  //                    as it has no color profile.
  //             BitDepths - The bit depths of the channels. The alpha channel is the LAST depth.
  template<class AlphaPixelT, class FundamentalTraitsT, class MapT, std::size_t ... BitDepths>
  class SDRBuilderWithAlpha : public SDRBase<AlphaPixelT, FundamentalTraitsT, BitDepths...> {
  public:
    // Function:   SDRBuilderWithAlpha
    // Purpose:    Construct with a given color model.
    SDRBuilderWithAlpha(const ColorModels::Base<AlphaPixelT, BitDepths...> *colorModel)
      : SDRBase<AlphaPixelT, FundamentalTraitsT, BitDepths...>(colorModel)
    {}
  protected:
    void
    nrmlToFundamental(float *nrml,
                      float *fs
                     ) const
    {
      // The last channel is the alpha channel.
      MapT().nrmlToFundamental(nrml, fs);
      fs[SDRBase<AlphaPixelT, FundamentalTraitsT, BitDepths...>::NUM_CHANNELS-1] =
        nrml[SDRBase<AlphaPixelT, FundamentalTraitsT, BitDepths...>::NUM_CHANNELS-1];
    }

    void
    fundamentalToNrml(float *fs,
                      float *nrml
                     ) const
    {
      MapT().fundamentalToNrml(fs, nrml);
      nrml[SDRBase<AlphaPixelT, FundamentalTraitsT, BitDepths...>::NUM_CHANNELS-1] =
        fs[SDRBase<AlphaPixelT, FundamentalTraitsT, BitDepths...>::NUM_CHANNELS-1];
    }
  };
}

#endif
