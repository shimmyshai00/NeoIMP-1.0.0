/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ControllerFactory.cpp
 * PURPOSE: Centralize the creation of all controllers needed in the program.
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

#include <AbstractModel/Services/IDocumentCreationService.hpp>

#include <View/IApplicationView.hpp>
#include <View/INewDocumentView.hpp>

#include <Application/Controller.hpp>
#include <Application/FileController.hpp>
#include <NewDocumentDlg/Controller.hpp>

namespace SDF::Impl::UILayer::Impl::Controller {
  ControllerFactory::ControllerFactory(AbstractModel::Services::IDocumentCreationService *documentCreationService)
    : m_documentCreationService(documentCreationService)
  {}

  ControllerFactory::~ControllerFactory() {}

  std::unique_ptr<Application::Controller> ControllerFactory::createApplicationController() {
    return std::make_unique<Application::Controller>();
  }

  std::unique_ptr<Application::FileController> ControllerFactory::createApplicationFileController() {
    return std::make_unique<Application::FileController>();
  }

  std::unique_ptr<NewDocumentDlg::Controller> ControllerFactory::createNewDocumentDlgController() {
    return std::make_unique<NewDocumentDlg::Controller>(m_documentCreationService);
  }
}
