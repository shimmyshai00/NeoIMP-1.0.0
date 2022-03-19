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

#include "../../../Common/Model/ICrudRepository.hpp"
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
      Common::Model::ICrudRepository<Common::Handle, DomainObjects::State::DocumentViewState> *
        documentViewStateRepository
    ));

    Common::Handle
    addView(Common::Handle imageHandle, float anchorX, float anchorY, float anchorMag);

    float
    getViewingPointX(Common::Handle viewHandle) const;

    float
    getViewingPointY(Common::Handle viewHandle) const;

    float
    getViewingPointMagnification(Common::Handle viewHandle) const;

    void
    setViewingPointX(Common::Handle viewHandle, float x);

    void
    setViewingPointY(Common::Handle viewHandle, float y);

    void
    setViewingPointMagnification(Common::Handle viewHandle, float mag);

    void
    setViewingPointPos(Common::Handle viewHandle, float x, float y);

    void
    setViewingPoint(Common::Handle viewHandle, float x, float y, float mag);

    Common::PIConnection
    addViewingPointListener(
      Common::Handle viewHandle,
      std::shared_ptr<Common::IListener<float, float, float>> listener
    );
  private:
    Common::Model::ICrudRepository<Common::Handle, DomainObjects::State::DocumentViewState> *
      m_documentViewStateRepository;

    Common::Handle m_nextViewHandle;
  };
}

#endif
