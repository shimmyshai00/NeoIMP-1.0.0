#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLOR_IREVNORMALIZER_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COLOR_IREVNORMALIZER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IRevNormalizer.hpp
 * PURPOSE: Defines the IRevNormalizer interface.
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
  // Class:      IRevNormalizer
  // Purpose:    Defines the reverse mapping to the one in IFwdNormalizer.
  // Parameters: ColorModelT - The color model (in Models) used.
  //             PixelDataT - The type of pixel data accepted.
  template<class ColorModelT, class PixelDataT>
  class IRevNormalizer {
  public:
    virtual ~IRevNormalizer() = default;

    // Function:   unnormalize
    // Purpose:    Converts a uniform representation to pixel data.
    // Parameters: uniformRep - The input uniform representation.
    //             px - The object to receive the output pixel data.
    // Returns:    None.
    virtual void
    unnormalize(const std::array<float, ColorModelT::num_channels> &uniformRep, PixelDataT &px)
      const = 0;
  };
}

#endif
