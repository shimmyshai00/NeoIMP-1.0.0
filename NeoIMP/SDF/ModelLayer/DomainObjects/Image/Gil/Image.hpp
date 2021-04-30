#ifndef SDF_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_IMAGE_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_IMAGE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Image.hpp
 * PURPOSE: Defines the Image class.
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

#include <SDF/ModelLayer/Services/AbstractDomain/IImage.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/IImageDataVisitor.hpp>
#include <SDF/ModelLayer/DomainObjects/Image/Gil/Layer.hpp>

#include <SDF/ModelLayer/Math/Coord.hpp>

#include <memory>

namespace SDF::ModelLayer::DomainObjects::Image::Gil {
  // Class:   Image
  // Purpose: Implements an image structure using Boost::GIL as the background library. This allows for using a number
  //          of common, off-the-shelf algorithms where appropriate, including persistence algorithms for common
  //          formats like PNG.
  template<class GilImageType, class GilRegionType, class GilPixelType>
  class Image : public Services::AbstractDomain::IImage {
  public:
    // Function:   Image
    // Purpose:    Construct a new image to the specified parameters.
    // Parameters: id - The ID code of this image.
    //             name - The name of this image.
    //             width - The width of the image in pixels.
    //             height - The height of the image in pixels.
    Image(int id,
          std::string name,
          std::size_t width,
          std::size_t height
         );

    // Function:   Image
    // Purpose:    Construct a new image from a GIL buffer.
    // Parameters: id - The ID code of this image.
    //             name - The name of this image.
    //             gilImage - The GIL image buffer to construct from.
    Image(int id,
          std::string name,
          const GilImageType &gilImage
         );

    int
    getId() const;

    std::string
    getName() const;

    std::size_t
    getWidth() const;

    std::size_t
    getHeight() const;

    std::size_t
    getNumLayers() const;

    Math::Coord<float>
    getViewCenter() const;

    float
    getViewMagnification() const;

    void
    setName(std::string name);

    void
    setViewCenter(Math::Coord<float> viewCenter);

    void
    setViewMagnification(float viewMagnification);

    void
    addLayerBefore(std::size_t pos,
                   std::size_t width,
                   std::size_t height
                  );

    void
    removeLayer(std::size_t pos);

    std::size_t
    getRawLayerWidth(std::size_t layerNum) const;

    std::size_t
    getRawLayerHeight(std::size_t layerNum) const;

    void
    acceptImageDataVisitor(std::size_t layerNum,
                           Math::Rect<std::size_t> rect,
                           Services::AbstractDomain::IImageDataVisitor &visitor
                          );
  private:
    int m_id;
    std::string m_name;
    std::size_t m_width, m_height;

    Math::Coord<float> m_viewCenter;
    float m_viewMagnification;

    std::vector<std::unique_ptr<Layer<GilImageType, GilRegionType, GilPixelType>>> m_layerStack;
  };
}

#include "SDF/ModelLayer/DomainObjects/Image/Gil/Image.tpp"

#endif
