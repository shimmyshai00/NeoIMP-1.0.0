/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CreateDocumentService.cpp
 * PURPOSE: Implements the CreateDocumentService class.
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

#include "CreateDocumentService.hpp"

#include <iostream>

namespace SDF::ModelLayer::Services {
  CreateDocumentService::CreateDocumentService(Repositories::IRepository<DomainObjects::Image::IImage> *imageRepository,
                                               DomainObjects::IFactory<DomainObjects::Image::IImage,
                                                                       UILayer::AbstractModel::Data::DocumentSpec
                                                                      > *imageFactory
                                              )
    : m_imageRepository(imageRepository),
      m_imageFactory(imageFactory)
  {}

  UILayer::AbstractModel::Handle
  CreateDocumentService::createDocument(UILayer::AbstractModel::Data::DocumentSpec spec) {
    std::unique_ptr<DomainObjects::Image::IImage> image(m_imageFactory->create(spec));
    int imageId(image->getId());

    m_imageRepository->create(std::move(image));

    return imageId;
  }
}
