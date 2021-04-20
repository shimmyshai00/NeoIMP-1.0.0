/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Component.cpp
 * PURPOSE: Defines the DI component for the Qt GUI implementation.
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

#include <SDF/UILayer/Gui/Qt/Component.hpp>

#include <SDF/Interfaces/IEventHandler.hpp>

#include <SDF/UILayer/Gui/IGuiElement.hpp>

#include <SDF/UILayer/Gui/Qt/Controller/GuiController.hpp>
#include <SDF/UILayer/Gui/Qt/Controller/MainWindowController.hpp>

#include <SDF/UILayer/Gui/Qt/View/MainWindow.hpp>

namespace SDF::UILayer::Gui::Qt {
  fruit::Component<IGuiController>
  getComponent() {
    return fruit::createComponent()
      .registerFactory<std::unique_ptr<IGuiElement>(fruit::Assisted<IGuiController *>)>(
        [](IGuiController *guiController) {
          auto controller = std::make_unique<Controller::MainWindowController>(guiController);
          return std::unique_ptr<IGuiElement>(new View::MainWindow(std::move(controller), nullptr));
        }
      )
      .bind<IGuiController, Controller::GuiController>();
  }
}
