/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ApplicationMasterController.cpp
 * PURPOSE: Implementation of the application master controller, which creates and destroys the various temporary views
 *          used in the program.
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

#include <ApplicationMasterController.hpp>

#include <View/IViewFactory.hpp>
#include <View/IApplicationView.hpp>

#include <ControllerFactory.hpp>
#include <ApplicationController.hpp>

#include <Messages.hpp>

namespace SDF::Impl::UILayer::Impl::Controller {
  enum {
    VIEW_ID_APPLICATION_VIEW
  };
}

namespace SDF::Impl::UILayer::Impl::Controller {
  ApplicationMasterController::ApplicationMasterController(
    View::IViewFactory *viewFactory,
    ControllerFactory *controllerFactory
  )
    : m_viewFactory(viewFactory),
      m_controllerFactory(controllerFactory)
  {}

  void ApplicationMasterController::receiveMessage(void *sender, std::string message) {
    // View creation
    if(message == Messages::CreateApplicationView) {
      std::unique_ptr<View::IApplicationView> applicationView(m_viewFactory->createApplicationView());
      std::unique_ptr<ApplicationController> applicationController(
        m_controllerFactory->createApplicationController(applicationView.get())
      );

      auto viewUnit = Framework::MVCViewUnit::Builder(std::move(applicationView))
        .addController(std::move(applicationController))
        .build();

      addViewUnit(VIEW_ID_APPLICATION_VIEW, std::move(viewUnit));
    }

    // View destruction
    if(message == Messages::DestroyApplicationView) {
      removeViewUnit(VIEW_ID_APPLICATION_VIEW);
    }
  }
}
