/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ApplicationController.cpp
 * PURPOSE: Handles events from the application view.
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

#include <ApplicationController.hpp>

#include <Framework/MVCViewUnit.hpp>

#include <View/IViewFactory.hpp>
#include <View/IApplicationView.hpp>

//#include <NewDocumentController.hpp>
//#include <FileCommandsController.hpp>

#include <ControllerFactory.hpp>

namespace SDF::Impl::UILayer::Impl::Controller {
  ApplicationController::ApplicationController(View::IApplicationView *applicationView)
    : m_applicationView(applicationView)
  {
    m_applicationViewConn = m_applicationView->attachObserver(this);
  }

  ApplicationController::~ApplicationController() {}

  void ApplicationController::receiveMessage(void *sender, std::string message) {}

  void ApplicationController::notify(View::Events::ExitCommandEvent event) {
    // NB: will need smth more thorough eventually
    m_viewUnit->removeSelf();
  }
}
