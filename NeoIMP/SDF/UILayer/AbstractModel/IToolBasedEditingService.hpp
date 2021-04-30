#ifndef SDF_UILAYER_ABSTRACTMODEL_ITOOLBASEDEDITINGSERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_ITOOLBASEDEDITINGSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IToolBasedEditingService.hpp
 * PURPOSE: Defines the IToolBasedEditingService interface.
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

#include <SDF/UILayer/AbstractModel/Handle.hpp>
#include <SDF/UILayer/AbstractModel/Properties/Tool.hpp>

namespace SDF::UILayer::AbstractModel {
  // Class:      IToolBasedEditingService
  // Purpose:    Defines a service interface for controlling the image editing tools.
  // Parameters: None.
  class IToolBasedEditingService {
  public:
    virtual ~IToolBasedEditingService() = default;

    // Function:   setActiveTool
    // Purpose:    Sets the currently-active editing tool.
    // Parameters: tool - The enum value of the editing tool to use now.
    // Returns:    None.
    virtual void
    setActiveTool(Properties::Tool tool) = 0;

    // Function:   beginToolApplication
    // Purpose:    Begin applying the current editing tool to a document.
    // Parameters: handle - The handle of the image document for which we will apply the tool to.
    // Returns:    None.
    virtual void
    beginToolApplication(Handle handle) = 0;

    // Function:   applyToolAtPoint
    // Purpose:    Apply the editing tool at a given point on the image for which application has been started with
    //             beginToolApplication.
    // Parameters: x, y - The coordinates to which this tool will be applied.
    // Returns:    None.
    virtual void
    applyToolAtPoint(float x, float y) = 0;

    // Function:   finishToolApplication
    // Purpose:    Finalize the application of an editing tool.
    // Parameters: None.
    // Returns:    None.
    virtual void
    finishToolApplication() = 0;
  };
}

#endif
