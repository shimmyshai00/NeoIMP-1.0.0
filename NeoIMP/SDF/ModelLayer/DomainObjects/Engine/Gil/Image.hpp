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

#include "../IImage.hpp"
#include "../Uid.hpp"
#include "Layer.hpp"

#include <cstddef>
#include <string>
#include <vector>
#include <memory>

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  // Class:      Image
  // Purpose:    Defines a Boost.GIL-based image.
  // Parameters: GilImageT - The Boost.GIL image type underlying this image. Must implement GIL's
  //                         RandomAccess2DImageConcept.
  template<class GilImageT>
  class Image : public IImage {
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

    Uid
    getUid() const;

    IImage &
    getObject();

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
  private:
    Uid m_uid;

    std::string m_name;
    std::string m_fileSpec;

    std::size_t m_widthPx;
    std::size_t m_heightPx;
    float m_resolutionPpi;

    std::vector<std::unique_ptr<Layer<GilImageT>>> m_layers;
  };
}

#include "Image.tpp"

#endif
