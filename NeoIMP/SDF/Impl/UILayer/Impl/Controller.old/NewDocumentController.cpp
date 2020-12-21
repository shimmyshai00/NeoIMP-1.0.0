/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    NewDocumentController.cpp
 * PURPOSE: Implementation of the MVC controller associated with the new-document view.
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

#include <NewDocumentController.hpp>

#include <AbstractModel/Services/IDocumentCreationService.hpp>
#include <ModelLayer/Handle.hpp>

#include <View/IViewManager.hpp>
#include <View/ICreateNewDocumentView.hpp>
#include <View/IDocumentView.hpp>

#include <iostream>

namespace SDF::Impl::UILayer::Impl::Controller {
  NewDocumentController::NewDocumentController(
    View::IViewManager *viewManager,
    AbstractModel::Services::IDocumentCreationService *documentCreationService
  )
    : m_viewManager(viewManager),
      m_createNewDocumentView(viewManager->getCreateNewDocumentView()),
      m_documentCreationService(documentCreationService)
  {
    m_createNewDocumentView->setAcceptDocumentParamsCommandObserver(this);
  }

  void NewDocumentController::onNewDocumentCommand() {
    m_createNewDocumentView->show();
  }

  void NewDocumentController::onAcceptNewDocumentParamsCommand(
    int documentWidthPx, int documentHeightPx, float documentResolutionPpi,
    AbstractModel::Properties::ColorModel colorModel, AbstractModel::Properties::BitDepth bitDepth
  ) {
    ModelLayer::Handle handle(m_documentCreationService->createDocument(
      documentWidthPx, documentHeightPx, documentResolutionPpi,
      colorModel, bitDepth
    ));

    m_viewManager->createDocumentView(handle);
  }
}
