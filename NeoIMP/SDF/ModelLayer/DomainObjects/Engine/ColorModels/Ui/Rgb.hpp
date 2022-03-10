#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORMODELS_UI_RGB_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORMODELS_UI_RGB_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RGB.hpp
 * PURPOSE: Defines the Rgb template.
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

#include "../Categories.hpp"

#include <cstddef>

namespace SDF::ModelLayer::DomainObjects::Engine::ColorModels::Ui {
  // Class:      Rgb
  // Purpose:    Defines a family of RGB-based UI-facing color models.
  // Parameters: UiPixelT - The pixel type defined in the abstract UI layer.
  //             BitsR - The number of bits in the Red channel.
  //             BitsG - The number of bits in the Green channel.
  //             BitsB - The number of bits in the Blue channel.
  template<class UiPixelT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
  class Rgb : public ColorModels::RgbBase<RgbPixel<BitsR, BitsG, BitsB>, BitsR, BitsG, BitsB>
  {
  public:
    inline UiPixelT
    encode(float *values) const;

    inline void
    decode(UiPixelT pixel,
           float *values
          ) const;
  };
}

#include "Rgb.tpp"

#endif
