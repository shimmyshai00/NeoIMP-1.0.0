/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ControllerFactory.cpp
 * PURPOSE: Implementation of the controller factory. This centralizes the injection of model layer services into the
 *          controllers.
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
#include <AbstractModel/Services/IImageInformationService.hpp>
#include <AbstractModel/Services/IImageRenderingService.hpp>

#include <View/IViewFactory.hpp>
#icnlude <View/IApplicationView.hpp>

namespace SDF::Impl::UILayer::Impl::Controller {
  ControllerFactory::ControllerFactory(
    AbstractModel::Services::IDocumentCreationService *documentCreationService,
    AbstractModel::Services::IImageInformationService *imageInformationService,
    AbstractModel::Services::IImageRenderingService *imageRenderingService,
    View::IViewFactory *viewFactory
  )
    : m_documentCreationService(documentCreationService),
      m_imageInformationService(imageInformationService),
      m_imageRenderingService(imageRenderingService),
      m_viewFactory(viewFactory)
  {}

  std::unique_ptr<ApplicationController> ControllerFactory::createApplicationController() {
    return std::make_unique<ApplicationController>(m_viewFactory, this);
  }

  std::unique_ptr<FileCommandsController> createFileCommandsController(View::IApplicationView *applicationView) {
    return std::make_unique<FileCommandsController>(m_viewFactory, applicationView->getFileCommandsView(), this);
  }

  std::unique_ptr<NewDocumentController> createNewDocumentController(View::IApplicationView *applicationView) {
    return std::make_unique<NewDocumentController>(
      m_documentCreationService,
      m_viewFactory,
      applicationView->getOpenDocumentsView()
    );
  }
}
