/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentViewConfigService.cpp
 * PURPOSE: Implements the DocumentViewConfigService class.
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

#include <DocumentViewConfigService.hpp>

#include <Interfaces/IEventHandler.hpp>

#include <ModelLayer/Exceptions/Exceptions.hpp>
#include <DataLayer/Exceptions/Exceptions.hpp>

#include <SDF/ModelLayer/AbstractData/IRepository.hpp>
#include <SDF/ModelLayer/Services/AbstractDomain/IImage.hpp>

#include <Math/Coord.hpp>

#include "BrokerId.hpp"

namespace SDF::ModelLayer::Services {
  using namespace UILayer::AbstractModel;

  DocumentViewConfigService::DocumentViewConfigService(
    AbstractData::IRepository<AbstractDomain::IImage> *documentRepository,
    Interfaces::IMessageBroker<AbstractDomain::Defs::ImageChange> *messageBroker
  )
    : m_documentRepository(documentRepository),
      m_messageBroker(messageBroker)
  {
    m_messageBroker->addSubscriber(this);
  }

  DocumentViewConfigService::~DocumentViewConfigService() {
    m_messageBroker->removeSubscriber(this);
  }

  void
  DocumentViewConfigService::attachObserver(Interfaces::IEventHandler<Events::ViewportEvent> *observer) {
    m_observers.push_back(observer);
  }

  void
  DocumentViewConfigService::removeObserver(Interfaces::IEventHandler<Events::ViewportEvent> *observer) {
    m_observers.erase(std::find(m_observers.begin(), m_observers.end(), observer));
  }

  float
  DocumentViewConfigService::getDocumentCenterX(Handle handle) const {
    try {
      return m_documentRepository->retrieve(handle)->getViewCenter().getX();
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  float
  DocumentViewConfigService::getDocumentCenterY(Handle handle) const {
    try {
      return m_documentRepository->retrieve(handle)->getViewCenter().getY();
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  float
  DocumentViewConfigService::getDocumentMagnification(Handle handle) const{
    try {
      return m_documentRepository->retrieve(handle)->getViewMagnification();
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  void
  DocumentViewConfigService::setDocumentCenterX(Handle handle, float centerX) {
    try {
      Math::Coord<float> curCenter(m_documentRepository->retrieve(handle)->getViewCenter());
      Math::Coord<float> newCenter(Math::Coord<float>(centerX, curCenter.getY()));

      m_documentRepository->retrieve(handle)->setViewCenter(newCenter);

      std::shared_ptr<Events::ViewCenterChangedEvent> event(new Events::ViewCenterChangedEvent);

      event->documentHandle = handle;
      event->centerX = newCenter.getX();
      event->centerY = newCenter.getY();

      for(auto observer : m_observers) {
        observer->handleEvent(event);
      }
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  void
  DocumentViewConfigService::setDocumentCenterY(Handle handle, float centerY) {
    try {
      Math::Coord<float> curCenter(m_documentRepository->retrieve(handle)->getViewCenter());
      Math::Coord<float> newCenter(Math::Coord<float>(curCenter.getX(), centerY));

      m_documentRepository->retrieve(handle)->setViewCenter(newCenter);

      std::shared_ptr<Events::ViewCenterChangedEvent> event(new Events::ViewCenterChangedEvent);

      event->documentHandle = handle;
      event->centerX = newCenter.getX();
      event->centerY = newCenter.getY();

      for(auto observer : m_observers) {
        observer->handleEvent(event);
      }
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  void
  DocumentViewConfigService::setDocumentMagnification(Handle handle, float magnification) {
    try {
      m_documentRepository->retrieve(handle)->setViewMagnification(magnification);

      std::shared_ptr<Events::ViewMagnificationChangedEvent> event(new Events::ViewMagnificationChangedEvent);

      event->documentHandle = handle;
      event->magnification = magnification;

      for(auto observer : m_observers) {
        observer->handleEvent(event);
      }
    } catch(DataLayer::Exceptions::ObjectNotFoundException &e) {
      throw ModelLayer::Exceptions::DocumentNotFoundException(handle);
    }
  }

  // Private members.
  int
  DocumentViewConfigService::getUid() const {
    return SERVICE_DOCUMENT_VIEW_CONFIG;
  }

  void
  DocumentViewConfigService::receiveMessage(std::shared_ptr<AbstractDomain::Defs::ImageChange> message) {
    if(auto p = dynamic_cast<AbstractDomain::Defs::ImageViewportCenterChanged *>(message.get())) {
      handleImageViewportCenterChangedMessage(p);
    } else if(auto p = dynamic_cast<AbstractDomain::Defs::ImageViewportMagnificationChanged *>(message.get())) {
      handleImageViewportMagnificationChangedMessage(p);
    }
  }

  void
  DocumentViewConfigService::handleImageViewportCenterChangedMessage(
    AbstractDomain::Defs::ImageViewportCenterChanged *message
  ) {
    std::shared_ptr<Events::ViewCenterChangedEvent> event(new Events::ViewCenterChangedEvent);

    event->documentHandle = message->imageId;
    event->centerX = message->newCenter.getX();
    event->centerY = message->newCenter.getY();

    for(auto observer : m_observers) {
      observer->handleEvent(event);
    }
  }

  void
  DocumentViewConfigService::handleImageViewportMagnificationChangedMessage(
    AbstractDomain::Defs::ImageViewportMagnificationChanged *message
  ) {
    printf("MAGNIF\n");
    std::shared_ptr<Events::ViewMagnificationChangedEvent> event(new Events::ViewMagnificationChangedEvent);

    event->documentHandle = message->imageId;
    event->magnification = message->newMagnif;

    for(auto observer : m_observers) {
      observer->handleEvent(event);
    }
  }
}
