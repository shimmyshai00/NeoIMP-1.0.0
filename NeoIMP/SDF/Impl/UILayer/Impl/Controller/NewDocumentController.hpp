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

#include <boost/signals2/connection.hpp>

namespace SDF::Impl::UILayer {
  namespace AbstractModel::Services {
    class IDocumentCreationService;
  }

  namespace Impl {
    namespace View {
      class INewDocumentView;
    }

    namespace Controller {
      class NewDocumentController {
      public:
        NewDocumentController(
          AbstractModel::Services::IDocumentCreationService *documentCreationService,
          View::INewDocumentView *newDocumentView
        );

        void createNewDocument();
      private:
        AbstractModel::Services::IDocumentCreationService *m_documentCreationService;

        View::INewDocumentView *m_newDocumentView;
      };
    }
  }
}

#endif
