#ifndef SDF_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_LAYER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_LAYER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Layer.hpp
 * PURPOSE: Defines the Layer class.
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

#include <SDF/ModelLayer/Math/Coord.hpp>
#include <SDF/ModelLayer/Math/Rect.hpp>

#include <SDF/ModelLayer/Services/AbstractDomain/IImageDataVisitor.hpp>

#include <cstddef>

namespace SDF::ModelLayer::DomainObjects::Image::Gil {
  // Class:      Layer
  // Purpose:    Defines a single image layer.
  // Parameters: GilImageType - The type for a whole image raster.
  //             GilRegionType - The type of a raster region.
  //             GilPixelType - The type of individual pixels. All three of these must agree.
  template<class GilImageType, class GilRegionType, class GilPixelType>
  class Layer {
  public:
    // Function:   Layer
    // Purpose:    Construct a layer of the given size.
    // Parameters: width - The width of the layer.
    //             height - The height of the layer.
    Layer(std::size_t width, std::size_t height);

    // Function:   getWidth
    // Purpose:    Get the width of the layer in pixels.
    // Parameters: None.
    // Returns:    The width of the layer, in pixels.
    std::size_t
    getWidth() const;

    // Function:   getHeight
    // Purpose:    Get the height of the layer in pixels.
    // Parameters: None.
    // Returns:    The height of the layer, in pixels.
    std::size_t
    getHeight() const;

    // Function:   acceptLayerDataVisitor
    // Purpose:    Accept a visitor into the implementation data of the layer.
    // Parameters: rect - The rectangle of the region to visit.
    //             visitor - The visitor to use.
    // Returns:    None.
    void
    acceptLayerDataVisitor(Math::Rect<std::size_t> rect,
                           Services::AbstractDomain::IImageDataVisitor &visitor
                          );
  private:
    GilImageType m_layerPixelData;
  };
}

#include "SDF/ModelLayer/DomainObjects/Image/Gil/Layer.tpp"

#endif
