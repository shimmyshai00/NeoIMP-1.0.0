/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UiRgbUnnormalizer.cpp
 * PURPOSE: Implements the UiRgbUnnormalizer class.
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

#include "UiRgbUnnormalizer.hpp"

namespace SDF::Editor::ModelLayer::Services::Color {
  void
  UiRgbUnnormalizer::unnormalize(
    const std::array<float, 3> &a_uniformRep,
    UILayer::AbstractModel::Defs::Color::IColor<UILayer::AbstractModel::Defs::Color::UiColorModel>
      &a_px
  ) const {
    a_px.setValueF(0, a_uniformRep[0]);
    a_px.setValueF(1, a_uniformRep[1]);
    a_px.setValueF(2, a_uniformRep[2]);
  }
}
