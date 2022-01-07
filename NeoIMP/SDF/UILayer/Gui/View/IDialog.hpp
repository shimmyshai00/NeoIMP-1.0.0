#ifndef SDF_UILAYER_GUI_VIEW_IDIALOG_HPP
#define SDF_UILAYER_GUI_VIEW_IDIALOG_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IDialog.hpp
 * PURPOSE: Defines the IDialog interface.
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

#include "../../../Patterns/IConnection.hpp"
#include "../../Mvc/IView.hpp"
#include "../../Mvc/IController.hpp"

#include <memory>

namespace SDF::UILayer::Gui::View {
  // Class:      IDialog
  // Purpose:    Defines the widget system-agnostic interface for dialogs.
  // Parameters: RespT - The data type of the generated response from the dialog.
  template<class RespT>
  class IDialog : public virtual Mvc::IView {
  public:
    virtual ~IDialog() = default;

    // Event hooks.
    virtual Patterns::PIConnection
    hookOnAccept(std::unique_ptr<Mvc::IController<RespT>> controller) = 0;

    virtual Patterns::PIConnection
    hookOnReject(std::unique_ptr<Mvc::IController<>> controller) = 0;
  };
}


#endif
