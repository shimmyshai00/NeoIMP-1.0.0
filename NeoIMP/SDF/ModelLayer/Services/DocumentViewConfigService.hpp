#ifndef SDF_MODELLAYER_SERVICES_DOCUMENTVIEWCONFIGSERVICE_HPP
#define SDF_MODELLAYER_SERVICES_DOCUMENTVIEWCONFIGSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentViewConfigService.hpp
 * PURPOSE: Defines the DocumentViewConfigService class.
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

#include <SDF/Interfaces/IEventHandler.hpp>
#include <SDF/Interfaces/IFactory.hpp>

#include <SDF/UILayer/AbstractModel/IDocumentViewConfigService.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/IImage.hpp>
#include <SDF/ModelLayer/AbstractData/RepositoryEvent.hpp>

#include <fruit/fruit.h>

#include <map>

namespace SDF::ModelLayer {
  namespace AbstractData {
    template<class T>
    class IObservableRepository;

    template<class T>
    class IRepository;
  }

  namespace Services {
    namespace AbstractDomain {
      class IDocumentViewParams;
    }

    // Class:      DocumentViewConfigService
    // Purpose:    Holds the document viewport settings.
    // Parameters: None.
    class DocumentViewConfigService : public UILayer::AbstractModel::IDocumentViewConfigService,
                                      private Interfaces::IEventHandler<
                                        AbstractData::RepositoryEvent<AbstractDomain::IImage>
                                      >
    {
    public:
      INJECT(DocumentViewConfigService(AbstractData::IRepository<AbstractDomain::IDocumentViewParams> *repository,
                                       AbstractData::IObservableRepository<AbstractDomain::IImage> *documentRepository,
                                       Interfaces::IFactory<AbstractDomain::IDocumentViewParams, float, float, float> *
                                        paramFactory
                                      ));
      ~DocumentViewConfigService();

      float
      getDocumentCenterX(UILayer::AbstractModel::Handle handle) const;

      float
      getDocumentCenterY(UILayer::AbstractModel::Handle handle) const;

      float
      getDocumentMagnification(UILayer::AbstractModel::Handle handle) const;

      void
      setDocumentCenterX(UILayer::AbstractModel::Handle handle, float centerX);

      void
      setDocumentCenterY(UILayer::AbstractModel::Handle handle, float centerY);

      void
      setDocumentMagnification(UILayer::AbstractModel::Handle handle, float magnification);
    private:
      AbstractData::IRepository<AbstractDomain::IDocumentViewParams> *m_repository;
      AbstractData::IObservableRepository<AbstractDomain::IImage> *m_documentRepository;
      Interfaces::IFactory<AbstractDomain::IDocumentViewParams, float, float, float> *m_paramFactory;

      std::map<int, int> m_documentHandleToViewportHandleMap;

      void
      handleEvent(std::shared_ptr<AbstractData::RepositoryEvent<AbstractDomain::IImage>> event);

      void
      handleCreatedEvent(AbstractData::Created<AbstractDomain::IImage> *event);

      void
      handleLoadedEvent(AbstractData::Loaded<AbstractDomain::IImage> *event);

      void
      handleDeletedEvent(AbstractData::Deleted<AbstractDomain::IImage> *event);
    };
  }
}

#endif
