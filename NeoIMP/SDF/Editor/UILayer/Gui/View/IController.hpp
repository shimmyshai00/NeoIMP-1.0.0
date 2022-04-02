#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_ICONTROLLER_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_ICONTROLLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IController.hpp
 * PURPOSE: Defines the IController interface.
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

namespace SDF::Editor::UILayer::Gui::View {
  // Class:      IController
  // Purpose:    Defines an interface for GUI controllers.
  // Parameters: TriggerArgs - The arguments to pass when triggering the controller.
  template<class ... TriggerArgs>
  class IController {
  public:
    virtual ~IController() = default;

    // Function:   onTrigger
    // Purpose:    Trigger the event represented by this controller.
    // Parameters: args - The arguments to pass.
    // Returns:    None.
    virtual void
    onTrigger(TriggerArgs... a_args) = 0;
  };
}

#endif
