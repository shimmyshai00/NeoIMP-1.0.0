#ifndef SDF_UILAYER_GUI_QT_VIEW_SAFECONNECT_HPP
#define SDF_UILAYER_GUI_QT_VIEW_SAFECONNECT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    safeConnect.hpp
 * PURPOSE: Defines the safeConnect helper function.
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

#include <iostream>
#include <exception>

namespace SDF::UILayer::Gui::Qt::View {
  // Function:   safeConnect
  // Purpose:    Connect a Qt QObject signal to a functor in an exception-safe way.
  // Parameters: qObj - The QObject to connect to.
  //             signal - The signal to connect to.
  //             func - The functor to connect in a safe way.
  template<typename QObj, typename Functor, typename ... Args>
  QMetaObject::Connection
  safeConnect(QObj *qObj,
              void (QObj::*signal)(Args...),
              Functor func
             )
  {
    return QObject::connect(qObj, signal, [=](Args... args) {
      try {
        func(args...);
      } catch(std::exception &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
      }
    });
  }
}

#endif
