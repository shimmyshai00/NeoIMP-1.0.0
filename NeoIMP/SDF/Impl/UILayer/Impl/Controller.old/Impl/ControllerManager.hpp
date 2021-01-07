#ifndef SDF_IMPL_UILAYER_IMPL_CONTROLLER_CONTROLLERMANAGER_HPP
#define SDF_IMPL_UILAYER_IMPL_CONTROLLER_CONTROLLERMANAGER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ControllerManager.hpp
 * PURPOSE: The controller manager, which serves an analogous role to the view manager in that it registers views with
 *          the appropriate controllers and holds all available controllers in the system.
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

#include <SDF/Impl/UILayer/Impl/Controller/IControllerManager.hpp>

#include <SDF/Impl/UILayer/Impl/Framework/MVCEventBinding.hpp>
#include <SDF/Impl/UILayer/Impl/Framework/MVCUpdateBinding.hpp>

#include <SDF/Impl/UILayer/Impl/View/Events/NewCommandEvent.hpp>
#include <SDF/Impl/UILayer/Impl/View/Events/SaveAsCommandEvent.hpp>
#include <SDF/Impl/UILayer/Impl/View/Events/ExitCommandEvent.hpp>
#include <SDF/Impl/UILayer/Impl/View/Events/AcceptDocumentParametersEvent.hpp>
#include <SDF/Impl/UILayer/Impl/View/Events/AcceptSaveParametersEvent.hpp>

#include <SDF/Impl/UILayer/Impl/View/Updates/DocumentAddedUpdate.hpp>
#include <SDF/Impl/UILayer/Impl/View/Updates/DocumentNameChangedUpdate.hpp>

#include <fruit/fruit.h>

#include <memory>

namespace SDF::Impl::UILayer {
  namespace AbstractModel::Services {
    class IDocumentCreationService;
    class IDocumentStorageService;
  }

  namespace Impl::Controller::Impl {
    class ApplicationController;
    class NewDocumentController;
    class SaveDocumentController;

    class ControllerManager : public IControllerManager {
    public:
      INJECT(ControllerManager(
        AbstractModel::Services::IDocumentCreationService *documentCreationService,
        AbstractModel::Services::IDocumentStorageService *documentStorageService
      ));

      ~ControllerManager();

      void setUIController(IUIController *uiController);

      void registerApplicationView(View::IApplicationView *applicationView);
      void registerNewDocumentView(View::INewDocumentView *newDocumentView);
      void registerSaveDocumentView(View::ISaveDocumentView *saveDocumentView);
      void registerOpenDocumentsView(View::IOpenDocumentsView *openDocumentsView);

      void unregisterApplicationView(View::IApplicationView *applicationView);
      void unregisterNewDocumentView(View::INewDocumentView *newDocumentView);
      void unregisterSaveDocumentView(View::ISaveDocumentView *saveDocumentView);
      void unregisterOpenDocumentsView(View::IOpenDocumentsView *openDocumentsView);
    private:
      AbstractModel::Services::IDocumentCreationService *m_documentCreationService;
      AbstractModel::Services::IDocumentStorageService *m_documentStorageService;

      IUIController *m_uiController;

      std::unique_ptr<ApplicationController> m_applicationController;
      std::unique_ptr<NewDocumentController> m_newDocumentController;
      std::unique_ptr<SaveDocumentController> m_saveDocumentController;

      // Bindings
      Framework::MVCEventBinding<View::Events::NewCommandEvent> m_newCommandEventBindings;
      Framework::MVCEventBinding<View::Events::SaveAsCommandEvent> m_saveAsCommandEventBindings;
      Framework::MVCEventBinding<View::Events::ExitCommandEvent> m_exitCommandEventBindings;
      Framework::MVCEventBinding<View::Events::AcceptDocumentParametersEvent> m_acceptDocumentParametersEventBindings;
      Framework::MVCEventBinding<View::Events::AcceptSaveParametersEvent> m_acceptSaveParametersEventBindings;

      Framework::MVCUpdateBinding<View::Updates::DocumentAddedUpdate> m_documentAddedUpdateBindings;
      Framework::MVCUpdateBinding<View::Updates::DocumentNameChangedUpdate> m_documentNameChangedUpdateBindings;
    };
  }
}

#endif