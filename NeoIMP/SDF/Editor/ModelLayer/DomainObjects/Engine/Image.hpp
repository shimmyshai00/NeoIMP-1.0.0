#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_IMAGE_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_IMAGE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Image.hpp
 * PURPOSE: Defines the Image template.
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

#include "Dimensions.hpp"
#include "Layer.hpp"

#include <cstddef>
#include <string>
#include <memory>
#include <vector>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine {
  // Class:      Image
  // Purpose:    Defines an image object. This is actually a fully-instantiatable class template.
  //             The engine uses a composition-favoring system that builds images up from components
  //             (sort of like the "entity-component-system" architecture common in games, but with
  //             a little less freedom). The image object defines some basic characteristics and
  //             provides the layer stack, which is common to all engine implementations.
  // Parameters: ImplSpecT - A traits struct defining the implementation parameters for this image.
  template<class ImplSpecT>
  class Image {
  public:
    // Function:   Image
    // Purpose:    Constructs a new image to the specified parameters.
    // Parameters: name - The name of the image.
    //             resolutionPpi - The resolution of the image.
    Image(std::string name, float resolutionPpi);

    // Function:   getName
    // Purpose:    Gets the name of the image.
    // Parameters: None.
    // Returns:    The image name.
    std::string
    getName() const;

    // Function:   getWidthPx
    // Purpose:    Gets the width of the image in pixels. This width is set by that of the image's
    //             background layer.
    // Parameters: None.
    // Returns:    The width of the image in pixels.
    ImageMeasure
    getWidthPx() const;

    // Function:   getHeightPx
    // Purpose:    Gets the height of the image in pixels. This height is set by that of the image's
    //             background layer.
    // Parameters: None.
    // Returns:    The height of the image in pixels.
    ImageMeasure
    getHeightPx() const;

    // Function:   getRect
    // Purpose:    Get the image's total bounding rectangle.
    // Parameters: None.
    // Returns:    The total bounding rectangle.
    ImageRect
    getRect() const;

    // Function:   getResolutionPpi
    // Purpose:    Gets the resolution of the image in PPI.
    // Parameters: None.
    // Returns:    The resolution of the image in PPI.
    float
    getResolutionPpi() const;

    // Function:   getNumLayers
    // Purpose:    Gets the number of image layers.
    // Parameters: None.
    // Returns:    The number of layers in the image.
    std::size_t
    getNumLayers() const;

    // Function:   getLayer
    // Purpose:    Access a layer of this image.
    // Parameters: layerNum - The layer number to get.
    // Returns:    The requested layer.
    Layer<ImplSpecT> &
    getLayer(std::size_t layerNum);

    const Layer<ImplSpecT> &
    getLayer(std::size_t layerNum) const;

    // Function:   setName
    // Purpose:    Sets the name of the image.
    // Parameters: name - The new name to set.
    // Returns:    None.
    void
    setName(std::string name);

    // Function:   setResolutionPpi
    // Purpose:    Sets the image resolution (the conversion factor between pixels and physical
    //             units).
    // Parameters: resolutionPpi - The new resolution in PPI.
    // Returns:    None.
    void
    setResolutionPpi(float resolutionPpi);

    // Function:   addLayer
    // Purpose:    Injects a new layer into the image.
    // Parameters: layer - The layer to insert.
    // Returns:    None.
    void
    addLayer(std::unique_ptr<Layer<ImplSpecT>> layer);
  private:
    std::string m_name;
    float m_resolutionPpi;

    std::vector<std::unique_ptr<Layer<ImplSpecT>>> m_layers;
  };
}

#include "Image.tpp"

#endif
