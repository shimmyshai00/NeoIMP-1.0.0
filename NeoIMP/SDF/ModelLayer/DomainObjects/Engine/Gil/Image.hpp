#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMAGE_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_GIL_IMAGE_HPP

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

#include "../../../AbstractData/Entity/Gil/Image.hpp"
#include "../IImage.hpp"
#include "Layer.hpp"

#include <cstddef>
#include <string>
#include <vector>
#include <memory>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  // Class:      Image
  // Purpose:    Defines a Boost.GIL-based image.
  // Parameters: GilImageT - The Boost.GIL image type underlying this image. Must implement GIL's
  //                         RandomAccess2DImageConcept. Note that boost::gil::any_image_t is NOT allowed for use here,
  //                         since it does not implement this concept fully. To get a variant-like type for images, use
  //                         the AnyImage class instead, which properly handles this case.
  template<class ... GilImageTs>
  class AnyImage;

  template<class GilImageT>
  class Image : public IImage<Image<GilImageT>, AbstractData::Entity::Gil::Image<GilImageT>> {
  public:
    // Function:   Image
    // Purpose:    Construct a new image of the given size. The new image will have a single background layer also of
    //             the size given.
    // Parameters: name - The name of the image.
    //             fileSpec - The file spec to save the image to (may be empty).
    //             widthPx - The width of the image in pixels.
    //             heightPx - The height of the image in pixels.
    //             resolutionPpi - The resolution of the image in PPI.
    Image(std::string name,
          std::string fileSpec,
          std::size_t widthPx,
          std::size_t heightPx,
          float resolutionPpi
         );

    std::shared_ptr<AbstractData::Entity::Gil::Image<GilImageT>>
    getEntity() const;

    std::string
    getName() const;

    std::string
    getFileSpec() const;

    std::size_t
    getWidthPx() const;

    std::size_t
    getHeightPx() const;

    float
    getResolutionPpi() const;

    UILayer::AbstractModel::Defs::EColorModel
    getColorModel() const;

    std::size_t
    getNumChannels() const;

    UILayer::AbstractModel::Defs::EBitDepth
    getChannelBitDepth() const;

    std::size_t
    getNumLayers() const;

    std::size_t
    getLayerWidthPx(std::size_t which) const;

    std::size_t
    getLayerHeightPx(std::size_t which) const;

    // Function:   getLayerPixelAt
    // Purpose:    Gets a pixel at a given coordinate from a layer.
    // Parameters: layerNum - The layer number to get the pixel from.
    //             pos - The position to get the pixel from.
    //             x - The x-coordinate to get the pixel from.
    //             y - The y-coordinate to get the pixel from.
    typename GilImageT::view_t::value_type
    getLayerPixelAt(std::size_t layerNum,
                    Math::Coord<std::size_t> pos
                   ) const;

    typename GilImageT::view_t::value_type
    getLayerPixelAt(std::size_t layerNum,
                    std::size_t x,
                    std::size_t y
                   ) const;

    // Function:   getLayerView
    // Purpose:    Gets a Boost.GIL view of a region of an image layer.
    // Parameters: layerNum - The layer number to get the pixel from.
    //             rect - The rectangle to get the view for.
    //             x1 - The upper-left x-coordinate of the rectangle.
    //             y1 - The upper-left y-coordinate of the rectangle.
    //             x2 - The lower-right x-coordinate of the rectangle.
    //             y2 - The lower-right y-coordinate of the rectangle.
    typename GilImageT::view_t
    getLayerView(std::size_t layerNum);

    typename GilImageT::const_view_t
    getLayerView(std::size_t layerNum) const;

    typename GilImageT::view_t
    getLayerView(std::size_t layerNum,
                 Math::Rect<std::size_t> rect
                );

    typename GilImageT::const_view_t
    getLayerView(std::size_t layerNum,
                 Math::Rect<std::size_t> rect
                ) const;

    typename GilImageT::view_t
    getLayerView(std::size_t layerNum,
                 std::size_t x1,
                 std::size_t y1,
                 std::size_t x2,
                 std::size_t y2
                );

    typename GilImageT::const_view_t
    getLayerView(std::size_t layerNum,
                 std::size_t x1,
                 std::size_t y1,
                 std::size_t x2,
                 std::size_t y2
                ) const;
  private:
    template<class ... GilImageTs>
    friend class AnyImage;

    std::string m_name;
    std::string m_fileSpec;

    std::size_t m_widthPx;
    std::size_t m_heightPx;
    float m_resolutionPpi;

    std::vector<Layer<GilImageT>> m_layers;
  };
}

#include "Image.tpp"

#endif
