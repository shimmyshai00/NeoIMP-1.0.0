#ifndef SDF_UILAYER_GUI_QT_VIEW_TOOLBOX_HPP
#define SDF_UILAYER_GUI_QT_VIEW_TOOLBOX_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Toolbox.hpp
 * PURPOSE: Defines the Toolbox class.
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

#include <SDF/UILayer/AbstractModel/Events/ToolEvent.hpp>

#include <SDF/UILayer/Gui/Qt/Events/GuiEvent.hpp>

#include <SDF/UILayer/Gui/Qt/View/QtGuiElement.hpp>

#include <QDockWidget>

#include <QMenu>
#include <QAction>

#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class Toolchest; }
QT_END_NAMESPACE

namespace SDF::UILayer {
  namespace AbstractModel::ToolConfig {
    class IZoomToolCfgService;
  }

  namespace Gui::Qt::View {
    // Class:      Toolbox
    // Purpose:    Displays a palette containing the image editing tools.
    // Parameters: None.
    class Toolbox : public QtGuiElement<QDockWidget>,
                    private Interfaces::IEventHandler<AbstractModel::Events::ZoomToolEvent>
    {
      Q_OBJECT
    public:
      Toolbox(AbstractModel::ToolConfig::IZoomToolCfgService *zoomToolCfgService,
              std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> controller,
              QWidget *parent = nullptr
             );
      ~Toolbox();
    private:
      AbstractModel::ToolConfig::IZoomToolCfgService *m_zoomToolCfgService;

      Ui::Toolchest *m_ui;

      std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> m_controller;

      void
      handleEvent(std::shared_ptr<AbstractModel::Events::ZoomToolEvent> event);

      void
      handleZoomToolModeChangedEvent(AbstractModel::Events::ZoomToolModeChangedEvent *event);
    };
  }
}

#endif
