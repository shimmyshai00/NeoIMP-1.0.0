#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_IIMAGE_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_IIMAGE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IImage.hpp
 * PURPOSE: Defines the IImage interface.
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
#include "Dimensions.hpp"

#include <vector>
#include <string>
#include <cstddef>

namespace SDF::ModelLayer::DomainObjects::Engine {
  // Class:      IImage
  // Purpose:    Defines an interface for image documents.
  // Parameters: None.
  class IImage {
  public:
    virtual ~IImage() = default;

    // Function:   getName
    // Purpose:    Get the name of this image.
    // Parameters: None.
    // Returns:    The image name.
    virtual std::string
    getName() const = 0;

    // Function:   getFileSpec
    // Purpose:    Get the file spec of this image.
    // Parameters: None.
    // Returns:    The image file spec.
    virtual std::string
    getFileSpec() const = 0;

    // Function:   getWidthPx
    // Purpose:    Get the width of the image in pixels.
    // Parameters: None.
    // Returns:    The image width in pixels.
    virtual ImageMeasure
    getWidthPx() const = 0;

    // Function:   getHeightPx
    // Purpose:    Get the height of the image in pixels.
    // Parameters: None.
    // Returns:    The image height in pixels.
    virtual ImageMeasure
    getHeightPx() const = 0;

    // Function:   getResolutionPpi
    // Purpose:    Get the image resolution in PPI.
    // Parameters: None.
    // Returns:    The image resolution.
    virtual float
    getResolutionPpi() const = 0;

    // Function:   getImageTopology
    // Purpose:    Gets the topology of the image.
    // Parameters: None.
    // Returns:    The type of topology this image has.

    // Function:   getBkgColorModel
    // Purpose:    Get the background color model used by this image.
    // Parameters: None.
    // Returns:    The background color model used.
    virtual IColorModel &
    getBkgColorModel() const = 0;

    // Function:   getColorModel
    // Purpose:    Get the color model used by this image.
    // Parameters: None.
    // Returns:    The color model used.
    virtual IColorModel &
    getColorModel() const = 0;

    // Function:   getNumLayers
    // Purpose:    Gets the number of layers in the image.
    // Parameters: None.
    // Returns:    The number of image layers.
    virtual std::size_t
    getNumLayers() const = 0;

    // Function:   getLayerWidthPx
    // Purpose:    Gets the width of a layer in pixels.
    // Parameters: which - The layer to get the width of.
    // Returns:    The width of the layer in pixels.
    virtual ImageMeasure
    getLayerWidthPx(std::size_t which) const = 0;

    // Function:   getLayerHeightPx
    // Purpose:    Gets the height of a layer in pixels.
    // Parameters: height - The layer to get the width of.
    // Returns:    The height of the layer in pixels.
    virtual ImageMeasure
    getLayerHeightPx(std::size_t which) const = 0;

    // Function:   getLayerRect
    // Purpose:    Gets the rectangle inhabited by a given layer.
    // Parameters: which - The layer to get the rectangle of.
    // Returns:    The rectangle occupied by the layer.
    virtual ImageRect
    getLayerRect(std::size_t which) const = 0;
  };
}

#endif
