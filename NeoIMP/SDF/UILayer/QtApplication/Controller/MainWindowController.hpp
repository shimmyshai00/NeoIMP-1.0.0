#ifndef SDF_UILAYER_QTAPPLICATION_CONTROLLER_MAINWINDOWCONTROLLER_HPP
#define SDF_UILAYER_QTAPPLICATION_CONTROLLER_MAINWINDOWCONTROLLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainWindowController.hpp
 * PURPOSE: Defines the MainWindowController class.
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

#include "../View/Events/MainWindowEvent.hpp"
#include "../View/IView.hpp"
#include "IController.hpp"

#include <QMainWindow>
#include <memory>

namespace SDF::UILayer::QtApplication::Controller {
  // Class:      MainWindowController
  // Purpose:    Provides the controller for the main window.
  // Parameters: None.
  class MainWindowController : public IController<View::Events::MainWindowEvent> {
  public:
    MainWindowController();

    void
    setView(View::IView<QMainWindow> *view);

    void
    handleEvent(std::shared_ptr<View::Events::MainWindowEvent> event);
  private:
    View::IView<QMainWindow> *m_view;
  };
}

#endif
