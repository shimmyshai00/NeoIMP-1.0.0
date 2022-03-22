#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_IEC61966_SRGB_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLORSPACES_IEC61966_SRGB_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IEC61966_sRGB.hpp
 * PURPOSE: Defines the IEC61966_sRGB template.
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

#include "../ColorModels/Categories.hpp"
#include "../IColorModel.hpp"
#include "Fundamental/XyzD65.hpp"
#include "Maps/IEC61966_sRGB.hpp"
#include "SDRBuilder.hpp"

#include <algorithm>
#include <cmath>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::ColorSpaces {
  // Class:      IEC61966_sRGB
  // Purpose:    Defines a family of domain level color spaces based on the IEC 61966-2-1:1999 sRGB
  //             "standard Red Green Blue" standard, which is the common color space used by typical
  //             monitors and typical reference designant of RGB raw data in image files (e.g. CSS
  //             hex values on the Web). In effect, the "plate carrée" of color spaces. The
  //             fundamental space is CIE 1931 XYZ with the D65 standard illuminant. This last bit
  //             SHOULD BE NOTED. E.g. Photoshop has a CIELAB space implementation which uses *D50*.
  //             This affects the normalization. (implied TBA: add XyzD50 fundamental space)
  // Parameters: PixelDataT - The pixel data format to use.
  //             BitsR, BitsG, BitsB - The bit widths of the pixel data channels.
  template<class PixelDataT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB>
  using IEC61966_sRGB = SDRBuilderNoAlpha<
    PixelDataT, Fundamental::XyzD65, Maps::IEC61966_sRGB, BitsR, BitsG, BitsB
  >;

  // Alpha channel version.
  template<
    class AlphaPixelT, std::size_t BitsR, std::size_t BitsG, std::size_t BitsB, std::size_t BitsA
  >
  using IEC61966_sRGB_Alpha = SDRBuilderWithAlpha<
    AlphaPixelT, Fundamental::XyzD65, Maps::IEC61966_sRGB, BitsR, BitsG, BitsB, BitsA
  >;
}

#endif
