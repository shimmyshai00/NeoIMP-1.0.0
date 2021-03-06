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

#include <AbstractModel/ToolConfig/IZoomToolCfgService.hpp>

#include <AbstractModel/IDocumentCreationService.hpp>
#include <AbstractModel/IDocumentStorageService.hpp>
#include <AbstractModel/IUiStateModelService.hpp>
#include <AbstractModel/IToolApplicationService.hpp>

#include <MainWindowController.hpp>
#include <NewDocumentDialogController.hpp>
#include <SaveAsDialogController.hpp>
#include <OpenDialogController.hpp>
#include <ToolboxController.hpp>
#include <ZoomToolConfigController.hpp>

namespace SDF::UILayer::Gui::Qt::Controller {
  Factory::Factory(IGuiController *guiController,
                   AbstractModel::ToolConfig::IZoomToolCfgService *zoomToolCfgService,
                   AbstractModel::IDocumentCreationService *documentCreationService,
                   AbstractModel::IDocumentStorageService *documentStorageService,
                   AbstractModel::IUiStateModelService<AbstractModel::Handle> *handleStateModelService,
                   AbstractModel::IUiStateModelService<bool> *boolStateModelService,
                   AbstractModel::IToolApplicationService *toolApplicationService
                  )
    : m_guiController(guiController),
      m_zoomToolCfgService(zoomToolCfgService),
      m_documentCreationService(documentCreationService),
      m_documentStorageService(documentStorageService),
      m_handleStateModelService(handleStateModelService),
      m_boolStateModelService(boolStateModelService),
      m_toolApplicationService(toolApplicationService)
  {}

  std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>>
  Factory::create(std::string guiElementType) {
    if(guiElementType == "MainWindow") {
      return std::make_unique<MainWindowController>(m_handleStateModelService,
                                                    m_boolStateModelService,
                                                    m_guiController
                                                   );
    } else if(guiElementType == "NewDocumentDialog") {
      return std::make_unique<NewDocumentDialogController>(m_documentCreationService);
    } else if(guiElementType == "SaveAsDialog") {
      return std::make_unique<SaveAsDialogController>(m_documentStorageService, m_handleStateModelService);
    } else if(guiElementType == "OpenDialog") {
      return std::make_unique<OpenDialogController>(m_documentStorageService, m_handleStateModelService);
    } else if(guiElementType == "Toolchest") {
      return std::make_unique<ToolboxController>(m_zoomToolCfgService,
                                                 m_toolApplicationService
                                                );
    } else if(guiElementType == "ZoomToolConfig") {
      return std::make_unique<ZoomToolConfigController>(m_zoomToolCfgService);
    } else {
      //throw UILayer::Exceptions::NonexistentGuiElementTypeException(elementType);
      return std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>>(); // TBA
    }
  }
}
