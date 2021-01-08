#ifndef SDF_IMPL_UILAYER_IMPL_CONTROLLER_CONTROLLERFACTORY_HPP
#define SDF_IMPL_UILAYER_IMPL_CONTROLLER_CONTROLLERFACTORY_HPP
/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ControllerFactory.hpp
 * PURPOSE: Implementation of the controller factory. This centralizes the injection of model layer services into the
 *          controllers.
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

#include <fruit/fruit.h>

#include <memory>

namespace SDF::Impl::UILayer {
  namespace AbstractModel::Services {
    class IDocumentCreationService;
    class IImageInformationService;
    class IImageRenderingService;
  }

  namespace Impl {
    namespace View {
      class IViewFactory;
      class IApplicationView;
      class IOpenDocumentsView;
    }

    namespace Controller {
      class ApplicationController;
      class FileCommandsController;
      class NewDocumentController;

      class ControllerFactory {
      public:
        INJECT(ControllerFactory(
          AbstractModel::Services::IDocumentCreationService *documentCreationService,
          AbstractModel::Services::IImageInformationService *imageInformationService,
          AbstractModel::Services::IImageRenderingService *imageRenderingService,
          View::IViewFactory *viewFactory
        ));

        std::unique_ptr<ApplicationController> createApplicationController();
        std::unique_ptr<FileCommandsController> createFileCommandsController(View::IFileCommandsView *fileCommandsView);
        std::unique_ptr<NewDocumentController> createNewDocumentController(View::IOpenDocumentsView *openDocumentsView);
      private:
        AbstractModel::Services::IDocumentCreationService *m_documentCreationService;
        AbstractModel::Services::IImageInformationService *m_imageInformationService;
        AbstractModel::Services::IImageRenderingService *m_imageRenderingService;

        View::IViewFactory *m_viewFactory;
      };
    }
  }
}

#endif
