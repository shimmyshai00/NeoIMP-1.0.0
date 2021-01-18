#ifndef SDF_IMPL_FRAMEWORK_MVCVIEWCAST_HPP
#define SDF_IMPL_FRAMEWORK_MVCVIEWCAST_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCViewCast.hpp
 * PURPOSE: Casts a unique_ptr to a view to one for its view hierarchy node. Useful for adding views to a view
 *          hierarchy.
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

#include <SDF/Impl/Framework/MVCViewNode.hpp>
#include <SDF/Impl/Framework/IMVCView.hpp>

#include <memory>

namespace SDF::Impl::Framework {
  template<class V>
  std::unique_ptr<MVCViewNode> MVCViewCast(std::unique_ptr<V> view) {
    V *viewPtr = view.release();
    return std::unique_ptr<MVCViewNode>(&viewPtr->getViewHierarchy());
  }
}

#endif
