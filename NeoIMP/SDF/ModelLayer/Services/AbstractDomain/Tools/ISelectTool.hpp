#ifndef SDF_MODELLAYER_SERVICE_ABSTRACTDOMAIN_TOOLS_ISELECTTOOL_HPP
#define SDF_MODELLAYER_SERVICE_ABSTRACTDOMAIN_TOOLS_ISELECTTOOL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ISelectTool.hpp
 * PURPOSE: Defines the ISelectTool interface.
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
#include <SDF/UILayer/AbstractModel/ToolConfig/Properties/SelectMode.hpp>

namespace SDF::ModelLayer::Services::AbstractDomain::Tools {
  // Class:      ISelectTool
  // Purpose:    Defines the configuration interface for the selection tool.
  // Parameters: None.
  class ISelectTool : public ITool {
  public:
    virtual ~ISelectTool() = default;

    // Function:   getMode
    // Purpose:    Gets the selection mode.
    // Parameters: None.
    // Returns:    The current selection mode.
    virtual UILayer::AbstractModel::ToolConfig::Properties::SelectMode
    getMode() const = 0;

    // Function:   setMode
    // Purpose:    Sets the selection mode.
    // Parameters: mode - The selection mode to use.
    // Returns:    None.
    virtual void
    setMode(UILayer::AbstractModel::ToolConfig::Properties::SelectMode mode) = 0;
  };
}

#endif
