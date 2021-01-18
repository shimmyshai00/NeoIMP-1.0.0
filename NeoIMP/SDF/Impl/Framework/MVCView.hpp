#ifndef SDF_IMPL_FRAMEWORK_MVCVIEW_HPP
#define SDF_IMPL_FRAMEWORK_MVCVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCView.hpp
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

#include <SDF/Impl/Framework/IMVCView.hpp>
#include <SDF/Impl/Framework/MVCViewNode.hpp>
#include <SDF/Impl/Framework/MVCDynamicObserver.hpp>

#include <vector>
#include <memory>

namespace SDF::Impl::Framework {
  template<class VObs>
  class MVCController;

  class MVCView : public virtual IMVCView, public MVCViewNode {
  public:
    virtual ~MVCView() = 0;

    MVCViewNode &getViewHierarchy();
  };

  template<class MObs>
  class MVCStateView : public IMVCStateView<MObs>, public virtual MVCView {
  public:
    virtual ~MVCStateView() = 0;

    virtual void connectToModelObservables(MObs &observables) = 0;
  };

  template<class VObs>
  class MVCInteractiveView : public virtual IMVCInteractiveView<VObs>,
                             public virtual MVCView,
                             public MVCDynamicObserver
  {
  public:
    virtual ~MVCInteractiveView() = 0;

    void addController(std::unique_ptr<IMVCController<VObs>> controller);
  protected:
    VObs m_viewObservables;
  private:
    std::vector<std::unique_ptr<IMVCController<VObs>>> m_controllers;
  };
}

#include "SDF/Impl/Framework/MVCView.tpp"

#endif
