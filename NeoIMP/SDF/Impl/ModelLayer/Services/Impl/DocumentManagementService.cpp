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

#include <DocumentManagementService.hpp>

#include <MemoryLayer/IImageRepository.hpp>
#include <DomainObjects/Image/AbstractImage.hpp>

#include <DomainObjects/Image/Gil/ImageFactory.hpp>

namespace SDF::Impl::ModelLayer::Services::Impl {
  DocumentManagementService::DocumentManagementService(MemoryLayer::IImageRepository *imageRepository)
    : m_imageRepository(imageRepository)
  {}

  Handle DocumentManagementService::createDocument(
    int documentWidthPx, int documentHeightPx, float documentResolutionPpi,
    Color::ColorModel colorModel, Color::BitDepth bitDepth
  ) {
    return m_imageRepository->addNewImage("", DomainObjects::Image::Gil::createImage(
      documentWidthPx, documentHeightPx, documentResolutionPpi,
      colorModel, bitDepth
    ));
  }
}
