/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GuiController.cpp
 * PURPOSE: Defines the GuiController class.
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

#include <GuiController.hpp>

#include <IGuiElement.hpp>

namespace SDF::UILayer::Gui::Qt::Controller {
  GuiController::GuiController(
    std::function<
      std::unique_ptr<Interfaces::IFactory<IGuiElement<QWidget>,
                                           IGuiElement<QWidget> *,
                                           std::string
                                          >
                     >(IGuiController<QWidget> *)
    > guiElementFactoryFactory
  )
  {
    std::unique_ptr<Interfaces::IFactory<IGuiElement<QWidget>, IGuiElement<QWidget> *, std::string>>
      factory(guiElementFactoryFactory(this));

    addGuiElement("MainWindow", factory->create(nullptr, "MainWindow"));
  }

  std::vector<std::string>
  GuiController::getGuiElementNames() {
    std::vector<std::string> rv;

    for(auto el : m_guiElementMap) {
      rv.push_back(el.first);
    }

    return rv;
  }

  IGuiElement<QWidget> *
  GuiController::getGuiElementByName(std::string name) {
    if(m_guiElementMap.find(name) == m_guiElementMap.end()) {
      return nullptr;
    } else {
      if(!m_guiElementMap[name]) {
        m_guiElementMap.erase(name); // erase destroyed elements
        return nullptr;
      } else {
        return m_guiElementMap[name];
      }
    }
  }

  void
  GuiController::addGuiElement(std::string name,
                               std::unique_ptr<IGuiElement<QWidget>> guiElement
                              )
  {
    IGuiElement<QWidget> *el(guiElement.get());
    m_guiElementOwners.push_back(std::move(guiElement));

    m_guiElementMap[name] = el;
  }
}
