#ifndef SDF_UILAYER_QT_VIEW_HOOK_HPP
#define SDF_UILAYER_QT_VIEW_HOOK_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Hook.hpp
 * PURPOSE: Defines the Hook template.
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

#include "IController.hpp"

#include <QMetaObject>
#include <QObject>

#include <memory>

namespace SDF::UILayer::Qt::View {
  // Class:      Hook
  // Purpose:    Wraps a hook of a Qt signal item to a controller so that only one controller is permitted at a time
  //             and they can easily be changed dynamically. Also provides exception handling for errors from the
  //             controller.
  // Parameters: QObjT - The type of QObject to hook.
  //             Args - The signal arguments.
  template<class QObjT, class ... Args>
  class Hook {
  public:
    Hook(QObjT *src,
         void (QObjT::*srcSignal)(Args...)
        );

    void
    hook(std::unique_ptr<IController<Args...>> controller);
  private:
    QObjT *m_src;
    void (QObjT::*m_srcSignal)(Args...);

    std::unique_ptr<IController<Args...>> m_controller;
    QMetaObject::Connection m_conn;
  };
}

#include "Hook.tpp"

#endif
