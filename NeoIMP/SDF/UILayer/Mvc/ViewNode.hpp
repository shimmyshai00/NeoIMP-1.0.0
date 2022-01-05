#ifndef SDF_UILAYER_MVC_VIEWNODE_HPP
#define SDF_UILAYER_MVC_VIEWNODE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewNode.hpp
 * PURPOSE: Defines the ViewNode class.
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

#include "IView.hpp"

namespace SDF::UILayer::Mvc {
  // Class:      ViewNode
  // Purpose:    Implements the widget system-agnostic hierarchy management
  //             functionality.
  // Parameters: None.
  class ViewNode : public virtual IView {
  public:
    ViewNode();

    ViewNode *
    getParent();

    ViewNode *
    getFirstChild();

    ViewNode *
    getNextSibling();

    // Function:   registerChild
    // Purpose:    Registers a view as a child in the widget system-agnostic
    //             view hierarchy. Note that ownership is not affected.
    //             Ownership is meant to be handled by the widget system.
    // Parameters: child - The child view to add.
    // Returns:    None.
    void
    registerChild(ViewNode *child);

    // Function:   unregisterSelf
    // Purpose:    Unregister this view node from the widget system-agnostic
    //             view hierarchy. Note again that ownership is not affected.
    // Parameters: None.
    // Returns:    None.
    void
    unregisterSelf();
  private:
    ViewNode *m_parent;
    ViewNode *m_firstChild;
    ViewNode *m_nextSibling;
  };
}

#endif
