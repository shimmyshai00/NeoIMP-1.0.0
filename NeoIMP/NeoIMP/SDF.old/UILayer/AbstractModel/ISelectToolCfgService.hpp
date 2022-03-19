#ifndef SDF_UILAYER_ABSTRACTMODEL_ISELECTTOOLCFGSERVICE_HPP
#define SDF_UILAYER_ABSTRACTMODEL_ISELECTTOOLCFGSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ISelectToolCfgService.hpp
 * PURPOSE: Defines the ISelectToolCfgService interface.
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
#include <SDF/UILayer/AbstractModel/Properties/Tool/SelectMode.hpp>

namespace SDF::UILayer::AbstractModel {
  // Class:      ISelectToolCfgService
  // Purpose:    Defines the interface for configuring the selection tool.
  // Parameters: None.
  class ISelectToolCfgService : public Interfaces::IObservable<Events::SelectToolEvent> {
  public:
    virtual ~ISelectToolCfgService() = default;

    // Function:   setMode
    // Purpose:    Set the mode of the select tool (i.e. the marquee type).
    // Parameters: mode - The select tool mode.
    // Returns:    None.
    virtual void
    setMode(Properties::Tool::SelectMode mode) = 0;

    // Function:   getMode
    // Purpose:    Get the mode of the select tool.
    // Parameters: None.
    // Returns:    The current select tool mode.
    virtual Properties::Tool::SelectMode
    getMode() const = 0;
  };
}

#endif
