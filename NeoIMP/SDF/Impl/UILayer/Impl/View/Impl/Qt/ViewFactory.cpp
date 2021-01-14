/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewFactory.cpp
 * PURPOSE: The Qt-based view factory.
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

#include <ViewFactory.hpp>

#include <IUIManager.hpp>
#include <ApplicationView.hpp>
#include <NewDocumentView.hpp>

#include <Controller/ApplicationController.hpp>
#include <Controller/NewDocumentDialogController.hpp>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  ViewFactory::ViewFactory() {}

  std::unique_ptr<BaseApplicationView> ViewFactory::createApplicationView(IUIManager *uiManager) {
    std::unique_ptr<BaseApplicationView> view(new ApplicationView());
    view->addController(std::make_unique<Controller::ApplicationController>(uiManager, this, view.get()));

    return std::move(view);
  }

  std::unique_ptr<BaseNewDocumentView> ViewFactory::createNewDocumentView(IUIManager *uiManager) {
    std::unique_ptr<BaseNewDocumentView> view(new NewDocumentView());
    view->addController(std::make_unique<Controller::NewDocumentDialogController>(uiManager, view.get()));

    return std::move(view);
  }
}
