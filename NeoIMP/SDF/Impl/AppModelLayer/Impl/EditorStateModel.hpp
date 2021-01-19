#ifndef SDF_IMPL_APPMODELLAYER_IMPL_EDITORSTATEMODEL_HPP
#define SDF_IMPL_APPMODELLAYER_IMPL_EDITORSTATEMODEL_HPP

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

#include <SDF/Impl/Framework/IMVCView.hpp>

#include <SDF/Impl/AppModelLayer/Impl/IEditorStateModelMutation.hpp>
#include <SDF/Impl/UILayer/AbstractAppModel/State/IOpenDocumentsModel.hpp>
#include <SDF/Impl/UILayer/AbstractAppModel/Handle.hpp>

#include <fruit/fruit.h>
#include <vector>

namespace SDF::Impl::AppModelLayer::Impl {
  class EditorStateModel : public IEditorStateModelMutation,
                           public UILayer::AbstractAppModel::State::IOpenDocumentsModel
  {
  public:
    INJECT(EditorStateModel());

    // State manipulation.
    void addDocument(UILayer::AbstractAppModel::Handle handle);
    void removeDocument(UILayer::AbstractAppModel::Handle handle);

    // View access.
    void attachStateView(Framework::IMVCStateView<UILayer::AbstractAppModel::State::OpenDocumentsObservables> *view);
  private:
    // State.
    std::vector<UILayer::AbstractAppModel::Handle> m_openDocumentHandles;

    // Observables.
    UILayer::AbstractAppModel::State::OpenDocumentsObservables m_openDocumentsObservables;
  };
}

#endif
