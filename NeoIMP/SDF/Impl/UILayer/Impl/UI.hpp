#ifndef SDF_IMPL_UILAYER_IMPL_QT_UI_HPP
#define SDF_IMPL_UILAYER_IMPL_QT_UI_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    UI.hpp
 * PURPOSE: The UI manager.
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
#include <SDF/Impl/UILayer/Impl/IUIControl.hpp>

#include <fruit/fruit.h>
#include <memory>
#include <map>

namespace SDF::Impl::UILayer {
  namespace Impl {
    namespace View {
      class IViewFactory;
      class IViewSink;

      class IApplicationView;
    }

    class UI : public IUIEntryPoint,
               public IUIControl
    {
    public:
      INJECT(UI(View::IViewFactory *viewFactory,
                View::IViewSink *viewSink
               ));
      ~UI();

      void start();
      void closeUI();
    private:
      View::IViewFactory *m_viewFactory;
      View::IViewSink *m_viewSink;

      std::unique_ptr<View::IApplicationView> m_applicationView;
    };
  }
}

#endif
