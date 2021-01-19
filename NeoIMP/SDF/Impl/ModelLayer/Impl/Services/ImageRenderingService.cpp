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

#include <DomainObjects/Image/AbstractImage.hpp>
#include <DomainObjects/Image/ImageDataVisitor.hpp>
#include <DomainObjects/Algorithms/Renderer/Visitor.hpp>
#include <DomainObjects/Math/Rect.hpp>

#include <AbstractMemory/Repositories/IImageRepository.hpp>
#include <DomainObjects/Image/AbstractImage.hpp>

#include <ModelLayer/Exceptions/Exceptions.hpp>
#include <MemoryLayer/Exceptions/Exceptions.hpp>

namespace SDF::Impl::ModelLayer::Impl::Services {
  ImageRenderingService::ImageRenderingService(AbstractMemory::Repositories::IImageRepository *imageRepository)
    : m_imageRepository(imageRepository),
      m_visitor(new DomainObjects::Algorithms::Renderer::Visitor)
  {}

  const unsigned char *
  ImageRenderingService::renderImageRegion(AppModelLayer::AbstractModel::Handle handle,
                                           int x1, int y1, int x2, int y2
                                          )
  {
    try {
      // NB: needs to be made threadsafe
      DomainObjects::Image::AbstractImage *m_image(&m_imageRepository->access(handle));

      // Visit the desired region.
      if((x1 < 0) || (y1 < 0) || (x2 >= m_image->getImageWidth()) || (y2 >= m_image->getImageHeight())) {
        throw ModelLayer::Exceptions::RectangleOutOfBoundsException(x1, y1, x2, y2);
      }

      m_image->acceptLayerPixelVisitor(0, DomainObjects::Math::Rect<std::size_t>(x1, y1, x2, y2), m_visitor);
      return m_visitor->getRenderData();
    } catch(MemoryLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::InvalidHandleException(handle);
    }
  }
}
