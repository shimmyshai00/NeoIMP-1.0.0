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
  // Class:      IColorModel
  // Purpose:    Defines a color model. A color model describes the structure of the data used to
  //             represent the color of a pixel. It does *not* describe directly how that data maps
  //             to "physical" colors (to the extent one can call colors "physical" phenomena). This
  //             is obtained when a color model is combined with a  suitable mapping, producing a
  //             color space. When image data (typically RGB) is "blitted" to a monitor "directly",
  //             the resulting colors depend on the characteristics of that monitor - that is, the
  //             monitor itself constitutes an implicit color space. Minding this fact can allow us
  //             to adjust the image to create consistency across a variety of display media.
  // Parameters: PixelDataT - The data type of pixel the color model produces.
  class IColorModel {
  public:
    virtual ~IColorModel() = default;

    // Function:   getNumChannels
    // Purpose:    Gets the number of channels this color model has.
    // Parameters: None.
    // Returns:    The number of channels in a single pixel.
    virtual std::size_t
    getNumChannels() const = 0;

    // Function:   getChannelBitDepth
    // Purpose:    Obtains the bit depth of a single channel.
    // Parameters: channelNum - The channel to get the bit depth of.
    // Returns:    The bit depth of one channel.
    virtual std::size_t
    getChannelBitDepth(std::size_t channelNum) const = 0;

    // Function:   getChannelMinValue
    // Purpose:    Gets the minimum value of each channel.
    // Parameters: channelNum - The channel to get the minimum value of.
    // Returns:    The minimum value allowed in this channel.
    virtual float
    getChannelMinValue(std::size_t channelNum) const = 0;

    // Function:   getChannelMaxValue
    // Purpose:    Gets the maximum value of each channel.
    // Parameters: channelNum - The channel to get the minimum value of.
    // Returns:    The maximum value allowed in this channel.
    virtual float
    getChannelMaxValue(std::size_t channelNum) const = 0;
  };

  // Exposes the pixel implementation.
  template<class PixelDataT>
  class IColorModelImpl : public IColorModel {
  public:
    virtual ~IColorModelImpl() = default;

    // Function:   encode
    // Purpose:    Encode the given data as color values.
    // Parameters: values - The channel values (should be getNumChannels() worth) to use to
    //                      generate the pixel (must be in the ranges given).
    // Returns:    The generated pixel.
    virtual PixelDataT
    encode(float *values) const = 0;

    // Function:   decode
    // Purpose:    Decodes the given pixel into color values.
    // Parameters: pixel - The pixel data input.
    //             values - The array to receive the values.
    // Returns:    None.
    virtual void
    decode(PixelDataT pixel,
           float *values
          ) const = 0;
  };
}

#endif
