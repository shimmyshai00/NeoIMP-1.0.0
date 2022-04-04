/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OnSave.cpp
 * PURPOSE: Implements the OnSave class.
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

#include "OnSave.hpp"

#include "../../../../../Error/UiException.hpp"

namespace SDF::Editor::UILayer::Gui::Controller::MainWindow {
  OnSave::OnSave(deps_t a_deps, IViewProducer<> *a_filePromptProducer)
    : m_services(a_deps),
      m_filePromptProducer(a_filePromptProducer)
  {
  }

  void
  OnSave::onTrigger() {
    using namespace AbstractModel::Editing;
    using namespace AbstractModel::Storage;
    using namespace Common;

    Handle activeDocumentHandle = m_services.get<IGetActiveDocumentService>()->getActiveDocument();
    if(activeDocumentHandle == HANDLE_INVALID) {
      throw Error::ErrMsgException("Tried to save a document when no document was selected by the "
      "user.");
    }

    if(m_services.get<IGetDocumentFileInfoService>()->wasDocumentPreviouslySaved(
      activeDocumentHandle))
    {
      using namespace AbstractModel::Defs;

      // Just save with this file spec.
      std::string fileSpec = m_services.get<IGetDocumentFileInfoService>()->getFileSpec(
        activeDocumentHandle);
      FileFormat fileFormat = m_services.get<IGetDocumentFileInfoService>()->getFileFormat(
        activeDocumentHandle);
      m_services.get<ISaveDocumentService>()->saveDocument(activeDocumentHandle, fileSpec,
        fileFormat);
    } else {
      // Do like "save as" and open a save dialog.
      m_filePromptProducer->produceView();
    }
  }
}
