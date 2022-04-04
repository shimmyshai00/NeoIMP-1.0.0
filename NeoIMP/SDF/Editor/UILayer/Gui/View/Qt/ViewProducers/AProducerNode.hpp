#ifndef SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWPRODUCERS_APRODUCERNODE_HPP
#define SDF_EDITOR_UILAYER_GUI_VIEW_QT_VIEWPRODUCERS_APRODUCERNODE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AProducerNode.hpp
 * PURPOSE: Defines the AProducerNode class.
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

#include "../../../../../../Common/Handle.hpp"

#include <QWidget>

#include <memory>

namespace SDF::Editor::UILayer::Gui::View::Qt::ViewProducers {
  // Class:      AProducerNode
  // Purpose:    Defines an abstract base for producers that makes explicit their composition into a
  //             hierarchical structure and avoids variable clutter for storing dynamically-created
  //             child view producers. YES, this kind of structure inevitably re-emerged as in the
  //             dark days of NeoIMP ... Was so hesitant to use it before because it involves
  //             extensive downcast typecasting - trying to figure out how to jostle all these
  //             seemingly conflicting coding rules ...
  // Parameters: None.
  class AProducerNode {
  public:
    // Function:   AProducerNode
    // Purpose:    Build this producer node off another. NOTE: when this class is constructed with
    //             a parent, it becomes owned by that parent, so you should NOT instantiate a
    //             producer on the stack! This is the same methodology Qt uses, by the way.
    // Parameters: id - A unique ID value for this producer node.
    //             parent - The parent to build off of.
    //
    AProducerNode(Common::Handle a_id, AProducerNode *a_parent = nullptr);

    // Function:   getId
    // Purpose:    Gets the all-important unique ID code for this producer node.
    // Parameters: None.
    // Returns:    The node's unique ID code.
    Common::Handle
    getId() const;

    // Function:   getParent
    // Purpose:    Gets the parent of this node.
    // Parameters: None.
    // Returns:    A pointer to the parent, or nullptr if no parent.
    AProducerNode *
    getParent();

    // Function:   getFirstChild
    // Purpose:    Gets the first child of this node.
    // Parameters: None.
    // Returns:    This node's first child.
    AProducerNode *
    getFirstChild();

    // Function:   getNextSibling
    // Purpose:    Gets the next sibling of this node.
    // Parameters: None.
    // Returns:    This node's next sibling.
    AProducerNode *
    getNextSibling();

    // Function:   removeFirstChild
    // Purpose:    Removes the first child of this node.
    // Parameters: None.
    // Returns:    The owning pointer to the child.
    std::unique_ptr<AProducerNode>
    removeFirstChild();

    // Function:   removeNextSibling
    // Purpose:    Removes the next sibling of this node.
    // Parameters: None.
    // Returns:    The owning pointer to the next sibling.
    std::unique_ptr<AProducerNode>
    removeNextSibling();

    // Function:   getViewWidget
    // Purpose:    Obtains the view widget, which may be nullptr if this producer has not been
    //             requested to produce its widget yet. We could even abstract this out of the Qt
    //             subsystem altogether (e.g. make this a #template with a WidgetBaseT parameter),
    //             saving having to reproduce the ViewProducers hierarchy for each 3rd party widget
    //             system libraries we may want to use, and we'd be back to our original NeoIMP
    //             design - want to see how this goes first. (maybe this struct is a decent idea
    //             after all and decent ideas sometimes require downcasting.)
    // Parameters: None.
    // Returns:    An uncast pointer to the view widget.
    virtual QWidget *
    getViewWidget() = 0;

    // Function:   findChildById
    // Purpose:    Finds a child producer by its ID code.
    // Parameters: id - The ID of the child to get.
    // Returns:    A non-owning reference to the child, or nullptr if none (or throw?).
    template<class U>
    U *
    findChildById(Common::Handle id);
  private:
    Common::Handle m_id;
    AProducerNode *m_parent;

    std::unique_ptr<AProducerNode> m_firstChild;
    std::unique_ptr<AProducerNode> m_nextSibling;
  };
}

#include "AProducerNode.tpp"

#endif
