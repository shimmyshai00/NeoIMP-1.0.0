#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_MVCVIEWBASE_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_MVCVIEWBASE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCViewBase.hpp
 * PURPOSE: Provides a base for MVC views.
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
#include <SDF/Impl/UILayer/Impl/Framework/MVCViewEvent.hpp>

#include <memory>
#include <vector>

namespace SDF::Impl::UILayer::Impl::Framework {
  class IMVCController;

  class MVCViewBase : public virtual IMVCView {
  public:
    MVCViewBase();
    ~MVCViewBase();

    IMVCView *getParent();
    IMVCView *getFirstChild();
    IMVCView *getNextSibling();

    IMVCView *addChildAtBeginning(std::unique_ptr<IMVCView> child);
    IMVCView *addSiblingAfter(std::unique_ptr<IMVCView> sibling);

    std::unique_ptr<IMVCView> removeChild(IMVCView *child);

    void addController(std::unique_ptr<IMVCController> controller);
  protected:
    void dispatchEvent(MVCViewEvent e);
  private:
    IMVCView *m_parent;
    std::unique_ptr<IMVCView> m_firstChild;
    std::unique_ptr<IMVCView> m_nextSibling;

    std::vector<std::unique_ptr<IMVCController>> m_controllers;
  };
}

#endif
