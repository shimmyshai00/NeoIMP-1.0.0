/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SaveDocumentController.cpp
 * PURPOSE: The MVC controller for the save-document view.
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

#include <SaveDocumentController.hpp>

#include <AbstractModel/Services/IDocumentStorageService.hpp>
#include <AbstractModel/Handle.hpp>

#include <IUIController.hpp>
#include <View/ISaveDocumentView.hpp>

#include <iostream>
#include <algorithm>

namespace SDF::Impl::UILayer::Impl::Controller::Impl {
  SaveDocumentController::SaveDocumentController(
    AbstractModel::Services::IDocumentStorageService *documentStorageService,
    IUIController *uiController
  )
    : m_documentStorageService(documentStorageService),
      m_uiController(uiController)
  {}

  SaveDocumentController::~SaveDocumentController() {
    for(auto const &conn : m_acceptSaveParametersHookMap) conn.second.disconnect();
  }

  void SaveDocumentController::hookSaveAsCommandEvent(
    Framework::IMVCViewEventHook<View::Events::SaveAsCommandEvent> *hook
  ) {
    m_saveAsCommandHookMap[hook] = hook->connectEventListener(
      [=](View::Events::SaveAsCommandEvent event) {
        m_uiController->showSaveDocumentView();
      }
    );
  }

  void SaveDocumentController::hookAcceptSaveParametersEvent(
    Framework::IMVCViewEventHook<View::Events::AcceptSaveParametersEvent> *hook
  ) {
    // TBA

    /*
    m_acceptDocumentParametersHookMap[hook] = hook->connectEventListener(
      [=](View::Events::AcceptDocumentParametersEvent event) {
        AbstractModel::Handle handle(m_documentCreationService->createDocument(event.spec));
        for(auto &updatable : m_documentAddedUpdatables) {
          updatable->update(View::Updates::DocumentAddedUpdate { handle });
        }

        m_uiController->createDocumentView(handle);
      }
    );
    */
  }

  void SaveDocumentController::addDocumentNameChangedUpdatable(
    Framework::IMVCViewUpdate<View::Updates::DocumentNameChangedUpdate> *updatable
  ) {
    m_documentNameChangedUpdatables.push_back(updatable);
  }

  void SaveDocumentController::removeSaveAsCommandHook(
    Framework::IMVCViewEventHook<View::Events::SaveAsCommandEvent> *hook
  ) {
    m_saveAsCommandHookMap[hook].disconnect();
    m_saveAsCommandHookMap.erase(hook);
  }

  void SaveDocumentController::removeAcceptSaveParametersHook(
    Framework::IMVCViewEventHook<View::Events::AcceptSaveParametersEvent> *hook
  ) {
    m_acceptSaveParametersHookMap[hook].disconnect();
    m_acceptSaveParametersHookMap.erase(hook);
  }

  void SaveDocumentController::removeDocumentNameChangedUpdatable(
    Framework::IMVCViewUpdate<View::Updates::DocumentNameChangedUpdate> *updatable
  ) {
    m_documentNameChangedUpdatables.erase(std::find(
      m_documentNameChangedUpdatables.begin(), m_documentNameChangedUpdatables.end(),
      updatable
    ));
  }
}
