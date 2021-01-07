#ifndef SDF_IMPL_UILAYER_IMPL_FRAMEWORK_MVCOBSERVABLE_HPP
#define SDF_IMPL_UILAYER_IMPL_FRAMEWORK_MVCOBSERVABLE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCObservable.hpp
 * PURPOSE: Provides a template for the boilerplate for MVC observables. Wraps Boost::Signals2.
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

#include <SDF/Impl/UILayer/Impl/Framework/IMVCObserver.hpp>

#include <boost/signals2/signal.hpp>

namespace SDF::Impl::UILayer::Impl::Framework {
  template<class EventType>
  class MVCObservable {
  public:
    MVCObservable() {}

    boost::signals2::connection attachObserver(IMVCObserver<EventType> *observer) {
      return m_signal.connect([=](EventType e) { observer->notify(e); });
    }
  protected:
    void notifyObservers(EventType event) {
      m_signal(event);
    }
  private:
    boost::signals2::signal<void (EventType)> m_signal;
  };
}

#endif
