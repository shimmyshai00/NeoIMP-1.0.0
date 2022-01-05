#ifndef SDF_UILAYER_BASEHOOK_TPP
#define SDF_UILAYER_BASEHOOK_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    BaseHook.tpp
 * PURPOSE: Implements the BaseHook template.
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

namespace SDF::UILayer {
  namespace Impl {
    template<class ... Args>
    class BaseHookConnection : public Patterns::IConnection {
    public:
      BaseHookConnection(
        BaseHook<Args...> *baseHook,
        std::unique_ptr<Patterns::IMvcController<Args...>> controller
      )
        : m_baseHook(baseHook),
          m_controller(std::move(controller)),
          m_controllerPtr(m_controller.get()),
          m_connected(false)
      {
      }

      void
      connect() {
        if(!m_connected) {
          m_baseHook->m_controllers.push_back(std::move(m_controller));
          m_connected = true;
        }
      }

      void
      disconnect() {
        if(m_connected) {
          for(typename
              std::list<std::unique_ptr<Patterns::IMvcController<Args...>>>
                 ::iterator
                it(m_baseHook->m_controllers.begin());
              it != m_baseHook->m_controllers.end();
              ++it
             )
          {
            if(it->get() == m_controllerPtr) {
              m_controller = std::move(*it);
              m_baseHook->m_controllers.erase(it);
              m_connected = false;

              break;
            }
          }
        }
      }
    private:
      BaseHook<Args...> *m_baseHook;
      std::unique_ptr<Patterns::IMvcController<Args...>> m_controller;
      Patterns::IMvcController<Args...> *m_controllerPtr;

      bool m_connected;
    };
  }

  template<class ... Args>
  BaseHook<Args...>::BaseHook() {
  }

  template<class ... Args>
  Patterns::PIConnection
  BaseHook<Args...>::hook(
    std::unique_ptr<Patterns::IMvcController<Args...>> controller
  ) {
    return std::make_shared<Impl::BaseHookConnection<Args...>>(
      this,
      std::move(controller)
    );
  }

  // Function:   trigger
  // Purpose:    Trigger an event.
  // Parameters: args - The trigger arguments.
  // Returns:    None.
  template<class ... Args>
  void
  BaseHook<Args...>::trigger(Args... args) {
    for(typename
        std::list<std::unique_ptr<Patterns::IMvcController<Args...>>>::iterator
          it(m_controllers.begin());
        it != m_controllers.end();
        ++it
       )
    {
      it->onTrigger(args...);
    }
  }
}

#endif
