#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORMODELS_COLORSPACES_SDRBASE_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORMODELS_COLORSPACES_SDRBASE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SDRBase.hpp
 * PURPOSE: Defines the SDRBase template.
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
#include "../IColorSpace.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::ColorSpaces {
  // Class:   SDRBase
  // Purpose: Defines a base template for short dynamic range (SDR) color space families.
  // Parameters: PixelDataT - The pixel data type.
  //             FundamentalTraitsT - The fundamental space traits class.
  //             BitDepths - The bit depths of the channels.
  template<class PixelDataT, class FundamentalTraitsT, std::size_t ... BitDepths>
  class SDRBase : public IColorSpace<PixelDataT, FundamentalTraitsT> {
  protected:
    typedef boost::mp11::mp_list_c<std::size_t, BitDepths...> channel_counts_type;
    static const std::size_t NUM_CHANNELS = boost::mp11::mp_size<channel_counts_type>::value;
  private:
    const ColorModels::Base<PixelDataT, BitDepths...> *m_colorModel;

    float m_nrmlScaleFactors[NUM_CHANNELS];
    float m_nrmlOffsets[NUM_CHANNELS];
  public:
    // Function:   SDRBase
    // Purpose:    Construct with a given color model.
    SDRBase(const ColorModels::Base<PixelDataT, BitDepths...> *colorModel)
      : m_colorModel(colorModel)
    {
      for(std::size_t i(0); i < NUM_CHANNELS; ++i)
        m_nrmlScaleFactors[i] = m_colorModel->getChannelMax(i) - m_colorModel->getChannelMin(i);

      for(std::size_t i(0); i < NUM_CHANNELS; ++i)
        m_nrmlOffsets[i] = m_colorModel->getChannelMin(i);
    }

    const IColorModel<PixelDataT> &
    getColorModel() const {
      return *m_colorModel;
    }

    void
    pixelToFundamental(PixelDataT pixel,
                       float *fs
                      ) const
    {
      float nrmlValues[NUM_CHANNELS];

      m_colorModel->convertPixelTo(pixel, nrmlValues);

      for(std::size_t i(0); i < NUM_CHANNELS; ++i)
        nrmlValues[i] = (nrmlValues[i] - m_nrmlOffsets[i]) / m_nrmlScaleFactors[i];

      printf("   nrml pixel rgb: %f %f %f\n", nrmlValues[0], nrmlValues[1], nrmlValues[2]);

      nrmlToFundamental(nrmlValues, fs);

      printf("   fs: %f %f %f\n", fs[0], fs[1], fs[2]);
    }

    PixelDataT
    fundamentalToPixel(float *fs) const {
      float unnValues[4];

      fundamentalToNrml(fs, unnValues);

      for(std::size_t i(0) ; i < NUM_CHANNELS; ++i)
        unnValues[i] = (unnValues[i] * m_nrmlScaleFactors[i]) + m_nrmlOffsets[i];

      return m_colorModel->convertToPixel(unnValues);
    }
  protected:
    // Function:   nrmlToFundamental
    // Purpose:    Convert normalized RGB input in the range [0, 1] to XYZ space values.
    // Parameters: nrml - The incoming normalized RGB input.
    //             fs - The output fundamental space values. The implementation must retain the
    //                  proper white point normalization, i.e. when given (1.0f, 1.0f, 1.0f) as
    //                  input in nrml, fs must yield the normalized white point as defined in the
    //                  fundamental space traits class.
    // Returns:    None.
    virtual void
    nrmlToFundamental(float *nrml,
                      float *fs
                     ) const = 0;

    // Function:   fundamentalToNrml
    // Purpose:    Does the inverse of the above mapping.
    // Parameters: fs - The incoming fundamental space values.
    //             nrml - The output normalized RGB values.
    // Returns:    None.
    virtual void
    fundamentalToNrml(float *fs,
                      float *nrml
                     ) const = 0;
  };
}

#endif
