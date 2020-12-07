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
#include <DomainObjects/Image/ImageTypes.hpp>

namespace SDF::Impl::ModelLayer::Services::Impl {
  DocumentManagementService::DocumentManagementService(MemoryLayer::IImageRepository *imageRepository)
    : m_imageRepository(imageRepository)
  {}

  Handle DocumentManagementService::createDocument(
    int documentWidthPx, int documentHeightPx, float documentResolutionPpi,
    Color::ColorModel colorModel, Color::BitDepth bitDepth
  ) {
    using namespace ModelLayer::Color;
    using namespace DomainObjects::Image;

    std::unique_ptr<ImageVariant> newImage;

    if((colorModel == COLOR_MODEL_RGB) && (bitDepth == BIT_DEPTH_8)) {
      newImage = std::unique_ptr<ImageVariant>(
        new ImageVariant { RGB24Image(documentWidthPx, documentHeightPx, documentResolutionPpi) }
      );
    } else if((colorModel == COLOR_MODEL_RGB) && (bitDepth == BIT_DEPTH_10)) {
      newImage = std::unique_ptr<ImageVariant>(
        new ImageVariant { RGB30Image(documentWidthPx, documentHeightPx, documentResolutionPpi) }
      );
    } else if((colorModel == COLOR_MODEL_RGB) && (bitDepth == BIT_DEPTH_12)) {
      newImage = std::unique_ptr<ImageVariant>(
        new ImageVariant { RGB36Image(documentWidthPx, documentHeightPx, documentResolutionPpi) }
      );
    } else if((colorModel == COLOR_MODEL_RGB) && (bitDepth == BIT_DEPTH_16)) {
      newImage = std::unique_ptr<ImageVariant>(
        new ImageVariant { RGB48Image(documentWidthPx, documentHeightPx, documentResolutionPpi) }
      );
    } else if((colorModel == COLOR_MODEL_CMYK) && (bitDepth == BIT_DEPTH_8)) {
      newImage = std::unique_ptr<ImageVariant>(
        new ImageVariant { CMYK32Image(documentWidthPx, documentHeightPx, documentResolutionPpi) }
      );
    } else if((colorModel == COLOR_MODEL_CMYK) && (bitDepth == BIT_DEPTH_10)) {
      newImage = std::unique_ptr<ImageVariant>(
        new ImageVariant { CMYK40Image(documentWidthPx, documentHeightPx, documentResolutionPpi) }
      );
    } else if((colorModel == COLOR_MODEL_CMYK) && (bitDepth == BIT_DEPTH_12)) {
      newImage = std::unique_ptr<ImageVariant>(
        new ImageVariant { CMYK48Image(documentWidthPx, documentHeightPx, documentResolutionPpi) }
      );
    } else if((colorModel == COLOR_MODEL_CMYK) && (bitDepth == BIT_DEPTH_16)) {
      newImage = std::unique_ptr<ImageVariant>(
        new ImageVariant { CMYK64Image(documentWidthPx, documentHeightPx, documentResolutionPpi) }
      );
    }

    return m_imageRepository->addNewImage("", std::move(newImage));
  }
}
