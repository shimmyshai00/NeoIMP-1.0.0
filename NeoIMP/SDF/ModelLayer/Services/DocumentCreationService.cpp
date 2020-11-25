/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentCreationService.cpp
 * PURPOSE: Implementation of the DocumentCreationService class.
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

#include <DomainObjects/Image/ImageTypes.hpp>

#include <Repository/IVolatileRepository.hpp>
#include <Repository/VolatileImageRepositoryComponent.hpp>

namespace SDF::ModelLayer::Services {
  class DocumentCreationService : public UILayer::AbstractModel::IDocumentCreationService {
  public:
    INJECT(DocumentCreationService(
      Repository::IVolatileRepository<DomainObjects::Image::ImageVariant> *volatileImageRepository
    )) : m_volatileImageRepository(volatileImageRepository) {}

    ~DocumentCreationService() {}

    ModelLayer::Handle createDocument(
      int widthInPixels, int heightInPixels, float resolutionPpi,
      ModelLayer::DomainObjects::Color::ColorModel colorModel,
      ModelLayer::DomainObjects::Color::BitDepth bitDepth
    ) {
      using namespace ModelLayer::DomainObjects::Color;

      // Create an image of the requested type specification.
      std::unique_ptr<DomainObjects::Image::ImageVariant> imageVariant;
      DomainObjects::Image::ImageVariant var(SDF::ModelLayer::DomainObjects::Image::Image<SDF::ModelLayer::DomainObjects::Color::RGBColor<SDF::ModelLayer::DomainObjects::Color::ColorChannel<unsigned char, 255> >, SDF::ModelLayer::DomainObjects::Color::ColorChannel<unsigned char, 255> >(10, 10, 120.0f));
      if((colorModel == COLOR_MODEL_RGB) && (bitDepth == BIT_DEPTH_8)) {
        imageVariant = std::make_unique<DomainObjects::Image::ImageVariant>(
          DomainObjects::Image::RGB24Image(widthInPixels, heightInPixels, resolutionPpi)
        );
      } else if((colorModel == COLOR_MODEL_RGB) && (bitDepth == BIT_DEPTH_10)) {
        imageVariant = std::make_unique<DomainObjects::Image::ImageVariant>(
          DomainObjects::Image::RGB30Image(widthInPixels, heightInPixels, resolutionPpi)
        );
      } else if((colorModel == COLOR_MODEL_RGB) && (bitDepth == BIT_DEPTH_12)) {
        imageVariant = std::make_unique<DomainObjects::Image::ImageVariant>(
          DomainObjects::Image::RGB36Image(widthInPixels, heightInPixels, resolutionPpi)
        );
      } else if((colorModel == COLOR_MODEL_RGB) && (bitDepth == BIT_DEPTH_16)) {
        imageVariant = std::make_unique<DomainObjects::Image::ImageVariant>(
          DomainObjects::Image::RGB48Image(widthInPixels, heightInPixels, resolutionPpi)
        );
      } else if((colorModel == COLOR_MODEL_CMYK) && (bitDepth == BIT_DEPTH_8)) {
        imageVariant = std::make_unique<DomainObjects::Image::ImageVariant>(
          DomainObjects::Image::CMYK32Image(widthInPixels, heightInPixels, resolutionPpi)
        );
      } else if((colorModel == COLOR_MODEL_CMYK) && (bitDepth == BIT_DEPTH_10)) {
        imageVariant = std::make_unique<DomainObjects::Image::ImageVariant>(
          DomainObjects::Image::CMYK40Image(widthInPixels, heightInPixels, resolutionPpi)
        );
      } else if((colorModel == COLOR_MODEL_CMYK) && (bitDepth == BIT_DEPTH_12)) {
        imageVariant = std::make_unique<DomainObjects::Image::ImageVariant>(
          DomainObjects::Image::CMYK48Image(widthInPixels, heightInPixels, resolutionPpi)
        );
      } else if((colorModel == COLOR_MODEL_CMYK) && (bitDepth == BIT_DEPTH_16)) {
        imageVariant = std::make_unique<DomainObjects::Image::ImageVariant>(
          DomainObjects::Image::CMYK64Image(widthInPixels, heightInPixels, resolutionPpi)
        );
      }

      return m_volatileImageRepository->storeObject(std::move(imageVariant));
    }
  private:
    Repository::IVolatileRepository<DomainObjects::Image::ImageVariant> *m_volatileImageRepository;
  };
}

namespace SDF::ModelLayer::Services {
  fruit::Component<UILayer::AbstractModel::IDocumentCreationService> getDocumentCreationServiceComponent() {
    return fruit::createComponent()
      .bind<UILayer::AbstractModel::IDocumentCreationService, DocumentCreationService>()
      .install(Repository::getVolatileImageRepositoryComponent);
  }
}
