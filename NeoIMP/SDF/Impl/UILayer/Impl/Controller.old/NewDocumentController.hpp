#ifndef SDF_IMPL_UILAYER_IMPL_CONTROLLER_NEWDOCUMENTCONTROLLER_HPP
#define SDF_IMPL_UILAYER_IMPL_CONTROLLER_NEWDOCUMENTCONTROLLER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    NewDocumentController.hpp
 * PURPOSE: The MVC controller associated with the new-document view.
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

#include <SDF/Impl/UILayer/Impl/View/AbstractController/INewDocumentCommandObserver.hpp>
#include <SDF/Impl/UILayer/Impl/View/AbstractController/IAcceptNewDocumentParamsCommandObserver.hpp>

#include <SDF/Impl/UILayer/AbstractModel/Properties/ColorModels.hpp>
#include <SDF/Impl/UILayer/AbstractModel/Properties/BitDepths.hpp>

#include <fruit/fruit.h>

namespace SDF::Impl::UILayer {
  namespace AbstractModel::Services {
    class IDocumentCreationService;
  }

  namespace Impl {
    namespace View {
      class IViewManager;
      class ICreateNewDocumentView;
    }

    namespace Controller {
      class NewDocumentController : public View::AbstractController::INewDocumentCommandObserver,
        public View::AbstractController::IAcceptNewDocumentParamsCommandObserver {
      public:
        INJECT(NewDocumentController(
          View::IViewManager *viewManager,
          AbstractModel::Services::IDocumentCreationService *documentCreationService
        ));

        void onNewDocumentCommand();
        void onAcceptNewDocumentParamsCommand(
          int documentWidthPx, int documentHeightPx, float documentResolutionPpi,
          AbstractModel::Properties::ColorModel colorModel, AbstractModel::Properties::BitDepth bitDepth
        );
      private:
        View::IViewManager *m_viewManager;
        View::ICreateNewDocumentView *m_createNewDocumentView;

        AbstractModel::Services::IDocumentCreationService *m_documentCreationService;
      };
    }
  }
}

#endif