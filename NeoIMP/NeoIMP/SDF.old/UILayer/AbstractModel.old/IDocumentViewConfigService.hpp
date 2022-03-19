#ifndef SDF_UILAYER_ABSTRACTMODEL_IDOCUMENTVIEWCONFIGSERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_IDOCUMENTVIEWCONFIGSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IDocumentViewConfigService.hpp
 * PURPOSE: Defines the IDocumentViewConfigService interface.
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

#include <SDF/Interfaces/IObservable.hpp>

#include <SDF/UILayer/AbstractModel/Handle.hpp>
#include <SDF/UILayer/AbstractModel/Events/ViewportEvent.hpp>

namespace SDF::UILayer::AbstractModel {
  // Class:      IDocumentViewConfigService
  // Purpose:    Defines an interface for a service which holds geometric parameters describing how a document is to be
  //             viewed. Again, this nominally mixes a little UI-related data into the model layer but we don't really
  //             have a better place for it. This is needed to ensure that tools such as the zoom and selection tool
  //             which only alter the viewport can go through the same tool subsystem as other editing tools do and
  //             thus helps keep things harmonized.
  // Parameters: None.
  class IDocumentViewConfigService : public Interfaces::IObservable<Events::ViewportEvent> {
  public:
    virtual ~IDocumentViewConfigService() = default;

    // Function:   getDocumentCenterX
    // Purpose:    Get the X-coordinate of the view center of a document.
    // Parameters: handle - The document handle.
    // Returns:    The X-coordinate in pixels.
    virtual float
    getDocumentCenterX(Handle handle) const = 0;

    // Function:   getDocumentCenterY
    // Purpose:    Get the Y-coordinate of the view center of a document.
    // Parameters: handle - The document handle.
    // Returns:    The Y-coordinate in pixels.
    virtual float
    getDocumentCenterY(Handle handle) const = 0;

    // Function:   getDocumentMagnification
    // Purpose:    Get the magnification of the view center of a document.
    // Parameters: handle - The document handle.
    // Returns:    The magnification factor (dimensionless).
    virtual float
    getDocumentMagnification(Handle handle) const = 0;

    // Function:   setDocumentCenterX
    // Purpose:    Set the X-coordinate of the view center of a document.
    // Parameters: handle - The document handle.
    //             centerX - The new coordinate value.
    // Returns:    None.
    virtual void
    setDocumentCenterX(Handle handle, float centerX) = 0;

    // Function:   setDocumentCenterY
    // Purpose:    Set the Y-coordinate of the view center of a document.
    // Parameters: handle - The document handle.
    //             centerY - The new coordinate value.
    // Returns:    None.
    virtual void
    setDocumentCenterY(Handle handle, float centerY) = 0;

    // Function:   setDocumentMagnification
    // Purpose:    Set the magnification factor for viewing a documenet.
    // Parameters: handle - The document handle.
    //             magnification - The new magnification.
    // Returns:    None.
    virtual void
    setDocumentMagnification(Handle handle, float magnification) = 0;
  };
}

#endif
