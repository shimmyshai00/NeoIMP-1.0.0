#ifndef SDF_IMPL_UILAYER_IMPL_CONTROLLER_NEWDOCUMENTCONTROLLER_HPP
#define SDF_IMPL_UILAYER_IMPL_CONTROLLER_NEWDOCUMENTCONTROLLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    NewDocumentController.hpp
 * PURPOSE: The MVC controller for the new-document view.
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

#include <SDF/Impl/UILayer/Impl/Framework/IMVCControllerEventHandler.hpp>
#include <SDF/Impl/UILayer/Impl/Framework/IMVCControllerUpdateHook.hpp>

#include <SDF/Impl/UILayer/Impl/View/Events/NewCommandEvent.hpp>
#include <SDF/Impl/UILayer/Impl/View/Events/AcceptDocumentParametersEvent.hpp>

#include <SDF/Impl/UILayer/Impl/View/Updates/DocumentAddedUpdate.hpp>

#include <SDF/Impl/UILayer/AbstractModel/Data/DocumentSpec.hpp>

#include <boost/signals2/signal.hpp>

namespace SDF::Impl::UILayer {
  namespace AbstractModel::Services {
    class IDocumentCreationService;
  }

  namespace Impl {
    class IUIController;

    namespace Controller::Impl {
      class NewDocumentController : public Framework::IMVCControllerEventHandler<View::Events::NewCommandEvent>,
        public Framework::IMVCControllerEventHandler<View::Events::AcceptDocumentParametersEvent>,
        public Framework::IMVCControllerUpdateHook<View::Updates::DocumentAddedUpdate> {
      public:
        NewDocumentController(
          AbstractModel::Services::IDocumentCreationService *documentCreationService,
          IUIController *uiController
        );

        void handleEvent(View::Events::NewCommandEvent event);
        void handleEvent(View::Events::AcceptDocumentParametersEvent event);

        boost::signals2::connection connectUpdateDestination(
          std::function<void (View::Updates::DocumentAddedUpdate)> dest
        );
      private:
        AbstractModel::Services::IDocumentCreationService *m_documentCreationService;

        IUIController *m_uiController;

        boost::signals2::signal<void (View::Updates::DocumentAddedUpdate)> m_documentAddedUpdateSignal;
      };
    }
  }
}

#endif
