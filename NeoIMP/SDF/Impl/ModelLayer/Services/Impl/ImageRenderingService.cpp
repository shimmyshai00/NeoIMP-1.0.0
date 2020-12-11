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

#include <UILayer/IImageDataSource.hpp>

#include <ModelLayer/Exception/Exceptions.hpp>

namespace SDF::Impl::ModelLayer::Services::Impl {
  // Helper class.
  class ImageRenderer : public UILayer::IImageDataSource {
  public:
    ImageRenderer(MemoryLayer::IImageRepository *imageRepository, Handle handle)
      : m_image(imageRepository->access(handle))
    {
    }

    int getImageWidth() {
      return m_image->getImageWidth();
    }

    int getImageHeight() {
      return m_image->getImageHeight();
    }

    const unsigned char *accessImageData(int x1, int y1, int x2, int y2) {
      // Visit the desired region.
      if((x1 < 0) || (y1 < 0) || (x2 >= m_image->getImageWidth()) || (y2 >= m_image->getImageHeight())) {
        throw ModelLayer::Exception::RectangleOutOfBoundsException(x1, y1, x2, y2);
      }

      m_image->acceptLayerPixelVisitor(0, DomainObjects::Math::Rect<std::size_t>(x1, y1, x2, y2), &m_visitor);
      return &(m_visitor.accessRecoveredData()[0]);
    }
  private:
    DomainObjects::Image::AbstractImage *m_image;
    DomainObjects::Algorithms::DisplayGenerator::Visitor m_visitor;
  };
}

namespace SDF::Impl::ModelLayer::Services::Impl {
  ImageRenderingService::ImageRenderingService(MemoryLayer::IImageRepository *imageRepository)
    : m_imageRepository(imageRepository)
  {}

  std::unique_ptr<UILayer::IImageDataSource> ImageRenderingService::getDataSource(Handle imageHandle) {
    return std::make_unique<ImageRenderer>(m_imageRepository, imageHandle);
  }
}
