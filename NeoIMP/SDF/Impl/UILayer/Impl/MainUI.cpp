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

#include <View/IViewGenerator.hpp>
#include <View/IApplicationView.hpp>
#include <View/INewDocumentView.hpp>
#include <View/IDocumentView.hpp>

#include <Controller/ApplicationController.hpp>
#include <Controller/NewDocumentController.hpp>

namespace SDF::Impl::UILayer::Impl {
  MainUI::MainUI(
    AbstractModel::Services::IDocumentCreationService *documentCreationService,
    View::IViewGenerator *viewGenerator
  )
    : m_viewGenerator(viewGenerator),
      m_applicationView(m_viewGenerator->createApplicationView()),
      m_newDocumentView(m_viewGenerator->createNewDocumentView(m_applicationView.get())),
      m_applicationController(new Controller::ApplicationController(m_applicationView.get(), this)),
      m_newDocumentController(new Controller::NewDocumentController(
        documentCreationService,
        m_newDocumentView.get(),
        this
      ))
  {}

  MainUI::~MainUI() {}

  void MainUI::start() {
    m_applicationView->show();
  }

  void MainUI::showApplicationView() {
    m_applicationView->show();
  }

  void MainUI::showNewDocumentView() {
    m_newDocumentView->show();
  }

  void MainUI::addDocumentView(AbstractModel::Handle handle) {
    if(m_activeDocumentViews.find(handle) == m_activeDocumentViews.end()) {
      m_activeDocumentViews[handle] = m_viewGenerator->createDocumentView(m_applicationView.get(), handle);
    }
  }

  void MainUI::shutdownUI() {
    m_applicationView->close();
  }
}
