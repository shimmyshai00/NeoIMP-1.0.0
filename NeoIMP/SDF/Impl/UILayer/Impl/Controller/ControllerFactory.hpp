#ifndef SDF_IMPL_UILAYER_IMPL_CONTROLLER_CONTROLLERFACTORY_HPP
#define SDF_IMPL_UILAYER_IMPL_CONTROLLER_CONTROLLERFACTORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ControllerFactory.hpp
 * PURPOSE: Centralize the creation of all controllers needed in the program - especially, the injection of MVC model
 *          layer services.
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

#include <SDF/Impl/UILayer/Impl/Framework/IMVCView.hpp>

#include <fruit/fruit.h>
#include <memory>

namespace SDF::Impl::UILayer {
  namespace AbstractModel::Services {
    class IDocumentCreationService;
    class IDocumentStorageService;
  }

  namespace Impl {
    namespace View {
      class IApplicationView;
    }

    namespace Controller {
      namespace Application {
        class Controller;
        class FileController;
        class OpenDocumentsController;
      }

      namespace NewDocumentDlg {
        class Controller;
      }

      namespace SaveDocumentDlg {
        class Controller;
      }

      class ControllerFactory {
      public:
        INJECT(ControllerFactory(
          AbstractModel::Services::IDocumentCreationService *documentCreationService,
          AbstractModel::Services::IDocumentStorageService *documentStorageService
        ));
        ~ControllerFactory();

        std::unique_ptr<Application::Controller> createApplicationController();
        std::unique_ptr<Application::FileController> createApplicationFileController();
        std::unique_ptr<Application::OpenDocumentsController> createApplicationOpenDocumentsController(
          Framework::IMVCView *view
        );
        std::unique_ptr<NewDocumentDlg::Controller> createNewDocumentDlgController();
        std::unique_ptr<SaveDocumentDlg::Controller> createSaveDocumentDlgController();
      private:
        AbstractModel::Services::IDocumentCreationService *m_documentCreationService;
        AbstractModel::Services::IDocumentStorageService *m_documentStorageService;
      };
    }
  }
}

#endif
