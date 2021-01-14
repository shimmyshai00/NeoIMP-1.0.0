#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_MVCCOMPOSABLEVIEW_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_MVCCOMPOSABLEVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCComposableView.hpp
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

#include <SDF/Impl/UILayer/Impl/Framework/IMVCView.hpp>
#include <SDF/Impl/UILayer/Impl/Framework/MVCBaseView.hpp>

#include <memory>

namespace SDF::Impl::UILayer::Impl::Framework {
  class MVCComposableView : public MVCBaseView {
  public:
    MVCComposableView();
    ~MVCComposableView();

    IMVCView *getParent();
    IMVCView *getFirstChild();
    IMVCView *getNextSibling();

    virtual void show() = 0;
    virtual void close() = 0;

    void attachChild(std::unique_ptr<MVCComposableView> child);
    void attachSibling(std::unique_ptr<MVCComposableView> sibling);

    std::unique_ptr<MVCComposableView> removeSelf();
  private:
    MVCComposableView *m_parent;
    std::unique_ptr<MVCComposableView> m_firstChild;
    std::unique_ptr<MVCComposableView> m_nextSibling;
  };
}

#endif
