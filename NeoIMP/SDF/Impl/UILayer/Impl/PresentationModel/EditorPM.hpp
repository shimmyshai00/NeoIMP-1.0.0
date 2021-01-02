#ifndef SDF_IMPL_UILAYER_IMPL_PRESENTATIONMODEL_EDITORPM_HPP
#define SDF_IMPL_UILAYER_IMPL_PRESENTATIONMODEL_EDITORPM_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    EditorPM.hpp
 * PURPOSE: Defines a presentation model for the editor. This acts as a singular truth source for editor state that
 *          doesn't fit well into the model layer (domain model) (and this may even mature into a fifth layer in the
 *          future).
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

#include <SDF/Impl/UILayer/AbstractModel/Handle.hpp>

namespace SDF::Impl::UILayer::Impl::PresentationModel {
  class EditorPM {
  public:
    EditorPM();

    void setFocusDocument(AbstractModel::Handle focusDocumentHandle);
    AbstractModel::Handle getFocusDocument() const;
  private:
    AbstractModel::Handle m_focusDocument;
  };
}

#endif
