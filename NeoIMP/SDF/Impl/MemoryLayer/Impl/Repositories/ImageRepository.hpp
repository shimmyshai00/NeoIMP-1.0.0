#ifndef SDF_IMPL_MEMORYLAYER_IMPL_REPOSITORIES_IMAGEREPOSITORY_HPP
#define SDF_IMPL_MEMORYLAYER_IMPL_REPOSITORIES_IMAGEREPOSITORY_HPP

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

#include <SDF/Impl/ModelLayer/AbstractMemory/Repositories/IImageRepository.hpp>
#include <SDF/Impl/ModelLayer/AbstractMemory/Persistence/IImagePersister.hpp>
#include <SDF/Impl/ModelLayer/AbstractMemory/Persistence/IImagePersistenceMap.hpp>

#include <fruit/fruit.h>

#include <map>
#include <memory>

namespace SDF::Impl::MemoryLayer {
  namespace AbstractData {
    class IImageDataMapper;
  }

  namespace Impl::Repositories {
    class ImageRepository : public ModelLayer::AbstractMemory::Repositories::IImageRepository,
      public ModelLayer::AbstractMemory::Persistence::IImagePersister,
      public ModelLayer::AbstractMemory::Persistence::IImagePersistenceMap {
    public:
      INJECT(ImageRepository(AbstractData::IImageDataMapper *dataMapper));
      ~ImageRepository();

      void add(
        ModelLayer::AbstractMemory::Handle handle,
        std::unique_ptr<ModelLayer::Impl::DomainObjects::Image::AbstractImage> imageDocument
      );

      ModelLayer::Impl::DomainObjects::Image::AbstractImage &access(ModelLayer::AbstractMemory::Handle handle);
      void remove(ModelLayer::AbstractMemory::Handle handle);

      // Persistence methods.
      void assignFileSpec(ModelLayer::AbstractMemory::Handle handle, std::string fileSpec);
      void assignFileFormat(ModelLayer::AbstractMemory::Handle handle, DataLayer::Properties::FileFormat fileFormat);

      void persistImage(ModelLayer::AbstractMemory::Handle handle);
      void retrieveImage(ModelLayer::AbstractMemory::Handle handle);
    private:
      std::map<ModelLayer::AbstractMemory::Handle, std::unique_ptr<ModelLayer::Impl::DomainObjects::Image::AbstractImage>> m_imageMap;
      std::map<ModelLayer::AbstractMemory::Handle, std::string> m_imageFileSpecMap;
      std::map<ModelLayer::AbstractMemory::Handle, DataLayer::Properties::FileFormat> m_imageFileFormatMap;

      AbstractData::IImageDataMapper *m_dataMapper;
    };
  }
}

#endif
