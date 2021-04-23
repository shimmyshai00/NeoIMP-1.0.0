/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Factory.cpp
 * PURPOSE: Implements the Factory class.
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

#include <SDF/UILayer/Gui/Qt/Controller/Factory.hpp>

#include <SDF/UILayer/Exceptions/Exceptions.hpp>

#include <AbstractModel/IDocumentCreationService.hpp>

#include <MainWindowController.hpp>
#include <NewDocumentDialogController.hpp>

namespace SDF::UILayer::Gui::Qt::Controller {
  Factory::Factory(IGuiController *guiController,
                   AbstractModel::IDocumentCreationService *documentCreationService
                  )
    : m_guiController(guiController),
      m_documentCreationService(documentCreationService)
  {}

  std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>>
  Factory::create(std::string guiElementType) {
    if(guiElementType == "MainWindow") {
      return std::make_unique<MainWindowController>(m_guiController);
    } else if(guiElementType == "NewDocumentDialog") {
      return std::make_unique<NewDocumentDialogController>(m_documentCreationService);
    } else {
      //throw UILayer::Exceptions::NonexistentGuiElementTypeException(elementType);
      return std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>>(); // TBA
    }
  }
}
