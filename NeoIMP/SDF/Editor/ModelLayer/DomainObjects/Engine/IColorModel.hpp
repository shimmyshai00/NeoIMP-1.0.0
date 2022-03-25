#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_ICOLORMODEL_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_ICOLORMODEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IColorModel.hpp
 * PURPOSE: Defines the IColorModel interface.
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

#include "pixel_traits.hpp"

#include <cstddef>
#include <array>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine {
  // Class:   IColorModel
  // Purpose: Defines an interface for color models. A color model is a format for representing
  //          color information as computer data. Typically, models are defined in terms of a
  //          one or more channels, or dimensions, that represent intensities of different primary
  //          color components which combine to form a desired color.
  // Parameters: PixelDataT - The data type of the pixels that this color model uses.
  template<class PixelDataT>
  class IColorModel {
  public:
    virtual ~IColorModel() = default;

    // Function:   convertToPixel
    // Purpose:    Converts a set of numeric inputs to a pixel of the given data type.
    // Parameters: values - The channel values as floats in the range [0..1]. In high-dynamic range
    //                      (HDR) color spaces, the values are allowed to exceed 1.
    // Returns:    The newly-minted pixel.
    virtual PixelDataT
    convertToPixel(const std::array<float, pixel_traits<PixelDataT>::num_channels> &values) const =
      0;

    // Function:   convertPixelTo
    // Purpose:    Converts a pixel to a set of floating-point outputs.
    // Parameters: px - The pixel to convert.
    //             values - The array of channel values to receive the result. Must have
    //                      at least getNumChannels() elements.
    // Returns:    None.
    virtual void
    convertPixelTo(
      PixelDataT px,
      std::array<float, pixel_traits<PixelDataT>::num_channels> &values
    ) const = 0;
  };
}

#endif
