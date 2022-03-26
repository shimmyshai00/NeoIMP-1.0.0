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

    // Function:   getValueMin
    // Purpose:    Gets the minimum value that can be put into a channel of this color model.
    //             Normally, this is 0.
    // Parameters: channel - The channel to get the minimum for.
    // Returns:    The minimum value.
    virtual float
    getValueMin(std::size_t channel) const = 0;

    // Function:   getValueMax
    // Purpose:    Gets the maximum value that can be put into a channel of this color model. In SDR
    //             models, this is typically 1. In HDR models, it may surpass 1.
    // Parameters: channel - The channel to get the maximum for.
    // Returns:    The maximum value.
    virtual float
    getValueMax(std::size_t channel) const = 0;

    // Function:   getQuantizationStep
    // Purpose:    Gets the quantization step in a pixel channel. This is the minimum floating point
    //             step required to change the pixel data value, e.g. in 8-bpc color it is 1.0f/255.
    //             In HDR formats it is 0 (continuous) - NOTE THIS before taking a reciprocal of
    //             this value to avoid an FPE!
    // Parameters: channel - The channel to get the step for.
    // Returns:    The quantization step for this format.
    virtual float
    getQuantizationStep(std::size_t channel) const = 0;

    // Function:   valuesToPixel
    // Purpose:    Converts a set of values to a pixel of the given data type.
    // Parameters: values - The values to convert, which must be in the range
    //                      [getValueMin()..getValueMax()].
    // Returns:    The newly-minted pixel.
    virtual PixelDataT
    valuesToPixel(const std::array<float, pixel_traits<PixelDataT>::num_channels> &values) const =
      0;

    // Function:   pixelToValues
    // Purpose:    Converts a pixel to a set of values.
    // Parameters: px - The pixel to convert.
    // Returns:    An array of values corresponding to the pixel.
    virtual std::array<float, pixel_traits<PixelDataT>::num_channels>
    pixelToValues(const PixelDataT &px) const = 0;
  };
}

#endif
