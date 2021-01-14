/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCComposableView.cpp
 * PURPOSE: Provides a base for MVC views that can be composed with other views.
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

#include <MVCComposableView.hpp>
#include <UILayer/Exceptions/Exceptions.hpp>

namespace SDF::Impl::UILayer::Impl::Framework {
  MVCComposableView::MVCComposableView() : m_parent(nullptr) {}

  MVCComposableView::~MVCComposableView() {}

  IMVCView *MVCComposableView::getParent() {
    return m_parent;
  }

  IMVCView *MVCComposableView::getFirstChild() {
    return m_firstChild.get();
  }

  IMVCView *MVCComposableView::getNextSibling() {
    return m_nextSibling.get();
  }

  void MVCComposableView::attachChild(std::unique_ptr<MVCComposableView> child) {
    if(!m_firstChild) {
      m_firstChild = std::move(child);
      m_firstChild->m_parent = this;
    } else {
      m_firstChild->attachSibling(std::move(child));
    }
  }

  void MVCComposableView::attachSibling(std::unique_ptr<MVCComposableView> sibling) {
    if(!m_nextSibling) {
      m_nextSibling = std::move(sibling);
      m_nextSibling->m_parent = m_parent;
    } else {
      m_nextSibling->attachSibling(std::move(sibling));
    }
  }

  std::unique_ptr<MVCComposableView> MVCComposableView::removeSelf() {
    if(!m_parent) {
      throw UILayer::Exceptions::RemovedRootException();
    } else {
      if(m_parent->m_firstChild.get() == this) {
        std::unique_ptr<MVCComposableView> rv(std::move(m_parent->m_firstChild));
        m_firstChild = std::move(rv->m_nextSibling);
        rv->m_parent = nullptr;
        return std::move(rv);
      } else {
        MVCComposableView *curSibling(m_parent->m_firstChild.get());
        while(curSibling->m_nextSibling.get() != this) {
          curSibling = curSibling->m_nextSibling.get();
        }

        std::unique_ptr<MVCComposableView> rv(std::move(curSibling->m_nextSibling));
        curSibling->m_nextSibling = std::move(rv->m_nextSibling);
        rv->m_parent = nullptr;
        return std::move(rv);
      }
    }
  }
}
