#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_IVIEWFACTORY_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_IVIEWFACTORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IViewFactory.hpp
 * PURPOSE: The interface for the view factory.
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

#include <SDF/Impl/UILayer/AbstractAppModel/Handle.hpp>
#include <memory>

namespace SDF::Impl::UILayer::Impl {
  class IUIControl;

  namespace Controller {
    class ControllerFactory;
  }

  namespace View {
    class IApplicationView;
    class INewDocumentView;
    class ISaveDocumentView;
    class IOpenDocumentView;
    class IDocumentView;

    class IViewFactory {
    public:
      virtual ~IViewFactory() = default;

      virtual std::unique_ptr<IApplicationView> createApplicationView(IUIControl *uiControl) = 0;
      virtual std::unique_ptr<INewDocumentView> createNewDocumentView() = 0;
      virtual std::unique_ptr<ISaveDocumentView> createSaveDocumentView() = 0;
      virtual std::unique_ptr<IOpenDocumentView> createOpenDocumentView() = 0;
      virtual std::unique_ptr<IDocumentView> createDocumentView(AbstractAppModel::Handle handle) = 0;
    };
  }
}

#endif
