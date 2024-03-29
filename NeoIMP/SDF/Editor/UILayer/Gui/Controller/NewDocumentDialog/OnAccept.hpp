#ifndef SDF_EDITOR_UILAYER_GUI_CONTROLLER_NEWDOCUMENTDIALOG_ONACCEPT_HPP
#define SDF_EDITOR_UILAYER_GUI_CONTROLLER_NEWDOCUMENTDIALOG_ONACCEPT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OnAccept.hpp
 * PURPOSE: Defines the OnAccept class.
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

#include "../../../AbstractModel/Defs/ImageSpec.hpp"
#include "../../../AbstractModel/Create/ICreateDocumentService.hpp"

#include "../../View/IController.hpp"

namespace SDF::Editor::UILayer::Gui::Controller::NewDocumentDialog {
  // Class:      OnAccept
  // Purpose:    Handles the acceptance of a document specification.
  // Parameters: None.
  class OnAccept : public View::IController<AbstractModel::Defs::ImageSpec> {
  public:
    typedef Common::Model::ServicePack<AbstractModel::Create::ICreateDocumentService> deps_t;
  public:
    OnAccept(deps_t a_deps);

    void
    onTrigger(AbstractModel::Defs::ImageSpec a_imageSpec);
  private:
    deps_t m_services;
  };
}

#endif
