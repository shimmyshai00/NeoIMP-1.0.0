/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorConversionEngine.cpp
 * PURPOSE: Implements the ColorConversionEngine class.
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

#include "ColorConversionEngine.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil::Color {
  ColorConversionEngine::ColorConversionEngine() {
  }

  void
  ColorConversionEngine::registerRGBColorMapping(
    std::string name,
    std::shared_ptr<ColorSpaces::IBidirectionalMapping<FundamentalColorSpace>> mapping
  ) {
    // Register in every RGB space.
    template<class GilPixelT>
    using RGBColorSpace = ColorSpaces::SDRIllumColorSpace<GilPixelT, FundamentalColorSpace>;

    m_csm_RGB24_888[name] = std::make_unique<RGBColorSpace<boost::gil::rgb8_pixel_t>>(mapping);
  }

  template<class GilPixelT, class DstPixelT>
  void
  ColorConversionEngine::mapPixel(
    GilPixelT px,
    std::string fromSpace,
    const IRevColorSpace<DstPixelT, ColorSpaces::Fundamental::XyzD65> &toSpace
  ) {
    std::array<float, FundamentalColorSpace::num_channels> fundamentalValues;


  }
}
