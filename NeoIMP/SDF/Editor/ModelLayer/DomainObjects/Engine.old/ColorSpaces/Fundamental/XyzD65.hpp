#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_FUNDAMENTAL_XYZD65_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_FUNDAMENTAL_XYZD65_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    XyzD65.hpp
 * PURPOSE: Defines the traits for the fundamental space given by CIE 1931 XYZ with a D65 standard
 *          illuminant white point.
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

#include <cstddef>

namespace SDF::ModelLayer::DomainObjects::Engine::ColorSpaces::Fundamental {
  struct XyzD65 {
    static constexpr const std::size_t num_channels = 3;

    // The white point for this color space.
    static constexpr const float white_point_x = 0.31271f;
    static constexpr const float white_point_y = 0.32902f;
    static constexpr const float white_point_z = 0.35827f;

    // The normalization factor - in this case we want to normalize the Y-component to be equal to
    // 1.
    static constexpr const float white_point_nrml_fac = white_point_y;
  };
}

#endif
