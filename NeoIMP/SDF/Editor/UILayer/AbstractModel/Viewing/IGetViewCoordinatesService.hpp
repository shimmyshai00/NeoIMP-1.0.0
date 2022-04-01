#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_VIEWING_IGETVIEWCOORDINATESSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_VIEWING_IGETVIEWCOORDINATESSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IGetViewCoordinatesService.hpp
 * PURPOSE: Defines the IGetViewCoordinatesService interface.
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

#include "../../../../Common/Handle.hpp"
#include "../../../../Common/IConnection.hpp"
#include "../../../../Common/IListener.hpp"

#include <memory>

namespace SDF::Editor::UILayer::AbstractModel::Viewing {
  // Class:      IGetViewCoordinatesService
  // Purpose:    Defines the interface for an MVC service to get the viewing coordinates for
  //             image documents.
  // Parameters: None.
  class IGetViewCoordinatesService {
  public:
    virtual ~IGetViewCoordinatesService() = default;

    // Function:   getViewingPointX
    // Purpose:    Get the X-coordinate of the viewing point of an image document. Note that
    //             the meaning here of a "viewing point" is up to the specific kind of UI
    //             layer to interpret. Here, it's just some reference point indicating the
    //             view location, together with an amount by which the image around it will be
    //             magnified (and tba - rotated).
    // Parameters: viewHandle - The handle to the view (not the image!) to get the coordinates
    //             for.
    // Returns:    The X-coordinate of the viewing point of this image document.
    virtual float
    getViewingPointX(Common::Handle a_viewHandle) const = 0;

    // Function:   getViewingPointY
    // Purpose:    Gets the Y-coordinate of the viewing point.
    // Parameters: viewHandle - The handle to the view (not the image!) to get the coordinates
    //             for.
    // Returns:    The Y-coordinate of the viewing point of this image document.
    virtual float
    getViewingPointY(Common::Handle a_viewHandle) const = 0;

    // Function:   getViewingPointMagnification
    // Purpose:    Gets the magnification factor around the viewing point.
    // Parameters: viewHandle - The handle to the view (not the image!) to get the coordinates
    //             for.
    // Returns:    The magnification around this viewing point.
    virtual float
    getViewingPointMagnification(Common::Handle a_viewHandle) const = 0;

    // Function:   addViewingPointListener
    // Purpose:    Adds a listener to listen to changes in the viewing point for a given
    //             image.
    // Parameters: viewHandle - The handle to the view (not the image!) to get the coordinates
    //             for.
    //             listener - The listener function to attach to this image document.
    // Returns:    A connection object to the given listener.
    virtual Common::PIConnection
    addViewingPointListener(
      Common::Handle a_viewHandle,
      std::shared_ptr<Common::IListener<float, float, float>> a_listener
    ) = 0;
  };
}

#endif
