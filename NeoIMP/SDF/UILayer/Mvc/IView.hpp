#ifndef SDF_UILAYER_MVC_IVIEW_HPP
#define SDF_UILAYER_MVC_IVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IView.hpp
 * PURPOSE: Defines the IView interface.
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

#include "../../Patterns/IConnection.hpp"
#include "IController.hpp"

#include <string>
#include <memory>

namespace SDF::UILayer::Mvc {
  // Class:      IView
  // Purpose:    Defines an interface for MVC views.
  // Parameters: None.
  class IView {
  public:
    virtual ~IView() = default;

    // Function:   getParent
    // Purpose:    Get the parent view of this view in the view hierarchy.
    // Parameters: None.
    // Returns:    A pointer to the parent view.
    virtual IView *
    getParent() = 0;

    // Function:   getFirstChild
    // Purpose:    Get the first child view of this view in the view hierarchy.
    // Parameters: None.
    // Returns:    A pointer to the first child view.
    virtual IView *
    getFirstChild() = 0;

    // Function:   getNextSibling
    // Purpose:    Get the next sibling view of this view in the view hierarchy.
    // Parameters: None.
    // Returns:    A pointer to the next sibling view.
    virtual IView *
    getNextSibling() = 0;

    // Function:   getViewId
    // Purpose:    Get a string identifier for what view this is.
    // Parameters: None.
    // Returns:    The view ID as a string.
    virtual std::string
    getViewId() const = 0;

    // Function:   show
    // Purpose:    Displays the view.
    // Parameters: None.
    // Returns:    None.
    virtual void
    show() = 0;

    // Function:   destroyView
    // Purpose:    Destroys this view, removing it from the view hierarchy. Users should not regard
    //             pointers to it as valid after calling this; however, the actual deletion time is
    //             left to the implementation.
    // Parameters: None.
    // Returns:    None.
    virtual void
    destroyView() = 0;

    // Function:   hookOnDestroy
    // Purpose:    Hook the destroy event to a controller.
    // Parameters: controller - The controller to hook.
    // Returns:    A connection object for the hook.
    virtual Patterns::PIConnection
    hookOnDestroy(std::unique_ptr<IController<>> controller) = 0;
  };
}

#endif
