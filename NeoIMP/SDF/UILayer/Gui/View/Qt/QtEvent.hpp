#ifndef SDF_UILAYER_GUI_VIEW_QT_QTEVENT_HPP
#define SDF_UILAYER_GUI_VIEW_QT_QTEVENT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    QtEvent.hpp
 * PURPOSE: Defines the QtEvent template.
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

#include "../../../../Patterns/IConnection.hpp"
#include "../../../Mvc/IController.hpp"

#include <list>
#include <memory>

namespace SDF::UILayer::Gui::View::Qt {
  // Class:      QtEvent
  // Purpose:    Provides an event object which can be triggered to send messages to attached
  //             controllers. Features safe exception catching with error message display.
  // Parameters: ControllerArgs - The controller arguments.
  template<class ... ControllerArgs>
  class QtEvent {
  public:
    QtEvent();

    Patterns::PIConnection
    hook(std::unique_ptr<Mvc::IController<ControllerArgs...>> controller);

    void
    trigger(ControllerArgs... args);
  private:
    std::list<std::unique_ptr<Mvc::IController<ControllerArgs...>>>
      m_controllers;
  };
}

#include "QtEvent.tpp"

#endif
