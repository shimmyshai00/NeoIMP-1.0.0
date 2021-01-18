/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCViewNode.cpp
 * PURPOSE: The hierarchical container for MVC views.
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

#include <MVCViewNode.hpp>
//#include <SDF/Impl/UILayer/Exceptions/Exceptions.hpp>

namespace SDF::Impl::Framework {
  MVCViewNode::MVCViewNode() : m_parent(nullptr) {}
  MVCViewNode::~MVCViewNode() {}

  MVCViewNode *MVCViewNode::getParent() {
    return m_parent;
  }

  MVCViewNode *MVCViewNode::getFirstChild() {
    return m_firstChild.get();
  }

  MVCViewNode *MVCViewNode::getNextSibling() {
    return m_nextSibling.get();
  }

  void MVCViewNode::addChildAtBeginning(std::unique_ptr<MVCViewNode> child) {
    child->m_nextSibling = std::move(m_firstChild);
    m_firstChild = std::move(child);

    onChildAdded(m_firstChild.get());
  }

  void MVCViewNode::addChildAfter(MVCViewNode *addAfter, std::unique_ptr<MVCViewNode> child) {
    child->m_nextSibling = std::move(addAfter->m_nextSibling);
    addAfter->m_nextSibling = std::move(child);

    onChildAdded(addAfter->m_nextSibling.get());
  }

  void MVCViewNode::addChildAtEnd(std::unique_ptr<MVCViewNode> child) {
    MVCViewNode *curChild(m_firstChild.get());
    while(curChild->m_nextSibling) {
      curChild = curChild->m_nextSibling.get();
    }

    addChildAfter(curChild, std::move(child));
  }

  std::unique_ptr<MVCViewNode> MVCViewNode::removeSelf() {
    if(m_parent != nullptr) {
      m_parent->onChildRemoved(this);

      if(m_parent->m_firstChild.get() == this) {
        std::unique_ptr<MVCViewNode> us(std::move(m_parent->m_firstChild));
        m_parent->m_firstChild = std::move(us->m_nextSibling);
        us->m_parent = nullptr;

        return std::move(us);
      } else {
        MVCViewNode *prevChild(m_parent->m_firstChild.get());
        while(prevChild->m_nextSibling.get() != this) {
          prevChild = prevChild->m_nextSibling.get();
        }

        std::unique_ptr<MVCViewNode> us(std::move(prevChild->m_nextSibling));
        prevChild->m_nextSibling = std::move(us->m_nextSibling);
        us->m_parent = nullptr;

        return std::move(us);
      }
    } else {
      //throw UILayer::Exceptions::RemovedRootException();
      throw "Tried to remove root"; // TBA
    }
  }

  // Protected members.
  void MVCViewNode::onChildAdded(MVCViewNode *child) {}
  void MVCViewNode::onChildRemoved(MVCViewNode *child) {}
}
