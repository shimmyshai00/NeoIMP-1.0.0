#ifndef SDF_IMPL_UILAYER_IMPL_CONTROLLER_IMPL_SAVEDOCUMENTCONTROLLER_HPP
#define SDF_IMPL_UILAYER_IMPL_CONTROLLER_IMPL_SAVEDOCUMENTCONTROLLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SaveDocumentController.hpp
 * PURPOSE: The MVC controller for the save-document view.
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

#include <SDF/Impl/UILayer/Impl/Framework/IMVCViewEventHook.hpp>
#include <SDF/Impl/UILayer/Impl/Framework/IMVCViewUpdate.hpp>

#include <SDF/Impl/UILayer/Impl/View/Events/SaveAsCommandEvent.hpp>
#include <SDF/Impl/UILayer/Impl/View/Events/AcceptSaveParametersEvent.hpp>

#include <SDF/Impl/UILayer/Impl/View/Updates/DocumentNameChangedUpdate.hpp>

#include <map>
#include <vector>

namespace SDF::Impl::UILayer {
  namespace AbstractModel::Services {
    class IDocumentStorageService;
  }

  namespace Impl {
    class IUIController;

    namespace Controller::Impl {
      class SaveDocumentController {
      public:
        SaveDocumentController(
          AbstractModel::Services::IDocumentStorageService *documentStorageService,
          IUIController *uiController
        );

        ~SaveDocumentController();

        void hookSaveAsCommandEvent(Framework::IMVCViewEventHook<View::Events::SaveAsCommandEvent> *hook);
        void hookAcceptSaveParametersEvent(
          Framework::IMVCViewEventHook<View::Events::AcceptSaveParametersEvent> *hook
        );

        void addDocumentNameChangedUpdatable(
          Framework::IMVCViewUpdate<View::Updates::DocumentNameChangedUpdate> *updatable
        );

        void removeSaveAsCommandHook(Framework::IMVCViewEventHook<View::Events::SaveAsCommandEvent> *hook);
        void removeAcceptSaveParametersHook(
          Framework::IMVCViewEventHook<View::Events::AcceptSaveParametersEvent> *hook
        );

        void removeDocumentNameChangedUpdatable(
          Framework::IMVCViewUpdate<View::Updates::DocumentNameChangedUpdate> *updatable
        );
      private:
        AbstractModel::Services::IDocumentStorageService *m_documentStorageService;

        IUIController *m_uiController;

        std::map<Framework::IMVCViewEventHook<View::Events::SaveAsCommandEvent> *, boost::signals2::connection>
          m_saveAsCommandHookMap;
        std::map<
          Framework::IMVCViewEventHook<View::Events::AcceptSaveParametersEvent> *,
          boost::signals2::connection
        > m_acceptSaveParametersHookMap;

        std::vector<Framework::IMVCViewUpdate<View::Updates::DocumentNameChangedUpdate> *>
          m_documentNameChangedUpdatables;
      };
    }
  }
}

#endif
