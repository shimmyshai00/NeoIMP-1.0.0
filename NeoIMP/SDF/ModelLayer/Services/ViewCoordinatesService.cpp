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

#include "../../Common/FunctionListener.hpp"

namespace SDF::ModelLayer::Services {
  ViewCoordinatesService::ViewCoordinatesService(
    Repositories::IRepository<DomainObjects::Engine::Viewpoint> *viewpointRepository
  )
    : m_viewpointRepository(viewpointRepository)
  {
  }

  float
  ViewCoordinatesService::getViewingPointX(Common::Handle imageHandle) const {
    return m_viewpointRepository->retrieve(imageHandle)->m_position.getX();
  }

  float
  ViewCoordinatesService::getViewingPointY(Common::Handle imageHandle) const {
    return m_viewpointRepository->retrieve(imageHandle)->m_position.getY();
  }

  float
  ViewCoordinatesService::getViewingPointMagnification(Common::Handle imageHandle) const {
    return m_viewpointRepository->retrieve(imageHandle)->m_magnification;
  }

  void
  ViewCoordinatesService::setViewingPointX(Common::Handle imageHandle,
                                           float x
                                          )
  {
    auto vp = m_viewpointRepository->retrieve(imageHandle);
    vp->m_position.setX(x);
    m_viewpointRepository->update(imageHandle, vp);

    m_viewpointListeners.notify(imageHandle, vp->m_position.getX(), vp->m_position.getY(),
      vp->m_magnification);
  }

  void
  ViewCoordinatesService::setViewingPointY(Common::Handle imageHandle,
                                           float y
                                          )
  {
    auto vp = m_viewpointRepository->retrieve(imageHandle);
    vp->m_position.setY(y);
    m_viewpointRepository->update(imageHandle, vp);

    m_viewpointListeners.notify(imageHandle, vp->m_position.getX(), vp->m_position.getY(),
      vp->m_magnification);
  }


  void
  ViewCoordinatesService::setViewingPointMagnification(Common::Handle imageHandle,
                                                       float mag
                                                      )
  {
    auto vp = m_viewpointRepository->retrieve(imageHandle);
    vp->m_magnification = mag;
    m_viewpointRepository->update(imageHandle, vp);

    m_viewpointListeners.notify(imageHandle, vp->m_position.getX(), vp->m_position.getY(),
      vp->m_magnification);
  }

  void
  ViewCoordinatesService::setViewingPointPos(Common::Handle imageHandle,
                                             float x,
                                             float y
                                            )
  {
    auto vp = m_viewpointRepository->retrieve(imageHandle);
    vp->m_position = Math::Coord<float>(x, y);
    m_viewpointRepository->update(imageHandle, vp);

    m_viewpointListeners.notify(imageHandle, vp->m_position.getX(), vp->m_position.getY(),
      vp->m_magnification);
  }

  void
  ViewCoordinatesService::setViewingPoint(Common::Handle imageHandle,
                                          float x,
                                          float y,
                                          float mag
                                         )
  {
    auto vp = m_viewpointRepository->retrieve(imageHandle);

    vp->m_position = Math::Coord<float>(x, y);
    vp->m_magnification = mag;

    m_viewpointRepository->update(imageHandle, vp);

    m_viewpointListeners.notify(imageHandle, vp->m_position.getX(), vp->m_position.getY(),
      vp->m_magnification);
  }

  Common::PIConnection
  ViewCoordinatesService::addViewingPointListener(
    Common::Handle imageHandle,
    std::shared_ptr<Common::IListener<float, float, float>> listener
  ) {
    if(m_viewpointRepository->has(imageHandle)) {
      return m_viewpointListeners.addListener(imageHandle, listener);
    } else {
      // TBA: throw
    }
  }
}
