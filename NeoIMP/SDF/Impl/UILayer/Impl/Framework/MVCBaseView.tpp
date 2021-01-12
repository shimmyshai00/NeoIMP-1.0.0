/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCBaseView.tpp
 * PURPOSE: The base class for MVC views.
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

#include <SDF/Impl/UILayer/Exceptions/Exceptions.hpp>
#include <SDF/Impl/UILayer/Impl/Framework/IMVCController.hpp>

namespace SDF::Impl::UILayer::Impl::Framework {
  template<class EventType>
  MVCBaseView<EventType>::MVCBaseView() : m_parent(nullptr) {}

  template<class EventType>
  MVCBaseView<EventType>::~MVCBaseView() {}

  template<class EventType>
  IMVCView<EventType> *MVCBaseView<EventType>::getParent() {
    return m_parent;
  }

  template<class EventType>
  IMVCView<EventType> *MVCBaseView<EventType>::getFirstChild() {
    return m_firstChild;
  }

  template<class EventType>
  IMVCView<EventType> *MVCBaseView<EventType>::getNextSibling() {
    return m_nextSibling;
  }

  template<class EventType>
  void MVCBaseView<EventType>::addController(std::unique_ptr<IMVCController<EventType>> controller) {
    m_controllers.push_back(std::move(controller));
  }

  template<class EventType>
  void MVCBaseView<EventType>::addChild(std::unique_ptr<MVCBaseView> child) {
    child->m_parent = this;

    if(!m_firstChild) {
      m_firstChild = std::move(child);
    } else {
      MVCBaseView *curChild(m_firstChild.get());
      while(curChild->m_nextSibling) {
        curChild = curChild->m_nextSibling;
      }

      curChild->m_nextSibling = std::move(child);
    }
  }

  template<class EventType>
  std::unique_ptr<MVCBaseView> MVCBaseView<EventType>::removeSelf() {
    if(m_parent == nullptr) {
      throw UILayer::Exceptions::RemovedRootException();
    } else {
      if(m_parent->m_firstChild == this) {
        std::unique_ptr<MVCBaseView> rv(std::move(m_parent->m_firstChild));
        m_parent->m_firstChild = std::move(rv->m_nextSibling);

        rv->m_parent = nullptr;

        return std::move(rv);
      } else {
        MVCBaseView *curChild(m_firstChild.get());
        while(curChild->m_nextSibling.get() != this) {
          curChild = curChild->m_nextSibling;
        }

        std::unique_ptr<MVCBaseView> rv(std::move(curChild->m_nextSibling));
        curChild->m_nextSibling = std::move(rv->m_nextSibling);

        rv->m_parent = nullptr;

        return std::move(rv);
      }
    }
  }

  template<class EventType>
  void MVCBaseView<EventType>::dispatchEvent(EventType &event) {
    for(auto &controller : m_controllers) {
      controller->handleEvent(event);
    }
  }
}
