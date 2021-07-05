#ifndef SDF_UILAYER_GUI_QT_CONTROLLER_ZOOMTOOLCONFIGCONTROLLER_HPP
#define SDF_UILAYER_GUI_QT_CONTROLLER_ZOOMTOOLCONFIGCONTROLLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ZoomToolConfigController.hpp
 * PURPOSE: Defines the ZoomToolConfigController class.
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
#include <SDF/UILayer/Gui/Qt/Events/ZoomToolConfigEvent.hpp>

#include <fruit/fruit.h>
#include <memory>

namespace SDF::UILayer {
  namespace AbstractModel::ToolConfig {
    class IZoomToolCfgService;
  }

  namespace Gui::Qt::Controller {
    // Class:      ZoomToolConfigController
    // Purpose:    Handles events from the zoom tool configuration pane.
    // Parameters: None.
    class ZoomToolConfigController : public Interfaces::IEventHandler<Events::GuiEvent> {
    public:
      ZoomToolConfigController(AbstractModel::ToolConfig::IZoomToolCfgService *zoomToolCfgService);

      void
      handleEvent(std::shared_ptr<Events::GuiEvent> event);
    private:
      AbstractModel::ToolConfig::IZoomToolCfgService *m_zoomToolCfgService;

      void
      handleZoomStepChangedEvent(Events::ZoomStepChangedEvent *event);
    };
  }
}

#endif
