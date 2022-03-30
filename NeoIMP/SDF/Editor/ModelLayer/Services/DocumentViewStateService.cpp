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
    Common::Data::ICrudable<Common::Handle, DomainObjects::State::SDocumentViewState> *
      documentViewStateCrudable
  )
    : m_documentViewStateCrudable(documentViewStateCrudable)
  {
  }

  Common::Handle
  DocumentViewStateService::addView(
    Common::Handle imageHandle,
    float anchorX,
    float anchorY,
    float anchorMag
  ) {
    Common::Handle viewHandle(0);
    while(m_documentViewStateCrudable->has(viewHandle)) {
      ++viewHandle;
    }

    auto state = DomainObjects::State::SDocumentViewState(anchorX, anchorY, anchorMag);
    m_documentViewStateCrudable->create(viewHandle, state);

    return viewHandle;
  }

  float
  DocumentViewStateService::getViewingPointX(Common::Handle viewHandle) const {
    DomainObjects::State::SDocumentViewState dvs;
    m_documentViewStateCrudable->retrieve(viewHandle, dvs);

    return dvs.viewPosX;
  }

  float
  DocumentViewStateService::getViewingPointY(Common::Handle viewHandle) const {
    DomainObjects::State::SDocumentViewState dvs;
    m_documentViewStateCrudable->retrieve(viewHandle, dvs);

    return dvs.viewPosY;
  }

  float
  DocumentViewStateService::getViewingPointMagnification(Common::Handle viewHandle) const {
    DomainObjects::State::SDocumentViewState dvs;
    m_documentViewStateCrudable->retrieve(viewHandle, dvs);

    return dvs.viewMagnification;
  }

  void
  DocumentViewStateService::setViewingPointX(Common::Handle viewHandle, float x) {
    DomainObjects::State::SDocumentViewState dvs;
    m_documentViewStateCrudable->retrieve(viewHandle, dvs);
    dvs.viewPosX = x;
    m_documentViewStateCrudable->update(viewHandle, dvs);
    m_listeners.notify(viewHandle, dvs.viewPosX, dvs.viewPosY, dvs.viewMagnification);
  }

  void
  DocumentViewStateService::setViewingPointY(Common::Handle viewHandle, float y) {
    DomainObjects::State::SDocumentViewState dvs;
    m_documentViewStateCrudable->retrieve(viewHandle, dvs);
    dvs.viewPosY = y;
    m_documentViewStateCrudable->update(viewHandle, dvs);
    m_listeners.notify(viewHandle, dvs.viewPosX, dvs.viewPosY, dvs.viewMagnification);
  }

  void
  DocumentViewStateService::setViewingPointMagnification(Common::Handle viewHandle, float mag) {
    DomainObjects::State::SDocumentViewState dvs;
    m_documentViewStateCrudable->retrieve(viewHandle, dvs);
    dvs.viewMagnification = mag;
    m_documentViewStateCrudable->update(viewHandle, dvs);
    m_listeners.notify(viewHandle, dvs.viewPosX, dvs.viewPosY, dvs.viewMagnification);
  }

  void
  DocumentViewStateService::setViewingPointPos(Common::Handle viewHandle, float x, float y) {
    DomainObjects::State::SDocumentViewState dvs;
    m_documentViewStateCrudable->retrieve(viewHandle, dvs);
    dvs.viewPosX = x;
    dvs.viewPosY = y;
    m_documentViewStateCrudable->update(viewHandle, dvs);
    m_listeners.notify(viewHandle, dvs.viewPosX, dvs.viewPosY, dvs.viewMagnification);
  }

  void
  DocumentViewStateService::setViewingPoint(Common::Handle viewHandle, float x, float y, float mag)
  {
    DomainObjects::State::SDocumentViewState dvs;
    m_documentViewStateCrudable->retrieve(viewHandle, dvs);
    dvs.viewPosX = x;
    dvs.viewPosY = y;
    dvs.viewMagnification = mag;
    m_documentViewStateCrudable->update(viewHandle, dvs);
    m_listeners.notify(viewHandle, dvs.viewPosX, dvs.viewPosY, dvs.viewMagnification);
  }

  Common::PIConnection
  DocumentViewStateService::addViewingPointListener(
    Common::Handle viewHandle,
    std::shared_ptr<Common::IListener<float, float, float>> listener
  ) {
    return m_listeners.addListener(viewHandle, listener);
  }
}
