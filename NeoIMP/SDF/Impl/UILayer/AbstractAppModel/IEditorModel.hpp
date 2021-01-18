#ifndef SDF_IMPL_UILAYER_ABSTRACTAPPMODEL_IEDITORMODEL_HPP
#define SDF_IMPL_UILAYER_ABSTRACTAPPMODEL_IEDITORMODEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IEditorModel.hpp
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

#include <SDF/Impl/Framework/IMVCAppModel.hpp>
#include <SDF/Impl/Framework/MVCView.hpp>

#include <SDF/Impl/DataLayer/Properties/FileFormat.hpp>
#include <SDF/Impl/UILayer/AbstractAppModel/Data/DocumentSpec.hpp>
#include <SDF/Impl/UILayer/AbstractAppModel/DocumentHandle.hpp>
#include <SDF/Impl/UILayer/AbstractAppModel/IDocumentCreator.hpp>

#include <boost/signals2/signal.hpp>
#include <string>
#include <vector>

namespace SDF::Impl::UILayer::AbstractAppModel {
  struct EditorModelObservables {
    boost::signals2::signal<void (DocumentHandle)> documentAdded;
    boost::signals2::signal<void (DocumentHandle)> focusDocumentChanged;
  };

  class IEditorModel : public virtual Framework::IMVCAppModel<EditorModelObservables>, public IDocumentCreator {
  public:
    virtual ~IEditorModel() = default;

    virtual void attachView(Framework::IMVCView<EditorModelObservables> *view) = 0;

    virtual DocumentHandle createDocument(Data::DocumentSpec spec) = 0;
    virtual void saveDocument(
      DocumentHandle handle,
      std::string fileName, DataLayer::Properties::FileFormat fileFormat
    ) = 0;
    virtual DocumentHandle loadDocument(std::string fileName, DataLayer::Properties::FileFormat fileFormat) = 0;

    virtual std::vector<DocumentHandle> getOpenDocuments() = 0;
    virtual DocumentHandle getEditingFocusDocument() = 0;
    virtual void setEditingFocusDocument(DocumentHandle focusDocument) = 0;
  };
}

#endif
