/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OpenDialogController.cpp
 * PURPOSE: Implements the OpenDialogController class.
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

#include <OpenDialogController.hpp>

#include <AbstractModel/IDocumentStorageService.hpp>
#include <AbstractModel/IUiStateModelService.hpp>

#include <AbstractModel/Handle.hpp>

#include <StateKeys.hpp>

namespace SDF::UILayer::Gui::Qt::Controller {
  OpenDialogController::OpenDialogController(AbstractModel::IDocumentStorageService *documentStorageService,
                                             AbstractModel::IUiStateModelService<AbstractModel::Handle> *
                                              uiStateModelService
                                            )
    : m_documentStorageService(documentStorageService),
      m_uiStateModelService(uiStateModelService)
  {
  }

  void
  OpenDialogController::handleEvent(std::shared_ptr<Events::GuiEvent> event) {
    if(auto p = dynamic_cast<Events::AcceptEvent<View::FileIndicator> *>(event.get())) { handleAcceptEvent(p); }
    else if(auto p = dynamic_cast<Events::RejectEvent<View::FileIndicator> *>(event.get())) { handleRejectEvent(p); }
  }

  void
  OpenDialogController::handleAcceptEvent(Events::AcceptEvent<View::FileIndicator> *event) {
    AbstractModel::Handle handle(
      m_documentStorageService->loadDocument(event->dialogRv.fileSpec, event->dialogRv.fileFormat)
    );

    m_uiStateModelService->setStateElement(c_guiFocusDocumentKey, handle);
  }

  void
  OpenDialogController::handleRejectEvent(Events::RejectEvent<View::FileIndicator> *event) {
    // N/A
  }
}
