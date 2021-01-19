/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    EditorActionModel.cpp
 * PURPOSE: Delegates all the actions possible in the editor to the appropriate (domain) model-layer services.
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

#include <EditorActionModel.hpp>

#include <AbstractModel/Services/IDocumentCreationService.hpp>
#include <IEditorStateModelMutation.hpp>

#include <iostream>

namespace SDF::Impl::AppModelLayer::Impl {
  EditorActionModel::EditorActionModel(AbstractModel::Services::IDocumentCreationService *documentCreationService,
                                       IEditorStateModelMutation *editorStateModelMutation
                                      )
    : m_documentCreationService(documentCreationService),
      m_editorStateModelMutation(editorStateModelMutation)
  {}

  UILayer::AbstractAppModel::Handle
  EditorActionModel::createDocument(UILayer::AbstractAppModel::Data::DocumentSpec spec) {
    AbstractModel::Data::DocumentSpec modelSpec {
      spec.documentName,
      spec.documentWidthPx,
      spec.documentHeightPx,
      spec.documentResolutionPpi,
      spec.colorModel,
      spec.bitDepth
    };

    UILayer::AbstractAppModel::Handle handle(m_documentCreationService->createDocument(modelSpec));
    m_editorStateModelMutation->addDocument(handle);

    return handle;
  }
}
