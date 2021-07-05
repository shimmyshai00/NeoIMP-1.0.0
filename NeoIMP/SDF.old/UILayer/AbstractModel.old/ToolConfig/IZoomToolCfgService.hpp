#ifndef SDF_UILAYER_ABSTRACTMODEL_TOOLCONFIG_IZOOMTOOLSERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_TOOLCONFIG_IZOOMTOOLSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IZoomToolCfgService.hpp
 * PURPOSE: Defines the IZoomToolCfgService interface.
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
#include <SDF/UILayer/AbstractModel/Events/ToolEvent.hpp>

namespace SDF::UILayer::AbstractModel::ToolConfig {
  // Class:      IZoomToolCfgService
  // Purpose:    Defines the interface for configuring the zoom tool.
  // Parameters: None.
  class IZoomToolCfgService : public Interfaces::IObservable<Events::ZoomToolEvent> {
  public:
    virtual ~IZoomToolCfgService() = default;

    // Function:   setMode
    // Purpose:    Set the mode of the zoom tool (zoom in, zoom out, or zoom to original size).
    // Parameters: mode - The zoom tool mode.
    // Returns:    None.
    virtual void
    setMode(Properties::ZoomMode mode) = 0;

    // Function:   setZoomStep
    // Purpose:    Set the magnification step for each click of the zoom tool (only meaningful for zoom in/out modes).
    // Parameters: step - The zoom step, in "times".
    // Returns:    None.
    virtual void
    setZoomStep(float step) = 0;

    // Function:   getMode
    // Purpose:    Get the mode of the zoom tool.
    // Parameters: None.
    // Returns:    The current zoom tool mode.
    virtual Properties::ZoomMode
    getMode() const = 0;

    // Function:   getZoomStep
    // Purpose:    Get the zoom step of the zoom tool.
    // Parameters: none.
    // Returns:    The current zoom step.
    virtual float
    getZoomStep() const = 0;
  };
}

#endif
