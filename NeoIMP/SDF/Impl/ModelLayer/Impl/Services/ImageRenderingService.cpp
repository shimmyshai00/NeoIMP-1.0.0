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
#include <AbstractMemory/Repositories/IImageRenderingRepository.hpp>

#include <DomainObjects/Image/AbstractImage.hpp>
#include <DomainObjects/Rendering/AbstractImageRendering.hpp>
#include <DomainObjects/Rendering/RGB32ImageRendering.hpp>

#include <ModelLayer/Exceptions/Exceptions.hpp>
#include <MemoryLayer/Exceptions/Exceptions.hpp>

#include <Support/HandleGenerator.hpp>

namespace SDF::Impl::ModelLayer::Impl::Services {
  ImageRenderingService::ImageRenderingService(AbstractMemory::Repositories::IImageRepository *imageRepository,
                                               AbstractMemory::Repositories::IImageRenderingRepository *imageRenderingRepository,
                                               Support::HandleGenerator *handleGenerator
                                              )
    : m_imageRepository(imageRepository),
      m_imageRenderingRepository(imageRenderingRepository),
      m_handleGenerator(handleGenerator)
  {}

  AppModelLayer::AbstractModel::Handle ImageRenderingService::renderImage(AppModelLayer::AbstractModel::Handle imageHandle) {
    try {
      // NB: needs to be made threadsafe
      DomainObjects::Image::AbstractImage *m_image(&m_imageRepository->access(imageHandle));
      std::unique_ptr<DomainObjects::Rendering::RGB32ImageRendering> imageRendering(
        new DomainObjects::Rendering::RGB32ImageRendering(m_image->getImageWidth(), m_image->getImageHeight())
      );

      DomainObjects::Algorithms::Renderer::Visitor renderVisitor(imageRendering.get());
      m_image->acceptLayerPixelVisitor(0, m_image->getImageRect(), &renderVisitor);

      AppModelLayer::AbstractModel::Handle renderingHandle(m_handleGenerator->getNextHandle());
      m_imageRenderingRepository->add(renderingHandle, std::move(imageRendering));
      return renderingHandle;
    } catch(MemoryLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::InvalidHandleException(imageHandle);
    }
  }

  void ImageRenderingService::getRenderedRegion(const unsigned char *&origin,
                                                std::ptrdiff_t &rowStride,
                                                AppModelLayer::AbstractModel::Handle renderingHandle,
                                                int x1, int y1, int x2, int y2
                                               )
  {
    try {
      m_imageRenderingRepository->access(renderingHandle).accessRenderingData(
        origin, rowStride,
        DomainObjects::Math::Rect<std::size_t>(x1, y1, x2, y2)
      );
    } catch(MemoryLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::InvalidHandleException(renderingHandle);
    }
  }
}
