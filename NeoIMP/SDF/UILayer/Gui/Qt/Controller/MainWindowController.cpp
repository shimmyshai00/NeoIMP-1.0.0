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

#include <IGuiController.hpp>
#include <IGuiElement.hpp>

#include <Events/MainWindowEvent.hpp>

namespace SDF::UILayer::Gui::Qt::Controller {
  MainWindowController::MainWindowController(IGuiController *guiController)
    : m_guiController(guiController)
  {
  }

  void
  MainWindowController::handleEvent(std::shared_ptr<Events::GuiEvent> event) {
    if(auto p = dynamic_cast<Events::ExitClickedEvent *>(event.get())) { handleExitClickedEvent(p); }
  }

  void
  MainWindowController::handleExitClickedEvent(Events::ExitClickedEvent *event) {
    m_guiController->getGuiElementByName("MainWindow")->close();
  }
}
