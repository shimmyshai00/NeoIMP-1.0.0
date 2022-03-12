#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLORMODELS_GILRGBA_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLORMODELS_GILRGBA_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GilRgba.tpp
 * PURPOSE: Implements the GilRgba template.
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

namespace SDF::ModelLayer::DomainObjects::Engine::Gil::ColorModels {
  template<
    class GilPixelT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB, std::size_t BitsA
  >
  inline GilPixelT
  GilRgba<GilPixelT, BitsR, BitsG, BitsB, BitsA>::convertToPixel(float *values) const {
    return GilPixelT(values[0], values[1], values[2], values[3]);
  }

  template<
    class GilPixelT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB, std::size_t BitsA
  >
  inline void
  GilRgba<GilPixelT, BitsR, BitsG, BitsB, BitsA>::convertPixelTo(GilPixelT px,
                                                                 float *values
                                                                ) const
  {
    values[0] = boost::gil::at_c<0>(px);
    values[1] = boost::gil::at_c<1>(px);
    values[2] = boost::gil::at_c<2>(px);
    values[3] = boost::gil::at_c<3>(px);
  }
}

#endif
