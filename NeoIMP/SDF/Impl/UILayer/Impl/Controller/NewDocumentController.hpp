#ifndef SDF_IMPL_UILAYER_IMPL_CONTROLLER_NEWDOCUMENTCONTROLLER_HPP
#define SDF_IMPL_UILAYER_IMPL_CONTROLLER_NEWDOCUMENTCONTROLLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    NewDocumentController.hpp
 * PURPOSE: Implementation of the new-document controller.
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

#include <SDF/Impl/UILayer/Impl/Framework/MVCObject.hpp>
#include <SDF/Impl/UILayer/Impl/Framework/IMVCObserver.hpp>
#include <SDF/Impl/UILayer/Impl/Framework/MVCConnectionManager.hpp>

#include <SDF/Impl/UILayer/Impl/View/Events/AcceptDocumentParametersEvent.hpp>
#include <SDF/Impl/UILayer/Impl/View/Events/ViewDismissedEvent.hpp>

namespace SDF::Impl::UILayer::Impl {
  namespace View {
    class IViewFactory;
    class INewDocumentView;
  }

  namespace Controller {
    class NewDocumentController : public Framework::MVCObject,
      public Framework::IMVCObserver<View::Events::AcceptDocumentParametersEvent>,
      public Framework::IMVCObserver<View::Events::ViewDismissedEvent>
    {
    public:
      NewDocumentController(View::IViewFactory *viewFactory);
      ~NewDocumentController();

      void notify(View::Events::AcceptDocumentParametersEvent event);
      void notify(View::Events::ViewDismissedEvent event);
    private:
      std::unique_ptr<View::INewDocumentView> m_newDocumentView;

      Framework::MVCConnectionManager m_connectionManager;
    };
  }
}

#endif
