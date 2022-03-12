#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_SUPERFAMILIES_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_SUPERFAMILIES_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Superfamilies.hpp
 * PURPOSE: Defines bases for different (super-)families of color spaces. (We say "superfamilies"
 *          here because in our terminology a single "color space" is defined with a specfic color
 *          model down to a pixel format type. This may be different from common usage where those
 *          would be considered as different realizations of the same color space, and a "family of
 *          color spaces" is the group of realizations for a single color space.)
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
  // RGB superfamily
  template<
    class PixelDataT, class FundamentalTraitsT,
    std::size_t BitsR, std::size_t BitsG, std::size_t BitsB
  >
  class RgbBase : public SDRBase<PixelDataT, FundamentalTraitsT, BitsR, BitsG, BitsB> {
  public:
    // Gatekeeping constructor to only permit construction with an RGB color model.
    RgbBase(const ColorModels::RgbBase<PixelDataT, BitsR, BitsG, BitsB> *colorModel)
      : SDRBase<PixelDataT, FundamentalTraitsT, BitsR, BitsG, BitsB>(colorModel)
    {}
  };
}

#endif
