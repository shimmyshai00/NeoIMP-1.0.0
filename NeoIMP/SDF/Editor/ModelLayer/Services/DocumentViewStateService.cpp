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
  namespace Impl {
    class WrappedListener : public Common::IListener<DomainObjects::State::ViewCoordinates> {
    public:
      WrappedListener(std::shared_ptr<Common::IListener<float, float, float>> callLis)
        : m_callLis(callLis)
      {
      }

      void
      notify(DomainObjects::State::ViewCoordinates args) {
        m_callLis->notify(args.m_viewPosX, args.m_viewPosY, args.m_viewMagnification);
      }
    private:
      std::shared_ptr<Common::IListener<float, float, float>> m_callLis;
    };
  }

  DocumentViewStateService::DocumentViewStateService(
    Common::Model::ICrudRepository<Common::Handle, DomainObjects::State::DocumentViewState> *
      documentViewStateRepository
  )
    : m_documentViewStateRepository(documentViewStateRepository),
      m_nextViewHandle(0)
  {
  }

  Common::Handle
  DocumentViewStateService::addView(
    Common::Handle imageHandle,
    float anchorX,
    float anchorY,
    float anchorMag
  ) {
    Common::Handle rv(m_nextViewHandle++);

    auto state = std::make_unique<DomainObjects::State::DocumentViewState>(anchorX, anchorY,
      anchorMag);
    m_documentViewStateRepository->insert(rv, std::move(state));

    return rv;
  }

  float
  DocumentViewStateService::getViewingPointX(Common::Handle viewHandle) const {
    return m_documentViewStateRepository->retrieve(viewHandle)->get().m_viewPosX;
  }

  float
  DocumentViewStateService::getViewingPointY(Common::Handle viewHandle) const {
    return m_documentViewStateRepository->retrieve(viewHandle)->get().m_viewPosY;
  }

  float
  DocumentViewStateService::getViewingPointMagnification(Common::Handle viewHandle) const {
    return m_documentViewStateRepository->retrieve(viewHandle)->get().m_viewMagnification;
  }

  void
  DocumentViewStateService::setViewingPointX(Common::Handle viewHandle, float x) {
    auto p = m_documentViewStateRepository->retrieve(viewHandle);
    auto val = p->get();
    val.m_viewPosX = x;
    p->set(val);
    m_documentViewStateRepository->update(viewHandle, *p);
  }

  void
  DocumentViewStateService::setViewingPointY(Common::Handle viewHandle, float y) {
    auto p = m_documentViewStateRepository->retrieve(viewHandle);
    auto val = p->get();
    val.m_viewPosY = y;
    p->set(val);
    m_documentViewStateRepository->update(viewHandle, *p);
  }

  void
  DocumentViewStateService::setViewingPointMagnification(Common::Handle viewHandle, float mag) {
    auto p = m_documentViewStateRepository->retrieve(viewHandle);
    auto val = p->get();
    val.m_viewMagnification = mag;
    p->set(val);
    m_documentViewStateRepository->update(viewHandle, *p);
  }

  void
  DocumentViewStateService::setViewingPointPos(Common::Handle viewHandle, float x, float y) {
    auto p = m_documentViewStateRepository->retrieve(viewHandle);
    auto val = p->get();
    val.m_viewPosX = x;
    val.m_viewPosY = y;
    p->set(val);
    m_documentViewStateRepository->update(viewHandle, *p);
  }

  void
  DocumentViewStateService::setViewingPoint(Common::Handle viewHandle, float x, float y, float mag)
  {
    auto p = m_documentViewStateRepository->retrieve(viewHandle);
    auto val = p->get();
    val.m_viewPosX = x;
    val.m_viewPosY = y;
    val.m_viewMagnification = mag;
    p->set(val);
    m_documentViewStateRepository->update(viewHandle, *p);
  }

  Common::PIConnection
  DocumentViewStateService::addViewingPointListener(
    Common::Handle viewHandle,
    std::shared_ptr<Common::IListener<float, float, float>> listener
  ) {
    auto p = m_documentViewStateRepository->retrieve(viewHandle);
    auto wrappedListener = std::make_shared<Impl::WrappedListener>(listener);
    return p->addListener(wrappedListener);
  }
}
