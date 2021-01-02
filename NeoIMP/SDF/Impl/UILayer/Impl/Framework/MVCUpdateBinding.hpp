#ifndef SDF_IMPL_UILAYER_IMPL_FRAMEWORK_MVCUPDATEBINDING_HPP
#define SDF_IMPL_UILAYER_IMPL_FRAMEWORK_MVCUPDATEBINDING_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCUpdateBinding.hpp
 * PURPOSE: Provides a binding between MVC update sources and sinks. For cutting down on boilerplate.
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

#include <SDF/Impl/UILayer/Impl/Framework/IMVCControllerUpdateHook.hpp>
#include <SDF/Impl/UILayer/Impl/Framework/IMVCViewUpdate.hpp>

#include <boost/signals2/connection.hpp>

#include <map>
#include <vector>

namespace SDF::Impl::UILayer::Impl::Framework {
  // Defines bindings for a whole type of updates.
  template<class UpdateType>
  class MVCUpdateBinding {
  public:
    ~MVCUpdateBinding() {
      //for(auto &vec : m_bindings) {
        //for(auto &conn : vec) {
          //conn.disconnect();
        //}
      //}
    }

    void bindUpdateSink(IMVCViewUpdate<UpdateType> *sink, IMVCControllerUpdateHook<UpdateType> *src) {
      m_bindings[sink].push_back(src->connectUpdateDestination([=](UpdateType u) { sink->update(u); }));
    }

    void releaseUpdateSink(IMVCViewUpdate<UpdateType> *sink) {
      for(auto &conn : m_bindings[sink]) {
        conn.disconnect();
      }
    }
  private:
    std::map<IMVCViewUpdate<UpdateType> *, std::vector<boost::signals2::connection>> m_bindings;
  };
}

#endif
