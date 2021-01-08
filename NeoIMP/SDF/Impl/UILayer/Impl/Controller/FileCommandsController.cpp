/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FileCommandsController.cpp
 * PURPOSE: Implementation of the file commands controller.
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

#include <FileCommandsController.hpp>
#include <NewDocumentController.hpp>

#include <View/IViewFactory.hpp>
#include <View/IFileCommandsView.hpp>

#include <ControllerFactory.hpp>

namespace SDF::Impl::UILayer::Impl::Controller {
  FileCommandsController::FileCommandsController(
    View::IViewFactory *viewFactory,
    View::IFileCommandsView *fileCommandsView,
    Controller::ControllerFactory *controllerFactory
  )
    : m_viewFactory(viewFactory),
      m_fileCommandsView(fileCommandsView),
      m_controllerFactory(controllerFactory)
  {
    m_connectionManager.addConnection(m_fileCommandsView->Framework::MVCObservable<View::Events::NewCommandEvent>::attachObserver(this));
    m_connectionManager.addConnection(m_fileCommandsView->Framework::MVCObservable<View::Events::SaveAsCommandEvent>::attachObserver(this));
  }

  void FileCommandsController::notify(View::Events::NewCommandEvent event) {
    // Get the parameters for creating the new document from the user.
    std::shared_ptr<NewDocumentController> controller(new NewDocumentController(m_viewFactory));
    addChild(controller);
  }

  void FileCommandsController::notify(View::Events::SaveAsCommandEvent event) {

  }
}
