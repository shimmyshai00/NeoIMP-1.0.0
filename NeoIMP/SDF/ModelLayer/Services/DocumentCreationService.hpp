#ifndef SDF_MODELLAYER_SERVICES_DOCUMENTCREATIONSERVICE_HPP
#define SDF_MODELLAYER_SERVICES_DOCUMENTCREATIONSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentCreationService.hpp
 * PURPOSE: Defines the DocumentCreationService class.
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

#include <SDF/UILayer/AbstractModel/IDocumentCreationService.hpp>
#include <SDF/Interfaces/IFactory.hpp>

#include <SDF/ModelLayer/Services/AbstractDomain/DocumentSpec.hpp>

#include <fruit/fruit.h>

namespace SDF::ModelLayer {
  namespace AbstractData {
    template<class T>
    class IRepository;
  }

  namespace Services {
    namespace AbstractDomain {
      class IImage;
      class IDeltaEditor;
    }


    // Class:      DocumentCreationService
    // Purpose:    Provides the model layer service for creating new documents.
    // Parameters: None.
    class DocumentCreationService : public UILayer::AbstractModel::IDocumentCreationService {
    public:
      INJECT(DocumentCreationService(AbstractData::IRepository<AbstractDomain::IImage> *imageRepository,
                                     AbstractData::IRepository<AbstractDomain::IDeltaEditor> *deltaEditorRepository,
                                     Interfaces::IFactory<AbstractDomain::IImage, AbstractDomain::DocumentSpec> *
                                      imageFactory,
                                     Interfaces::IFactory<AbstractDomain::IDeltaEditor,
                                                          AbstractDomain::IImage *
                                                         > *deltaEditorFactory
                                    ));

      void
      createDocument(int documentWidthPx,
                     int documentHeightPx,
                     float documentResolutionPpi,
                     UILayer::AbstractModel::Properties::ColorModel colorModel,
                     UILayer::AbstractModel::Properties::BitDepth bitDepth
                    );
    private:
      AbstractData::IRepository<AbstractDomain::IImage> *m_imageRepository;
      AbstractData::IRepository<AbstractDomain::IDeltaEditor> *m_deltaEditorRepository;

      Interfaces::IFactory<AbstractDomain::IImage, AbstractDomain::DocumentSpec> *m_imageFactory;
      Interfaces::IFactory<AbstractDomain::IDeltaEditor,
                           AbstractDomain::IImage *
                          > *m_deltaEditorFactory;
    };
  }
}

#endif
