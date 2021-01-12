#ifndef SDF_IMPL_UILAYER_IMPL_FRAMEWORK_IMVCVIEW_HPP
#define SDF_IMPL_UILAYER_IMPL_FRAMEWORK_IMVCVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IMVCView.hpp
 * PURPOSE: Provides a general interface for MVC views with basic functionality such as view hierarchy and update
 *          messaging in an abstract, widget system-independent manner.
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

#include <memory>

namespace SDF::Impl::UILayer::Impl::Framework {
  template<class EventType>
  class IMVCController;

  template<class EventType>
  class IMVCView {
  public:
    virtual ~IMVCView() = default;

    virtual IMVCView<EventType> *getParent() = 0;
    virtual IMVCView<EventType> *getFirstChild() = 0;
    virtual IMVCView<EventType> *getNextSibling() = 0;

    // This ownership ensures that when or if the view is destroyed dynamically, the relevant controllers are
    // destroyed along with it, so that both views and controllers can be added and removed dynamically.
    virtual void addController(std::unique_ptr<IMVCController<EventType>> controller) = 0;
  };
}

#endif
