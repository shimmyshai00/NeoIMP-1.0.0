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

#include <SDF/UILayer/Gui/Qt/View/Factory.hpp>

#include <SDF/UILayer/Exceptions/Exceptions.hpp>

#include <SDF/UILayer/AbstractModel/IDocumentAccessService.hpp>

#include <MainWindow.hpp>
#include <NewDocumentDialog.hpp>

namespace SDF::UILayer::Gui::Qt::View {
  Factory::Factory(
    std::unique_ptr<Interfaces::IFactory<Interfaces::IEventHandler<Events::GuiEvent>, std::string>> controllerFactory,
    AbstractModel::IDocumentAccessService *documentAccessService
  )
    : m_controllerFactory(std::move(controllerFactory)),
      m_documentAccessService(documentAccessService)
  {}

  IGuiElement *
  Factory::create(IGuiElement *parent, std::string elementType) {
    std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> controller(m_controllerFactory->create(elementType));

    if(elementType == "MainWindow") {
      MainWindow *rv(new MainWindow(std::move(controller), dynamic_cast<QWidget *>(parent)));
      m_documentAccessService->attachObserver(rv); // NB: need some safe way to disconnect this on destruction in
                                                   //     general cases
      return rv;
    } else if(elementType == "NewDocumentDialog") {
      return new NewDocumentDialog(std::move(controller), dynamic_cast<QWidget *>(parent));
    } else {
      //throw UILayer::Exceptions::NonexistentGuiElementTypeException(elementType);
    }
  }
}
