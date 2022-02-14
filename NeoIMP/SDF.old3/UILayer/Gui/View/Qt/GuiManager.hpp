#ifndef SDF_UILAYER_GUI_VIEW_QT_GUIMANAGER_HPP
#define SDF_UILAYER_GUI_VIEW_QT_GUIMANAGER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GuiManager.hpp
 * PURPOSE: Defines the GuiManager class.
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

#include "../../Controller/IGuiController.hpp"

#include "ViewFactory.hpp"
#include "MainWindow.hpp"
#include "NewDocumentDialog.hpp"

#include <QPointer>

#include <fruit/fruit.h>

namespace SDF::UILayer::Gui::View::Qt {
  // Class:      GuiManager
  // Purpose:    Manages the layout of the GUI and creates/destroys views.
  // Parameters: None.
  class GuiManager : public Controller::IGuiController {
  public:
    INJECT(GuiManager(ViewFactory *viewFactory));

    void
    startGui();

    void
    closeGui();

    void
    showNewDocumentDialog();
  private:
    ViewFactory *m_viewFactory;

    QPointer<MainWindow> m_mainWindow;
    QPointer<NewDocumentDialog> m_newDocumentDialog;
  };
}

#endif