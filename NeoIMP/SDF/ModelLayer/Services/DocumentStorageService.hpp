#ifndef SDF_MODELLAYER_SERVICES_DOCUMENTSTORAGESERVICE_HPP
#define SDF_MODELLAYER_SERVICES_DOCUMENTSTORAGESERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentStorageService.hpp
 * PURPOSE: Defines the DocumentStorageService class.
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

#include <SDF/Interfaces/IFactory.hpp>

#include <SDF/UILayer/AbstractModel/IDocumentStorageService.hpp>
#include <SDF/UILayer/AbstractModel/Properties/FileFormat.hpp>
#include <SDF/UILayer/AbstractModel/Handle.hpp>

#include <SDF/ModelLayer/AbstractData/ImageFileFormat.hpp>

#include <fruit/fruit.h>

#include <string>

namespace SDF::ModelLayer {
  namespace AbstractData {
    template<class T, class FileFormat>
    class IFileSystemPersistenceController;

    template<class T>
    class IRepository;
  }

  namespace Services {
    namespace AbstractDomain {
      class IImage;
      class IDeltaEditor;

      template<class T, class U>
      class IObjectMap;
    }

    // Class:      DocumentStorageService
    // Purpose:    Provides the model layer service for storing and retrieving documents.
    // Parameters: None.
    class DocumentStorageService : public UILayer::AbstractModel::IDocumentStorageService {
    public:
      INJECT(DocumentStorageService(AbstractData::IRepository<AbstractDomain::IImage> *imageRepository,
                                    AbstractData::IFileSystemPersistenceController<AbstractDomain::IImage,
                                                                                   AbstractData::ImageFileFormat
                                                                                  > *fileSystemPersistenceController,
                                    AbstractDomain::IObjectMap<AbstractDomain::IImage, AbstractDomain::IDeltaEditor> *
                                     deltaEditorMap,
                                    Interfaces::IFactory<AbstractDomain::IDeltaEditor,
                                                         AbstractDomain::IImage *
                                                        > *deltaEditorFactory
                                   ));

      void
      saveDocument(std::string fileName,
                   UILayer::AbstractModel::Properties::FileFormat fileFormat,
                   UILayer::AbstractModel::Handle documentHandle
                  );

      UILayer::AbstractModel::Handle
      loadDocument(std::string fileName,
                   UILayer::AbstractModel::Properties::FileFormat fileFormat
                  );
    private:
      AbstractData::IRepository<AbstractDomain::IImage> *m_imageRepository;
      AbstractData::IFileSystemPersistenceController<AbstractDomain::IImage, AbstractData::ImageFileFormat> *
        m_fileSystemPersistenceController;
      AbstractDomain::IObjectMap<AbstractDomain::IImage, AbstractDomain::IDeltaEditor> *m_deltaEditorMap;

      Interfaces::IFactory<AbstractDomain::IDeltaEditor, AbstractDomain::IImage *> *m_deltaEditorFactory;
    };
  }
}

#endif
