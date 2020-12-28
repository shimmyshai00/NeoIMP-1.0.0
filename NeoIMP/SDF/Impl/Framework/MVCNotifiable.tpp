/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCNotifiable.tpp
 * PURPOSE: An implementation of the observer pattern for the MVC views and controllers.
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

#include <SDF/Impl/Framework/IMVCObserverHandle.hpp>

namespace SDF::Impl::Framework::Impl {
  // Helper class.
  template<class ... Args>
  class ObserverHandle : public IMVCObserverHandle {
  public:
    ObserverHandle(std::vector<std::function<void (Args ...)>> *funcList, std::function<void (Args ...)> func)
      : m_funcList(funcList),
        m_func(func)
    {}

    void connect() {
      if(std::find(m_funcList->begin(), m_funcList->end(), m_func) == m_funcList->end()) {
        m_funcList->push_back(m_func);
      }
    }

    void disconnect() {
      m_funcList->erase(std::find(m_funcList->begin(), m_funcList->end(), m_func));
    }
  private:
    std::vector<std::function<void (Args ...)>> *m_funcList;
    std::function<void (Args ...)> m_func;
  };
}

namespace SDF::Impl::Framework {
  template<class ... Args>
  MVCNotifiable<Args ...>::MVCNotifiable() {}

  template<class ... Args>
  std::unique_ptr<IMVCObserverHandle> MVCNotifiable<Args ...>::attachObserver(std::function<void (Args ...)> func) {
    return std::make_unique<Impl::ObserverHandle<Args ...>>(&m_funcList, func);
  }

  template<class ... Args>
  void MVCNotifiable<Args ...>::notify(Args... args) {
    for(auto f : m_funcList) {
      f(args...);
    }
  }
}
