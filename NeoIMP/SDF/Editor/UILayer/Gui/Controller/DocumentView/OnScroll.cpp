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
    AbstractModel::Viewing::ISetViewXCoordinateService *a_setViewXCoordinateService
  )
    : m_setViewXCoordinateService(a_setViewXCoordinateService)
  {
  }

  void
  OnHScroll::onTrigger(Common::Handle a_documentHandle, float a_scrollPos) {
    if(m_setViewXCoordinateService != nullptr) {
      m_setViewXCoordinateService->setViewingPointX(a_documentHandle, a_scrollPos);
    }
  }
}

namespace SDF::Editor::UILayer::Gui::Controller::DocumentView {
  OnVScroll::OnVScroll(
    AbstractModel::Viewing::ISetViewYCoordinateService *a_setViewYCoordinateService
  )
    : m_setViewYCoordinateService(a_setViewYCoordinateService)
  {
  }

  void
  OnVScroll::onTrigger(Common::Handle a_documentHandle, float a_scrollPos) {
    if(m_setViewYCoordinateService != nullptr) {
      m_setViewYCoordinateService->setViewingPointY(a_documentHandle, a_scrollPos);
    }
  }
}
