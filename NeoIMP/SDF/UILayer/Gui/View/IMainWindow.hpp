#ifndef SDF_UILAYER_GUI_VIEW_IMAINWINDOW_HPP
#define SDF_UILAYER_GUI_VIEW_IMAINWINDOW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IMainWindow.hpp
 * PURPOSE: Defines the IMainWindow interface.
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

#include "../../../Patterns/IConnection.hpp"
#include "../../Mvc/IView.hpp"
#include "../../Mvc/IController.hpp"

#include <memory>

namespace SDF::UILayer::Gui::View {
  // Class:      IMainWindow
  // Purpose:    Defines the widget system-agnostic interface for the main window.
  // Parameters: None.
  class IMainWindow : public virtual Mvc::IView {
  public:
    virtual ~IMainWindow() = default;

    // Event hooks.
    virtual Patterns::PIConnection
    hookOnNew(std::unique_ptr<Mvc::IController<>> controller) = 0;

    virtual Patterns::PIConnection
    hookOnExit(std::unique_ptr<Mvc::IController<>> controller) = 0;
  };
}

#endif
