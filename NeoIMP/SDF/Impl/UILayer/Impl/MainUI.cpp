/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainUI.cpp
 * PURPOSE: Implementation of the main UI layer object.
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

#include <MainUI.hpp>

#include <AbstractModel/Services/IDocumentCreationService.hpp>

#include <View/IViewManager.hpp>
#include <View/IApplicationView.hpp>

#include <Controller/NewDocumentController.hpp>

namespace SDF::Impl::UILayer::Impl {
  MainUI::MainUI(
    AbstractModel::Services::IDocumentCreationService *documentCreationService,
    View::IViewManager *viewManager
  )
    : m_viewManager(viewManager),
      m_newDocumentController(new Controller::NewDocumentController(
        documentCreationService,
        viewManager->getNewDocumentView()
      ))
  {
    m_applicationView = m_viewManager->getApplicationView();

    m_applicationView->addNewCommandObserver([=]() { onNewCommand(); });
    m_applicationView->addExitCommandObserver([=]() { onExitCommand(); });
  }

  MainUI::~MainUI() {}

  void MainUI::start() {
    m_applicationView->show();
  }

  // Private members.
  void MainUI::onNewCommand() {
    m_newDocumentController->createNewDocument();
  }

  void MainUI::onExitCommand() {
    m_applicationView->close();
  }
}
