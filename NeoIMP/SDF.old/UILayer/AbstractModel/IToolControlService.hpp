#ifndef SDF_UILAYER_ABSTRACTMODEL_ITOOLCONTROLSERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_ITOOLCONTROLSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IToolControlService.hpp
 * PURPOSE: Defines the IToolControlService interface.
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

#include <SDF/UILayer/AbstractModel/Properties/ColorModel.hpp>
#include <SDF/UILayer/AbstractModel/Properties/BitDepth.hpp>

namespace SDF::UILayer::AbstractModel {
  // Class:      IToolControlService
  // Purpose:    Defines an interface for a model layer service to control which editing tool is being used.
  // Parameters: None.
  class IToolControlService {
  public:
    virtual ~IToolControlService() = default;

    // Function:   getActiveEditingTool
    // Purpose:    Get the currently-active editing tool.
    // Parameters: None.
    // Returns:    The tool enum value for the active editing tool.
    virtual Properties::Tool
    getActiveEditingTool() const = 0;

    // Function:   setActiveEditingTool
    // Purpose:    Set the currently-active editing tool.
    // Parameters: tool - The tool to set as active.
    // Returns:    None.
    virtual void
    setActiveEditingTool(Properties::Tool tool) = 0;
  };
}

#endif
