#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_IVIEWMANAGER_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_IVIEWMANAGER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IViewManager.hpp
 * PURPOSE: Defines an interface for the view manager. The purpose of the view manager is to isolate the controllers
 *          from how views are composed together as a layout, not just what widget systems are used to implement them.
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

#include <SDF/Impl/UILayer/AbstractModel/Handle.hpp>

#include <memory>

namespace SDF::Impl::UILayer::Impl::View {
  class IApplicationView;
  class INewDocumentView;
  class IOpenDocumentsView;
  class ISaveDocumentView;
  class IDocumentView;

  class IViewManager {
  public:
    virtual ~IViewManager() = default;

    // Commands.
    virtual void createDocumentView(AbstractModel::Handle documentHandle) = 0;
    virtual void removeDocumentView(AbstractModel::Handle documentHandle) = 0;

    // View access.
    virtual IApplicationView *getApplicationView() = 0;
    virtual INewDocumentView *getNewDocumentView() = 0;
    virtual IOpenDocumentsView *getOpenDocumentsView() = 0;
    virtual IDocumentView *getDocumentView(AbstractModel::Handle documentHandle) = 0;
  };
}

#endif
