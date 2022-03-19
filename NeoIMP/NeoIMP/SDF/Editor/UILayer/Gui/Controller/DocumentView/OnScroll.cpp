/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OnScroll.cpp
 * PURPOSE: Implements the OnHScroll and OnVScroll classes.
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

#include "OnScroll.hpp"

#include <cstdio>

namespace SDF::Editor::UILayer::Gui::Controller::DocumentView {
  OnHScroll::OnHScroll(
    AbstractModel::Viewing::ISetViewXCoordinateService *setViewXCoordinateService
  )
    : m_setViewXCoordinateService(setViewXCoordinateService)
  {
  }

  void
  OnHScroll::onTrigger(Common::Handle documentHandle, float scrollPos) {
    if(m_setViewXCoordinateService != nullptr) {
      m_setViewXCoordinateService->setViewingPointX(documentHandle, scrollPos);
    }
  }
}

namespace SDF::Editor::UILayer::Gui::Controller::DocumentView {
  OnVScroll::OnVScroll(
    AbstractModel::Viewing::ISetViewYCoordinateService *setViewYCoordinateService
  )
    : m_setViewYCoordinateService(setViewYCoordinateService)
  {
  }

  void
  OnVScroll::onTrigger(Common::Handle documentHandle, float scrollPos) {
    if(m_setViewYCoordinateService != nullptr) {
      m_setViewYCoordinateService->setViewingPointY(documentHandle, scrollPos);
    }
  }
}
