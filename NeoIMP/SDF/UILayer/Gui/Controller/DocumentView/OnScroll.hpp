#ifndef SDF_UILAYER_GUI_CONTROLLER_DOCUMENTVIEW_ONSCROLL_HPP
#define SDF_UILAYER_GUI_CONTROLLER_DOCUMENTVIEW_ONSCROLL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OnScroll.hpp
 * PURPOSE: Defines the OnHScroll and OnVScroll classes.
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

#include "../../../../Common/Handle.hpp"
#include "../../../AbstractModel/ISetViewCoordinatesService.hpp"
#include "../../View/IController.hpp"

namespace SDF::UILayer::Gui::Controller::DocumentView {
  // Class:      OnHScroll
  // Purpose:    Handles a horizontal scroll event.
  // Parameters: None.
  class OnHScroll : public View::IController<Common::Handle, float> {
  public:
    OnHScroll(AbstractModel::ISetViewCoordinatesService *setViewCoordinatesService);

    void
    onTrigger(Common::Handle documentHandle,
              float scrollPos
             );
  private:
    AbstractModel::ISetViewCoordinatesService *m_setViewCoordinatesService;
  };
}

namespace SDF::UILayer::Gui::Controller::DocumentView {
  // Class:      OnVScroll
  // Purpose:    Handles a vertical scroll event.
  // Parameters: None.
  class OnVScroll : public View::IController<Common::Handle, float> {
  public:
    OnVScroll(AbstractModel::ISetViewCoordinatesService *setViewCoordinatesService);

    void
    onTrigger(Common::Handle documentHandle,
              float scrollPos
             );
  private:
    AbstractModel::ISetViewCoordinatesService *m_setViewCoordinatesService;
  };
}

#endif