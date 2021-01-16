/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCViewBase.cpp
 * PURPOSE: Provides a base for MVC views. Note: This code presumes that all MVC views are to inherit from this base.
 *          The interface should only be used to define other view interfaces.
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

#include <MVCViewBase.hpp>
#include <UILayer/Exceptions/Exceptions.hpp>

#include <IMVCController.hpp>

#include <cassert>

namespace SDF::Impl::UILayer::Impl::Framework {
  MVCViewBase::MVCViewBase() : m_parent(nullptr) {}

  MVCViewBase::~MVCViewBase() {}

  IMVCView *MVCViewBase::getParent() {
    return m_parent;
  }

  IMVCView *MVCViewBase::getFirstChild() {
    return m_firstChild.get();
  }

  IMVCView *MVCViewBase::getNextSibling() {
    return m_nextSibling.get();
  }

  IMVCView *MVCViewBase::addChildAtBeginning(std::unique_ptr<IMVCView> child) {
    auto *childBase(dynamic_cast<MVCViewBase *>(child.get()));
    assert(childBase != nullptr);

    childBase->m_parent = this;
    childBase->m_nextSibling = std::move(m_firstChild);
    m_firstChild = std::move(child);

    return childBase;
  }

  IMVCView *MVCViewBase::addSiblingAfter(std::unique_ptr<IMVCView> sibling) {
    auto *siblingBase(dynamic_cast<MVCViewBase *>(sibling.get()));
    assert(siblingBase != nullptr);

    siblingBase->m_parent = this;
    siblingBase->m_nextSibling = std::move(m_nextSibling);
    m_nextSibling = std::move(sibling);

    return siblingBase;
  }

  std::unique_ptr<IMVCView> MVCViewBase::removeChild(IMVCView *child) {
    auto *childBase(dynamic_cast<MVCViewBase *>(child));
    assert(childBase != nullptr);

    IMVCView *curChild(getFirstChild());
    if(curChild == child) {
      std::unique_ptr<IMVCView> rv(std::move(m_firstChild));

      childBase->m_parent = nullptr;
      m_firstChild = std::move(childBase->m_nextSibling);

      return std::move(rv);
    } else {
      while((curChild->getNextSibling() != child) && (curChild->getNextSibling() != nullptr)) {
        curChild = curChild->getNextSibling();
      }

      if(curChild->getNextSibling() != nullptr) {
        auto *curChildBase(dynamic_cast<MVCViewBase *>(curChild));
        assert(curChildBase != nullptr);

        std::unique_ptr<IMVCView> rv(std::move(curChildBase->m_nextSibling));
        childBase->m_parent = nullptr;
        curChildBase->m_nextSibling = std::move(childBase->m_nextSibling);

        return std::move(rv);
      } else {
        return std::unique_ptr<IMVCView>();
      }
    }
  }

  void MVCViewBase::addController(std::unique_ptr<IMVCController> controller) {
    m_controllers.push_back(std::move(controller));
  }

  void MVCViewBase::dispatchEvent(MVCViewEvent e) {
    for(auto &controller : m_controllers) {
      controller->onViewEvent(this, e);
    }
  }
}
