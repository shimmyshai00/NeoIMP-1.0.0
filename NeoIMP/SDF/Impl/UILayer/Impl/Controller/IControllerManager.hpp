#ifndef SDF_IMPL_UILAYER_IMPL_CONTROLLER_ICONTROLLERMANAGER_HPP
#define SDF_IMPL_UILAYER_IMPL_CONTROLLER_ICONTROLLERMANAGER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IControllerManager.hpp
 * PURPOSE: Defines an interface for the controller manager. The purpose of the view manager is to isolate the
 *          controllers from how views are composed together as a layout, not just what widget systems are used to
 *          implement them.
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

namespace SDF::Impl::UILayer::Impl {
  namespace View {
    class IApplicationView;
    class INewDocumentView;
    class IOpenDocumentsView;
  }

  class IUIController;

  namespace Controller {
    class IControllerManager {
    public:
      virtual ~IControllerManager() = default;

      virtual void setUIController(IUIController *uiController) = 0;

      virtual void registerApplicationView(View::IApplicationView *applicationView) = 0;
      virtual void registerNewDocumentView(View::INewDocumentView *newDocumentView) = 0;
      virtual void registerOpenDocumentsView(View::IOpenDocumentsView *openDocumentsView) = 0;

      virtual void unregisterApplicationView(View::IApplicationView *applicationView) = 0;
      virtual void unregisterNewDocumentView(View::INewDocumentView *newDocumentView) = 0;
      virtual void unregisterOpenDocumentsView(View::IOpenDocumentsView *openDocumentsView) = 0;
    };
  }
}

#endif
