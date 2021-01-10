/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MasterController.cpp
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

#include <MasterController.hpp>

#include <View/IViewFactory.hpp>
#include <ControllerFactory.hpp>

#include <Application/ViewUnitProvider.hpp>
#include <NewDocumentDlg/ViewUnitProvider.hpp>

#include <Messages.hpp>

namespace SDF::Impl::UILayer::Impl::Controller {
  enum {
    APPLICATION_VIEW_ID,
    NEW_DOCUMENT_DLG_VIEW_ID
  };
}

namespace SDF::Impl::UILayer::Impl::Controller {
  MasterController::MasterController(
    View::IViewFactory *viewFactory,
    ControllerFactory *controllerFactory
  )
    : m_viewFactory(viewFactory),
      m_controllerFactory(controllerFactory)
  {}

  void MasterController::receiveMessage(void *sender, std::string message) {
    // View creation
    if(message == Messages::CreateApplicationView) {
      addViewUnit(APPLICATION_VIEW_ID, std::move(Application::createViewUnit(m_viewFactory, m_controllerFactory)));
    } else if(message == Messages::CreateNewDocumentView) {
      addViewUnit(NEW_DOCUMENT_DLG_VIEW_ID, std::move(NewDocumentDlg::createViewUnit(m_viewFactory, m_controllerFactory)));
    }

    // View destruction
    if(message == Messages::DestroyApplicationView) {
      removeViewUnit(APPLICATION_VIEW_ID);
    } else if(message == Messages::DestroyNewDocumentView) {
      removeViewUnit(NEW_DOCUMENT_DLG_VIEW_ID);
    }
  }
}
