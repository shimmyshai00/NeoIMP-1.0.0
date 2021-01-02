#ifndef SDF_IMPL_UILAYER_IMPL_FRAMEWORK_MVCEVENTBINDING_HPP
#define SDF_IMPL_UILAYER_IMPL_FRAMEWORK_MVCEVENTBINDING_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCEventBinding.hpp
 * PURPOSE: Provides a binding between MVC event sources and sinks. For cutting down on boilerplate.
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

#include <SDF/Impl/UILayer/Impl/Framework/IMVCViewEventHook.hpp>
#include <SDF/Impl/UILayer/Impl/Framework/IMVCControllerEventHandler.hpp>

#include <boost/signals2/connection.hpp>

#include <map>
#include <vector>

namespace SDF::Impl::UILayer::Impl::Framework {
  // Defines bindings for a whole type of events.
  template<class EventType>
  class MVCEventBinding {
  public:
    ~MVCEventBinding() {
      //for(auto &vec : m_bindings) {
        //for(auto &conn : vec) {
      //    conn.disconnect();
        //}
      //}
    }

    void bindEventSource(IMVCViewEventHook<EventType> *src, IMVCControllerEventHandler<EventType> *sink) {
      m_bindings[src].push_back(src->connectEventListener([=](EventType e) { sink->handleEvent(e); }));
    }

    void releaseEventSource(IMVCViewEventHook<EventType> *src) {
      for(auto &conn : m_bindings[src]) {
        conn.disconnect();
      }

      m_bindings.erase(src);
    }
  private:
    std::map<IMVCViewEventHook<EventType> *, std::vector<boost::signals2::connection>> m_bindings;
  };
}

#endif
