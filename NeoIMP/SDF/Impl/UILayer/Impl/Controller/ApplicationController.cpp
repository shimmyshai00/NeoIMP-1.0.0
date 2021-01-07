/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ApplicationController.cpp
 * PURPOSE: Implementation of the application controller.
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

#include <View/IViewFactory.hpp>
#include <View/IApplicationView.hpp>

#include <NewDocumentController.hpp>

namespace SDF::Impl::UILayer::Impl::Controller {
  ApplicationController::ApplicationController(View::IViewFactory *viewFactory)
    : m_viewFactory(viewFactory),
      m_applicationView(viewFactory->createApplicationView())
  {
    m_connectionManager.addConnection(m_applicationView->Framework::MVCObservable<View::Events::NewCommandEvent>::attachObserver(this));
    m_connectionManager.addConnection(m_applicationView->Framework::MVCObservable<View::Events::SaveAsCommandEvent>::attachObserver(this));
    m_connectionManager.addConnection(m_applicationView->Framework::MVCObservable<View::Events::ExitCommandEvent>::attachObserver(this));

    m_applicationView->show();
  }

  ApplicationController::~ApplicationController() {}

  void ApplicationController::notify(View::Events::NewCommandEvent event) {
    // Get the parameters for creating the new document from the user.
    std::unique_ptr<NewDocumentController> controller(new NewDocumentController(m_viewFactory));
    addChild(std::move(controller));
  }

  void ApplicationController::notify(View::Events::SaveAsCommandEvent event) {

  }

  void ApplicationController::notify(View::Events::ExitCommandEvent event) {
    m_applicationView->close();
  }
}
