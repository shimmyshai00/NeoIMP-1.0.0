#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_ICOLOR_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_ICOLOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IColor.hpp
 * PURPOSE: Defines the IColor interface.
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

#include "ColorFormat.hpp"

#include <cstddef>

namespace SDF::Editor::UILayer::AbstractModel::Defs::Color {
  // Class:      IColor
  // Purpose:    Defines a generic interface for representing color values. This interface is not
  //             high-performance, so should not be used for moving large amounts of data into and
  //             out of the model.
  // Parameters: FormatEnumT - The enumeration of the type of color formats allowed.
  template<class FormatEnumT>
  class IColor {
  public:
    virtual ~IColor() = default;

    // Function:   getColorFormat
    // Purpose:    Gets the color format of this color.
    // Parameters: None.
    // Returns:    The enumeration value of the color format.
    virtual FormatEnumT
    getColorFormat() const = 0;

    // Function:   getNumChannels
    // Purpose:    Gets the number of channels in the color.
    // Parameters: None.
    // Returns:    The number of channels in this color.
    virtual std::size_t
    getNumChannels() const = 0;

    // Function:   getChannelMin
    // Purpose:    Gets the minimum value of the indicated channel.
    // Parameters: channelIdx - The index of the channel to get the minimum for.
    // Returns:    The channel's minimum value.
    virtual int
    getChannelMin(std::size_t a_channelIdx) const = 0;

    // Function:   getChannelMax
    // Purpose:    Gets the maximum value of the indicated channel.
    // Parameters: channelIdx - The index of the channel to get the maximum for.
    // Returns:    The channel's maximum value.
    virtual int
    getChannelMax(std::size_t a_channelIdx) const = 0;

    // Function:   getValue
    // Purpose:    Gets the value of a given channel.
    // Parameters: channelIdx - The index of the channel to get the value of.
    // Returns:    The value of this channel.
    virtual int
    getValue(std::size_t a_channelIdx) const = 0;

    // Function:   getValueF
    // Purpose:    Gets the value of a given channel as a float with a reference interval in [0..1]
    //             (may exceed this interval in some cases with special interpretations).
    // Parameters: channelIdx - The index of the channel to get the value of.
    // Returns:    The value of this channel.
    virtual float
    getValueF(std::size_t a_channelIdx) const = 0;

    // Function:   setValue
    // Purpose:    Sets the value of a given channel.
    // Parameters: channelIdx - The index of the channel to set the value of.
    //             value - The value to set it to.
    // Returns:    None.
    virtual void
    setValue(std::size_t a_channelIdx, int a_value) = 0;

    // Function:   setValueF
    // Purpose:    Sets the value of a given channel using floating point.
    // Parameters: channelIdx - The index of the channel to set the value of.
    //             value - The value to set it to.
    // Returns:    None.
    virtual void
    setValueF(std::size_t a_channelIdx, float a_value) = 0;
  };
}

#endif
