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

#include "EColorModel.hpp"
#include "EBitDepth.hpp"

#include <cstddef>

namespace SDF::Editor::UILayer::AbstractModel::Defs::Color {
  // Class:      IColor
  // Purpose:    Provides an interface for moving color data between the UI and model layers
  //             seamlessly. Note that this interface is not high-performance; it should not be used
  //             to move large amounts of data like renderings.
  // Parameters: None.
  class IColor {
  public:
    virtual ~IColor() = default;

    // Function:   getColorModel
    // Purpose:    Gets the color model used by this color.
    // Parameters: None.
    // Returns:    The used color model.
    virtual EColorModel
    getColorModel() const = 0;

    // Function:   getBitDepth
    // Purpose:    Gets the bit depth used by this color.
    // Parameters: None.
    // Returns:    The used bit depth.
    virtual EBitDepth
    getBitDepth() const = 0;

    // Function:   getNumChannels
    // Purpose:    Gets the number of color channels in this color.
    // Parameters: None.
    // Returns:    The number of color channels.
    virtual std::size_t
    getNumChannels() const = 0;

    // Function:   getChannelMin
    // Purpose:    Gets the minimum value of a color channel.
    // Parameters: channel - The channel to get the minimum value for.
    // Returns:    The minimum value for this channel.
    virtual float
    getChannelMin(std::size_t channel) const = 0;

    // Function:   getChannelMax
    // Purpose:    Gets the maximum value of a color channel.
    // Parameters: channel - The channel to get the minimum value for.
    // Returns:    The maximum value for this channel.
    virtual float
    getChannelMax(std::size_t channel) const = 0;

    // Function:   get
    // Purpose:    Gets the value of a color channel.
    // Parameters: channel - The channel to get the value of.
    // Returns:    The stored value of this channel.
    virtual float
    get(std::size_t channel) const = 0;

    // Function:   set
    // Purpose:    Sets the value of a color channel.
    // Parameters: channel - The channel to set the value of.
    //             val - The value to set. If outside the range
    //                   [getChannelMin(...), getChannelMax(...)], it will be clamped.
    // Returns:    None.
    virtual void
    set(std::size_t channel, float val) = 0;
  };
}

#endif
