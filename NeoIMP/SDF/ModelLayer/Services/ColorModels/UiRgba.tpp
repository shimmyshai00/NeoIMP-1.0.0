#ifndef SDF_MODELLAYER_SERVICES_COLORMODELS_UIRGBA_TPP
#define SDF_MODELLAYER_SERVICES_COLORMODELS_UIRGBA_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiRgba.tpp
 * PURPOSE: Implements the UiRgba template.
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

#include "../../Exceptions.hpp"

namespace SDF::ModelLayer::Services::ColorModels {
  template<
    class UiPixelT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB, std::size_t BitsA
  >
  inline UiPixelT
  UiRgba<UiPixelT, BitsR, BitsG, BitsB, BitsA>::convertToPixel(float *values) const {
    return UiPixelT(floor(values[0]), floor(values[1]), floor(values[2]), floor(values[3]));
  }

  template<
    class UiPixelT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB, std::size_t BitsA
  >
  inline void
  UiRgba<UiPixelT,BitsR, BitsG, BitsB, BitsA>::convertPixelTo(UiPixelT px,
                                                              float *values
                                                             ) const
  {
    values[0] = px.m_r;
    values[1] = px.m_g;
    values[2] = px.m_b;
    values[3] = px.m_a;
  }
}

#endif
