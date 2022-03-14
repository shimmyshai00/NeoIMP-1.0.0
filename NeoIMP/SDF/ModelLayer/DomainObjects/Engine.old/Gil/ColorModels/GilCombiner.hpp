#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLORMODELS_GILCOMBINER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLORMODELS_GILCOMBINER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GilCombiner.hpp
 * PURPOSE: Defines the combiner for alpha channels into Boost.GIL pixels.
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

#include "../../ColorModels/Alphaize.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::Gil::ColorModels {
  // Class:      GilCombiner
  // Purpose:    Augments a pixel with an alpha channel.
  // Parameters: GilPixelT - The source type.
  //             GilAlphaPixelT - The alpha-augmented type.
  template<class GilPixelT, class GilAlphaPixelT>
  struct GilCombiner {
    GilAlphaPixelT
    combine(GilPixelT pixel, float alpha) {
      return GilAlphaPixelT()
    }
  };
}
#endif
