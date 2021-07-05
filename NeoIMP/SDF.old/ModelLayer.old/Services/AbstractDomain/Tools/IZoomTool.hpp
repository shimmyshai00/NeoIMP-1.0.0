#ifndef SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_TOOLS_IZOOMTOOL_HPP
#define SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_TOOLS_IZOOMTOOL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IZoomTool.hpp
 * PURPOSE: Defines the IZoomTool interface.
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
#include <SDF/UILayer/AbstractModel/ToolConfig/Properties/ZoomMode.hpp>

namespace SDF::ModelLayer::Services::AbstractDomain::Tools {
  // Class:      IZoomTool
  // Purpose:    Defines the configuration interface for the zoom tool.
  // Parameters: None.
  class IZoomTool : public ITool {
  public:
    virtual ~IZoomTool() = default;

    // Function:   getMode
    // Purpose:    Gets the zooming mode.
    // Parameters: None.
    // Returns:    The current zooming mode.
    virtual UILayer::AbstractModel::ToolConfig::Properties::ZoomMode
    getMode() const = 0;

    // Function:   getStep
    // Purpose:    Gets the magnification step.
    // Parameters: None.
    // Returns:    The size of the magnification step.
    virtual float
    getStep() const = 0;

    // Function:   setMode
    // Purpose:    Sets the zooming mode.
    // Parameters: mode - The zoom mode to use.
    // Returns:    None.
    virtual void
    setMode(UILayer::AbstractModel::ToolConfig::Properties::ZoomMode mode) = 0;

    // Function:   setStep
    // Purpose:    Set the size of the magnification step (i.e. the magnification on a single click of the tool).
    // Parameters: step - The size of the magnification step in "times".
    // Returns:    None.
    virtual void
    setStep(float step) = 0;
  };
}

#endif
