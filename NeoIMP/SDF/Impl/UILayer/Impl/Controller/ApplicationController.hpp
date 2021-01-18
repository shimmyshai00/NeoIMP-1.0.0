#ifndef SDF_IMPL_UILAYER_IMPL_CONTROLLER_APPLICATIONCONTROLLER_HPP
#define SDF_IMPL_UILAYER_IMPL_CONTROLLER_APPLICATIONCONTROLLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ApplicationController.hpp
 * PURPOSE: The controller associated with the application view.
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

#include <SDF/Impl/Framework/MVCController.hpp>
#include <SDF/Impl/UILayer/Impl/View/IApplicationView.hpp>

namespace SDF::Impl::UILayer::Impl {
  class IUIControl;

  namespace View {
    class IViewFactory;
    class IApplicationView;
  };

  namespace Controller {
    class ApplicationController : public Framework::MVCController<View::ApplicationViewObservables> {
    public:
      ApplicationController(IUIControl *uiControl, View::IViewFactory *viewFactory);

      void setView(View::IApplicationView *applicationView);
      void connectToViewObservables(View::ApplicationViewObservables &observables);
    private:
      IUIControl *m_uiControl;

      View::IViewFactory *m_viewFactory;
      View::IApplicationView *m_applicationView;
    };
  }
}

#endif
