/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageRenderingRepository.hpp
 * PURPOSE: Implementation of the image rendering repository.
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

#include <ImageRenderingRepository.hpp>

#include <ModelLayer/Impl/DomainObjects/Rendering/AbstractImageRendering.hpp>

#include <MemoryLayer/Exceptions/Exceptions.hpp>

namespace SDF::Impl::MemoryLayer::Impl::Repositories {
  ImageRenderingRepository::ImageRenderingRepository() {}
  ImageRenderingRepository::~ImageRenderingRepository() {}

  void
  ImageRenderingRepository::add(ModelLayer::AbstractMemory::Handle handle,
                                std::unique_ptr<ModelLayer::Impl::DomainObjects::Rendering::AbstractImageRendering> imageRendering
                               )
  {
    if(m_imageRenderingMap.find(handle) != m_imageRenderingMap.end()) {
      throw MemoryLayer::Exceptions::DuplicateObjectException(handle);
    }

    m_imageRenderingMap[handle] = std::move(imageRendering);
  }

  ModelLayer::Impl::DomainObjects::Rendering::AbstractImageRendering &
  ImageRenderingRepository::access(ModelLayer::AbstractMemory::Handle handle) {
    if(m_imageRenderingMap.find(handle) == m_imageRenderingMap.end()) {
      throw MemoryLayer::Exceptions::ObjectNotFoundException(handle);
    }

    return *m_imageRenderingMap[handle];
  }

  void
  ImageRenderingRepository::remove(ModelLayer::AbstractMemory::Handle handle) {
    if(m_imageRenderingMap.find(handle) == m_imageRenderingMap.end()) {
      throw MemoryLayer::Exceptions::ObjectNotFoundException(handle);
    }

    m_imageRenderingMap.erase(handle);
  }
}
