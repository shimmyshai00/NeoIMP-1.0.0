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

namespace SDF::UILayer::Gui::Controller::DocumentView {
  OnHScroll::OnHScroll(AbstractModel::ISetViewCoordinatesService *setViewCoordinatesService)
    : m_setViewCoordinatesService(setViewCoordinatesService)
  {
  }

  void
  OnHScroll::onTrigger(Common::Handle documentHandle,
                       float scrollPos
                      )
  {
    if(m_setViewCoordinatesService != nullptr) {
      m_setViewCoordinatesService->setViewingPointX(documentHandle, scrollPos);
    }
  }
}

namespace SDF::UILayer::Gui::Controller::DocumentView {
  OnVScroll::OnVScroll(AbstractModel::ISetViewCoordinatesService *setViewCoordinatesService)
    : m_setViewCoordinatesService(setViewCoordinatesService)
  {
  }

  void
  OnVScroll::onTrigger(Common::Handle documentHandle,
                       float scrollPos
                      )
  {
    if(m_setViewCoordinatesService != nullptr) {
      m_setViewCoordinatesService->setViewingPointY(documentHandle, scrollPos);
    }
  }
}
