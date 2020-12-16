/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    PNGRepository.hpp
 * PURPOSE: The PNG-format image repository implementation.
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

#include <PNGRepository.hpp>

#include <ModelLayer/Impl/DomainObjects/Image/AbstractImage.hpp>

#include <Algorithms/SaveAsPNGVisitor.hpp>
#include <DataLayer/Exceptions/Exceptions.hpp>

namespace SDF::Impl::DataLayer::Impl::Repositories {
  PNGRepository::PNGRepository() {}

  void PNGRepository::saveImage(std::string fileName, ModelLayer::Impl::DomainObjects::Image::AbstractImage &image) {
    if(image.getNumImageLayers() > 1) {
      throw DataLayer::Exceptions::MultilayerImageNotSupportedException("PNG");
    }

    Algorithms::SaveAsPNGVisitor visitor(fileName);
    image.acceptLayerPixelVisitor(0, image.getImageRect(), &visitor);
  }

  std::unique_ptr<ModelLayer::Impl::DomainObjects::Image::AbstractImage> PNGRepository::loadImage(
    std::string fileName
  ) {
    // TBA
    return std::unique_ptr<ModelLayer::Impl::DomainObjects::Image::AbstractImage>();
  }
}
