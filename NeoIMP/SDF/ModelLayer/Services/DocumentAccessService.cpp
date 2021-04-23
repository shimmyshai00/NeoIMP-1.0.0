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

#include <DocumentAccessService.hpp>

#include <ModelLayer/Exceptions/Exceptions.hpp>
#include <DataLayer/Exceptions/Exceptions.hpp>

#include <AbstractData/IObservableRepository.hpp>
#include <AbstractData/IRepository.hpp>

#include <AbstractDomain/IImage.hpp>

#include <algorithm>

#include <iostream>

namespace SDF::ModelLayer::Services {
  using namespace UILayer::AbstractModel;

  using AbstractData::IRepository;
  using AbstractData::IObservableRepository;

  DocumentAccessService::DocumentAccessService(IObservableRepository<AbstractDomain::IImage> *imageRepository)
    : m_imageRepository(imageRepository)
  {
    m_imageRepository->attachObserver(this);
  }

  DocumentAccessService::~DocumentAccessService() {
    m_imageRepository->removeObserver(this);
  }

  void
  DocumentAccessService::attachObserver(Interfaces::IEventHandler<Events::DocumentEvent> *observer) {
    m_observers.push_back(observer);
  }

  void
  DocumentAccessService::removeObserver(Interfaces::IEventHandler<Events::DocumentEvent> *observer) {
    m_observers.erase(std::find(m_observers.begin(), m_observers.end(), observer));
  }

  std::vector<Handle>
  DocumentAccessService::getActiveDocuments() {
    std::vector<Handle> rv;

    return rv;
  }

  std::string
  DocumentAccessService::getDocumentName(UILayer::AbstractModel::Handle handle) const {
    // TBA
    return "Untitled";
  }

  int
  DocumentAccessService::getDocumentWidthPx(UILayer::AbstractModel::Handle handle) const {
    try {
      return m_imageRepository->retrieve(handle)->getWidth();
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  int
  DocumentAccessService::getDocumentHeightPx(UILayer::AbstractModel::Handle handle) const {
    try {
      return m_imageRepository->retrieve(handle)->getHeight();
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  float
  DocumentAccessService::getDocumentResolutionPpi(UILayer::AbstractModel::Handle handle) const {
    return 120.0f; // TBA
  }

  UILayer::AbstractModel::Properties::ColorModel
  DocumentAccessService::getDocumentColorModel(UILayer::AbstractModel::Handle handle) const {
    // TBA
    return Properties::COLOR_MODEL_MAX;
  }

  UILayer::AbstractModel::Properties::BitDepth
  DocumentAccessService::getDocumentBitDepth(UILayer::AbstractModel::Handle handle) const {
    // TBA
    return Properties::BIT_DEPTH_MAX;
  }

  std::size_t
  DocumentAccessService::getDocumentNumLayers(UILayer::AbstractModel::Handle handle) const {
    try {
      return m_imageRepository->retrieve(handle)->getNumLayers();
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  // Private members.
  void
  DocumentAccessService::handleEvent(std::shared_ptr<AbstractData::RepositoryEvent<AbstractDomain::IImage>> event)
  {
    if(auto p = dynamic_cast<AbstractData::Created<AbstractDomain::IImage> *>(event.get())) { handleCreateEvent(p); }
  }

  void
  DocumentAccessService::handleCreateEvent(AbstractData::Created<AbstractDomain::IImage> *event)
  {
    std::shared_ptr<UILayer::AbstractModel::Events::DocumentCreated>
      uiEvent(new UILayer::AbstractModel::Events::DocumentCreated);
    uiEvent->handle = event->objectId;

    for(auto observer : m_observers) {
      observer->handleEvent(uiEvent);
    }
  }
}
