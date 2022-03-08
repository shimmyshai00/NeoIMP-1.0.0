#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORMODELS_UI_RGB_TPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORMODELS_UI_RGB_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RGB.tpp
 * PURPOSE: Implements the Rgb template.
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

#include "../../../../Exceptions.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::ColorModels::Ui {
  template<std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
  inline
  UILayer::AbstractModel::Defs::RGBColor<
    UILayer::AbstractModel::Defs::Channel<BitsR>,
    UILayer::AbstractModel::Defs::Channel<BitsG>,
    UILayer::AbstractModel::Defs::Channel<BitsB>
  >
  Rgb<BitsR, BitsG, BitsB>::encode(float *values) const {
    return UILayer::AbstractModel::Defs::RGBColor<
      UILayer::AbstractModel::Defs::Channel<BitsR>,
      UILayer::AbstractModel::Defs::Channel<BitsG>,
      UILayer::AbstractModel::Defs::Channel<BitsB>
    >(values[0], values[1], values[2]);
  }

  template<std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
  inline void
  Rgb<BitsR, BitsG, BitsB>::decode(UILayer::AbstractModel::Defs::RGBColor<
                                    UILayer::AbstractModel::Defs::Channel<BitsR>,
                                    UILayer::AbstractModel::Defs::Channel<BitsG>,
                                    UILayer::AbstractModel::Defs::Channel<BitsB>
                                   > pixel,
                                   float *values
                                  ) const
  {
    values[0] = pixel.m_r;
    values[1] = pixel.m_g;
    values[2] = pixel.m_b;
  }
}

#endif
