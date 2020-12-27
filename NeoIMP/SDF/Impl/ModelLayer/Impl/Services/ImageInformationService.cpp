/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageInformationService.cpp
 * PURPOSE: The UI image information service implementation.
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

#include <ImageInformationService.hpp>

#include <DomainObjects/Image/AbstractImage.hpp>

#include <DomainObjects/Meta/ObjectMap.hpp>
#include <ModelLayer/Exceptions/Exceptions.hpp>

namespace SDF::Impl::ModelLayer::Impl::Services {
  ImageInformationService::ImageInformationService(
    DomainObjects::Meta::ObjectMap<DomainObjects::Image::AbstractImage> *imageMap
  )
    : m_imageMap(imageMap)
  {}

  std::string ImageInformationService::getImageName(ModelLayer::Handle handle) {
    if(m_imageMap->find(handle) == nullptr) {
      throw ModelLayer::Exceptions::InvalidHandleException(handle);
    }

    return m_imageMap->find(handle)->getImageName();
  }
  
  int ImageInformationService::getImageWidth(ModelLayer::Handle handle) {
    if(m_imageMap->find(handle) == nullptr) {
      throw ModelLayer::Exceptions::InvalidHandleException(handle);
    }

    return m_imageMap->find(handle)->getImageWidth();
  }

  int ImageInformationService::getImageHeight(ModelLayer::Handle handle) {
    if(m_imageMap->find(handle) == nullptr) {
      throw ModelLayer::Exceptions::InvalidHandleException(handle);
    }

    return m_imageMap->find(handle)->getImageHeight();
  }
}