#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_SDRCOLORSPACE_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_SDRCOLORSPACE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SDRColorSpace.hpp
 * PURPOSE: Defines the SDRColorSpace template.
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

#include "../IColorSpace.hpp"
#include "../IColorModel.hpp"
#include "../pixel_traits.hpp"
#include "IMap.hpp"

#include <array>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::ColorSpaces {
  // Class:   SDRColorSpace
  // Purpose: Defines a template for short dynamic range (SDR) color space families.
  // Parameters: PixelDataT - The pixel data type.
  //             FundamentalTraitsT - The fundamental space traits class.
  template<class PixelDataT, class FundamentalTraitsT>
  class SDRColorSpace : public IColorSpace<PixelDataT, FundamentalTraitsT> {
  private:
    const IColorModel<PixelDataT> *m_colorModel;
    const IMap<pixel_traits<PixelDataT>::semantic_t, FundamentalTraitsT> *m_map;
  public:
    SDRColorSpace(
      const IColorModel<PixelDataT> *colorModel,
      const IMap<pixel_traits<PixelDataT>::semantic_t, FundamentalTraitsT> *map
    )
      : m_colorModel(colorModel),
        m_map(map)
    {
    }

    inline std::array<float, FundamentalTraitsT::num_channels>
    pixelToFundamental(const PixelDataT &pixel) const {
      std::array<float, FundamentalTraitsT::num_channels> rv;
      auto vals = m_colorModel->pixelToValues(pixel);
      m_map->valsToFundamental(&vals[0], &fs[0]);
      return rv;
    }

    inline PixelDataT
    fundamentalToPixel(const std::array<float, FundamentalTraitsT::num_channels> &fs) const {
      std::array<float, FundamentalTraitsT::num_channels> vals;
      m_map->fundamentalToVals(&fs[0], &vals[0]);
      return m_colorModel->valuesToPixel(vals);
    }
  };
}

#endif
