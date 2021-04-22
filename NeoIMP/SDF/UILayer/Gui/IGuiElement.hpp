#ifndef SDF_UILAYER_GUI_IGUIELEMENT_HPP
#define SDF_UILAYER_GUI_IGUIELEMENT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IGuiElement.hpp
 * PURPOSE: Defines the IGuiElement interface.
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

namespace SDF::UILayer::Gui {
  // Class:      IGuiElement
  // Purpose:    Provides an interface for GUI elements (or "views" to use the MVC terminology, but this class also
  //             defines behavior specific to them as in a GUI vs. other types of view we might use).
  // Parameters: NodeType - The type of hierarchy node used by these elements to own each other.
  template<class NodeType>
  class IGuiElement {
  public:
    virtual ~IGuiElement() = default;

    // Function:   getParent
    // Purpose:    Get the parent of this GUI element in the composition hierarchy.
    // Parameters: None.
    // Returns:    The parent GUI element, or nullptr if no parent (i.e. this is the root of a hierarchy).
    virtual IGuiElement<NodeType> *
    getParent() = 0;

    // Function:   show
    // Purpose:    Displays the GUI element on the screen.
    // Parameters: None.
    // Returns:    None.
    virtual void
    show() = 0;

    // Function:   close
    // Purpose:    Removes the GUI element from the screen.
    // Parameters: None.
    // Returns:    None.
    virtual void
    close() = 0;
  };
}

#endif
