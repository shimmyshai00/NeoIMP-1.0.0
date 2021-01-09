/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCTreeNode.tpp
 * PURPOSE: Provides a base container that implements the hierarchy interface using a linked tree.
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

namespace SDF::Impl::UILayer::Impl::Framework {
  template<class T>
  MVCTreeNode<T>::MVCTreeNode() : m_parent(nullptr) {}

  template<class T>
  MVCTreeNode<T>::~MVCTreeNode() {}

  template<class T>
  T *MVCTreeNode<T>::downcast() {
    return this;
  }

  template<class T>
  IMVCHierarchyObject<T> *MVCTreeNode<T>::getParent() {
    return m_parent;
  }

  template<class T>
  IMVCHierarchyObject<T> *MVCTreeNode<T>::getFirstChild() {
    return m_firstChild.get();
  }

  template<class T>
  IMVCHierarchyObject<T> *MVCTreeNode<T>::getNextSibling() {
    return m_nextSibling.get();
  }

  template<class T>
  void MVCTreeNode<T>::addChild(std::unique_ptr<MVCTreeNode<T>> newChild) {
    if(!m_firstChild) {
      m_firstChild = std::move(newChild);
    } else {
      MVCTreeNode<T> *curChild(m_firstChild.get());
      while(curChild->m_nextSibling) {
        curChild = curChild->m_nextSibling.get();
      }

      curChild->m_nextSibling = std::move(newChild);
    }

    newChild->m_parent = this;
  }

  template<class T>
  std::unique_ptr<MVCTreeNode<T>> MVCTreeNode<T>::unlink() {
    if(m_parent == nullptr) {
      throw UILayer::Exceptions::RemovedRootException();
    } else {
      if(m_parent->m_firstChild.get() == this) {
        std::unique_ptr<MVCTreeNode<T>> rv(std::move(m_parent->m_firstChild));
        m_parent->m_firstChild = std::move(rv->m_nextSibling);

        rv->m_parent = nullptr;

        return std::move(rv);
      } else {
        MVCTreeNode<T> *curChild(m_firstChild.get());
        while(curChild->m_nextSibling.get() != this) {
          curChild = curChild->m_nextSibling.get();
        }

        std::unique_ptr<MVCTreeNode<T>> rv(std::move(curChild->m_nextSibling));
        curChild->m_nextSibling = std::move(rv->m_nextSibling);

        rv->m_parent = nullptr;

        return std::move(rv);
      }
    }
  }
}
