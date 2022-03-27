#ifndef SDF_EDITOR_MODELLAYER_ABSTRACTDATA_GIL_COLORSPACE_HPP
#define SDF_EDITOR_MODELLAYER_ABSTRACTDATA_GIL_COLORSPACE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorSpace.hpp
 * PURPOSE: Defines some convenience shorthand for Boost.GIL color spaces.
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

#include "../../../ModelLayer/DomainObjects/Engine/IBidirectionalColorSpace.hpp"
#include "../../../ModelLayer/DomainObjects/Engine/ColorSpaces/Fundamental/XyzD65.hpp"

namespace SDF::Editor::ModelLayer::AbstractData::Gil {
  template<class GilPixelT>
  using RgbColorSpace = ModelLayer::DomainObjects::Engine::IBidirectionalColorSpace<
    GilPixelT,
    ModelLayer::DomainObjects::Engine::ColorSpaces::Fundamental::XyzD65
  >;
}

#endif
