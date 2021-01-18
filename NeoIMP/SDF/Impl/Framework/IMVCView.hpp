#ifndef SDF_IMPL_FRAMEWORK_IMVCVIEW_HPP
#define SDF_IMPL_FRAMEWORK_IMVCVIEW_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IMVCView.hpp
 * PURPOSE: Provides the common interface for MVC view objects.
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

#include <memory>

namespace SDF::Impl::Framework {
  class MVCViewNode;

  template<class VObs>
  class IMVCController;

  // The common interface for all view types.
  class IMVCView {
  public:
    virtual ~IMVCView() = default;

    virtual MVCViewNode &getViewHierarchy() = 0;
  };

  // For views that show model state.
  template<class MObs>
  class IMVCStateView : public virtual IMVCView {
  public:
    virtual ~IMVCStateView() = default;
    virtual void connectToModelObservables(MObs &observables) = 0;
  };

  // For views that provide interaction.
  template<class VObs>
  class IMVCInteractiveView : public virtual IMVCView {
  public:
    virtual ~IMVCInteractiveView() = default;
    virtual void addController(std::unique_ptr<IMVCController<VObs>> controller) = 0;
  };
}

#endif
