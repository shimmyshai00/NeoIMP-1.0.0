#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLOR_COLORCONVERSIONENGINE_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_COLOR_COLORCONVERSIONENGINE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ColorConversionEngine.hpp
 * PURPOSE: Defines the ColorConversionEngine class.
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

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Gil::Color {
  // Class:      ColorConversionEngine
  // Purpose:    Defines an engine core that converts Boost.GIL pixels from document color spaces to
  //             user-provided spaces.
  // Parameters: None.
  class ColorConversionEngine {
  private:
    // Note: you can change this if you want to use a different fundamental (e.g. D50) - however,
    //       some spaces may need adaptation (TBA).
    typedef ColorSpaces::Fundamental::XyzD65 FundamentalColorSpace;
  public:
    ColorConversionEngine();

    void
    registerRGBColorMapping(
      std::string name,
      std::shared_ptr<ColorSpaces::IBidirectionalMapping<FundamentalColorSpace>> mapping
    );

    template<class GilPixelT, class DstPixelT>
    void
    mapPixel(
      GilPixelT px,
      std::string fromSpace,
      const IRevColorSpace<DstPixelT, FundamentalColorSpace> &toSpace
    );
  private:
    // All the different color formats.
    // RGB
    std::map<std::string, std::shared_ptr<ColorSpaces::IBidirectionalMapping<FundamentalColorSpace>>
      m_rgbMappings;
  };
}

#endif
