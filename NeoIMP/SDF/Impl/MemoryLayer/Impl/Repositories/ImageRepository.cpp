/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageRepository.hpp
 * PURPOSE: Implementation of the in-memory image repository.
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

#include <ImageRepository.hpp>

#include <MemoryLayer/Exceptions/Exceptions.hpp>

#include <UILayer/AbstractModel/Handle.hpp>
#include <ModelLayer/Impl/DomainObjects/Image/AbstractImage.hpp>

namespace SDF::Impl::MemoryLayer::Impl::Repositories {
  ImageRepository::ImageRepository() {}
  ImageRepository::~ImageRepository() {}

  void ImageRepository::add(
    UILayer::AbstractModel::Handle handle,
    std::unique_ptr<ModelLayer::Impl::DomainObjects::Image::AbstractImage> imageDocument
  ) {
    if(m_imageMap.find(handle) != m_imageMap.end()) {
      throw MemoryLayer::Exceptions::DuplicateObjectException(handle);
    }

    m_imageMap[handle] = std::move(imageDocument);
  }

  ModelLayer::Impl::DomainObjects::Image::AbstractImage &ImageRepository::access(
    UILayer::AbstractModel::Handle handle
  ) {
    if(m_imageMap.find(handle) == m_imageMap.end()) {
      throw MemoryLayer::Exceptions::ObjectNotFoundException(handle);
    }

    return *m_imageMap[handle];
  }

  void ImageRepository::remove(UILayer::AbstractModel::Handle handle) {
    if(m_imageMap.find(handle) == m_imageMap.end()) {
      throw MemoryLayer::Exceptions::ObjectNotFoundException(handle);
    }

    m_imageMap.erase(handle);
  }
}
