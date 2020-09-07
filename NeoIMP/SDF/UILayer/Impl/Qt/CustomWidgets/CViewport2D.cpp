/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CViewport2D.cpp
 * PURPOSE: Implementation of the coordinate calculator for a 2-dimensional viewport.
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

#include <SDF/UILayer/Impl/Qt/CustomWidgets/CViewport2D.hpp>

namespace SDF {
  namespace UILayer {
    namespace Impl::Qt::CustomWidgets::Detail {
      CViewport2D::CViewport2D(float viewportCenterXPos, float viewportCenterYPos,
        float viewportSizeX, float viewportSizeY, float viewportMagnification)
      : m_centerX(viewportCenterXPos),
        m_centerY(viewportCenterYPos),
        m_sizeX(viewportSizeX),
        m_sizeY(viewportSizeY),
        m_magnificationFactor(viewportMagnification)
        {
        }

      float CViewport2D::getViewportX1InImageSpace() const {
        return m_centerX - ((m_sizeX / 2.0) / m_magnificationFactor);
      }

      float CViewport2D::getViewportY1InImageSpace() const {
        return m_centerY - ((m_sizeY / 2.0) / m_magnificationFactor);
      }

      float CViewport2D::getViewportX2InImageSpace() const {
        return m_centerX + ((m_sizeX / 2.0) / m_magnificationFactor);
      }

      float CViewport2D::getViewportY2InImageSpace() const {
        return m_centerY + ((m_sizeY / 2.0) / m_magnificationFactor);
      }

      float CViewport2D::getViewportXOfImageSpacePoint(float imageSpaceX, float imageSpaceY) const {
        return (imageSpaceX - m_centerX) * m_magnificationFactor;
      }

      float CViewport2D::getViewportYOfImageSpacePoint(float imageSpaceX, float imageSpaceY) const {
        return (imageSpaceY - m_centerY) * m_magnificationFactor;
      }

      float CViewport2D::getImageSpaceXOfViewportPoint(float viewportX, float viewportY) const {
        return m_centerX + (viewportX / m_magnificationFactor);
      }

      float CViewport2D::getImageSpaceYOfViewportPoint(float viewportX, float viewportY) const {
        return m_centerY + (viewportY / m_magnificationFactor);
      }
    }
  }
}
