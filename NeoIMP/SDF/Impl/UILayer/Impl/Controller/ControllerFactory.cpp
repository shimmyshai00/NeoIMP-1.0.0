/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ControllerFactory.cpp
 * PURPOSE: The controller factory.
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

#include <ControllerFactory.hpp>

#include <View/IViewFactory.hpp>

#include <MainUI.hpp>

#include <ApplicationController.hpp>
#include <NewDocumentDialogController.hpp>

namespace SDF::Impl::UILayer::Impl::Controller {
  ControllerFactory::ControllerFactory(
    AbstractAppModel::IDocumentCreator *documentCreator,
    View::IViewFactory *viewFactory
  )
    : m_viewFactory(viewFactory),
      m_documentCreator(documentCreator),
      m_parentUi(nullptr)
  {}

  void ControllerFactory::setUI(MainUI *ui) {
    m_parentUi = ui;
  }

  std::unique_ptr<ApplicationController> ControllerFactory::createApplicationController() {
    return std::make_unique<ApplicationController>(m_parentUi, m_viewFactory);
  }

  std::unique_ptr<NewDocumentDialogController> ControllerFactory::createNewDocumentDlgController() {
    return std::make_unique<NewDocumentDialogController>(m_parentUi, m_documentCreator);
  }
}
