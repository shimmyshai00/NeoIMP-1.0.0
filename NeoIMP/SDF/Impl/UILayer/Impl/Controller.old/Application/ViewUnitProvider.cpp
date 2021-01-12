/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewUnitProvider.cpp
 * PURPOSE: Creates the view unit for the application view.
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

#include <View/IApplicationView.hpp>
#include <View/IFileCommandsView.hpp>
#include <View/IOpenDocumentsView.hpp>

#include <Application/Controller.hpp>
#include <Application/FileController.hpp>
#include <Application/OpenDocumentsController.hpp>

namespace SDF::Impl::UILayer::Impl::Controller::Application {
  std::unique_ptr<Framework::MVCViewUnit> createViewUnit(
    View::IViewFactory *viewFactory,
    ControllerFactory *controllerFactory
  ) {
    std::unique_ptr<View::IApplicationView> view(viewFactory->createApplicationView());
    View::IFileCommandsView *fileSubView(view->getFileCommandsView());
    View::IOpenDocumentsView *openDocumentsSubView(view->getOpenDocumentsView());

    std::unique_ptr<Controller> controller(controllerFactory->createApplicationController());
    std::unique_ptr<FileController> fileController(controllerFactory->createApplicationFileController());
    std::unique_ptr<OpenDocumentsController> openDocumentsController(
      controllerFactory->createApplicationOpenDocumentsController(openDocumentsSubView)
    );

    fileSubView->Framework::MVCObservable<View::Events::NewCommandEvent>::attachObserver(fileController.get());
    fileSubView->Framework::MVCObservable<View::Events::SaveAsCommandEvent>::attachObserver(fileController.get());

    openDocumentsSubView->Framework::MVCObservable<View::Events::FocusDocumentChangedEvent>::attachObserver(
      openDocumentsController.get()
    );

    return Framework::MVCViewUnit::Builder(std::move(view))
      .addController(std::move(controller))
      .addController(std::move(fileController))
      .addController(std::move(openDocumentsController))
      .build();
  }
}
