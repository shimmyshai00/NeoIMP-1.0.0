/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UIManager.cpp
 * PURPOSE: The UI manager. This holds all active views in the application and associates them with their needed
 *          controllers.
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

#include <UIManager.hpp>

#include <View/IApplicationView.hpp>

#include <Controller/ApplicationController.hpp>

namespace SDF::Impl::UILayer::Impl {
  UIManager::UIManager() : m_nextViewId(0) {}
  UIManager::~UIManager() {}

  // View retention. These may connect with other controllers that need to hear about events from the given views.
  int UIManager::retainView(std::unique_ptr<View::IApplicationView> view) {
    std::unique_ptr<Controller::ApplicationController> controller(new Controller::ApplicationController(view.get()));

    m_viewConnections[m_nextViewId].push_back(
      view->Framework::IMVCObservable<View::Events::NewCommandEvent>::attachObserver(controller.get())
    );
    m_viewConnections[m_nextViewId].push_back(
      view->Framework::IMVCObservable<View::Events::SaveAsCommandEvent>::attachObserver(controller.get())
    );
    m_viewConnections[m_nextViewId].push_back(
      view->Framework::IMVCObservable<View::Events::ExitCommandEvent>::attachObserver(controller.get())
    );

    m_applicationViews[m_nextViewId] = std::move(view);
    m_applicationControllers[m_nextViewId] = std::move(controller);

    return m_nextViewId++;
  }

  // View removal.
  void UIManager::destroyView(int viewId) {
    for(auto &conn : m_viewConnections[viewId]) {
      conn.disconnect();
    }

    // Erase from whichever arrays contain this view and its associated controller.
    m_applicationViews.erase(viewId);

    m_applicationControllers.erase(viewId);
  }
}
