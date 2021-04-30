#ifndef SDF_UIAYER_GUI_QT_CONTROLLER_TOOLBOXCONTROLLER_HPP
#define SDF_UIAYER_GUI_QT_CONTROLLER_TOOLBOXCONTROLLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ToolboxController.hpp
 * PURPOSE: Defines the ToolboxController class.
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

#include <SDF/Interfaces/IEventHandler.hpp>

#include <SDF/UILayer/Gui/Qt/Events/GuiEvent.hpp>
#include <SDF/UILayer/Gui/Qt/Events/ToolboxEvent.hpp>

#include <fruit/fruit.h>
#include <memory>

namespace SDF::UILayer {
  namespace AbstractModel {
    class IToolBasedEditingService;
  }

  namespace Gui::Qt::Controller {
    // Class:      ToolboxController
    // Purpose:    Handles events from the toolchest dialog.
    // Parameters: None.
    class ToolboxController : public Interfaces::IEventHandler<Events::GuiEvent> {
    public:
      ToolboxController(AbstractModel::IToolBasedEditingService *toolBasedEditingService);

      void
      handleEvent(std::shared_ptr<Events::GuiEvent> event);
    private:
      AbstractModel::IToolBasedEditingService *m_toolBasedEditingService;

      void
      handleSelectToolSelectedEvent(Events::SelectToolSelectedEvent *event);

      void
      handleZoomToolSelectedEvent(Events::ZoomToolSelectedEvent *event);

      void
      handleCageTransformToolSelectedEvent(Events::CageTransformToolSelectedEvent *event);
    };
  }
}
#endif
