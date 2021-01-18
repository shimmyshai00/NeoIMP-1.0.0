/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    EditorModel.cpp
 * PURPOSE: Provides an abstracted "user interface" for the core editor functionality - loading, saving, managing and
 *          selecting documents for editing, including transient state such as which document is currently selected for
 *          editing.
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

#include <EditorModel.hpp>

#include <AbstractModel/Services/IDocumentCreationService.hpp>
#include <AbstractModel/Services/IDocumentStorageService.hpp>
#include <AbstractModel/Services/IImageInformationService.hpp>
#include <AbstractModel/Services/IImageBaseEditingService.hpp>

namespace SDF::Impl::AppModelLayer::Impl {
  EditorModel::EditorModel(
    AbstractModel::Services::IDocumentCreationService *documentCreationService,
    AbstractModel::Services::IDocumentStorageService *documentStorageService,
    AbstractModel::Services::IImageInformationService *imageInformationService,
    AbstractModel::Services::IImageBaseEditingService *imageBaseEditingService
  )
    : m_documentCreationService(documentCreationService),
      m_documentStorageService(documentStorageService),
      m_imageInformationService(imageInformationService),
      m_imageBaseEditingService(imageBaseEditingService),
      m_focusDocumentHandle(-1)
  {}

  EditorModel::~EditorModel() {}

  void EditorModel::attachView(Framework::IMVCView<UILayer::AbstractAppModel::EditorModelObservables> *view) {
    view->connectToModelObservables(m_observables);
  }

  UILayer::AbstractAppModel::DocumentHandle EditorModel::createDocument(
    UILayer::AbstractAppModel::Data::DocumentSpec spec)
  {
    UILayer::AbstractAppModel::DocumentHandle handle(m_documentCreationService->createDocument(
      {
        spec.documentName,
        spec.documentWidthPx, spec.documentHeightPx, spec.documentResolutionPpi,
        spec.colorModel, spec.bitDepth
      }
    ));

    m_openDocuments.push_back(handle);
    m_focusDocumentHandle = handle;

    m_observables.documentAdded(handle);
    m_observables.focusDocumentChanged(handle);

    return handle;
  }

  void EditorModel::saveDocument(
    UILayer::AbstractAppModel::DocumentHandle handle,
    std::string fileName, DataLayer::Properties::FileFormat fileFormat
  ) {
    m_documentStorageService->saveDocument(fileName, fileFormat, handle);
  }

  UILayer::AbstractAppModel::DocumentHandle EditorModel::loadDocument(
    std::string fileName, DataLayer::Properties::FileFormat fileFormat
  ) {
    UILayer::AbstractAppModel::DocumentHandle handle(m_documentStorageService->loadDocument(fileName, fileFormat));

    m_openDocuments.push_back(handle);
    m_focusDocumentHandle = handle;

    m_observables.documentAdded(handle);
    m_observables.focusDocumentChanged(handle);

    return handle;
  }

  std::vector<UILayer::AbstractAppModel::DocumentHandle> EditorModel::getOpenDocuments() {
    return m_openDocuments;
  }

  UILayer::AbstractAppModel::DocumentHandle EditorModel::getEditingFocusDocument() {
    return m_focusDocumentHandle;
  }

  void EditorModel::setEditingFocusDocument(UILayer::AbstractAppModel::DocumentHandle focusDocument) {
    m_focusDocumentHandle = focusDocument;
    m_observables.focusDocumentChanged(focusDocument);
  }
}
