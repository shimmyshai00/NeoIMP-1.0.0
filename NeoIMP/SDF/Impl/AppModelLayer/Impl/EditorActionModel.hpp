#ifndef SDF_IMPL_APPMODELLAYER_IMPL_EDITORACTIONMODEL_HPP
#define SDF_IMPL_APPMODELLAYER_IMPL_EDITORACTIONMODEL_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    EditorActionModel.hpp
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

#include <SDF/Impl/UILayer/AbstractAppModel/Actions/ICreateDocumentAction.hpp>
#include <SDF/Impl/UILayer/AbstractAppModel/Actions/ISaveDocumentAsAction.hpp>
#include <SDF/Impl/UILayer/AbstractAppModel/Actions/IOpenDocumentAction.hpp>
#include <SDF/Impl/UILayer/AbstractAppModel/Actions/ISetFocusDocumentAction.hpp>

#include <SDF/Impl/UILayer/AbstractAppModel/Handle.hpp>
#include <SDF/Impl/UILayer/AbstractAppModel/Data/DocumentSpec.hpp>

#include <fruit/fruit.h>

namespace SDF::Impl::AppModelLayer {
  namespace AbstractModel::Services {
    class IDocumentCreationService;
    class IDocumentStorageService;
    class IImageInformationService;
    class IImageRenderingService;
  }

  namespace Impl {
    class EditorStateModel;

    class EditorActionModel : public UILayer::AbstractAppModel::Actions::ICreateDocumentAction,
                              public UILayer::AbstractAppModel::Actions::ISaveDocumentAsAction,
                              public UILayer::AbstractAppModel::Actions::IOpenDocumentAction,
                              public UILayer::AbstractAppModel::Actions::ISetFocusDocumentAction
    {
    public:
      INJECT(EditorActionModel(AbstractModel::Services::IDocumentCreationService *documentCreationService,
                               AbstractModel::Services::IDocumentStorageService *documentStorageService,
                               AbstractModel::Services::IImageInformationService *imageInformationService,
                               AbstractModel::Services::IImageRenderingService *imageRenderingService,
                               EditorStateModel *editorStateModel
                              ));

      UILayer::AbstractAppModel::Handle createDocument(UILayer::AbstractAppModel::Data::DocumentSpec spec);
      void saveDocumentAs(std::string fileName, DataLayer::Properties::FileFormat fileFormat);
      void openDocument(std::string fileName, DataLayer::Properties::FileFormat fileFormat);
      void setFocusDocument(UILayer::AbstractAppModel::Handle handle);
    private:
      AbstractModel::Services::IDocumentCreationService *m_documentCreationService;
      AbstractModel::Services::IDocumentStorageService *m_documentStorageService;
      AbstractModel::Services::IImageInformationService *m_imageInformationService;
      AbstractModel::Services::IImageRenderingService *m_imageRenderingService;

      EditorStateModel *m_editorStateModel;
    };
  }
}

#endif
