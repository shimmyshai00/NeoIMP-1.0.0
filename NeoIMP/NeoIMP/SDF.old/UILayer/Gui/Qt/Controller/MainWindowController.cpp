/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainWindowController.cpp
 * PURPOSE: Implements the MainWindowController class.
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

#include <MainWindowController.hpp>

#include <AbstractModel/IUiStateModelService.hpp>

#include <IGuiController.hpp>
#include <IGuiElement.hpp>

#include <Events/MainWindowEvent.hpp>
#include <SDF/UILayer/Gui/StateKeys.hpp>

namespace SDF::UILayer::Gui::Qt::Controller {
  MainWindowController::MainWindowController(AbstractModel::IUiStateModelService<AbstractModel::Handle> *
                                              handleStateModelService,
                                             AbstractModel::IUiStateModelService<bool> *boolStateModelService,
                                             IGuiController *guiController
                                            )
    : m_handleStateModelService(handleStateModelService),
      m_boolStateModelService(boolStateModelService),
      m_guiController(guiController)
  {
    m_boolStateModelService->setStateElement(c_toolboxVisibleKey, true);
    m_boolStateModelService->setStateElement(c_toolSettingsVisibleKey, false);
  }

  void
  MainWindowController::handleEvent(std::shared_ptr<Events::GuiEvent> event) {
    if(auto p = dynamic_cast<Events::NewClickedEvent *>(event.get())) { handleNewClickedEvent(p); }
    else if(auto p = dynamic_cast<Events::OpenClickedEvent *>(event.get())) { handleOpenClickedEvent(p); }
    else if(auto p = dynamic_cast<Events::SaveAsClickedEvent *>(event.get())) { handleSaveAsClickedEvent(p); }
    else if(auto p = dynamic_cast<Events::ExitClickedEvent *>(event.get())) { handleExitClickedEvent(p); }
    else if(auto p = dynamic_cast<Events::DockableToggledEvent *>(event.get())) { handleDockableToggledEvent(p); }
    else if(auto p = dynamic_cast<Events::FocusDocumentChangedEvent *>(event.get())) {
      handleFocusDocumentChangedEvent(p);
    }
  }

  void
  MainWindowController::handleNewClickedEvent(Events::NewClickedEvent *event) {
    m_guiController->getGuiElementByName("NewDocumentDialog")->show();
  }

  void
  MainWindowController::handleOpenClickedEvent(Events::OpenClickedEvent *event) {
    m_guiController->getGuiElementByName("OpenDialog")->show();
  }

  void
  MainWindowController::handleSaveAsClickedEvent(Events::SaveAsClickedEvent *event) {
    m_guiController->getGuiElementByName("SaveAsDialog")->show();
  }

  void
  MainWindowController::handleExitClickedEvent(Events::ExitClickedEvent *event) {
    m_guiController->getGuiElementByName("MainWindow")->close();
  }

  void
  MainWindowController::handleFocusDocumentChangedEvent(Events::FocusDocumentChangedEvent *event) {
    m_handleStateModelService->setStateElement(c_guiFocusDocumentKey, event->focusedHandle);
  }

  void
  MainWindowController::handleDockableToggledEvent(Events::DockableToggledEvent *event) {
    m_boolStateModelService->setStateElement(event->dockableStateKey, event->toggleValue);
  }
}
