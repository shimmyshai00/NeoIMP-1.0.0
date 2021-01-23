/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    EditorStateModel.hpp
 * PURPOSE: Centralizes all the editor UI state.
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

#include <EditorStateModel.hpp>
#include <DocumentStateModel.hpp>

#include <UILayer/AbstractAppModel/State/IDocumentAppModel.hpp>

#include <algorithm>

namespace SDF::Impl::AppModelLayer::Impl {
  EditorStateModel::EditorStateModel()
    : m_focusDocumentHandle(-1)
  {}

  EditorStateModel::~EditorStateModel() {}

  // State manipulation.
  void
  EditorStateModel::addDocument(UILayer::AbstractAppModel::Handle handle,
                                UILayer::AbstractAppModel::Data::DocumentSpec spec,
                                const unsigned char *initialRenderingPtr
                               )
  {
    m_openDocumentHandles.push_back(handle);
    m_documentModels[handle] = std::make_unique<DocumentStateModel>(handle, spec, initialRenderingPtr);
    onDocumentAdded(handle);
  }

  void EditorStateModel::addDocument(UILayer::AbstractAppModel::Handle handle,
                                     std::string documentName,
                                     int documentWidthPx,
                                     int documentHeightPx,
                                     float documentResolutionPpi,
                                     const unsigned char *initialRenderingPtr
                                    )
  {
    m_openDocumentHandles.push_back(handle);
    m_documentModels[handle] = std::make_unique<DocumentStateModel>(handle,
                                                                    documentName,
                                                                    documentWidthPx,
                                                                    documentHeightPx,
                                                                    documentResolutionPpi,
                                                                    initialRenderingPtr
                                                                   );
    onDocumentAdded(handle);
  }

  void
  EditorStateModel::removeDocument(UILayer::AbstractAppModel::Handle handle) {
    m_openDocumentHandles.erase(std::find(m_openDocumentHandles.begin(), m_openDocumentHandles.end(), handle));
    onDocumentRemoved(handle);
  }

  void
  EditorStateModel::setFocusDocument(UILayer::AbstractAppModel::Handle handle) {
    m_focusDocumentHandle = handle;
    onFocusDocumentChanged(handle);
  }

  // State access.
  std::vector<UILayer::AbstractAppModel::Handle>
  EditorStateModel::getOpenDocumentHandles() const {
    return m_openDocumentHandles;
  }

  UILayer::AbstractAppModel::State::IDocumentAppModel *
  EditorStateModel::getDocumentModel(UILayer::AbstractAppModel::Handle handle) {
    if(m_documentModels.find(handle) != m_documentModels.end()) {
      return m_documentModels[handle].get();
    } else {
      return nullptr;
    }
  }

  DocumentStateModel *
  EditorStateModel::getDocumentStateModel(UILayer::AbstractAppModel::Handle handle) {
    if(m_documentModels.find(handle) != m_documentModels.end()) {
      return m_documentModels[handle].get();
    } else {
      return nullptr;
    }
  }

  UILayer::AbstractAppModel::Handle
  EditorStateModel::getFocusDocument() {
    return m_focusDocumentHandle;
  }
}
