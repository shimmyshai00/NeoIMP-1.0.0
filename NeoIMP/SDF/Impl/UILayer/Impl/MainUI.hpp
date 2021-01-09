#ifndef SDF_IMPL_UILAYER_IMPL_MAINUI_HPP
#define SDF_IMPL_UILAYER_IMPL_MAINUI_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainUI.hpp
 * PURPOSE: The main UI layer object. This effectively acts as a "back end" for all the MVC views and controllers.
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

#include <SDF/Impl/UILayer/IUIEntryPoint.hpp>

#include <fruit/fruit.h>
#include <memory>
#include <map>

namespace SDF::Impl::UILayer {
  namespace Impl {
    namespace View {
      class IViewFactory;
    }

    namespace Controller {
      class ControllerFactory;
      class ApplicationMasterController;
    }

    class MainUI : public IUIEntryPoint {
    public:
      INJECT(MainUI(View::IViewFactory *viewFactory, Controller::ControllerFactory *controllerFactory));

      ~MainUI();

      void start();
    private:
      std::unique_ptr<Controller::ApplicationMasterController> m_applicationMasterController;
    };
  }
}

#endif
