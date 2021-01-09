#ifndef SDF_IMPL_UILAYER_IMPL_FRAMEWORK_MVCTREENODE_HPP
#define SDF_IMPL_UILAYER_IMPL_FRAMEWORK_MVCTREENODE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCTreeNode.hpp
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

#include <SDF/Impl/UILayer/Impl/Framework/IMVCHierarchyObject.hpp>

namespace SDF::Impl::UILayer::Impl::Framework {
  template<class T>
  class MVCTreeNode : public IMVCHierarchyObject<T> {
  public:
    MVCTreeNode();
    ~MVCTreeNode();

    T *downcast();

    IMVCHierarchyObject<T> *getParent();
    IMVCHierarchyObject<T> *getFirstChild();
    IMVCHierarchyObject<T> *getNextSibling();

    void addChild(std::unique_ptr<MVCTreeNode<T>> newChild);
    std::unique_ptr<MVCTreeNode<T>> unlink();
  private:
    MVCTreeNode<T> *m_parent;
    std::unique_ptr<MVCTreeNode<T>> m_firstChild;
    std::unique_ptr<MVCTreeNode<T>> m_nextSibling;
  };
}

#include "SDF/Impl/UILayer/Impl/Framework/MVCTreeNode.tpp"

#endif
