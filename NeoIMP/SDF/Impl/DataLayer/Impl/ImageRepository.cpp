/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageRepository.hpp
 * PURPOSE: Implementation of the image repository.
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

#include <DataLayer/Exceptions/Exceptions.hpp>

#include <Framework/IMVCDomainObject.hpp>
#include <ModelLayer/Impl/DomainObjects/Image/AbstractImage.hpp>

#include <UILayer/AbstractModel/Properties/FileFormat.hpp>
#include <Framework/Handle.hpp>

namespace SDF::Impl::DataLayer::Impl {
  ImageRepository::ImageRepository() {}

  void ImageRepository::add(
    std::unique_ptr<Framework::IMVCDomainObject<ModelLayer::Impl::DomainObjects::Image::AbstractImage>> object
  ) {
    Framework::Handle objectId(object->getDomainObjectId());

    if(m_domainObjectMap.find(objectId) != m_domainObjectMap.end()) {
      throw DataLayer::Exceptions::IdAlreadyInUseException(objectId);
    }

    m_domainObjectMap[objectId] = std::move(object);
  }

  std::unique_ptr<Framework::IMVCDomainObject<ModelLayer::Impl::DomainObjects::Image::AbstractImage>>
    ImageRepository::retrieve(Framework::Handle handle)
  {
    if(m_domainObjectMap.find(handle) == m_domainObjectMap.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(handle);
    }

    m_fileNameMap.erase(handle);
    m_fileFormatMap.erase(handle);

    return std::move(m_domainObjectMap[handle]);
  }

  Framework::IMVCDomainObject<ModelLayer::Impl::DomainObjects::Image::AbstractImage> *
    ImageRepository::retrieveNonOwning(Framework::Handle handle)
  {
    if(m_domainObjectMap.find(handle) == m_domainObjectMap.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(handle);
    }

    return m_domainObjectMap[handle].get();
  }

  void ImageRepository::update(
    std::unique_ptr<Framework::IMVCDomainObject<ModelLayer::Impl::DomainObjects::Image::AbstractImage>> object
  ) {
    Framework::Handle objectId(object->getDomainObjectId());

    if(m_domainObjectMap.find(objectId) == m_domainObjectMap.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(objectId);
    }

    m_domainObjectMap[objectId] = std::move(object);
  }

  void ImageRepository::remove(Framework::Handle handle) {
    if(m_domainObjectMap.find(handle) == m_domainObjectMap.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(handle);
    }

    m_domainObjectMap.erase(handle);
    m_fileNameMap.erase(handle);
    m_fileFormatMap.erase(handle);
  }

  void ImageRepository::addBinding(
    Framework::Handle handle,
    std::string fileName, UILayer::AbstractModel::Properties::FileFormat fileFormat
  ) {
    m_fileNameMap[handle] = fileName;
    m_fileFormatMap[handle] = fileFormat;
  }

  void ImageRepository::removeBinding(Framework::Handle handle) {
    m_fileNameMap.erase(handle);
    m_fileFormatMap.erase(handle);
  }
}
