#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_ICOLORMODEL_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_ICOLORMODEL_HPP

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

#include <cstddef>

namespace SDF::ModelLayer::DomainObjects::Engine {
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

    // Function:   getNumChannels
    // Purpose:    Gets the number of channels in this color model.
    // Parameters: None.
    // Returns:    The number of channels.
    virtual std::size_t
    getNumChannels() const = 0;

    // Function:   getChannelMax
    // Purpose:    Gets the maximum representable value for a color channel in the model.
    // Parameters: channelNum - The channel to get the maximum value for.
    // Returns:    The maximum value as a floating point number.
    virtual float
    getChannelMax(std::size_t channelNum) const = 0;

    // Function:   getChannelMin
    // Purpose:    Gets the minimum representable value for a color channel in the model.
    // Parameters: channelNum - The channel to get the maximum value for.
    // Returns:    The minimum value as a floating point number.
    virtual float
    getChannelMin(std::size_t channelNum) const = 0;

    // Function:   convertToPixel
    // Purpose:    Converts a set of numeric inputs to a pixel of the given data type.
    // Parameters: values - The channel values as floats in the range from getChannelMin() to
    //                      getChannelMax(). Must have getNumChannels() elements.
    // Returns:    The newly-minted pixel.
    virtual PixelDataT
    convertToPixel(float *values) const = 0;

    // Function:   convertPixelTo
    // Purpose:    Converts a pixel to a set of floating-point outputs.
    // Parameters: px - The pixel to convert.
    //             values - The array of channel values to receive the result. Must have
    //                      at least getNumChannels() elements.
    // Returns:    None.
    virtual void
    convertPixelTo(PixelDataT px,
                   float *values
                  ) const = 0;
  };
}

#endif
