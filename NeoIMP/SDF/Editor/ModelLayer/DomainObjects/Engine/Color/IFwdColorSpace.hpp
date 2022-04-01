#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLOR_IFWDCOLORSPACE_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLOR_IFWDCOLORSPACE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IFwdColorSpace.hpp
 * PURPOSE: Defines the IFwdColorSpace interface.
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
  // Class:      IFwdColorSpace
  // Purpose:    Defines a color space in terms of a mapping between normalized values in a color
  //             model and a fundamental space (here, we typically use a suitable normalization of
  //             CIEXYZ or CIELAB based on a reference standard illuminant).
  // Parameters: ColorModelT - The color model (in Models) used.
  //             FundamentalTraitsT - The fundamental space used.
  template<class ColorModelT, class FundamentalTraitsT>
  class IFwdColorSpace {
  public:
    virtual ~IFwdColorSpace() = default;

    // Function:   nrmlToFundamental
    // Purpose:    Converts a normalized pixel in its color model to a fundamental-space
    //             representation.
    // Parameters: uniformRep - The uniform data to convert.
    //             fs - The resulting fundamental-space representation (also in [0..1] typically).
    // Returns:    None.
    virtual void
    nrmlToFundamental(
      const std::array<float, ColorModelT::num_channels> &a_uniformRep,
      std::array<float, FundamentalTraitsT::num_channels> &a_fs
    ) const = 0;
  };
}

#endif
