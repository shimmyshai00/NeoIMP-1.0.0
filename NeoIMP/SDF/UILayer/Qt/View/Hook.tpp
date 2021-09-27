#ifndef SDF_UILAYER_QT_VIEW_HOOK_TPP
#define SDF_UILAYER_QT_VIEW_HOOK_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Hook.tpp
 * PURPOSE: Implements the Hook template.
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

namespace SDF::UILayer::Qt::View {
  template<class QObjT, class ... Args>
  Hook<QObjT, Args...>::Hook(QObjT *src,
                             void (QObjT::*srcSignal)(Args...)
                            )
    : m_src(src),
      m_srcSignal(srcSignal)
  {}

  template<class QObjT, class ... Args>
  void
  Hook<QObjT, Args...>::hook(std::unique_ptr<IController<Args...>> controller) {
    if(m_controller) {
      QObject::disconnect(m_conn);
    }

    m_controller = std::move(controller);
    m_conn = QObject::connect(m_src, m_srcSignal, [&](Args... args) { m_controller->handle(args...); });
  }
}

#endif
