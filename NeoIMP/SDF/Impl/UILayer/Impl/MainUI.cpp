/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainUI.cpp
 * PURPOSE: Implementation of the main UI layer object.
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

#include <MainUI.hpp>

#include <View/IViewFactory.hpp>
#include <View/BaseApplicationView.hpp>

#include <Controller/ApplicationController.hpp>

namespace SDF::Impl::UILayer::Impl {
  MainUI::MainUI(View::IViewFactory *viewFactory)
    : m_viewFactory(viewFactory)
  {}

  MainUI::~MainUI() {}

  void MainUI::start() {
    m_applicationView = m_viewFactory->createApplicationView();
    m_applicationView->show();
  }

  void MainUI::closeUI() {
    m_applicationView->close();
    m_applicationView.release();
  }

  void MainUI::viewRemoved(std::unique_ptr<Framework::IMVCView> view) {
    m_discardedViews.push_back(std::move(view));
  }

  void MainUI::pump() {
    m_discardedViews.clear();
  }
}
