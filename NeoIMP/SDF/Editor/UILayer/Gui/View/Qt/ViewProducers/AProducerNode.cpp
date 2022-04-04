/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    AProducerNode.cpp
 * PURPOSE: Implements the AProducerNode class.
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

#include "AProducerNode.hpp"

namespace SDF::Editor::UILayer::Gui::View::Qt::ViewProducers {
  AProducerNode::AProducerNode(Common::Handle a_id, AProducerNode *a_parent)
    : m_id(a_id),
      m_parent(a_parent)
  {
    // Give the parent ownership of us.
    if(m_parent != nullptr) {
      if(!m_parent->m_firstChild) {
        m_parent->m_firstChild = std::unique_ptr<AProducerNode>(this);
      } else {
        AProducerNode *child(m_parent->m_firstChild.get());
        while(child->m_nextSibling) {
          child = child->m_nextSibling.get();
        }

        child->m_nextSibling = std::unique_ptr<AProducerNode>(this);
      }
    }
  }

  Common::Handle
  AProducerNode::getId() const {
    return m_id;
  }

  AProducerNode *
  AProducerNode::getParent() {
    return m_parent;
  }

  AProducerNode *
  AProducerNode::getFirstChild() {
    return m_firstChild.get();
  }

  AProducerNode *
  AProducerNode::getNextSibling() {
    return m_nextSibling.get();
  }

  std::unique_ptr<AProducerNode>
  AProducerNode::removeFirstChild() {
    std::unique_ptr<AProducerNode> rv(std::move(m_firstChild));
    if(rv) {
      m_firstChild = std::move(rv->m_nextSibling);
    }

    return std::move(rv);
  }

  std::unique_ptr<AProducerNode>
  AProducerNode::removeNextSibling() {
    std::unique_ptr<AProducerNode> rv(std::move(m_nextSibling));
    if(rv) {
      m_nextSibling = std::move(rv->m_nextSibling);
    }

    return std::move(rv);
  }
}
