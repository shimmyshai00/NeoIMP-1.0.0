/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MVCMasterController.cpp
 * PURPOSE: A base class for MVC "master controllers" which hold a list of, and are meant to dynamically create and
 *          destroy, view units.
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

#include <MVCMasterController.hpp>
#include <algorithm>

namespace SDF::Impl::UILayer::Impl::Framework {
  MVCMasterController::MVCMasterController() {}

  void MVCMasterController::addOwnable(std::unique_ptr<MVCViewUnit> ownable) {
    (static_cast<IMVCOwnable<MVCViewUnit> *>(ownable.get()))->setOwner(this); // yeegh :(
    m_viewUnits.push_back(std::move(ownable));
  }

  std::unique_ptr<MVCViewUnit> MVCMasterController::removeOwnable(MVCViewUnit *ownable) {
    std::vector<std::unique_ptr<MVCViewUnit>>::iterator it(m_viewUnits.begin());

    while(it->get() != ownable) {
      ++it;
    }

    std::unique_ptr<MVCViewUnit> rv(std::move(*it));
    m_viewUnits.erase(it);

    return std::move(rv);
  }
}
