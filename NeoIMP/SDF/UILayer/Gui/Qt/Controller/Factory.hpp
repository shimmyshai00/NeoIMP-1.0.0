#ifndef SDF_UILAYER_GUI_QT_CONTROLLER_FACTORY_HPP
#define SDF_UILAYER_GUI_QT_CONTROLLER_FACTORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Factory.hpp
 * PURPOSE: Defines the Factory class.
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
#include <SDF/Interfaces/IEventHandler.hpp>

#include <SDF/UILayer/AbstractModel/Handle.hpp>
#include <SDF/UILayer/Gui/Qt/Events/GuiEvent.hpp>

#include <fruit/fruit.h>

#include <memory>
#include <string>

namespace SDF::UILayer {
  namespace AbstractModel {
    class IDocumentCreationService;
    class IDocumentStorageService;

    template<class StateT>
    class IUiStateModelService;

    class IToolApplicationService;
  }

  namespace Gui {
    class IGuiController;

    namespace Qt::Controller {
      // Class:      Factory
      // Purpose:    Construct new GUI controllers.
      // Parameters: None.
      class Factory : public Interfaces::IFactory<Interfaces::IEventHandler<Events::GuiEvent>, std::string>
      {
      public:
        Factory(IGuiController *guiController,
                AbstractModel::IDocumentCreationService *documentCreationService,
                AbstractModel::IDocumentStorageService *documentStorageService,
                AbstractModel::IUiStateModelService<AbstractModel::Handle> *handleStateModelService,
                AbstractModel::IUiStateModelService<bool> *boolStateModelService,
                AbstractModel::IToolApplicationService *toolApplicationService
               );

        // Creates the appropriate controller for the given type of GUI element.
        std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>>
        create(std::string guiElementType);
      private:
        IGuiController *m_guiController;

        AbstractModel::IDocumentCreationService *m_documentCreationService;
        AbstractModel::IDocumentStorageService *m_documentStorageService;
        AbstractModel::IUiStateModelService<AbstractModel::Handle> *m_handleStateModelService;
        AbstractModel::IUiStateModelService<bool> *m_boolStateModelService;
        AbstractModel::IToolApplicationService *m_toolApplicationService;
      };
    }
  }
}

#endif
