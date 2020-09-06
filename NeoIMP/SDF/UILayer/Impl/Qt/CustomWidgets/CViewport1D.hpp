#ifndef SDF_UILAYER_IMPL_QT_CUSTOMWIDGETS_CVIEWPORT1D_HPP
#define SDF_UILAYER_IMPL_QT_CUSTOMWIDGETS_CVIEWPORT1D_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    CViewport1D.hpp
 * PURPOSE: A coordinate calculator for a 1-dimensional viewport. Used for the ruler.
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
      class CViewport1D {
      public:
        CViewport1D(float viewportCenterPos, float viewportSize, float viewportMagnification);
        ~CViewport1D() {}

        float getViewportLeftInImageSpace() const;
        float getViewportRightInImageSpace() const;

        float getViewportCoordOfImageSpacePoint(float imageSpaceCoord) const;
        float getImageSpaceCoordOfViewportPoint(float viewportCoord) const;
      private :
        float m_leftImagePos;
        float m_rightImagePos;
        float m_viewportSize;
      };
    }
  }
}
#endif
