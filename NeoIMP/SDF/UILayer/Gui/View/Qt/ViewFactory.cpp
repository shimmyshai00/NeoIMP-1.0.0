/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewFactory.cpp
 * PURPOSE: Implements the ViewFactory class.
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

#include "ViewFactory.hpp"

// NB: add controller factory?
#include "../../Controller/MainWindow/New.hpp"
#include "../../Controller/MainWindow/Exit.hpp"
#include "../../Controller/NewDocumentDialog/Accept.hpp"

namespace SDF::UILayer::Gui::View::Qt {
  ViewFactory::ViewFactory(AbstractModel::IMetricsService *metricsService,
                           AbstractModel::ICreateImageService *createImageService
                          )
    : m_metricsService(metricsService),
      m_createImageService(createImageService)
  {
  }

  MainWindow *
  ViewFactory::createMainWindow(IQtView *parent,
                                Controller::IGuiController *guiController
                               )
  {
    MainWindow *rv(new MainWindow(nullptr));

    std::unique_ptr<Mvc::IController<>> onNewController(
      new Controller::MainWindow::New(guiController));
    std::unique_ptr<Mvc::IController<>> onExitController(
      new Controller::MainWindow::Exit(guiController));

    rv->hookOnNew(std::move(onNewController))->connect();
    rv->hookOnExit(std::move(onExitController))->connect();

    return rv;
  }

  NewDocumentDialog *
  ViewFactory::createNewDocumentDialog(IQtView *parent) {
    NewDocumentDialog *rv(new NewDocumentDialog(m_metricsService, parent));

    std::unique_ptr<Mvc::IController<AbstractModel::Defs::ImageSpec>> onAcceptController(
      new Controller::NewDocumentDialog::Accept(m_createImageService));

    rv->hookOnAccept(std::move(onAcceptController))->connect();

    return rv;
  }
}
