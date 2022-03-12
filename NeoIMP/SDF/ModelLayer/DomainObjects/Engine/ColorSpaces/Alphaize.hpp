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
  // Class:      Alphaize
  // Purpose:    Adapts a color space defined for an initially alpha channel-free pixel format to an
  //             alpha channel-possessing one. Note that a converter object must be supplied to
  //             append and remove the alpha channel. This is a sort of decorator pattern.
  // Parameters: BaseSpaceT - The base color space type.
  //             AlphaPixelT - The type of pixel with added alpha channel.
  //             AlphaBits - The number of bits in the added alpha channel.
  //             ConverterT - The converter type.
  template<
    template<class PixelDataT, class FundamentalTraitsT> class BaseSpaceT,
    std::size_t AlphaPixelT,
    class ConverterT
  >
  class Alphaize : public IColorSpace<AlphaPixelT, FundamentalTraitsT> {
  private:
    const BaseSpaceT *m_baseSpace;
  public:
    Alphaize(const BaseSpaceT *baseSpace)
      : m_baseSpace(baseSpace)
    {
    }


  }
}
#endif
