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
        UILayer::AbstractModel::Handle handle,
        std::unique_ptr<ModelLayer::Impl::DomainObjects::Image::AbstractImage> imageDocument
      );

      ModelLayer::Impl::DomainObjects::Image::AbstractImage &access(UILayer::AbstractModel::Handle handle);
      void remove(UILayer::AbstractModel::Handle handle);

      // Persistence methods.
      void assignFileSpec(UILayer::AbstractModel::Handle handle, std::string fileSpec);
      void assignFileFormat(
        UILayer::AbstractModel::Handle handle,
        UILayer::AbstractModel::Properties::FileFormat fileFormat
      );

      void persistImage(UILayer::AbstractModel::Handle handle);
      void retrieveImage(UILayer::AbstractModel::Handle handle);
    private:
      std::map<UILayer::AbstractModel::Handle, std::unique_ptr<ModelLayer::Impl::DomainObjects::Image::AbstractImage>>
        m_imageMap;

      std::map<UILayer::AbstractModel::Handle, std::string> m_imageFileSpecMap;
      std::map<UILayer::AbstractModel::Handle, UILayer::AbstractModel::Properties::FileFormat> m_imageFileFormatMap;

      AbstractData::IImageDataMapper *m_dataMapper;
    };
  }
}

#endif
