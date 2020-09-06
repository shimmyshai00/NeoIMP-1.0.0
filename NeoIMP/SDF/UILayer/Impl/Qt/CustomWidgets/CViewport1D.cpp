/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CViewport1D.cpp
 * PURPOSE: Implementation of the coordinate calculator for a 1-dimensional viewport.
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

#include <SDF/UILayer/Impl/Qt/CustomWidgets/CViewport1D.hpp>

namespace SDF {
  namespace UILayer {
    namespace Impl::Qt::CustomWidgets::Detail {
      CViewport1D::CViewport1D(float viewportCenterPos, float viewportSize, float viewportMagnification)
      : m_leftImagePos(viewportCenterPos - ((viewportSize / 2.0f) / viewportMagnification)),
        m_rightImagePos(viewportCenterPos + ((viewportSize / 2.0f) / viewportMagnification)),
        m_viewportSize(viewportSize)
        {
        }

      float CViewport1D::getViewportLeftInImageSpace() const {
        return m_leftImagePos;
      }

      float CViewport1D::getViewportRightInImageSpace() const {
        return m_rightImagePos;
      }

      float CViewport1D::getViewportCoordOfImageSpacePoint(float imageSpaceCoord) const {
        return ((imageSpaceCoord - m_leftImagePos) / (m_rightImagePos - m_leftImagePos)) * m_viewportSize;
      }

      float CViewport1D::getImageSpaceCoordOfViewportPoint(float viewportCoord) const {
        return m_leftImagePos + ((viewportCoord / m_viewportSize) * (m_rightImagePos - m_leftImagePos));
      }
    }
  }
}
