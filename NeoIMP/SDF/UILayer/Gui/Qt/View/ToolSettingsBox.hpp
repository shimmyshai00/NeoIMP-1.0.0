#ifndef SDF_UILAYER_GUI_QT_VIEW_TOOLSETTINGSBOX_HPP
#define SDF_UILAYER_GUI_QT_VIEW_TOOLSETTINGSBOX_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ToolSettingsBox.hpp
 * PURPOSE: Defines the ToolSettingsBox class.
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
#include <SDF/Interfaces/IBorrowedFactory.hpp>

#include <SDF/UILayer/AbstractModel/Events/ToolEvent.hpp>
#include <SDF/UILayer/AbstractModel/Properties/Tool.hpp>

#include <SDF/UILayer/Gui/Qt/View/QtGuiElement.hpp>

#include <QDockWidget>
#include <QBoxLayout>

namespace SDF::UILayer {
  namespace AbstractModel {
    class IToolApplicationService;
  }

  namespace Gui::Qt::View {
    // Class:      ToolSettingsBox
    // Purpose:    Provides a dockable box showing settings for the currently-selected editing tool.
    // Parameters: None.
    class ToolSettingsBox : public QtGuiElement<QDockWidget>,
                            private Interfaces::IEventHandler<AbstractModel::Events::ToolEvent>
    {
      Q_OBJECT
    public:
      ToolSettingsBox(AbstractModel::IToolApplicationService *toolApplicationService,
                      std::unique_ptr<Interfaces::IBorrowedFactory<IGuiElement, IGuiElement *, std::string>>
                        configPanesFactory,
                      QWidget *parent = nullptr
                     );
      ~ToolSettingsBox();
    private:
      AbstractModel::IToolApplicationService *m_toolApplicationService;

      std::map<AbstractModel::Properties::Tool, QWidget *> m_configPanes;

      void
      addConfigPane(AbstractModel::Properties::Tool tool, QWidget *pane);

      void
      handleEvent(std::shared_ptr<AbstractModel::Events::ToolEvent> event);

      void
      handleActiveToolChangedEvent(AbstractModel::Events::ActiveToolChangedEvent *event);
    };
  }
}

#endif
