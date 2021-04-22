#ifndef SDF_UILAYER_GUI_IGUICONTROLLER_HPP
#define SDF_UILAYER_GUI_IGUICONTROLLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IGuiController.hpp
 * PURPOSE: Defines the IGuiController interface.
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

#include <vector>
#include <string>

namespace SDF::UILayer::Gui {
  class IGuiElement;

  // Class:      IGuiController
  // Purpose:    Provides an interface for the front-end GUI controller, which adds and removes different GUI elements.
  // Parameters: None.
  class IGuiController {
  public:
    virtual ~IGuiController() = default;

    // Function:   getGuiElementNames
    // Purpose:    Get the names of the GUI elements available in this controller.
    // Parameters: None.
    // Returns:    The list of all available elements.
    virtual std::vector<std::string>
    getGuiElementNames() = 0;

    // Function:   getGuiElementByName
    // Purpose:    Access a specific GUI element.
    // Parameters: name - The name of the element to access.
    // Returns:    The IGuiElement interface to this element.
    virtual IGuiElement *
    getGuiElementByName(std::string name) = 0;
  };
}

#endif
