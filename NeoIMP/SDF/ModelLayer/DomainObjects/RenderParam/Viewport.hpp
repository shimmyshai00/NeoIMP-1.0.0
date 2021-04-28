#ifndef SDF_MODELLAYER_DOMAINOBJECTS_RENDERPARAM_VIEWPORT_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_RENDERPARAM_VIEWPORT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Viewport.hpp
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

#include <SDF/ModelLayer/Services/AbstractDomain/IDocumentViewParams.hpp>

namespace SDF::ModelLayer::DomainObjects::RenderParam {
  // Class:      Viewport
  // Purpose:    Defines a viewport for rendering an image document.
  // Parameters: None.
  class Viewport : public Services::AbstractDomain::IDocumentViewParams {
  public:
    // Function:   Viewport
    // Purpose:    Construct a new viewport with the given parameters.
    // Parameters: id - The unique ID of this domain object.
    //             centerX - The X-coordinate of the view center.
    //             centerY - The Y-coordinate of the view center.
    //             magnif - The magnification of the viewport.
    Viewport(int id,
             float centerX,
             float centerY,
             float magnif
            );

    int
    getId() const;

    float
    getCenterX() const;

    float
    getCenterY() const;

    float
    getMagnification() const;

    void
    setCenterX(float centerX);

    void
    setCenterY(float centerY);

    void
    setMagnification(float magnif);
  private:
    int m_id;
    float m_centerX;
    float m_centerY;
    float m_magnif;
  };
}

#endif
