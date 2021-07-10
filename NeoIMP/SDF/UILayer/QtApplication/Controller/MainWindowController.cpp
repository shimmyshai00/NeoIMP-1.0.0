/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainWindowController.cpp
 * PURPOSE: Implements the MainWindowController class.
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

#include "MainWindowController.hpp"

#include <iostream>

namespace SDF::UILayer::QtApplication::Controller {
  MainWindowController::MainWindowController()
    : m_view(nullptr)
  {}

  void
  MainWindowController::setView(View::IView<QMainWindow> *view) {
    m_view = view;
  }

  void
  MainWindowController::handleEvent(std::shared_ptr<View::Events::MainWindowEvent> event) {
    if(auto *p = dynamic_cast<View::Events::MainWindowExitMenuEvent *>(event.get())) {
      if(m_view) {
        m_view->getQWidget()->close();
      }
    }
  }
}
