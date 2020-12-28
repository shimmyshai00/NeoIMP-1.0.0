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

#include <SDF/Impl/UILayer/AbstractModel/Services/IDocumentStorageService.hpp>

#include <fruit/fruit.h>
#include <string>

namespace SDF::Impl::ModelLayer {
  namespace AbstractData {
    class IImageRepository;
    class IImageFileMap;
  }

  namespace Impl::Services {
    class DocumentStorageService : public UILayer::AbstractModel::Services::IDocumentStorageService {
    public:
      INJECT(DocumentStorageService(
        AbstractData::IImageRepository *imageRepository,
        AbstractData::IImageFileMap *imageFileMap
      ));

      void saveDocument(
        std::string fileSpec, UILayer::AbstractModel::Properties::FileFormat fileFormat,
        Framework::Handle handle
      );

      Framework::Handle loadDocument(
        std::string fileSpec, UILayer::AbstractModel::Properties::FileFormat fileFormat
      );
    private:
      AbstractData::IImageRepository *m_imageRepository;
      AbstractData::IImageFileMap *m_imageFileMap;
    };
  }
}

#endif
