#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_ALPHAIZE_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_ALPHAIZE_HPP

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

namespace SDF::ModelLayer::DomainObjects::Engine::ColorSpaces {
  // Class:    Alphaize
  // Purpose:  A decorator to adapt a "normal" color space to append an alpha channel.
  template<
    template<class PixelDataT, class FundamentalTraitsT, std::size_t ... BitDepths>
      class BaseSpaceT,
    class AlphaPixelDataT, std::size_t AlphaBits,
    class AlphaCombiner
  >
  class Alphaize : public IColorSpace<AlphaPixelDataT, FundamentalTraitsT>,
                   public BaseSpaceT
  {
  private:
    ColorModels::Alphaize<IColorModel<PixelDataT>, AlphaPixelDataT, AlphaBits, AlphaCombiner>
      m_colorModel;

    float m_nrmlScaleFactor;
    float m_nrmlOffset;
  public:
    inline
    Alphaize(const BaseSpaceT &baseSpace)
      : BaseSpaceT(baseSpace),
        m_colorModel(BaseSpaceT::getColorModel()),
        m_nrmlScaleFactor(m_colorModel->getAlphaMax() - m_colorModel->getAlphaMin()),
        m_nrmlOffset(m_colorMode->getAlphaMin())
    {}

    const IColorModel<AlphaPixelDataT> &
    getColorModel() const {
      return m_colorModel;
    }

    void
    pixelToFundamental(AlphaPixelDataT pixel,
                       float *fs
                      ) const
    {
      AlphaCombiner ac;
      std::pair<PixelDataT, float> splitPixel = ac.split(pixel);

      BaseSpaceT::pixelToFundamental(splitPixel.first, fs);
      fs[m_colorModel->getNumChannels()-1] = splitPixel.second;
    }

    AlphaPixelDataT
    fundamentalToPixel(float *fs) const {
      AlphaCombiner ac;
      PixelDataT pixel = BaseSpaceT::fundamentaToPixel(fs);

      return ac.combine(pixel, fs[m_colorModel->getNumChannels()-1]);
    }
  };
}

#endif
