#ifndef SDF_UILAYER_GUI_QT_VIEW_FACTORY_HPP
#define SDF_UILAYER_GUI_QT_VIEW_FACTORY_HPP

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

#include <SDF/Interfaces/IBorrowedFactory.hpp>
#include <SDF/Interfaces/IFactory.hpp>
#include <SDF/Interfaces/IEventHandler.hpp>

#include <SDF/UILayer/AbstractModel/Handle.hpp>

#include <SDF/UILayer/Gui/IGuiElement.hpp>

#include <SDF/UILayer/Gui/Qt/Events/GuiEvent.hpp>

#include <fruit/fruit.h>

#include <memory>
#include <string>

namespace SDF::UILayer {
  namespace AbstractModel {
    namespace ToolConfig {
      class IZoomToolCfgService;
    }

    class IDocumentAccessService;
    class IDocumentRenderService;
    class IDocumentViewConfigService;

    template<class StateT>
    class IUiStateModelService;

    class IToolApplicationService;
  }

  namespace Gui::Qt::View {
    // Class:      Factory
    // Purpose:    Construct new GUI elements. Note: use of this borrowed factory stuff may be confusing because
    //             actually it's a catch all for other types of ownership and here the ownership is that the passed
    //             parent GUI element owns and we have to document this; this is awkward but Qt wants to be in charge
    //             and we have to appease it!
    // Parameters: None.
    class Factory : public Interfaces::IBorrowedFactory<IGuiElement, IGuiElement *, std::string> {
    public:
      Factory(std::unique_ptr<Interfaces::IFactory<Interfaces::IEventHandler<Events::GuiEvent>, std::string>>
                controllerFactory,
              AbstractModel::IDocumentAccessService *documentAccessService,
              AbstractModel::IDocumentRenderService *documentRenderService,
              AbstractModel::IUiStateModelService<bool> *boolStateModelService,
              AbstractModel::IDocumentViewConfigService *documentViewConfigService,
              AbstractModel::IToolApplicationService *toolApplicationService,
              AbstractModel::ToolConfig::IZoomToolCfgService *zoomToolCfgService
             );

      // Note: The GUI element is presumed to be owned by its parent element.
      IGuiElement *
      create(IGuiElement *parent, std::string elementType);
    private:
      std::unique_ptr<Interfaces::IFactory<Interfaces::IEventHandler<Events::GuiEvent>, std::string>>
        m_controllerFactory;

      AbstractModel::IDocumentAccessService *m_documentAccessService;
      AbstractModel::IDocumentRenderService *m_documentRenderService;
      AbstractModel::IUiStateModelService<bool> *m_boolStateModelService;
      AbstractModel::IDocumentViewConfigService *m_documentViewConfigService;
      AbstractModel::IToolApplicationService *m_toolApplicationService;
      AbstractModel::ToolConfig::IZoomToolCfgService *m_zoomToolCfgService;
    };

    // Class:      DockablesFactory
    // Purpose:    Construct new dockable views inside a parent.
    // Parameters: None.
    class DockablesFactory : public Interfaces::IBorrowedFactory<IGuiElement, IGuiElement *, std::string> {
    public:
      DockablesFactory(AbstractModel::IToolApplicationService *toolApplicationService,
                       AbstractModel::ToolConfig::IZoomToolCfgService *zoomToolCfgService,
                       Interfaces::IFactory<Interfaces::IEventHandler<Events::GuiEvent>, std::string> *
                        controllerFactory
                      );

      // Note: The GUI element is presumed to be owned by its parent element.
      IGuiElement *
      create(IGuiElement *parent, std::string elementType);
    private:
      AbstractModel::IToolApplicationService *m_toolApplicationService;
      AbstractModel::ToolConfig::IZoomToolCfgService *m_zoomToolCfgService;

      Interfaces::IFactory<Interfaces::IEventHandler<Events::GuiEvent>, std::string> *m_controllerFactory;
    };

    // Class:      DocumentViewFactory
    // Purpose:    Construct a new document view.
    // Parameters: None.
    class DocumentViewFactory : public Interfaces::IBorrowedFactory<IGuiElement, IGuiElement *, AbstractModel::Handle> {
    public:
      DocumentViewFactory(AbstractModel::IDocumentAccessService *documentAccessService,
                          AbstractModel::IDocumentRenderService *documentRenderService,
                          AbstractModel::IDocumentViewConfigService *documentViewConfigService,
                          AbstractModel::IToolApplicationService *toolApplicationService
                         );

      IGuiElement *
      create(IGuiElement *parent,
             AbstractModel::Handle documentHandle
            );
    private:
      AbstractModel::IDocumentAccessService *m_documentAccessService;
      AbstractModel::IDocumentRenderService *m_documentRenderService;
      AbstractModel::IDocumentViewConfigService *m_documentViewConfigService;
      AbstractModel::IToolApplicationService *m_toolApplicationService;
    };

    // Class:      ConfigPanesFactory
    // Purpose:    Construct new configuration panes.
    // Parameters: None.
    class ConfigPanesFactory : public Interfaces::IBorrowedFactory<IGuiElement, IGuiElement *, std::string> {
    public:
      ConfigPanesFactory(AbstractModel::ToolConfig::IZoomToolCfgService *zoomToolCfgService,
                         Interfaces::IFactory<Interfaces::IEventHandler<Events::GuiEvent>, std::string> *
                          controllerFactory
                        );

      IGuiElement *
      create(IGuiElement *parent,
             std::string paneType
            );
    private:
      AbstractModel::ToolConfig::IZoomToolCfgService *m_zoomToolCfgService;

      Interfaces::IFactory<Interfaces::IEventHandler<Events::GuiEvent>, std::string> *m_controllerFactory;
    };
  }
}

#endif
