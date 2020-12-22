/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    WidgetProvider.cpp
 * PURPOSE: An object to provide properly-connected Qt widgets for the Qt-based UI system.
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

#include <WidgetProvider.hpp>

#include <Windows/MainWindow.hpp>
#include <Dialogs/NewDocumentDialog.hpp>

namespace SDF::Impl::UILayer::Impl::View::Impl::Qt {
  WidgetProvider::WidgetProvider()
    : m_mainWindow(new Windows::MainWindow),
      m_newDocumentDialog(new Dialogs::NewDocumentDialog)
  {}

  QPointer<Windows::MainWindow> WidgetProvider::getMainWindow() {
    return m_mainWindow;
  }

  QPointer<Dialogs::NewDocumentDialog> WidgetProvider::getNewDocumentDialog() {
    return m_newDocumentDialog;
  }
}
