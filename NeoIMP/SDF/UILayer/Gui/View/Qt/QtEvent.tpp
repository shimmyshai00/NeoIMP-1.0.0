#ifndef SDF_UILAYER_GUI_QT_VIEW_QTEVENT_TPP
#define SDF_UILAYER_GUI_QT_VIEW_QTEVENT_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Event.tpp
 * PURPOSE: Implements the Event template.
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

namespace SDF::UILayer::Gui::View::Qt::Impl {
  template<class ... ControllerArgs>
  class QtEventConn : public Patterns::IConnection {
  public:
    QtEventConn(std::list<std::unique_ptr<Mvc::IController<ControllerArgs...>>>
                  *controllerList,
                std::unique_ptr<Mvc::IController<ControllerArgs...>> controller
               )
      : m_controllerList(controllerList),
        m_controller(std::move(controller)),
        m_controllerPtr(nullptr)
    {
    }

    void
    connect() {
      if(m_controllerPtr == nullptr) {
        m_controllerPtr = m_controller.get();
        m_controllerList->push_back(std::move(m_controller));
      }
    }

    void
    disconnect() {
      if(m_controllerPtr != nullptr) {
        for(typename std::list<
            std::unique_ptr<Mvc::IController<ControllerArgs...>>
          >::iterator
          it(m_controllerList->begin()); it != m_controllerList->end(); ++it)
        {
          if(it->get() == m_controllerPtr) {
            m_controller = std::move(*it);
            m_controllerList->erase(it);

            m_controllerPtr = nullptr;
          }
        }
      }
    }
  private:
    std::list<std::unique_ptr<Mvc::IController<ControllerArgs...>>> *
      m_controllerList;
    std::unique_ptr<Mvc::IController<ControllerArgs...>> m_controller;
    Mvc::IController<ControllerArgs...> *m_controllerPtr;
  };
}

namespace SDF::UILayer::Gui::View::Qt {
  template<class ... ControllerArgs>
  QtEvent<ControllerArgs...>::QtEvent() {
  }

  template<class ... ControllerArgs>
  Patterns::PIConnection
  QtEvent<ControllerArgs...>::hook(
    std::unique_ptr<Mvc::IController<ControllerArgs...>> controller
  ) {
    return Patterns::PIConnection(new Impl::QtEventConn<ControllerArgs...>(
      &m_controllers, std::move(controller)));
  }

  template<class ... ControllerArgs>
  void
  QtEvent<ControllerArgs...>::trigger(ControllerArgs... args) {
    for(typename std::list<std::unique_ptr<Mvc::IController<ControllerArgs...>>>
      ::iterator
      it(m_controllers.begin()); it != m_controllers.end(); ++it)
    {
      (*it)->onTrigger(args...);
    }
  }
}

#endif
