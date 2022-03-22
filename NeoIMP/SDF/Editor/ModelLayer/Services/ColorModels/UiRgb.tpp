#ifndef SDF_EDITOR_MODELLAYER_SERVICES_COLORMODELS_UIRGB_TPP
#define SDF_EDITOR_MODELLAYER_SERVICES_COLORMODELS_UIRGB_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiRgb.tpp
 * PURPOSE: Implements the UiRgb template.
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

namespace SDF::Editor::ModelLayer::Services::ColorModels {
  template<class UiPixelT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
  inline UiPixelT
  UiRgb<UiPixelT, BitsR, BitsG, BitsB>::convertToPixel(float *values) const {
    return UiPixelT(floor(values[0] + 0.5f), floor(values[1] + 0.5f), floor(values[2] + 0.5f));
  }

  template<class UiPixelT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
  inline void
  UiRgb<UiPixelT,BitsR, BitsG, BitsB>::convertPixelTo(UiPixelT px, float *values) const {
    values[0] = px.getR();
    values[1] = px.getG();
    values[2] = px.getB();
  }
}

#endif
