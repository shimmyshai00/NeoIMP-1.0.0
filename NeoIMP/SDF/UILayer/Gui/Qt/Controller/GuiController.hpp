#ifndef SDF_UILAYER_GUI_QT_CONTROLLER_GUICONTROLLER_HPP
#define SDF_UILAYER_GUI_QT_CONTROLLER_GUICONTROLLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GuiController.hpp
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

#include <SDF/Interfaces/IFactory.hpp>
#include <SDF/UILayer/Gui/IGuiController.hpp>

#include <fruit/fruit.h>

#include <QWidget>

#include <fruit/fruit.h>

#include <vector>
#include <map>
#include <string>
#include <memory>

namespace SDF::UILayer::Gui {
  template<class NodeType>
  class IGuiElement;

  namespace Qt::Controller {
    // Class:      GuiController
    // Purpose:    Implements the whole-GUI controller for the Qt-based GUI.
    // Parameters: None.
    class GuiController : public IGuiController<QWidget> {
    public:
      INJECT(GuiController(
        std::function<
          std::unique_ptr<Interfaces::IFactory<IGuiElement<QWidget>,
                                               IGuiElement<QWidget> *,
                                               std::string
                                              >
                         >(IGuiController<QWidget> *)
        > guiElementFactoryFactory
      ));

      std::vector<std::string>
      getGuiElementNames();

      IGuiElement<QWidget> *
      getGuiElementByName(std::string name);
    private:
      std::vector<std::unique_ptr<IGuiElement<QWidget>>> m_guiElementOwners;
      std::map<std::string, IGuiElement<QWidget> *> m_guiElementMap;

      void
      addGuiElement(std::string name,
                    std::unique_ptr<IGuiElement<QWidget>> guiElement
                   );
    };
  }
}

#endif
