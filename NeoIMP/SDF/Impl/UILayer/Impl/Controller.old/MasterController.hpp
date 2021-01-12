#ifndef SDF_IMPL_UILAYER_IMPL_CONTROLLER_APPLICATIONMASTERCONTROLLER_HPP
#define SDF_IMPL_UILAYER_IMPL_CONTROLLER_APPLICATIONMASTERCONTROLLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MasterController.hpp
 * PURPOSE: Implementation of the application master controller, which creates and destroys the various temporary views
 *          used in the program.
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

#include <SDF/Impl/UILayer/Impl/Framework/MVCMasterController.hpp>

namespace SDF::Impl::UILayer::Impl {
  namespace View {
    class IViewFactory;
  }

  namespace Controller {
    class ControllerFactory;

    class MasterController : public Framework::MVCMasterController {
    public:
      MasterController(View::IViewFactory *viewFactory, ControllerFactory *controllerFactory);

      void receiveMessage(void *sender, std::string message);
    private:
      View::IViewFactory *m_viewFactory;
      Controller::ControllerFactory *m_controllerFactory;
    };
  }
}

#endif
