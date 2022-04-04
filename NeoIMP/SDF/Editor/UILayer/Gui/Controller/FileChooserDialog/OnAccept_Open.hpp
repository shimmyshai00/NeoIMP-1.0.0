#ifndef SDF_EDITOR_UILAYER_GUI_CONTROLLER_FILECHOOSERDIALOG_ONACCEPT_OPEN_HPP
#define SDF_EDITOR_UILAYER_GUI_CONTROLLER_FILECHOOSERDIALOG_ONACCEPT_OPEN_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OnAccept_Open.hpp
 * PURPOSE: Defines the OnAccept_Open class.
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

#include "../../../AbstractModel/Storage/ILoadDocumentService.hpp"

#include "../../View/IController.hpp"
#include "../IViewProducer.hpp"

#include <cstddef>
#include <string>

namespace SDF::Editor::UILayer::Gui::Controller::FileChooserDialog {
  // Class:      OnAccept_Open
  // Purpose:    Handles the acceptance of a document specification for loading a file.
  // Parameters: None.
  class OnAccept_Open : public View::IController<std::string, std::size_t> {
  public:
    typedef Common::Model::ServicePack<AbstractModel::Storage::ILoadDocumentService> deps_t;
  public:
    OnAccept_Open(deps_t a_deps);

    void
    onTrigger(std::string a_fileSpec, std::size_t a_fileFormat);
  private:
    deps_t m_services;
  };
}

#endif
