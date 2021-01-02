/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ControllerManager.cpp
 * PURPOSE: The controller manager, which serves an analogous role to the view manager in that it registers views with
 *          the appropriate controllers and holds all available controllers in the system.
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

#include <ControllerManager.hpp>

#include <AbstractModel/Services/IDocumentCreationService.hpp>
#include <AbstractModel/Services/IDocumentStorageService.hpp>

#include <IUIController.hpp>

#include <View/IApplicationView.hpp>
#include <View/INewDocumentView.hpp>
#include <View/ISaveDocumentView.hpp>
#include <View/IOpenDocumentsView.hpp>

#include <ApplicationController.hpp>
#include <NewDocumentController.hpp>
#include <SaveDocumentController.hpp>

namespace SDF::Impl::UILayer::Impl::Controller::Impl {
  ControllerManager::ControllerManager(
    AbstractModel::Services::IDocumentCreationService *documentCreationService,
    AbstractModel::Services::IDocumentStorageService *documentStorageService
  )
    : m_documentCreationService(documentCreationService),
      m_documentStorageService(documentStorageService)
  {}

  ControllerManager::~ControllerManager() {}

  void ControllerManager::setUIController(IUIController *uiController) {
    m_uiController = uiController;

    m_applicationController = std::make_unique<ApplicationController>(uiController);
    m_newDocumentController = std::make_unique<NewDocumentController>(m_documentCreationService, uiController);
    m_saveDocumentController = std::make_unique<SaveDocumentController>(m_documentStorageService, uiController);
  }

  void ControllerManager::registerApplicationView(View::IApplicationView *applicationView) {
    m_newDocumentController->hookNewCommandEvent(applicationView);
    m_saveDocumentController->hookSaveAsCommandEvent(applicationView);
    m_applicationController->hookExitCommandEvent(applicationView);
  }

  void ControllerManager::registerNewDocumentView(View::INewDocumentView *newDocumentView) {
    m_newDocumentController->hookAcceptDocumentParametersEvent(newDocumentView);
  }

  void ControllerManager::registerSaveDocumentView(View::ISaveDocumentView *saveDocumentView) {
    m_saveDocumentController->hookAcceptSaveParametersEvent(saveDocumentView);
  }

  void ControllerManager::registerOpenDocumentsView(View::IOpenDocumentsView *openDocumentsView) {
    m_newDocumentController->addDocumentAddedUpdatable(openDocumentsView);
  }

  void ControllerManager::unregisterApplicationView(View::IApplicationView *applicationView) {
    m_newDocumentController->removeNewCommandHook(applicationView);
    m_saveDocumentController->removeSaveAsCommandHook(applicationView);
    m_applicationController->removeExitCommandHook(applicationView);
  }

  void ControllerManager::unregisterNewDocumentView(View::INewDocumentView *newDocumentView) {
    m_newDocumentController->removeAcceptDocumentParametersHook(newDocumentView);
  }

  void ControllerManager::unregisterSaveDocumentView(View::ISaveDocumentView *saveDocumentView) {
    m_saveDocumentController->removeAcceptSaveParametersHook(saveDocumentView);
  }

  void ControllerManager::unregisterOpenDocumentsView(View::IOpenDocumentsView *openDocumentsView) {
    m_newDocumentController->removeDocumentAddedUpdatable(openDocumentsView);
  }
}
