#ifndef SDF_UILAYER_VIEW_IVIEWMANAGER_HPP
#define SDF_UILAYER_VIEW_IVIEWMANAGER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IViewManager.hpp
 * PURPOSE: Interface for a manager object that owns and manages the relationships between views. The details will
 *          depend on the widget package used.
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

namespace SDF::UILayer::View {
  class IApplicationView;
  class IGetNewDocumentSettingsView;

  class IViewManager {
  public:
    virtual ~IViewManager() = default;

    virtual IApplicationView *getApplicationView() = 0;
    virtual IGetNewDocumentSettingsView *getGetNewDocumentSettingsView() = 0;
  };
}

#endif
