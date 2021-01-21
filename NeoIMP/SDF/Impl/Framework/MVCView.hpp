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
  template<class V>
  class MVCController;

  class MVCView : public virtual IMVCView,
                  public MVCViewNode
  {
  public:
    virtual ~MVCView() = 0;

    MVCViewNode &getViewHierarchy();
  };

  template<class M>
  class MVCStateView : public virtual IMVCStateView<M>,
                       public virtual MVCView,
                       public MVCDynamicObserver {
  public:
    MVCStateView();
    virtual ~MVCStateView() = 0;

    void setAppModel(M *appModel);
  protected:
    M *getAppModel();
    virtual void connectToModelObservables() = 0;
  private:
    M *m_appModel;
  };

  template<class V>
  class MVCInteractiveView : public virtual IMVCInteractiveView<V>,
                             public virtual MVCView,
                             public virtual V
  {
  public:
    virtual ~MVCInteractiveView() = 0;

    void addController(std::unique_ptr<IMVCController<V>> controller);
  private:
    std::vector<std::unique_ptr<IMVCController<V>>> m_controllers;
  };
}

#include "SDF/Impl/Framework/MVCView.tpp"

#endif
