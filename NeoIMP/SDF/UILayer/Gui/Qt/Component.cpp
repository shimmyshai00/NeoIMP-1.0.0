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

#include <SDF/UILayer/AbstractModel/IDocumentCreationService.hpp>
#include <SDF/UILayer/AbstractModel/IDocumentStorageService.hpp>
#include <SDF/UILayer/AbstractModel/IDocumentAccessService.hpp>
#include <SDF/UILayer/AbstractModel/IDocumentRenderService.hpp>
#include <SDF/UILayer/AbstractModel/IUiStateModelService.hpp>
#include <SDF/UILayer/AbstractModel/IDocumentViewConfigService.hpp>
#include <SDF/UILayer/AbstractModel/IToolBasedEditingService.hpp>

#include <SDF/UILayer/Gui/Qt/Controller/Factory.hpp>
#include <SDF/UILayer/Gui/Qt/View/Factory.hpp>

#include <SDF/UILayer/Gui/Qt/Controller/GuiController.hpp>

#include <SDF/ModelLayer/Services/Component.hpp>

namespace SDF::UILayer::Gui::Qt {
  fruit::Component<IGuiController>
  getComponent() {
    return fruit::createComponent()
      .registerFactory<
        std::unique_ptr<Interfaces::IBorrowedFactory<IGuiElement,
                                                     IGuiElement *,
                                                     std::string
                                                    >
                       >(fruit::Assisted<IGuiController *>,
                         AbstractModel::IDocumentCreationService *,
                         AbstractModel::IDocumentStorageService *,
                         AbstractModel::IDocumentAccessService *,
                         AbstractModel::IDocumentRenderService *,
                         AbstractModel::IUiStateModelService<AbstractModel::Handle> *,
                         AbstractModel::IUiStateModelService<bool> *,
                         AbstractModel::IDocumentViewConfigService *,
                         AbstractModel::IToolBasedEditingService *
                        )
       >(
         [](IGuiController *guiController,
            AbstractModel::IDocumentCreationService *documentCreationService,
            AbstractModel::IDocumentStorageService *documentStorageService,
            AbstractModel::IDocumentAccessService *documentAccessService,
            AbstractModel::IDocumentRenderService *documentRenderService,
            AbstractModel::IUiStateModelService<AbstractModel::Handle> *handleStateModelService,
            AbstractModel::IUiStateModelService<bool> *boolStateModelService,
            AbstractModel::IDocumentViewConfigService *documentViewConfigService,
            AbstractModel::IToolBasedEditingService *toolBasedEditingService
           )
          {
           std::unique_ptr<Controller::Factory> controllerFactory(new Controller::Factory(guiController,
                                                                                          documentCreationService,
                                                                                          documentStorageService,
                                                                                          handleStateModelService,
                                                                                          boolStateModelService,
                                                                                          toolBasedEditingService
                                                                                         ));
           return std::unique_ptr<Interfaces::IBorrowedFactory<IGuiElement,
                                                               IGuiElement *,
                                                               std::string
                                                              >
                                 >(new View::Factory(std::move(controllerFactory),
                                                     documentAccessService,
                                                     documentRenderService,
                                                     boolStateModelService,
                                                     documentViewConfigService,
                                                     toolBasedEditingService
                                                    ));
         }
       )
      .bind<IGuiController, Controller::GuiController>()
      .install(ModelLayer::Services::getComponent);
  }
}
