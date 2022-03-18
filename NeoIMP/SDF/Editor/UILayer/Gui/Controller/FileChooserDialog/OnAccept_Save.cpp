/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OnAccept_Save.hpp
 * PURPOSE: Implements the OnAccept_Save class.
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

#include "OnAccept_Save.hpp"

#include "../../../../../Exception.hpp"
#include "../../../AbstractModel/Defs/EFileFormat.hpp"

#include "../../StateKeys.hpp"

namespace SDF::Editor::UILayer::Gui::Controller::FileChooserDialog {
  OnAccept_Save::OnAccept_Save(
    AbstractModel::IUiStateManagerService *uiStateManagerService,
    AbstractModel::ISaveDocumentService *saveDocumentService
  )
    : m_uiStateManagerService(uiStateManagerService),
      m_saveDocumentService(saveDocumentService)
  {
  }

  void
  OnAccept_Save::onTrigger(std::string fileSpec, std::size_t fileFormat) {
    Common::Handle curSelectedDocument(m_uiStateManagerService->getHandleEntry(c_uiHandle,
      c_activeDocumentKey));

    if(fileFormat < AbstractModel::Defs::FILE_FORMAT_MAX) {
      m_saveDocumentService->saveDocument(curSelectedDocument, fileSpec,
        static_cast<AbstractModel::Defs::EFileFormat>(fileFormat));
    } else {
      throw SDF::Exception(false, "Unknown file format specified! Cannot save to that.");
    }
  }
}
