/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SaveDocumentController.cpp
 * PURPOSE: The MVC controller associated with the save-document view.
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

#include <SaveDocumentController.hpp>

#include <AbstractModel/Properties/FileFormats.hpp>
#include <AbstractModel/Services/IDocumentStorageService.hpp>

#include <View/IViewManager.hpp>
#include <AbstractView/ISaveDocumentView.hpp>

namespace SDF::Impl::UILayer::Impl::Controller {
  SaveDocumentController::SaveDocumentController(
    View::IViewManager *viewManager,
    AbstractModel::Services::IDocumentStorageService *documentStorageService
  )
    : m_saveDocumentView(viewManager->getSaveDocumentView()),
      m_documentStorageService(documentStorageService)
  {}

  void SaveDocumentController::onSaveDocumentCommand() {
    m_saveDocumentView->getDocumentSaveParams(this);
  }

  void SaveDocumentController::receiveSaveParams(
    std::string fileName, AbstractModel::Properties::FileFormat fileFormat, ModelLayer::Handle documentHandle
  ) {
    m_documentStorageService->saveDocument(fileName, fileFormat, documentHandle);
  }
}
