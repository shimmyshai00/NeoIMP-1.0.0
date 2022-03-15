#ifndef SDF_EDITOR_UILAYER_GUI_IVIEWMANAGER_HPP
#define SDF_EDITOR_UILAYER_GUI_IVIEWMANAGER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IViewManager.hpp
 * PURPOSE: Defines the IViewManager interface.
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

#include "../../../Common/Handle.hpp"
#include "../Support/Bundle.hpp"

#include <memory>

namespace SDF::Editor::UILayer::Gui {
  // Class:      IViewManager
  // Purpose:    Provides a central interface to control the GUI's views.
  // Parameters: ViewEnumT - Enumeration of the available views.
  template<class ViewEnumT>
  class IViewManager {
  public:
    virtual ~IViewManager() = default;

    // Function:   produceView
    // Purpose:    Produce a new view according to a view spec.
    // Parameters: viewType - The type of view to produce.
    //             argBundle - The argument bundle to use to create the view.
    // Returns:    A handle to the produced view.
    virtual Common::Handle
    produceView(ViewEnumT viewType,
                std::shared_ptr<Support::Bundle> argBundle
               ) = 0;

    // Function:   destroyView
    // Purpose:    Destroy a produced view.
    // Parameters: viewHandle - The handle to the view to destroy.
    // Returns:    None.
    virtual void
    destroyView(Common::Handle viewHandle) = 0;

    // Function:   destroyAllOfType
    // Purpose:    Destroy all views of a given type.
    // Parameters: viewType - The type of view to destroy.
    // Returns:    None.
    virtual void
    destroyAllOfType(ViewEnumT viewType) = 0;

    // Function:   destroyAll
    // Purpose:    Destroy all active views.
    // Parameters: None.
    // Returns:    None.
    virtual void
    destroyAll() = 0;
  };
}

#endif
