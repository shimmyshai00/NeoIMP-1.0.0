#ifndef SDF_MODELLAYER_SERVICES_DOCUMENTACCESSSERVICE_HPP
#define SDF_MODELLAYER_SERVICES_DOCUMENTACCESSSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentAccessService.hpp
 * PURPOSE: Defines the DocumentAccessService class.
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

#include <SDF/UILayer/AbstractModel/IDocumentAccessService.hpp>
#include <SDF/UILayer/AbstractModel/Handle.hpp>
#include <SDF/UILayer/AbstractModel/Events/DocumentEvent.hpp>

#include <SDF/Interfaces/IEventHandler.hpp>
#include <SDF/ModelLayer/AbstractData/RepositoryEvent.hpp>

#include <fruit/fruit.h>
#include <vector>

namespace SDF::ModelLayer {
  namespace AbstractData {
    template<class T>
    class IObservableRepository;
  }

  namespace Services {
    namespace AbstractDomain {
      class IImage;
    }

    // Class:      DocumentAccessService
    // Purpose:    Provides the model layer service for creating new documents.
    // Parameters: None.
    class DocumentAccessService : public UILayer::AbstractModel::IDocumentAccessService,
                                  private Interfaces::IEventHandler<AbstractData::RepositoryEvent<AbstractDomain::IImage>>
    {
    public:
      INJECT(DocumentAccessService(AbstractData::IObservableRepository<AbstractDomain::IImage> *imageRepository));
      ~DocumentAccessService();

      void
      attachObserver(Interfaces::IEventHandler<UILayer::AbstractModel::Events::DocumentEvent> *observer);

      void
      removeObserver(Interfaces::IEventHandler<UILayer::AbstractModel::Events::DocumentEvent> *observer);

      std::vector<UILayer::AbstractModel::Handle>
      getActiveDocuments();

      std::string
      getDocumentName(UILayer::AbstractModel::Handle handle) const;

      int
      getDocumentWidthPx(UILayer::AbstractModel::Handle handle) const;

      int
      getDocumentHeightPx(UILayer::AbstractModel::Handle handle) const;

      float
      getDocumentResolutionPpi(UILayer::AbstractModel::Handle handle) const;

      UILayer::AbstractModel::Properties::ColorModel
      getDocumentColorModel(UILayer::AbstractModel::Handle handle) const;

      UILayer::AbstractModel::Properties::BitDepth
      getDocumentBitDepth(UILayer::AbstractModel::Handle handle) const;

      std::size_t
      getDocumentNumLayers(UILayer::AbstractModel::Handle handle) const;
    private:
      AbstractData::IObservableRepository<AbstractDomain::IImage> *m_imageRepository;

      std::vector<Interfaces::IEventHandler<UILayer::AbstractModel::Events::DocumentEvent> *> m_observers;

      void handleEvent(std::shared_ptr<AbstractData::RepositoryEvent<AbstractDomain::IImage>> event);

      void handleCreateEvent(AbstractData::Created<AbstractDomain::IImage> *event);
      void handleLoadEvent(AbstractData::Loaded<AbstractDomain::IImage> *event);
    };
  }
}

#endif
