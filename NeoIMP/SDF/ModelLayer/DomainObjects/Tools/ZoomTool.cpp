/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ZoomTool.cpp
 * PURPOSE: Defines the ZoomTool class.
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

#include <SDF/ModelLayer/DomainObjects/Tools/ZoomTool.hpp>

#include <algorithm>

namespace SDF::ModelLayer::DomainObjects::Tools {
  ZoomTool::ZoomTool(int id)
    : m_id(id),
      m_image(nullptr),
      m_applicationPoint(0.0f, 0.0f)
  {
  }

  int
  ZoomTool::getId() const {
    return m_id;
  }

  void
  ZoomTool::beginApplication(Services::AbstractDomain::IImage *image) {
    m_image = image;
  }

  void
  ZoomTool::applyAt(float x, float y) {
    m_applicationPoint = Math::Coord<float>(x, y);
  }

  void
  ZoomTool::commit() {
    // Zoom into the given application point.
    m_image->setViewCenter(m_applicationPoint);

    float curMagnif(m_image->getViewMagnification());
    float newMagnif(std::min(2.0f * curMagnif, 128.0f)); // max zoom: 128x or 12800%

    m_image->setViewMagnification(newMagnif);
  }
}
