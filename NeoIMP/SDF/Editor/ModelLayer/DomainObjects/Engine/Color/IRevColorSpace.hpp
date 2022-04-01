#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLOR_IREVCOLORSPACE_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLOR_IREVCOLORSPACE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IRevColorSpace.hpp
 * PURPOSE: Defines the IRevColorSpace interface.
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
  // Class:      IRevColorSpace
  // Purpose:    Defines the reverse of the IFwdColorSpace mapping. Not all color spaces permit this
  //             type of reverse mapping (i.e. from the fundamental space back to the color model
  //             space) - a notorious example are spaces built on the CMYK model used for designing
  //             printer-optimized images, due to the extra color dimension which cannot be
  //             straightforwardly carried across.
  // Parameters: ColorModelT - The color model (in Models) used.
  //             FundamentalTraitsT - The fundamental space used.
  template<class ColorModelT, class FundamentalTraitsT>
  class IRevColorSpace {
  public:
    virtual ~IRevColorSpace() = default;

    // Function:   fundamentalToNrml
    // Purpose:    Converts a fundamental-space representation back to a normalized color model
    //             representation.
    // Parameters: fs - The fundamental space representation to convert.
    //             uniformRep - The reversed uniform color model representation.
    // Returns:    None.
    virtual void
    fundamentalToNrml(
      const std::array<float, FundamentalTraitsT::num_channels> &a_fs,
      std::array<float, ColorModelT::num_channels> &a_uniformRep
    ) const = 0;
  };
}

#endif
