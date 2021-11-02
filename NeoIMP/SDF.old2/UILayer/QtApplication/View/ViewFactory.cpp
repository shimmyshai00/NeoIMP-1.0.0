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

#include "MainWindow.hpp"
#include "NewDocumentDialog.hpp"

namespace SDF::UILayer::QtApplication::View {
  ViewFactory::ViewFactory(Controller::IControllerFactory *controllerFactory)
    : m_controllerFactory(controllerFactory)
  {}

  IView<QMainWindow> *
  ViewFactory::createMainWindow() {
    std::unique_ptr<Controller::IController<QMainWindow, Events::MainWindowEvent>>
      controller(m_controllerFactory->createMainWindowController(this));

    return new MainWindow(std::move(controller));
  }

  IView<QDialog> *
  ViewFactory::createNewDocumentDialog(QWidget *parent) {
    std::unique_ptr<Controller::IController<QDialog, Events::DialogEvent>>
      controller(m_controllerFactory->createNewDocumentDialogController());

    return new NewDocumentDialog(std::move(controller));
  }
}