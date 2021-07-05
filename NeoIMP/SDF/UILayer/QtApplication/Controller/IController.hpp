#ifndef SDF_UILAYER_QTAPPLICATION_CONTROLLER_ICONTROLLER_HPP
#define SDF_UILAYER_QTAPPLICATION_CONTROLLER_ICONTROLLER_HPP

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

#include <memory>

namespace SDF::UILayer::QtApplication::View {
  // Class:      IController
  // Purpose:    Defines an interface for Qt MVC controllers.
  // Parameters: EventT - The type of event handled by this controller.
  template<class EventT>
  class IController {
  public:
    virtual ~IController() = default;

    // Function:   handleEvent
    // Purpose:    Handle a view-generated event.
    // Parameters: event - The event to handle.
    // Returns:    None.
    virtual void
    handleEvent(std::shared_ptr<EventT> event) = 0;
  };
}

#endif
