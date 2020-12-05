#ifndef SDF_IMPL_UILAYER_IMPL_MAINUI_HPP
#define SDF_IMPL_UILAYER_IMPL_MAINUI_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MainUI.hpp
 * PURPOSE: The main UI layer object.
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

#include <SDF/Impl/UILayer/IUI.hpp>

#include <fruit/fruit.h>

namespace SDF::Impl::UILayer::Impl {
  namespace View {
    class IViewManager;
    class IApplicationView;
  }

  namespace Controller {
    class ApplicationController;
    class NewDocumentController;
  }

  class MainUI : public IUI {
  public:
    INJECT(MainUI(
      View::IViewManager *viewManager,
      Controller::ApplicationController *applicationController,
      Controller::NewDocumentController *newDocumentController
    ));

    void start();
  private:
    View::IApplicationView *m_applicationView;

    Controller::ApplicationController *m_applicationController;
    Controller::NewDocumentController *m_newDocumentController;
  };
}

#endif
