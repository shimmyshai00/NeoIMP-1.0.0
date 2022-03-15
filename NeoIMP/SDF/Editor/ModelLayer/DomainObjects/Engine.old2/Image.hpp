#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_IMAGE_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_IMAGE_HPP

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
#include "ForegroundLayer.hpp"

#include <cstddef>
#include <string>
#include <memory>
#include <vector>

namespace SDF::ModelLayer::DomainObjects::Engine {
  // Class:      Image
  // Purpose:    Defines an image object. This is actually a fully-instantiatable class template.
  //             The idea is to use a composition-favoring system allowing for extension and
  //             modification of layers as well as the easy addition of new layer types.
  // Parameters: ImplSpecT - A traits struct defining the implementation parameters for this image.
  template<class ImplSpecT>
  class Image {
  public:
    // Function:   Image
    // Purpose:    Constructs a new image to the specified parameters.
    // Parameters: name - The name of the image.
    //             fileSpec - The image file spec.
    //             widthPx - The width of the image in pixels.
    //             heightPx - The height of the image in pixels.
    //             resolutionPpi - The resolution of the image in PPI.
    //             backgroundLayer - The initial background layer.
    Image(std::string name,
          std::string fileSpec,
          ImageMeasure widthPx,
          ImageMeasure heightPx,
          float resolutionPpi,
          std::unique_ptr<typename ImplSpecT::background_layer_t> backgroundLayer
         );

    // Function:   getName
    // Purpose:    Gets the name of the image.
    // Parameters: None.
    // Returns:    The image name.
    std::string
    getName() const;

    // Function:   getFileSpec
    // Purpose:    Gets the file spec of the image.
    // Parameters: None.
    // Returns:    The image file spec.
    std::string
    getFileSpec() const;

    // Function:   getWidthPx
    // Purpose:    Gets the width of the image in pixels.
    // Parameters: None.
    // Returns:    The width of the image in pixels.
    ImageMeasure
    getWidthPx() const;

    // Function:   getHeightPx
    // Purpose:    Gets the height of the image in pixels.
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

    // Function:   getBackgroundLayer
    // Purpose:    Gets the non-convertible background layer of this image.
    // Parameters: None.
    // Returns:    A reference to the background layer.
    typename ImplSpecT::background_layer_t &
    getBackgroundLayer();

    const typename ImplSpecT::background_layer_t &
    getBackgroundLayer() const;

    // Function:   getLayerType
    // Purpose:    Gets the type of a given image layer.
    // Parameters: layerNum - The layer number to get.
    // Returns:    The type of the requested layer.
    ELayerType
    getLayerType(std::size_t layerNum) const;

    // Function:   getLayer
    // Purpose:    Access a foreground layer of this image.
    // Parameters: layerNum - The layer number to get. 0 is the background layer so will not work.
    // Returns:    The requested layer.
    ILayer<ImplSpecT> &
    getLayer(std::size_t layerNum);

    const ILayer<ImplSpecT> &
    getLayer(std::size_t layerNum) const;

    // Function:   getLayerAs
    // Purpose:    Access a foreground layer of this image as its type.
    // Parameters: layerNum - The layer number to get. 0 is the background layer so will not work.
    // Returns:    The requested layer.
    template<class U>
    U &
    getLayerAs(std::size_t layerNum);

    template<class U>
    const U &
    getLayerAs(std::size_t layerNum) const;
  private:
    std::string m_name;
    std::string m_fileSpec;

    ImageMeasure m_widthPx;
    ImageMeasure m_heightPx;
    float m_resolutionPpi;

    std::unique_ptr<ImplSpecT::background_layer_t> m_backgroundLayer;
    std::vector<std::unique_ptr<ILayer<ImplSpecT>>> m_layers;
  };
}

#include "Image.tpp"

#endif
