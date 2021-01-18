#ifndef SDF_IMPL_MODELLAYER_IMPL_SERVICES_DOCUMENTSTORAGESERVICE_HPP
#define SDF_IMPL_MODELLAYER_IMPL_SERVICES_DOCUMENTSTORAGESERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentStorageService.hpp
 * PURPOSE: Headers for the document storage service implementation.
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

#include <SDF/Impl/AppModelLayer/AbstractModel/Services/IDocumentStorageService.hpp>

#include <fruit/fruit.h>
#include <string>

namespace SDF::Impl::ModelLayer {
  namespace AbstractMemory {
    namespace Repositories {
      class IImageRepository;
    }

    namespace Persistence {
      class IImagePersistenceMap;
      class IImagePersister;
    }
  }

  namespace Impl::Services {
    class DocumentStorageService : public AppModelLayer::AbstractModel::Services::IDocumentStorageService {
    public:
      INJECT(DocumentStorageService(AbstractMemory::Repositories::IImageRepository *imageRepository,
                                    AbstractMemory::Persistence::IImagePersistenceMap *imagePersistenceMap,
                                    AbstractMemory::Persistence::IImagePersister *imagePersister
                                   ));

      void saveDocument(std::string fileSpec,
                        DataLayer::Properties::FileFormat fileFormat,
                        AppModelLayer::AbstractModel::Handle handle
                       );

      AppModelLayer::AbstractModel::Handle loadDocument(std::string fileSpec,
                                                        DataLayer::Properties::FileFormat fileFormat
                                                       );
    private:
      AbstractMemory::Repositories::IImageRepository *m_imageRepository;
      AbstractMemory::Persistence::IImagePersistenceMap *m_imagePersistenceMap;
      AbstractMemory::Persistence::IImagePersister *m_imagePersister;
    };
  }
}

#endif
