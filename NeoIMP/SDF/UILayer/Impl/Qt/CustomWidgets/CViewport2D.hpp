#ifndef SDF_UILAYER_IMPL_QT_CUSTOMWIDGETS_CVIEWPORT2D_HPP
#define SDF_UILAYER_IMPL_QT_CUSTOMWIDGETS_CVIEWPORT2D_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CViewport2D.hpp
 * PURPOSE: A coordinate calculator for a 2-dimensional viewport. Used for the image view.
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

namespace SDF {
  namespace UILayer {
    namespace Impl::Qt::CustomWidgets::Detail {
      class CViewport2D {
      public:
        CViewport2D(float viewportCenterXPos, float viewportCenterYPos, float viewportSizeX, float viewportSizeY,
          float viewportMagnification);
        ~CViewport2D() {}

        float getViewportX1InImageSpace() const;
        float getViewportY1InImageSpace() const;
        float getViewportX2InImageSpace() const;
        float getViewportY2InImageSpace() const;

        float getViewportXOfImageSpacePoint(float imageSpaceX, float imageSpaceY) const;
        float getViewportYOfImageSpacePoint(float imageSpaceX, float imageSpaceY) const;
        float getImageSpaceXOfViewportPoint(float viewportX, float viewportY) const;
        float getImageSpaceYOfViewportPoint(float viewportX, float viewportY) const;
      private:
        float m_centerX;
        float m_centerY;
        float m_sizeX;
        float m_sizeY;
        float m_magnificationFactor;
      };
    }
  }
}

#endif
