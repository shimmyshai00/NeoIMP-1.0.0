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

#include <AbstractData/IRepository.hpp>

#include <AbstractDomain/IImage.hpp>

#include <BrokerId.hpp>

#include <algorithm>

#include <iostream>

namespace SDF::ModelLayer::Services {
  using namespace UILayer::AbstractModel;

  using AbstractData::IRepository;

  DocumentAccessService::DocumentAccessService(IRepository<AbstractDomain::IImage> *imageRepository,
                                               Interfaces::IMessageBroker<
                                                Events::RepositoryUpdate<AbstractDomain::IImage>
                                               > *messageBroker
                                              )
    : m_imageRepository(imageRepository),
      m_messageBroker(messageBroker)
  {
    m_messageBroker->addSubscriber(this);
  }

  DocumentAccessService::~DocumentAccessService() {
    m_messageBroker->removeSubscriber(this);
  }

  void
  DocumentAccessService::attachObserver(
    Interfaces::IEventHandler<UILayer::AbstractModel::Events::DocumentEvent> *observer
  ) {
    m_observers.push_back(observer);
  }

  void
  DocumentAccessService::removeObserver(
    Interfaces::IEventHandler<UILayer::AbstractModel::Events::DocumentEvent> *observer
  ) {
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
      printf("width of image %d: %d\n", handle, m_imageRepository->retrieve(handle)->getWidth());
      return m_imageRepository->retrieve(handle)->getWidth();
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  int
  DocumentAccessService::getDocumentHeightPx(UILayer::AbstractModel::Handle handle) const {
    try {
      printf("height of image %d: %d\n", handle, m_imageRepository->retrieve(handle)->getHeight());
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
  int
  DocumentAccessService::getUid() const {
    return SERVICE_DOCUMENT_ACCESS;
  }

  void
  DocumentAccessService::receiveMessage(std::shared_ptr<Events::RepositoryUpdate<AbstractDomain::IImage>> message) {
    if(auto p = dynamic_cast<Events::Created<AbstractDomain::IImage> *>(message.get())) { handleCreateMessage(p); }
  }

  void
  DocumentAccessService::handleCreateMessage(Events::Created<AbstractDomain::IImage> *message) {
    std::shared_ptr<UILayer::AbstractModel::Events::DocumentAdded>
      uiEvent(new UILayer::AbstractModel::Events::DocumentAdded);
    uiEvent->handle = message->objectId;

    for(auto observer : m_observers) {
      observer->handleEvent(uiEvent);
    }
  }
}
