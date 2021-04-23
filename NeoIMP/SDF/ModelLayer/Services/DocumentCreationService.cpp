/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentCreationService.cpp
 * PURPOSE: Implements the DocumentCreationService class.
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

#include <AbstractData/IRepository.hpp>
#include <AbstractDomain/IImage.hpp>

namespace SDF::ModelLayer::Services {
  DocumentCreationService::DocumentCreationService(AbstractData::IRepository<AbstractDomain::IImage> *imageRepository,
                                                   Interfaces::IFactory<AbstractDomain::IImage,
                                                                        AbstractDomain::DocumentSpec
                                                                       > *imageFactory
                                                  )
    : m_imageRepository(imageRepository),
      m_imageFactory(imageFactory)
  {}

  void
  DocumentCreationService::createDocument(int documentWidthPx,
                                          int documentHeightPx,
                                          float documentResolutionPpi,
                                          UILayer::AbstractModel::Properties::ColorModel colorModel,
                                          UILayer::AbstractModel::Properties::BitDepth bitDepth
                                         )
  {
    using namespace UILayer::AbstractModel;

    AbstractDomain::DocumentSpec spec {
      "Untitled",
      documentWidthPx,
      documentHeightPx,
      documentResolutionPpi,
      colorModel,
      bitDepth
    };

    m_imageRepository->create(m_imageFactory->create(spec));
  }
}
