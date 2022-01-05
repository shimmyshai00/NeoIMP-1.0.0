/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewNode.cpp
 * PURPOSE: Implements the ViewNode class.
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

#include "ViewNode.hpp"

namespace SDF::UILayer::Mvc {
  ViewNode::ViewNode()
    : m_parent(nullptr),
      m_firstChild(nullptr),
      m_nextSibling(nullptr)
  {
  }

  ViewNode *
  ViewNode::getParent() {
    return m_parent;
  }

  ViewNode *
  ViewNode::getFirstChild() {
    return m_firstChild;
  }

  ViewNode *
  ViewNode::getNextSibling() {
    return m_nextSibling;
  }

  void
  ViewNode::registerChild(ViewNode *child) {
    child->m_parent = this;

    if(m_firstChild == nullptr) {
      m_firstChild = child;
    } else {
      ViewNode *curChild(m_firstChild);
      while(curChild->m_nextSibling != nullptr) {
        curChild = curChild->m_nextSibling;
      }

      curChild->m_nextSibling = child;
    }
  }

  void
  ViewNode::unregisterSelf() {
    if(m_parent != nullptr) {
      if(m_parent->m_firstChild == this) {
        m_parent->m_firstChild = m_nextSibling;
      } else {
        ViewNode *curChild = m_parent->m_firstChild;
        while(curChild->m_nextSibling != this) {
          curChild = curChild->m_nextSibling;
        }

        curChild->m_nextSibling = m_nextSibling;
      }

      m_parent = nullptr;
    } else {
      // OOPS! TBA: exception throw
    }
  }
}
