#ifndef SDF_EDITOR_MODELLAYER_SERVICES_DOCUMENTVIEWSTATESERVICE_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_DOCUMENTVIEWSTATESERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentViewStateService.hpp
 * PURPOSE: Defines the DocumentViewStateService class.
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

#include "../../../Common/Data/ICrudable.hpp"
#include "../../../Common/ListenerMapContainer.hpp"
#include "../../../Common/Handle.hpp"
#include "../../UILayer/AbstractModel/Viewing/IAddViewService.hpp"
#include "../../UILayer/AbstractModel/Viewing/IGetViewCoordinatesService.hpp"
#include "../../UILayer/AbstractModel/Viewing/ISetViewXCoordinateService.hpp"
#include "../../UILayer/AbstractModel/Viewing/ISetViewYCoordinateService.hpp"
#include "../../UILayer/AbstractModel/Viewing/ISetViewCoordinatesService.hpp"
#include "../DomainObjects/State/DocumentViewState.hpp"

#include <fruit/fruit.h>

namespace SDF::Editor::ModelLayer::Services {
  // Class:      DocumentViewStateService
  // Purpose:    Defines an MVC service to act as a model for the document application view state
  //             data.
  // Parameters: None.
  class DocumentViewStateService :
    public UILayer::AbstractModel::Viewing::IAddViewService,
    public UILayer::AbstractModel::Viewing::IGetViewCoordinatesService,
    public UILayer::AbstractModel::Viewing::ISetViewXCoordinateService,
    public UILayer::AbstractModel::Viewing::ISetViewYCoordinateService,
    public UILayer::AbstractModel::Viewing::ISetViewCoordinatesService
  {
  public:
    INJECT(DocumentViewStateService(
      Common::Data::ICrudable<Common::Handle, DomainObjects::State::DocumentViewState> *
        a_documentViewStateCrudable
    ));

    Common::Handle
    addView(Common::Handle a_imageHandle, float a_anchorX, float a_anchorY, float a_anchorMag);

    float
    getViewingPointX(Common::Handle a_viewHandle) const;

    float
    getViewingPointY(Common::Handle a_viewHandle) const;

    float
    getViewingPointMagnification(Common::Handle a_viewHandle) const;

    void
    setViewingPointX(Common::Handle a_viewHandle, float a_x);

    void
    setViewingPointY(Common::Handle a_viewHandle, float a_y);

    void
    setViewingPointMagnification(Common::Handle a_viewHandle, float a_mag);

    void
    setViewingPointPos(Common::Handle a_viewHandle, float a_x, float a_y);

    void
    setViewingPoint(Common::Handle a_viewHandle, float a_x, float a_y, float a_mag);

    Common::PIConnection
    addViewingPointListener(
      Common::Handle a_viewHandle,
      std::shared_ptr<Common::IListener<float, float, float>> a_listener
    );
  private:
    Common::Data::ICrudable<Common::Handle, DomainObjects::State::DocumentViewState> *
      m_documentViewStateCrudable;

    Common::ListenerMapContainer<Common::Handle, float, float, float> m_listeners;
  };
}

#endif
