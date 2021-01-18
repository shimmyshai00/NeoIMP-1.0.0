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

#include <algorithm>

namespace SDF::Impl::AppModelLayer::Impl {
  EditorStateModel::EditorStateModel() {}

  // State manipulation.
  void EditorStateModel::addDocument(UILayer::AbstractAppModel::Handle handle) {
    m_openDocumentHandles.push_back(handle);
    m_openDocumentsObservables.onDocumentAdded(handle);
  }

  void EditorStateModel::removeDocument(UILayer::AbstractAppModel::Handle handle) {
    m_openDocumentHandles.erase(std::find(m_openDocumentHandles.begin(), m_openDocumentHandles.end(), handle));
    m_openDocumentsObservables.onDocumentRemoved(handle);
  }

  // View access.
  void EditorStateModel::attachStateView(Framework::IMVCStateView<UILayer::AbstractAppModel::State::OpenDocumentsObservables> *view) {
    view->connectToModelObservables(m_openDocumentsObservables);
  }
}
