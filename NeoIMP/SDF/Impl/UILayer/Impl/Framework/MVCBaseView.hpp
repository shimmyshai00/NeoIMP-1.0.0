#ifndef SDF_IMPL_UILAYER_IMPL_VIEW_MVCBASEVIEW_HPP
#define SDF_IMPL_UILAYER_IMPL_VIEW_MVCBASEVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCBaseView.hpp
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

#include <SDF/Impl/UILayer/Impl/Framework/IMVCView.hpp>

#include <memory>
#include <vector>

namespace SDF::Impl::UILayer::Impl::Framework {
  template<class EventType>
  class IMVCController;

  template<class EventType>
  class MVCBaseView : public IMVCView<EventType> {
  public:
    MVCBaseView();
    virtual ~MVCBaseView() = 0;

    IMVCView<EventType> *getParent();
    IMVCView<EventType> *getFirstChild();
    IMVCView<EventType> *getNextSibling();

    void addController(std::unique_ptr<IMVCController<EventType>> controller);
  protected:
    void addChild(std::unique_ptr<MVCBaseView> child);
    std::unique_ptr<MVCBaseView> removeSelf();

    void dispatchEvent(EventType &event);
  private:
    IMVCView<EventType> *m_parent;
    std::unique_ptr<MVCBaseView> m_firstChild;
    std::unique_ptr<MVCBaseView> m_nextSibling;

    std::vector<std::unique_ptr<IMVCController<EventType>> m_controllers;
  };
}

#include "SDF/Impl/UILayer/Impl/Framework/MVCBaseView.tpp"

#endif
