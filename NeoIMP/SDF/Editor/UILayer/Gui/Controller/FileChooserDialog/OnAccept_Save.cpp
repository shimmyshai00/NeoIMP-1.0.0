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

#include "../../../../../Error/UiException.hpp"
#include "../../../AbstractModel/Defs/FileFormat.hpp"

#include "../../state_keys.hpp"

namespace SDF::Editor::UILayer::Gui::Controller::FileChooserDialog {
  OnAccept_Save::OnAccept_Save(deps_t a_deps)
    : m_services(a_deps)
  {
  }

  void
  OnAccept_Save::onTrigger(std::string a_fileSpec, std::size_t a_fileFormat) {
    using namespace AbstractModel::Defs;
    using namespace AbstractModel::Editing;
    using namespace AbstractModel::Storage;
    using namespace Common;

    Handle curSelectedDocument(m_services.get<IGetActiveDocumentService>()->getActiveDocument());

    if(a_fileFormat < FILE_FORMAT_MAX) {
      m_services.get<ISaveDocumentService>()->saveDocument(curSelectedDocument, a_fileSpec,
        static_cast<FileFormat>(a_fileFormat));
    } else {
      throw Error::ErrMsgException("Unknown file format specified! Cannot save to that.");
    }
  }
}
