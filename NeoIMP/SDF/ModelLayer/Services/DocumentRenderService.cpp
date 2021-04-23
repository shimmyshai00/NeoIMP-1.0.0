/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentRenderService.cpp
 * PURPOSE: Implements the DocumentRenderService class.
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

#include <DocumentRenderService.hpp>

#include <ModelLayer/Exceptions/Exceptions.hpp>
#include <DataLayer/Exceptions/Exceptions.hpp>

#include <AbstractData/IRepository.hpp>

#include <AbstractDomain/IImage.hpp>
#include <AbstractDomain/IImageDataVisitor.hpp>
#include <AbstractDomain/IRenderBuffer.hpp>

#include <Math/Rect.hpp>

namespace SDF::ModelLayer::Services {
  DocumentRenderService::DocumentRenderService(AbstractData::IRepository<AbstractDomain::IImage> *imageRepository,
                                               AbstractData::IRepository<AbstractDomain::IRenderBuffer> *
                                                renderingsRepository,
                                               Interfaces::IFactory<AbstractDomain::IImageDataVisitor,
                                                                    AbstractDomain::IRenderBuffer *
                                                                   > *algorithmFactory,
                                               Interfaces::IFactory<AbstractDomain::IRenderBuffer,
                                                                    std::size_t,
                                                                    std::size_t
                                                                   > *renderBufferFactory
                                              )
    : m_imageRepository(imageRepository),
      m_renderingsRepository(renderingsRepository),
      m_algorithmFactory(algorithmFactory),
      m_renderBufferFactory(renderBufferFactory)
  {
  }

  UILayer::AbstractModel::Handle
  DocumentRenderService::renderImage(UILayer::AbstractModel::Handle imageHandle) {
    try {
      std::size_t imageWidthPx(m_imageRepository->retrieve(imageHandle)->getWidth());
      std::size_t imageHeightPx(m_imageRepository->retrieve(imageHandle)->getHeight());

      std::unique_ptr<AbstractDomain::IRenderBuffer>
        buffer(m_renderBufferFactory->create(imageWidthPx, imageHeightPx));

      std::unique_ptr<AbstractDomain::IImageDataVisitor>
        renderer(m_algorithmFactory->create(buffer.get()));

      m_imageRepository->retrieve(imageHandle)->acceptImageDataVisitor(0,
                                                                       Math::Rect<std::size_t>(
                                                                         0, 0,
                                                                         imageWidthPx-1, imageHeightPx-1
                                                                       ),
                                                                       *renderer
                                                                      );

      m_renderingsRepository->create(std::move(buffer));
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(imageHandle);
    }
  }

  void
  DocumentRenderService::getRenderedRegion(const unsigned char *&origin,
                                           std::ptrdiff_t &rowStride,
                                           UILayer::AbstractModel::Handle renderingHandle,
                                           int x1, int y1, int x2, int y2
                                          )
  {
    try {
      std::size_t elSize(m_renderingsRepository->retrieve(renderingHandle)->getElementSize());
      rowStride = elSize * m_renderingsRepository->retrieve(renderingHandle)->getWidth();
      origin = m_renderingsRepository->retrieve(renderingHandle)->getData() + (rowStride * y1) + (elSize * x1);
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::RenderingNotFoundException(renderingHandle);
    }
  }

/*
  unsigned char *
  DocumentRenderService::renderRegion(UILayer::AbstractModel::Handle handle, int x1, int y1, int x2, int y2) {
    try {
      m_imageRepository->retrieve(handle)->acceptImageDataVisitor(0,
                                                                  Math::Rect<std::size_t>(x1, y1, x2, y2),
                                                                  *m_renderingAlgorithm
                                                                 );
      return m_renderingAlgorithm->getResult();
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }
*/
}
