#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_ICOLORSPACE_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_ICOLORSPACE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IColorSpace.hpp
 * PURPOSE: Defines the IColorSpace interface.
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

#include "IColorModel.hpp"

#include <array>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine {
  // Class:      IColorSpace
  // Purpose:    Defines an interface for color spaces. A color space is, theoretically, a mapping
  //             from color data, represented in the format described by a color model, to actual
  //             human color perceptions, represented in terms of a fundamental space built on
  //             standardized psycho-physical measurements for some canonical "average" human
  //             observer. By combining color spaces representing the perceptions evoked by various
  //             media such as different types of monitors, printers, and the like, it is possible
  //             to prescribe how an image should be displayed so as to convey something which is as
  //             close as possible to what its creator intends.
  // Parameters: PixelDataT - The type of pixel data the color space maps.
  //             FundamentalTraitsT - The traits type describing the fundamental color space.
  template<class PixelDataT, class FundamentalTraitsT>
  class IColorSpace {
  public:
    virtual ~IColorSpace() = default;

    // Function:   getColorModel
    // Purpose:    Gets the underlying color model.
    // Parameters: None.
    // Returns:    The color model object.
    virtual const IColorModel<PixelDataT, FamilyT> &
    getColorModel() const = 0;

    // Function:   pixelToFundamental
    // Purpose:    Converts a pixel to the fundamental space.
    // Parameters: pixel - The pixel to convert.
    // Returns:    An array of values in the fundamental space representing the pixel.
    virtual std::array<float, FundamentalTraitsT::num_channels>
    pixelToFundamental(const PixelDataT &pixel) const = 0;

    // Function:   fundamentalToPixel
    // Purpose:    Performs the reverse mapping of the above.
    // Parameters: fs - The fundamental space pixel values.
    // Returns:    The resulting ordinary pixel.
    virtual PixelDataT
    fundamentalToPixel(const std::array<float, FundamentalTraitsT::num_channels> &fs) const = 0;
  };
}

#endif
