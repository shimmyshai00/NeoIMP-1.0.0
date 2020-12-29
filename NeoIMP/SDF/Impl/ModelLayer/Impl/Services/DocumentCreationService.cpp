/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentManagementService.cpp
 * PURPOSE: The basic document management service implementation.
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

#include <DocumentCreationService.hpp>

#include <AbstractMemory/Repositories/IImageRepository.hpp>
#include <DomainObjects/Image/AbstractImage.hpp>
#include <DomainObjects/Image/Gil/ImageFactory.hpp>

#include <UILayer/AbstractModel/Handle.hpp>
#include <UILayer/AbstractModel/Data/DocumentSpec.hpp>

namespace SDF::Impl::ModelLayer::Impl::Services {
  DocumentCreationService::DocumentCreationService(AbstractMemory::Repositories::IImageRepository *imageRepository)
    : m_imageRepository(imageRepository),
      m_nextHandle(0)
  {}

  UILayer::AbstractModel::Handle DocumentCreationService::createDocument(
    UILayer::AbstractModel::Data::DocumentSpec spec
  ) {
    std::unique_ptr<DomainObjects::Image::AbstractImage> image(DomainObjects::Image::Gil::createImage(
      spec.documentName, spec.documentWidthPx, spec.documentHeightPx, spec.documentResolutionPpi,
      spec.colorModel, spec.bitDepth
    ));

    UILayer::AbstractModel::Handle imageHandle(m_nextHandle++);
    m_imageRepository->add(imageHandle, std::move(image));

    return imageHandle;
  }
}
