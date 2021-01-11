/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewUnitProvider.cpp
 * PURPOSE: Creates the view unit for the save-document dialog.
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

#include <ViewUnitProvider.hpp>

#include <View/IViewFactory.hpp>
#include <ControllerFactory.hpp>

#include <View/ISaveDocumentView.hpp>
#include <SaveDocumentDlg/Controller.hpp>

namespace SDF::Impl::UILayer::Impl::Controller::SaveDocumentDlg {
  std::unique_ptr<Framework::MVCViewUnit> createViewUnit(
    View::IViewFactory *viewFactory,
    ControllerFactory *controllerFactory
  ) {
    std::unique_ptr<View::ISaveDocumentView> view(viewFactory->createSaveDocumentView());
    std::unique_ptr<Controller> controller(controllerFactory->createSaveDocumentDlgController());

    view->Framework::MVCObservable<View::Events::AcceptSaveParametersEvent>::attachObserver(controller.get());
    view->Framework::MVCObservable<View::Events::ViewDismissedEvent>::attachObserver(controller.get());

    return Framework::MVCViewUnit::Builder(std::move(view))
      .addController(std::move(controller))
      .build();
  }
}
