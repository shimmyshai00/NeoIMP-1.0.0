#ifndef SDF_EDITOR_UILAYER_GUI_CONTROLLER_COLORCHOOSERDIALOG_ONADVANCEDOPTIONSREQUEST_HPP
#define SDF_EDITOR_UILAYER_GUI_CONTROLLER_COLORCHOOSERDIALOG_ONADVANCEDOPTIONSREQUEST_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OnAdvancedOptionsRequest.hpp
 * PURPOSE: Defines the OnAdvancedOptionsRequest class.
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

#include "../../../../../Common/Model/ServicePack.hpp"

#include "../../View/IController.hpp"
#include "../IViewProducer.hpp"

namespace SDF::Editor::UILayer::Gui::Controller::ColorChooserDialog {
  // Class:      OnAdvancedOptionsRequest
  // Purpose:    Handles the request for advanced color selection options.
  // Parameters: None.
  class OnAdvancedOptionsRequest : public View::IController<> {
  public:
    typedef Common::Model::ServicePack<> deps_t;
  public:
    OnAdvancedOptionsRequest(deps_t a_deps, IViewProducer<> *a_advancedOptionsProducer);

    void
    onTrigger();
  private:
    deps_t m_services;

    IViewProducer<> *m_advancedOptionsProducer;
  };
}

#endif
