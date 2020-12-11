/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageRenderingService.cpp
 * PURPOSE: The UI image rendering service implementation.
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

#include <ImageRenderingService.hpp>

#include <MemoryLayer/IImageRepository.hpp>

#include <DomainObjects/Image/AbstractImage.hpp>
#include <DomainObjects/Image/ImageDataVisitor.hpp>
#include <DomainObjects/Algorithms/DisplayGenerator/Visitor.hpp>
#include <DomainObjects/Math/Rect.hpp>

#include <ModelLayer/Exception/Exceptions.hpp>

namespace SDF::Impl::ModelLayer::Services::Impl {
  ImageRenderingService::ImageRenderingService(MemoryLayer::IImageRepository *imageRepository)
    : m_imageRepository(imageRepository),
      m_visitor(std::make_unique<DomainObjects::Algorithms::DisplayGenerator::Visitor>())
  {}

  const std::vector<unsigned int> &ImageRenderingService::renderImageRegion(
    Handle handle,
    int x1, int y1, int x2, int y2
  ) {
    DomainObjects::Image::AbstractImage *image(m_imageRepository->access(handle));

    // Visit the desired region.
    if((x1 < 0) || (y1 < 0) || (x2 >= image->getImageWidth()) || (y2 >= image->getImageHeight())) {
      throw ModelLayer::Exception::RectangleOutOfBoundsException(x1, y1, x2, y2);
    }

    image->acceptLayerPixelVisitor(0, DomainObjects::Math::Rect<std::size_t>(x1, y1, x2, y2), m_visitor.get());
    return m_visitor->accessRecoveredData();
  }
}
