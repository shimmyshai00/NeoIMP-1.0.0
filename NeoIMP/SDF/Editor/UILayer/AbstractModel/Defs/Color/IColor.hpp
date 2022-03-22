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

#include <cstddef>

namespace SDF::Editor::UILayer::AbstractModel::Defs::Color {
  // Class:      IColor
  // Purpose:    Defines a uniform interface for color value objects at the UI level. This does not
  //             provide high efficiency and should not be used to move large volumes of data
  //             between layers.
  // Parameters: None.
  class IColor {
  public:
    virtual ~IColor() = default;

    // Function:   getColorModel
    // Purpose:    Gets the represented color model in this color.
    // Parameters: None.
    // Returns:    The color model.
    virtual EColorModel
    getColorModel() const = 0;

    // Function:   getNumChannels
    // Purpose:    Gets the number of available color channels.
    // Parameters: None.
    // Returns:    The number of channels in this color value.
    virtual std::size_t
    getNumChannels() const = 0;

    // Function:   getChannelMin
    // Purpose:    Gets the minimum value of a color channel.
    // Parameters: idx - The index (0...getNumChannels()-1) of the channel to get.
    // Returns:    The minimum value (usually 0).
    virtual float
    getChannelMin(std::size_t idx) const = 0;

    // Function:   getChannelMax
    // Purpose:    Gets the maximum value of a color channel.
    // Parameters: idx - The index of the channel to get.
    // Returns:    The maximum value.
    virtual float
    getChannelMax(std::size_t idx) const = 0;

    // Function:   get
    // Purpose:    Gets the stored value of a color channel.
    // Parameters: idx - The index to get.
    // Returns:    The value of this channel.
    virtual float
    get(std::size_t idx) const = 0;

    // Function:   set
    // Purpose:    Sets the stored value of a color channel.
    // Parameters: idx - The index to get.
    //             val - The value to set.
    // Returns:    None.
    virtual void
    set(std::size_t idx, float val) = 0;
  };
}

#endif
