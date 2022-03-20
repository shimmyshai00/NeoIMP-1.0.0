/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    OnAccept_Open.hpp
 * PURPOSE: Implements the OnAccept_Open class.
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

#include "OnAccept_Open.hpp"

#include "../../../../../Exception.hpp"
#include "../../../AbstractModel/Defs/EFileFormat.hpp"

#include "../../StateKeys.hpp"

namespace SDF::Editor::UILayer::Gui::Controller::FileChooserDialog {
  OnAccept_Open::OnAccept_Open(
    AbstractModel::Storage::ILoadDocumentService *loadDocumentService,
    IViewManager<View::EViewType> *viewManager
  )
    : m_loadDocumentService(loadDocumentService),
      m_viewManager(viewManager)
  {
  }

  void
  OnAccept_Open::onTrigger(std::string fileSpec, std::size_t fileFormat) {
    if(fileFormat < AbstractModel::Defs::FILE_FORMAT_MAX) {
      Common::Handle loadedDocumentHandle;
      loadedDocumentHandle = m_loadDocumentService->loadDocument(fileSpec,
        static_cast<AbstractModel::Defs::EFileFormat>(fileFormat));

      std::shared_ptr<Support::Bundle> bundle(new Support::Bundle());
      bundle->addHandle("document_handle", loadedDocumentHandle);
      m_viewManager->produceView(View::VIEW_DOCUMENT_VIEW, bundle);
    } else {
      throw SDF::Exception(false, "Unknown file format specified! Cannot save to that.");
    }
  }
}