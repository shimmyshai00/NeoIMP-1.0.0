/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewCoordinatesService.cpp
 * PURPOSE: Implements the ViewCoordinatesService class.
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

#include "ViewCoordinatesService.hpp"

#include "../../../Common/FunctionListener.hpp"
#include "../../../Common/Exceptions.hpp"
#include "../Exceptions.hpp"

#include <boost/uuid/uuid_generators.hpp>

namespace SDF::Editor::ModelLayer::Services {
  ViewCoordinatesService::ViewCoordinatesService(
    Common::Model::ICrudRepository<Common::Handle, DomainObjects::Engine::Viewpoint> *
      viewpointRepository,
    Common::MessageSystem::IChannel<Messages::Object> *objectMessageChannel
  )
    : m_uuid(boost::uuids::random_generator()()),
      m_viewpointRepository(viewpointRepository)
  {
    m_messageConn = objectMessageChannel->subscribe(this, [](const Messages::Object &msg) {
      return msg.m_objectType == Messages::OBJECT_IMAGE;
    });
    m_messageConn->connect();
  }

  ViewCoordinatesService::~ViewCoordinatesService() {
    m_messageConn->disconnect();
  }

  boost::uuids::uuid
  ViewCoordinatesService::getUuid() const {
    return m_uuid;
  }

  float
  ViewCoordinatesService::getViewingPointX(Common::Handle imageHandle) const {
    try {
      return m_viewpointRepository->retrieve(imageHandle)->m_position.x();
    } catch(Common::ObjectNotFoundException) { // NB: Abstraction leak!
      throw ImageNotFoundException(imageHandle);
    }
  }

  float
  ViewCoordinatesService::getViewingPointY(Common::Handle imageHandle) const {
    try {
      return m_viewpointRepository->retrieve(imageHandle)->m_position.y();
    } catch(Common::ObjectNotFoundException) { // NB: Abstraction leak!
      throw ImageNotFoundException(imageHandle);
    }
  }

  float
  ViewCoordinatesService::getViewingPointMagnification(Common::Handle imageHandle) const {
    try {
      return m_viewpointRepository->retrieve(imageHandle)->m_magnification;
    } catch(Common::ObjectNotFoundException) { // NB: Abstraction leak!
      throw ImageNotFoundException(imageHandle);
    }
  }

  void
  ViewCoordinatesService::setViewingPointX(Common::Handle imageHandle,
                                           float x
                                          )
  {
    try {
      auto vp = m_viewpointRepository->retrieve(imageHandle);
      vp->m_position.x() = x;
      m_viewpointRepository->update(imageHandle, *vp);

      m_viewpointListeners.notify(imageHandle, vp->m_position.x(), vp->m_position.y(),
        vp->m_magnification);
    } catch(Common::ObjectNotFoundException) { // NB: Abstraction leak!
      throw ImageNotFoundException(imageHandle);
    }
  }

  void
  ViewCoordinatesService::setViewingPointY(Common::Handle imageHandle,
                                           float y
                                          )
  {
    try {
      auto vp = m_viewpointRepository->retrieve(imageHandle);
      vp->m_position.y() = y;
      m_viewpointRepository->update(imageHandle, *vp);

      m_viewpointListeners.notify(imageHandle, vp->m_position.x(), vp->m_position.y(),
        vp->m_magnification);
    } catch(Common::ObjectNotFoundException) { // NB: Abstraction leak!
      throw ImageNotFoundException(imageHandle);
    }
  }


  void
  ViewCoordinatesService::setViewingPointMagnification(Common::Handle imageHandle,
                                                       float mag
                                                      )
  {
    try {
      auto vp = m_viewpointRepository->retrieve(imageHandle);
      vp->m_magnification = mag;
      m_viewpointRepository->update(imageHandle, *vp);

      m_viewpointListeners.notify(imageHandle, vp->m_position.x(), vp->m_position.y(),
        vp->m_magnification);
    } catch(Common::ObjectNotFoundException) { // NB: Abstraction leak!
      throw ImageNotFoundException(imageHandle);
    }
  }

  void
  ViewCoordinatesService::setViewingPointPos(Common::Handle imageHandle,
                                             float x,
                                             float y
                                            )
  {
    try {
      auto vp = m_viewpointRepository->retrieve(imageHandle);
      vp->m_position = DomainObjects::Engine::ImagePoint(x, y);
      m_viewpointRepository->update(imageHandle, *vp);

      m_viewpointListeners.notify(imageHandle, vp->m_position.x(), vp->m_position.y(),
        vp->m_magnification);
    } catch(Common::ObjectNotFoundException) { // NB: Abstraction leak!
      throw ImageNotFoundException(imageHandle);
    }
  }

  void
  ViewCoordinatesService::setViewingPoint(Common::Handle imageHandle,
                                          float x,
                                          float y,
                                          float mag
                                         )
  {
    try {
      auto vp = m_viewpointRepository->retrieve(imageHandle);

      vp->m_position = DomainObjects::Engine::ImagePoint(x, y);
      vp->m_magnification = mag;

      m_viewpointRepository->update(imageHandle, *vp);

      m_viewpointListeners.notify(imageHandle, vp->m_position.x(), vp->m_position.y(),
        vp->m_magnification);
    } catch(Common::ObjectNotFoundException) { // NB: Abstraction leak!
      throw ImageNotFoundException(imageHandle);
    }
  }

  void
  ViewCoordinatesService::receiveMessage(
    const Common::MessageSystem::IChannel<Messages::Object> *channel,
    const boost::uuids::uuid senderUuid,
    const Messages::Object &message
  ) {
    using namespace DomainObjects;

    if(message.m_objectType == Messages::OBJECT_IMAGE) {
      std::unique_ptr<Engine::Viewpoint> viewpoint(new Engine::Viewpoint(
        DomainObjects::Engine::ImagePoint(0.0f, 0.0f), 1.0f));
      m_viewpointRepository->insert(message.m_objectHandle, std::move(viewpoint));
    } else if(message.m_objectType == Messages::OBJECT_IMAGE) {
      m_viewpointRepository->erase(message.m_objectHandle);
    }
  }

  Common::PIConnection
  ViewCoordinatesService::addViewingPointListener(
    Common::Handle imageHandle,
    std::shared_ptr<Common::IListener<float, float, float>> listener
  ) {
    if(m_viewpointRepository->has(imageHandle)) {
      return m_viewpointListeners.addListener(imageHandle, listener);
    } else {
      throw ImageNotFoundException(imageHandle);
    }
  }
}
