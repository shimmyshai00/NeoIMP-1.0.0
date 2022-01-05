#ifndef SDF_UILAYER_GUI_CONTROLLER_IGUICONTROLLER_HPP
#define SDF_UILAYER_GUI_CONTROLLER_IGUICONTROLLER_HPP

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

namespace SDF::UILayer::Gui::Controller {
  // Class:   IGuiController
  // Purpose: Provides an interface describing the commands we want to issue to
  //          the GUI at a coarse scale, i.e. for obtaining and dismissing
  //          views. This allows us to offload the layout of the GUI, i.e. which
  //          views compose with which, mostly outside the controller section.
  class IGuiController {
  public:
    virtual ~IGuiController() = default;

    // Function:   startGui
    // Purpose:    Activates the GUI, emplacing the main view.
    // Parameters: None.
    // Returns:    None.
    virtual void
    startGui() = 0;

    // Function:   closeGui
    // Purpose:    Terminates the GUI session.
    // Parameters: None.
    // Returns:    None.
    virtual void
    closeGui() = 0;
  };
}

#endif
