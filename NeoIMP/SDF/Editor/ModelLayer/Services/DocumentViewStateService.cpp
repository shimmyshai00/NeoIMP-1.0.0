/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentStateModelService.cpp
 * PURPOSE: Implements the DocumentStateModelService class.
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

#include "DocumentViewStateService.hpp"


namespace SDF::Editor::ModelLayer::Services {
  DocumentViewStateService::DocumentViewStateService(
    Common::Data::ICrudable<Common::Handle, DomainObjects::State::DocumentViewState> *
      a_documentViewStateCrudable
  )
    : m_documentViewStateCrudable(a_documentViewStateCrudable)
  {
  }

  Common::Handle
  DocumentViewStateService::addView(
    Common::Handle a_imageHandle,
    float a_anchorX,
    float a_anchorY,
    float a_anchorMag
  ) {
    Common::Handle viewHandle(0);
    while(m_documentViewStateCrudable->has(viewHandle)) {
      ++viewHandle;
    }

    auto state = DomainObjects::State::DocumentViewState(a_anchorX, a_anchorY, a_anchorMag);
    m_documentViewStateCrudable->create(viewHandle, state);

    return viewHandle;
  }

  float
  DocumentViewStateService::getViewingPointX(Common::Handle a_viewHandle) const {
    DomainObjects::State::DocumentViewState dvs;
    m_documentViewStateCrudable->retrieve(a_viewHandle, dvs);

    return dvs.viewPosX;
  }

  float
  DocumentViewStateService::getViewingPointY(Common::Handle a_viewHandle) const {
    DomainObjects::State::DocumentViewState dvs;
    m_documentViewStateCrudable->retrieve(a_viewHandle, dvs);

    return dvs.viewPosY;
  }

  float
  DocumentViewStateService::getViewingPointMagnification(Common::Handle a_viewHandle) const {
    DomainObjects::State::DocumentViewState dvs;
    m_documentViewStateCrudable->retrieve(a_viewHandle, dvs);

    return dvs.viewMagnification;
  }

  void
  DocumentViewStateService::setViewingPointX(Common::Handle a_viewHandle, float a_x) {
    DomainObjects::State::DocumentViewState dvs;
    m_documentViewStateCrudable->retrieve(a_viewHandle, dvs);
    dvs.viewPosX = a_x;
    m_documentViewStateCrudable->update(a_viewHandle, dvs);
    m_listeners.notify(a_viewHandle, dvs.viewPosX, dvs.viewPosY, dvs.viewMagnification);
  }

  void
  DocumentViewStateService::setViewingPointY(Common::Handle a_viewHandle, float a_y) {
    DomainObjects::State::DocumentViewState dvs;
    m_documentViewStateCrudable->retrieve(a_viewHandle, dvs);
    dvs.viewPosY = a_y;
    m_documentViewStateCrudable->update(a_viewHandle, dvs);
    m_listeners.notify(a_viewHandle, dvs.viewPosX, dvs.viewPosY, dvs.viewMagnification);
  }

  void
  DocumentViewStateService::setViewingPointMagnification(Common::Handle a_viewHandle, float a_mag) {
    DomainObjects::State::DocumentViewState dvs;
    m_documentViewStateCrudable->retrieve(a_viewHandle, dvs);
    dvs.viewMagnification = a_mag;
    m_documentViewStateCrudable->update(a_viewHandle, dvs);
    m_listeners.notify(a_viewHandle, dvs.viewPosX, dvs.viewPosY, dvs.viewMagnification);
  }

  void
  DocumentViewStateService::setViewingPointPos(Common::Handle a_viewHandle, float a_x, float a_y) {
    DomainObjects::State::DocumentViewState dvs;
    m_documentViewStateCrudable->retrieve(a_viewHandle, dvs);
    dvs.viewPosX = a_x;
    dvs.viewPosY = a_y;
    m_documentViewStateCrudable->update(a_viewHandle, dvs);
    m_listeners.notify(a_viewHandle, dvs.viewPosX, dvs.viewPosY, dvs.viewMagnification);
  }

  void
  DocumentViewStateService::setViewingPoint(
    Common::Handle a_viewHandle,
    float a_x,
    float a_y,
    float a_mag
  ) {
    DomainObjects::State::DocumentViewState dvs;
    m_documentViewStateCrudable->retrieve(a_viewHandle, dvs);
    dvs.viewPosX = a_x;
    dvs.viewPosY = a_y;
    dvs.viewMagnification = a_mag;
    m_documentViewStateCrudable->update(a_viewHandle, dvs);
    m_listeners.notify(a_viewHandle, dvs.viewPosX, dvs.viewPosY, dvs.viewMagnification);
  }

  Common::PIConnection
  DocumentViewStateService::addViewingPointListener(
    Common::Handle a_viewHandle,
    std::shared_ptr<Common::IListener<float, float, float>> a_listener
  ) {
    return m_listeners.addListener(a_viewHandle, a_listener);
  }
}
