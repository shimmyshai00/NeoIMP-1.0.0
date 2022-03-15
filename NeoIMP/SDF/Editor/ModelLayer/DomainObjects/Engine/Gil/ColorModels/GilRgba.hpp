#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLORMODELS_GILRGBA_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLORMODELS_GILRGBA_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GilRgba.hpp
 * PURPOSE: Defines the GilRgba template.
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

#include <boost/gil/rgba.hpp>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil::ColorModels {
  // Class:      GilRgba
  // Purpose:    Defines a family of RGB color models with alpha, mapping to Boost.GIL pixel types.
  // Parameters: GilPixelT - The Boost.GIL (or 100% compatible) pixel type to use.
  //             BitsR, BitsG, BitsB, BitsA - The channel bit depths.
  template<
    class GilPixelT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB, std::size_t BitsA
  >
  class GilRgba : public Engine::ColorModels::RgbaBase<GilPixelT, BitsR, BitsG, BitsB, BitsA> {
  public:
    inline GilPixelT
    convertToPixel(float *values) const;

    inline void
    convertPixelTo(GilPixelT px,
                   float *values
                  ) const;
  };
}

#include "GilRgba.tpp"

#endif
