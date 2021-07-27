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

#include "../../../AbstractData/Entity/ImageEntity.hpp"
#include "../../../Metrics/ResolutionQuantity.hpp"
#include "../../../Metrics/LengthUnit.hpp"
#include "../../../Metrics/ResolutionUnit.hpp"
#include "../../../Math/Coord.hpp"
#include "../IImage.hpp"
#include "../IImageDataVisitor.hpp"
#include "Layer.hpp"
#include "Defs.hpp"

#include <cstddef>
#include <string>
#include <memory>
#include <map>
#include <vector>

namespace SDF::ModelLayer::DomainObjects::Image::Gil {
  // Class:   Image
  // Purpose: Implements an image structure using Boost::GIL as the background library. This allows for using a number
  //          of common, off-the-shelf algorithms where appropriate, including persistence algorithms for common
  //          formats like PNG.
  template<class GilImageType, class GilRegionType, class GilPixelType>
  class Image : public IImage {
  public:
    // Function:   Image
    // Purpose:    Construct a new image to the specified parameters.
    // Parameters: id - The ID code of this image.
    //             name - The name of this image.
    //             widthPx - The width of the image in pixels.
    //             heightPx - The height of the image in pixels.
    //             resolution - The resolution of the image.
    //             resolutionUnit - The unit of measurement the resolution is given in.
    Image(int id,
          std::string name,
          std::size_t widthPx,
          std::size_t heightPx,
          float resolution,
          Metrics::ResolutionUnit resolutionUnit
         );

    // Function:   Image
    // Purpose:    Construct a new image to the specified parameters.
    // Parameters: id - The ID code of this image.
    //             name - The name of this image.
    //             width - The width of the image.
    //             widthUnit - The unit of measurement this width is given in.
    //             height - The height of the image.
    //             heightUnit - The unit of measurement this height is given in.
    //             resolution - The resolution of the image.
    //             resolutionUnit - The unit of measurement the resolution is given in.
    Image(int id,
          std::string name,
          float width,
          Metrics::LengthUnit widthUnit,
          float height,
          Metrics::LengthUnit heightUnit,
          float resolution,
          Metrics::ResolutionUnit resolutionUnit
         );

    // Function:   Image
    // Purpose:    Construct a new image from a GIL buffer.
    // Parameters: id - The ID code of this image.
    //             name - The name of this image.
    //             gilImage - The GIL image buffer to construct from.
    //             resolution - The resolution of the image.
    //             resolutionUnit - The unit of measurement the resolution is given in.
    Image(int id,
          std::string name,
          const GilImageType &gilImage,
          float resolution,
          Metrics::ResolutionUnit resolutionUnit
         );

    int
    getId() const;

    std::unique_ptr<AbstractData::Entity::ImageEntity>
    createEntity() const;

    std::string
    getName() const;

    std::size_t
    getWidthPx() const;

    float
    getWidthPhys(Metrics::LengthUnit unit) const;

    std::size_t
    getHeightPx() const;

    float
    getHeightPhys(Metrics::LengthUnit unit) const;

    float
    getResolution(Metrics::ResolutionUnit unit) const;

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
    getRawLayerWidthPx(std::size_t layerNum) const;

    std::size_t
    getRawLayerHeightPx(std::size_t layerNum) const;

    void
    acceptImageDataVisitor(std::size_t layerNum,
                           Math::Rect<std::size_t> rect,
                           IImageDataVisitor &visitor
                          );
  private:
    int m_id;
    std::string m_name;
    std::size_t m_widthPx, m_heightPx;
    Metrics::resolution_quantity m_resolution;

    Math::Coord<float> m_viewCenter;
    float m_viewMagnification;

    std::vector<std::unique_ptr<Layer<GilImageType, GilRegionType, GilPixelType>>> m_layerStack;
  };
}

#include "Image.tpp"

#endif
