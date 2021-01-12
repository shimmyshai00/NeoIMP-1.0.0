/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ApplicationController.cpp
 * PURPOSE: The controller for the application view.
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

#include <IUIManager.hpp>

#include <View/IViewFactory.hpp>
#include <View/IApplicationView.hpp>

#include <View/Events/ExitCommandEvent.hpp>

#include <iostream>

namespace SDF::Impl::UILayer::Impl::Controller {
  ApplicationController::ApplicationController(
    IUIManager *uiManager, View::IViewFactory *viewFactory
  )
    : m_uiManager(uiManager),
      m_viewFactory(viewFactory)
  {}

  void ApplicationController::handleEvent(const Framework::MVCEvent &event) {
    if(auto *e = dynamic_cast<const Events::ExitCommandEvent *>(&event)) {
      m_uiManager->closeUI();
    }
  }
}
