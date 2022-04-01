#ifndef SDF_EDITOR_UILAYER_GUI_CONTROLLER_FILECHOOSERDIALOG_ONACCEPT_SAVE_HPP
#define SDF_EDITOR_UILAYER_GUI_CONTROLLER_FILECHOOSERDIALOG_ONACCEPT_SAVE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OnAccept_Save.hpp
 * PURPOSE: Defines the OnAccept_Save class.
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

#include "../../../AbstractModel/Editing/IGetActiveDocumentService.hpp"
#include "../../../AbstractModel/Storage/ISaveDocumentService.hpp"

#include "../../View/IController.hpp"
#include "../../View/ViewType.hpp"

#include <cstddef>
#include <string>

namespace SDF::Editor::UILayer::Gui::Controller::FileChooserDialog {
  // Class:      OnAccept_Save
  // Purpose:    Handles the acceptance of a document specification.
  // Parameters: None.
  class OnAccept_Save : public View::IController<std::string, std::size_t> {
  public:
    OnAccept_Save(
      AbstractModel::Editing::IGetActiveDocumentService *getActiveDocumentService,
      AbstractModel::Storage::ISaveDocumentService *saveDocumentService
    );

    void
    onTrigger(std::string fileSpec, std::size_t fileFormat);
  private:
    AbstractModel::Editing::IGetActiveDocumentService *m_getActiveDocumentService;
    AbstractModel::Storage::ISaveDocumentService *m_saveDocumentService;
  };
}

#endif
