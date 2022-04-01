#ifndef SDF_EDITOR_MODELLAYER_SERVICES_GIL_LOADDOCUMENTSERVICE_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_GIL_LOADDOCUMENTSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    LoadDocumentService.hpp
 * PURPOSE: Defines the LoadDocumentService class.
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

#include "../../../../Common/Handle.hpp"
#include "../../../UILayer/AbstractModel/Defs/FileFormat.hpp"
#include "../../../UILayer/AbstractModel/Storage/ILoadDocumentService.hpp"
#include "../../DomainObjects/Engine/Gil/ImageTypes.hpp"
#include "../../AbstractData/IImageLoader.hpp"
#include "../../AbstractData/IImageRetriever.hpp"

#include <fruit/fruit.h>

#include <string>

namespace SDF::Editor::ModelLayer::Services::Gil {
  // Class:      LoadDocumentService
  // Purpose:    Implements the ILoadDocumentService interface for the Boost.GIL framework.
  // Parameters: None.
  class LoadDocumentService : public UILayer::AbstractModel::Storage::ILoadDocumentService {
  public:
    INJECT(LoadDocumentService(
      AbstractData::IImageLoader<DomainObjects::Engine::Gil::Any_Image> *a_imageLoader,
      AbstractData::IImageRetriever<DomainObjects::Engine::Gil::Any_Image> *a_imageRetriever
    ));

    Common::Handle
    loadDocument(
      std::string a_fileSpec,
      UILayer::AbstractModel::Defs::FileFormat a_fileFormat
    );
  private:
    AbstractData::IImageLoader<DomainObjects::Engine::Gil::Any_Image> *m_imageLoader;
    AbstractData::IImageRetriever<DomainObjects::Engine::Gil::Any_Image> *m_imageRetriever;
  };
}

#endif
