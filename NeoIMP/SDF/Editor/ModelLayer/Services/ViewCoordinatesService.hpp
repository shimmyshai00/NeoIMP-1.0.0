#ifndef SDF_EDITOR_MODELLAYER_SERVICES_VIEWCOORDINATESSERVICE_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_VIEWCOORDINATESSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewCoordinatesService.hpp
 * PURPOSE: Defines the ViewCoordinatesService class.
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

#include "../../../Common/Model/ICrudRepository.hpp"
#include "../../../Common/MessageSystem/ISubscriber.hpp"
#include "../../../Common/MessageSystem/IChannel.hpp"
#include "../../../Common/Handle.hpp"
#include "../../../Common/IConnection.hpp"
#include "../../../Common/IListener.hpp"
#include "../../../Common/ListenerMapContainer.hpp"
#include "../../UILayer/AbstractModel/IGetViewCoordinatesService.hpp"
#include "../../UILayer/AbstractModel/ISetViewCoordinatesService.hpp"
#include "../DomainObjects/Engine/Viewpoint.hpp"
#include "Messages/Object.hpp"

#include <boost/uuid/uuid.hpp>
#include <fruit/fruit.h>

#include <memory>

namespace SDF::Editor::ModelLayer::Services {
  // Class:      ViewCoordinatesService
  // Purpose:    Implements the MVC service to manage image viewing coordinates.
  // Parameters: None.
  class ViewCoordinatesService : public UILayer::AbstractModel::IGetViewCoordinatesService,
                                 public UILayer::AbstractModel::ISetViewCoordinatesService,
                                 public Common::MessageSystem::ISubscriber<Messages::Object>
  {
  public:
    INJECT(ViewCoordinatesService(
      Common::Model::ICrudRepository<Common::Handle, DomainObjects::Engine::Viewpoint> *
        viewpointRepository,
      Common::MessageSystem::IChannel<Messages::Object> *objectMessageChannel
    ));

    ~ViewCoordinatesService();

    boost::uuids::uuid
    getUuid() const;

    float
    getViewingPointX(Common::Handle imageHandle) const;

    float
    getViewingPointY(Common::Handle imageHandle) const;

    float
    getViewingPointMagnification(Common::Handle imageHandle) const;

    void
    setViewingPointX(Common::Handle imageHandle, float x);

    void
    setViewingPointY(Common::Handle imageHandle, float y);

    void
    setViewingPointMagnification(Common::Handle imageHandle, float mag);

    void
    setViewingPointPos(Common::Handle imageHandle, float x, float y);

    void
    setViewingPoint(Common::Handle imageHandle, float x, float y, float mag);

    void
    receiveMessage(
      const Common::MessageSystem::IChannel<Messages::Object> *channel,
      const boost::uuids::uuid senderUuid,
      const Messages::Object &message
    );

    Common::PIConnection
    addViewingPointListener(
      Common::Handle imageHandle,
      std::shared_ptr<Common::IListener<float, float, float>> listener
    );
  private:
    boost::uuids::uuid m_uuid;

    Common::Model::ICrudRepository<Common::Handle, DomainObjects::Engine::Viewpoint> *
      m_viewpointRepository;
    Common::ListenerMapContainer<Common::Handle, float, float, float> m_viewpointListeners;

    Common::PIConnection m_messageConn;
  };
}

#endif
