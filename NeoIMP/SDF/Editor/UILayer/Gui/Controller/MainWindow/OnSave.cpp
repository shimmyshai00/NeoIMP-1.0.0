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
  OnSave::OnSave(
    AbstractModel::Editing::IGetActiveDocumentService *getActiveDocumentService,
    AbstractModel::Storage::IGetDocumentFileInfoService *getDocumentFileInfoService,
    AbstractModel::Storage::ISaveDocumentService *saveDocumentService,
    IViewManager<View::ViewType> *viewManager
  )
    : m_getActiveDocumentService(getActiveDocumentService),
      m_getDocumentFileInfoService(getDocumentFileInfoService),
      m_saveDocumentService(saveDocumentService),
      m_viewManager(viewManager)
  {
  }

  void
  OnSave::onTrigger() {
    Common::Handle activeDocumentHandle = m_getActiveDocumentService->getActiveDocument();
    if(activeDocumentHandle == Common::HANDLE_INVALID) {
      throw Error::ErrMsgException("Tried to save a document when no document was selected by the "
      "user.");
    }

    if(m_getDocumentFileInfoService->wasDocumentPreviouslySaved(activeDocumentHandle)) {
      using namespace AbstractModel::Defs;

      // Just save with this file spec.
      std::string fileSpec = m_getDocumentFileInfoService->getFileSpec(activeDocumentHandle);
      FileFormat fileFormat = m_getDocumentFileInfoService->getFileFormat(activeDocumentHandle);
      m_saveDocumentService->saveDocument(activeDocumentHandle, fileSpec, fileFormat);
    } else {
      // Do like "save as" and open a save dialog.
      m_viewManager->produceView(View::VIEW_SAVE_DOCUMENT_DIALOG,
        std::shared_ptr<Support::Bundle>());
    }
  }
}
