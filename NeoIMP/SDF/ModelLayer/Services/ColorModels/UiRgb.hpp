#ifndef SDF_MODELLAYER_SERVICES_COLORMODELS_UIRGB_HPP
#define SDF_MODELLAYER_SERVICES_COLORMODELS_UIRGB_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiRgb.hpp
 * PURPOSE: Defines the UiRgb template.
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

#include "../../DomainObjects/Engine/ColorModels/Categories.hpp"

#include <cstddef>

namespace SDF::ModelLayer::Services::ColorModels {
  // Class:      UiRgb
  // Purpose:    Defines a family of RGB-based UI-facing color models. This is kept in the service
  //             layer because it bridges the domain sublayer and the UI layer and thus keeps the
  //             domain sublayer free of UI cruft.
  // Parameters: UiPixelT - The pixel type defined in the abstract UI layer.
  //             BitsR - The number of bits in the Red channel.
  //             BitsG - The number of bits in the Green channel.
  //             BitsB - The number of bits in the Blue channel.
  template<class UiPixelT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
  class UiRgb : public DomainObjects::Engine::ColorModels::RgbBase<UiPixelT, BitsR, BitsG, BitsB>
  {
  public:
    inline UiPixelT
    convertToPixel(float *values) const;

    inline void
    convertPixelTo(UiPixelT px,
                   float *values
                  ) const;
  };
}

#include "UiRgb.tpp"

#endif
