/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCView.tpp
 * PURPOSE: The base for MVC view objects that implements the relevant boilerplate.
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

#include <SDF/Impl/Framework/IMVCController.hpp>

namespace SDF::Impl::Framework {
  template<class M>
  MVCStateView<M>::MVCStateView()
    : m_appModel(nullptr)
  {}

  template<class M>
  MVCStateView<M>::~MVCStateView() {}

  template<class M>
  M *
  MVCStateView<M>::getAppModel() {
    return m_appModel;
  }

  template<class M>
  void
  MVCStateView<M>::setAppModel(M *appModel) {
    disconnectAll();
    m_appModel = appModel;
    onAttachAppModel();
  }
}

namespace SDF::Impl::Framework {
  template<class V>
  MVCInteractiveView<V>::~MVCInteractiveView() {}

  template<class V>
  void
  MVCInteractiveView<V>::addController(std::unique_ptr<IMVCController<V>> controller) {
    controller->setView(this);
    m_controllers.push_back(std::move(controller));
  }
}
