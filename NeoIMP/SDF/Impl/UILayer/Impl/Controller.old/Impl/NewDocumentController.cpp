/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    NewDocumentController.cpp
 * PURPOSE: The MVC controller for the new-document view.
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
#include <AbstractModel/Handle.hpp>

#include <IUIController.hpp>
#include <View/INewDocumentView.hpp>

#include <iostream>
#include <algorithm>

namespace SDF::Impl::UILayer::Impl::Controller::Impl {
  NewDocumentController::NewDocumentController(
    AbstractModel::Services::IDocumentCreationService *documentCreationService,
    IUIController *uiController
  )
    : m_documentCreationService(documentCreationService),
      m_uiController(uiController)
  {}

  void NewDocumentController::handleEvent(View::Events::NewCommandEvent event) {
    m_uiController->showNewDocumentView();
  }

  void NewDocumentController::handleEvent(View::Events::AcceptDocumentParametersEvent event) {
    AbstractModel::Handle handle(m_documentCreationService->createDocument(event.spec));
    m_documentAddedUpdateSignal(View::Updates::DocumentAddedUpdate { handle });

    m_uiController->createDocumentView(handle);
  }

  boost::signals2::connection NewDocumentController::connectUpdateDestination(
    std::function<void (View::Updates::DocumentAddedUpdate)> dest
  ) {
    return m_documentAddedUpdateSignal.connect(dest);
  }
}
