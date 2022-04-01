#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLOR_IFWDNORMALIZER_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLOR_IFWDNORMALIZER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IFwdNormalizer.hpp
 * PURPOSE: Defines the IFwdNormalizer interface.
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

#include <array>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Color {
  // Class:      IFwdNormalizer
  // Purpose:    Defines a mapping that maps from pixel data in a given color model into a uniform
  //             intermediate representation in terms of floating-point numbers.
  // Parameters: ColorModelT - The color model (in Models) used.
  //             PixelDataT - The type of pixel data accepted.
  template<class ColorModelT, class PixelDataT>
  class IFwdNormalizer {
  public:
    virtual ~IFwdNormalizer() = default;

    // Function:   normalize
    // Purpose:    Converts a pixel to a uniform representation.
    // Parameters: px - The pixel to convert.
    //             uniformRep - The resulting uniform representation, as floats in the range [0..1]
    //                          and in the semantic ordering of the color model.
    // Returns:    None.
    virtual void
    normalize(const PixelDataT &a_px, std::array<float, ColorModelT::num_channels> &a_uniformRep)
      const = 0;
  };
}

#endif
