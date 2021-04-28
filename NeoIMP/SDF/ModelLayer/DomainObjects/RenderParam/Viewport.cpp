
/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Viewport.cpp
 * PURPOSE: Defines the Viewport class.
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

#include <Viewport.hpp>

namespace SDF::ModelLayer::DomainObjects::RenderParam {
  Viewport::Viewport(int id,
                     float centerX,
                     float centerY,
                     float magnif
                    )
    : m_id(id),
      m_centerX(centerX),
      m_centerY(centerY),
      m_magnif(magnif)
  {
  }

  int
  Viewport::getId() const {
    return m_id;
  }

  float
  Viewport::getCenterX() const {
    return m_centerX;
  }

  float
  Viewport::getCenterY() const {
    return m_centerY;
  }

  float
  Viewport::getMagnification() const {
    return m_magnif;
  }

  void
  Viewport::setCenterX(float centerX) {
    m_centerX = centerX;
  }

  void
  Viewport::setCenterY(float centerY) {
    m_centerY = centerY;
  }

  void
  Viewport::setMagnification(float magnif) {
    m_magnif = magnif;
  }
}
