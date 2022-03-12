#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLORSPACES_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLORSPACES_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorSpaces.hpp
 * PURPOSE: Provides static definitions for the Boost.GIL engine's color spaces.
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

#include "../ColorSpaces/IEC61966_sRGB.hpp"

#include "ColorModels/Defs.hpp"

#include <boost/gil/rgb.hpp>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil::ColorSpaces {
  // Types.
  typedef Engine::ColorSpaces::IEC61966_sRGB<boost::gil::rgb8_pixel_t, 8, 8, 8>
    IEC61966_sRGB_RGB24_888;
}

namespace SDF::ModelLayer::DomainObjects::Engine::Gil::ColorSpaces {
  // Constants.
  static const IEC61966_sRGB_RGB24_888 g_iec61966_sRGB_rgb24_888 =
    IEC61966_sRGB_RGB24_888(&ColorModels::g_rgb24_888);
}

#endif
