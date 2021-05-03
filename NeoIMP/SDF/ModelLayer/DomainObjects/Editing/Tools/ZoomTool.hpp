#ifndef SDF_MODELLAYER_DOMAINOBJECTS_EDITING_TOOLS_ZOOMTOOL_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_EDITING_TOOLS_ZOOMTOOL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ZoomTool.hpp
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

#include <SDF/ModelLayer/Services/AbstractDomain/ITool.hpp>

#include <SDF/ModelLayer/Math/Coord.hpp>

namespace SDF::ModelLayer {
  namespace Services::AbstractDomain {
    class IImage;
    class IImageDelta;
  }

  namespace DomainObjects::Editing::Tools {
    // Class:      ZoomTool
    // Purpose:    Defines an editing tool that zooms the view in and out of the image.
    // Parameters: None.
    class ZoomTool : public Services::AbstractDomain::ITool {
    public:
      ZoomTool(int id);

      int
      getId() const;

      void
      beginApplication(Services::AbstractDomain::IImage *image);

      void
      applyAt(float x, float y);

      std::unique_ptr<Services::AbstractDomain::IImageDelta>
      commit();
    private:
      int m_id;

      Services::AbstractDomain::IImage *m_image;
      Math::Coord<float> m_applicationPoint;
    };
  }
}

#endif
