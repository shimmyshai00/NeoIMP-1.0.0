/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCObject.cpp
 * PURPOSE: Provides a dynamic, hierarchical container base for ownership of MVC views and controllers.
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

#include <MVCObject.hpp>

#include <SDF/Impl/UILayer/Exceptions/Exceptions.hpp>

namespace SDF::Impl::UILayer::Impl::Framework {
  MVCObject::MVCObject() : m_parent(nullptr) {}
  MVCObject::~MVCObject() {}

  // Hierarchy methods.
  MVCObject *MVCObject::getParent() {
    return m_parent;
  }

  MVCObject *MVCObject::getFirstChild() {
    return m_firstChild.get();
  }

  MVCObject *MVCObject::getNextSibling() {
    return m_nextSibling.get();
  }

  void MVCObject::addChild(std::unique_ptr<MVCObject> child) {
    // Add this child to the end of the sibling list.
    if(!m_firstChild) {
      m_firstChild = std::move(child);
    } else {
      MVCObject *curSibling(m_firstChild.get());
      while(curSibling->getNextSibling() != nullptr) {
        curSibling = curSibling->getNextSibling();
      }

      curSibling->m_nextSibling = std::move(child);
    }
  }

  std::unique_ptr<MVCObject> MVCObject::unlink() {
    // Remove this MVC object from its parent.
    if(m_parent == nullptr) {
      // ERROR!
      throw UILayer::Exceptions::RemovedRootException();
    } else {
      // Excise from the sibling list.
      if(m_parent->getFirstChild() == this) {
        std::unique_ptr<MVCObject> selfPtr(std::move(m_parent->m_firstChild));
        m_parent->m_firstChild = std::move(selfPtr->m_nextSibling);

        return std::move(selfPtr);
      } else {
        MVCObject *curSibling(m_parent->m_firstChild.get());
        while(curSibling->getNextSibling() != this) {
          curSibling = curSibling->getNextSibling();
        }

        std::unique_ptr<MVCObject> selfPtr(std::move(curSibling->m_nextSibling));
        curSibling->m_nextSibling = std::move(selfPtr->m_nextSibling);

        return std::move(selfPtr);
      }
    }
  }
}
