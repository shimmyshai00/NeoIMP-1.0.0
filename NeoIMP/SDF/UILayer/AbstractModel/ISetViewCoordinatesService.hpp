#ifndef SDF_UILAYER_ABSTRACTMODEL_ISETVIEWCOORDINATESSERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_ISETVIEWCOORDINATESSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ISetViewCoordinatesService.hpp
 * PURPOSE: Defines the ISetViewCoordinatesService interface.
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

#include "../../Common/Handle.hpp"

namespace SDF::UILayer::AbstractModel {
  // Class:      ISetViewCoordinatesService
  // Purpose:    Defines the interface for an MVC service to set the viewing coordinates on
  //             image documents.
  // Parameters: None.
  class ISetViewCoordinatesService {
  public:
    virtual ~ISetViewCoordinatesService() = default;

    // Function:   setViewingPointX
    // Purpose:    Set the X-coordinate of the viewing point of an image document.
    // Parameters: imageHandle - The handle to the image document.
    //             x - The new X-coordinate.
    // Returns:    None.
    virtual void
    setViewingPointX(Common::Handle imageHandle,
                     float x
                    ) = 0;

    // Function:   setViewingPointY
    // Purpose:    Set the Y-coordinate of the viewing point.
    // Parameters: imageHandle - The handle to the image document.
    //             y - The new Y-coordinate.
    // Returns:    None.
    virtual void
    setViewingPointY(Common::Handle imageHandle,
                     float y
                    ) = 0;

    // Function:   setViewingPointMagnification
    // Purpose:    Sets the magnification factor around the viewing point.
    // Parameters: imageHandle - The handle of the image document.
    //             mag - The magnification to set.
    // Returns:    None.
    virtual void
    setViewingPointMagnification(Common::Handle imageHandle,
                                 float mag
                                ) = 0;

    // Function:   setViewingPointPos
    // Purpose:    Sets both coordinates simultaneously so as to trigger listeners only once.
    // Parameters: imageHandle - The handle to the image document.
    //             x, y - The new coordinates.
    // Returns:    None.
    virtual void
    setViewingPointPos(Common::Handle imageHandle,
                       float x,
                       float y
                      ) = 0;

    // Function:   setViewingPoint
    // Purpose:    Set the whole thing simultaneously.
    // Parameters: imageHandle - The handle to the image document.
    //             x, y - The new coordinates.
    //             mag - The new magnification.
    // Returns:    None.
    virtual void
    setViewingPoint(Common::Handle imageHandle,
                    float x,
                    float y,
                    float mag
                   ) = 0;
  };
}

#endif
