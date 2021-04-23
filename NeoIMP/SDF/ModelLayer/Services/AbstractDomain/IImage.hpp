#ifndef SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IIMAGE_HPP
#define SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IIMAGE_HPP

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

#include <SDF/ModelLayer/Services/AbstractDomain/IDomainObject.hpp>

#include <SDF/ModelLayer/Math/Rect.hpp>

#include <cstddef>

namespace SDF::ModelLayer::Services::AbstractDomain {
  class IImageDataVisitor;

  // Class:      IImage
  // Purpose:    Defines the interface for an image document.
  // Parameters: None.
  class IImage : public IDomainObject<IImage> {
  public:
    virtual ~IImage() = default;

    // Function:   getWidth
    // Purpose:    Get the width of the image in pixels.
    // Parameters: None.
    // Returns:    The width.
    virtual std::size_t
    getWidth() const = 0;

    // Function:   getHeight
    // Purpose:    Get the height of the image in pixels.
    // Parameters: None.
    // Returns:    The height.
    virtual std::size_t
    getHeight() const = 0;

    // Function:   getNumLayers
    // Purpose:    Gets the number of layers in this image.
    // Parameters: None.
    // Returns:    The number of layers.
    virtual std::size_t
    getNumLayers() const = 0;

    // Function:   addLayerBefore
    // Purpose:    Adds a new layer to the image.
    // Parameters: pos - The position in the layer stack to add the new layer before (0 is the bottom layer). This
    //                   ranges from 0 to the number of image layers.
    //             width - The width of the layer to add, in pixels.
    //             height - The height of the layer to add, in pixels.
    // Returns:    None.
    virtual void
    addLayerBefore(std::size_t pos,
                   std::size_t width,
                   std::size_t height
                  ) = 0;

    // Function:   removeLayer
    // Purpose:    Removes a layer from the image.
    // Parameters: pos - The position of the layer to remove.
    // Returns:    None.
    virtual void
    removeLayer(std::size_t pos) = 0;

    // Function:   getRawLayerWidth
    // Purpose:    Get the untransformed width of a layer in pixels.
    // Parameters: layerNum - the layer number of the layer.
    // Returns:    None.
    virtual std::size_t
    getRawLayerWidth(std::size_t layerNum) const = 0;

    // Function:   getRawLayerHeight
    // Purpose:    Get the untransformed height of a layer in pixels.
    // Parameters: layerNum - the layer number of the layer.
    // Returns:    None.
    virtual std::size_t
    getRawLayerHeight(std::size_t layerNum) const = 0;

    // Function:   acceptImageDataVisitor
    // Purpose:    Accepts a visitor to the underlying implementation data of the image. This is not abstract but is
    //             very efficient, and recommended for use in implementing core, time-consuming graphics processing
    //             algorithms.
    // Parameters: layerNum - The layer to visit.
    //             rect - The region to visit.
    //             visitor - The visitor to pass to the layer.
    // Returns:    None.
    virtual void
    acceptImageDataVisitor(std::size_t layerNum,
                           Math::Rect<std::size_t> rect,
                           IImageDataVisitor &visitor
                          ) = 0;
  };
}

#endif
