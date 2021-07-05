#ifndef SDF_UILAYER_GUI_QT_VIEW_ZOOMTOOLCONFIGPANE_HPP
#define SDF_UILAYER_GUI_QT_VIEW_ZOOMTOOLCONFIGPANE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ZoomToolConfigPane.hpp
 * PURPOSE: Defines the ZoomToolConfigPane class.
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

#include <SDF/UILayer/Gui/Qt/View/CustomWidgets/EditableSlider.hpp>

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

#include <memory>

namespace SDF::UILayer {
  namespace AbstractModel::ToolConfig {
    class IZoomToolCfgService;
  }

  namespace Gui::Qt::View {
    // Class:      ZoomToolConfigPane
    // Purpose:    Defines the pane widget for configuring the zoom tool.
    // Parameters: None.
    class ZoomToolConfigPane : public QtGuiElement<QWidget>,
                               private Interfaces::IEventHandler<AbstractModel::Events::ZoomToolEvent>
    {
      Q_OBJECT
    public:
      ZoomToolConfigPane(AbstractModel::ToolConfig::IZoomToolCfgService *zoomToolCfgService,
                         std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> controller,
                         QWidget *parent = nullptr
                        );
      ~ZoomToolConfigPane();
    private:
      AbstractModel::ToolConfig::IZoomToolCfgService *m_zoomToolCfgService;

      std::unique_ptr<Interfaces::IEventHandler<Events::GuiEvent>> m_controller;

      QGridLayout *m_gridLayout;

      QLabel *m_zoomDirectionLabel;
      QLabel *m_zoomDirectionIndicatorLabel;

      QLabel *m_zoomPowerLabel;
      CustomWidgets::EditableSlider *m_zoomPowerSlider;

      QLabel *m_spacer;

      void
      updateZoomMode();

      void
      handleEvent(std::shared_ptr<AbstractModel::Events::ZoomToolEvent> event);
    };
  }
}

#endif
