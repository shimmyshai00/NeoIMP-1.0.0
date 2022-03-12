#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_RGBBASE_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_RGBBASE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RgbBase.hpp
 * PURPOSE: Defines the RgbBase template.
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
  // Class:   RgbBase
  // Purpose: Defines a base template for families of RGB color spaces. These spaces
  // Parameters: PixelDataT - The pixel data type.
  //             FundamentalTraitsT - The fundamental space traits class. This should be an XYZ
  //                                  fundamental space (i.e. either Fundamental::XyzD65 or
  //                                  XyzD50 [TBA]).
  //             BitsR, BitsG, BitsB - The bit depths.
  template<
    class PixelDataT, class FundamentalTraitsT,
    std::size_t BitsR, std::size_t BitsG, std::size_t BitsB
  >
  class RgbBase : public IColorSpace<PixelDataT, FundamentalTraitsT> {
  public:
    // Function:   RgbBase
    // Purpose:    Construct with a given color model. Gatekeeps the color model to RGB types only.
    // Parameters: colorModel - The color model to construct with.
    RgbBase(const ColorModels::RgbBase<PixelDataT, BitsR, BitsG, BitsB> *colorModel)
      : m_colorModel(colorModel)
    {
      m_nrmlScaleFactors[0] = m_colorModel->getChannelMax(0) - m_colorModel->getChannelMin(0);
      m_nrmlScaleFactors[1] = m_colorModel->getChannelMax(1) - m_colorModel->getChannelMin(1);
      m_nrmlScaleFactors[2] = m_colorModel->getChannelMax(2) - m_colorModel->getChannelMin(2);

      m_nrmlOffsets[0] = m_colorModel->getChannelMin(0);
      m_nrmlOffsets[1] = m_colorModel->getChannelMin(1);
      m_nrmlOffsets[2] = m_colorModel->getChannelMin(2);
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
      float nrmlRgb[3];

      m_colorModel->convertPixelTo(pixel, nrmlRgb);

      nrmlRgb[0] = (nrmlRgb[0] - m_nrmlOffsets[0]) / m_nrmlScaleFactors[0];
      nrmlRgb[1] = (nrmlRgb[1] - m_nrmlOffsets[1]) / m_nrmlScaleFactors[1];
      nrmlRgb[2] = (nrmlRgb[2] - m_nrmlOffsets[2]) / m_nrmlScaleFactors[2];

      nrmlToFundamental(nrmlRgb, fs);
    }

    PixelDataT
    fundamentalToPixel(float *fs) const {
      float unnRgb[3];

      fundamentalToNrml(fs, unnRgb);

      unnRgb[0] = (unnRgb[0] * m_nrmlScaleFactors[0]) + m_nrmlOffsets[0];
      unnRgb[1] = (unnRgb[1] * m_nrmlScaleFactors[1]) + m_nrmlOffsets[1];
      unnRgb[2] = (unnRgb[2] * m_nrmlScaleFactors[2]) + m_nrmlOffsets[2];

      return m_colorModel->convertToPixel(unnRgb);
    }
  protected:
    const ColorModels::RgbBase<PixelDataT, BitsR, BitsG, BitsB> *m_colorModel;

    float m_nrmlScaleFactors[3];
    float m_nrmlOffsets[3];

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
