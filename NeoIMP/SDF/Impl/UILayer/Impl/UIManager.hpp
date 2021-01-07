#ifndef SDF_IMPL_UILAYER_IMPL_UIMANAGER_HPP
#define SDF_IMPL_UILAYER_IMPL_UIMANAGER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UIManager.hpp
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

#include <SDF/Impl/UILayer/Impl/IViewContainer.hpp>

#include <boost/signals2/connection.hpp>

#include <fruit/fruit.h>

#include <map>
#include <memory>

namespace SDF::Impl::UILayer::Impl {
  namespace View {
    class IApplicationView;
  }

  namespace Controller {
    class ApplicationController;
  }

  class UIManager : public IViewContainer<View::IApplicationView> {
  public:
    INJECT(UIManager());
    ~UIManager();

    int retainView(std::unique_ptr<View::IApplicationView> view);

    void destroyView(int viewId);
  private:
    int m_nextViewId;

    // The registries of active views.
    std::map<int, std::unique_ptr<View::IApplicationView>> m_applicationViews;

    // The principal controllers for each view.
    std::map<int, std::unique_ptr<Controller::ApplicationController>> m_applicationControllers;

    // The connections between the views and controllers.
    std::map<int, std::vector<boost::signals2::connection>> m_viewConnections;
  };
}

#endif
