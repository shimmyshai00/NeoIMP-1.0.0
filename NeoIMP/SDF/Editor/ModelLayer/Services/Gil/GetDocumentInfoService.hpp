#ifndef SDF_EDITOR_MODELLAYER_SERVICES_GIL_GETDOCUMENTINFOSERVICE_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_GIL_GETDOCUMENTINFOSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GetDocumentInfoService.hpp
 * PURPOSE: Defines the GetDocumentInfoService class.
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
#include "../../../UILayer/AbstractModel/Editing/IGetDocumentNameService.hpp"
#include "../../../UILayer/AbstractModel/Metrics/IGetDocumentDimensionsService.hpp"
#include "../../../UILayer/AbstractModel/Color/IGetDocumentColorFormatService.hpp"
#include "../../../UILayer/AbstractModel/Defs/Color/ColorFormat.hpp"
#include "../../../UILayer/AbstractModel/Defs/LengthUnit.hpp"
#include "../../DomainObjects/Engine/Gil/ImageTypes.hpp"
#include "../../AbstractData/IImageRetriever.hpp"

#include <fruit/fruit.h>

namespace SDF::Editor::ModelLayer::Services::Gil {
  // Class:      GetDocumentInfoService
  // Purpose:    Provides a service to get information about the properties of a document.
  // Parameters: None.
  class GetDocumentInfoService :
    public UILayer::AbstractModel::Editing::IGetDocumentNameService,
    public UILayer::AbstractModel::Metrics::IGetDocumentDimensionsService,
    public UILayer::AbstractModel::Color::IGetDocumentColorFormatService
  {
  public:
    INJECT(GetDocumentInfoService(
      AbstractData::IImageRetriever<DomainObjects::Engine::Gil::Any_Image> *a_imageRepository
    ));

    std::string
    getDocumentName(Common::Handle a_documentHandle);

    float
    getDocumentWidth(
      Common::Handle a_documentHandle,
      UILayer::AbstractModel::Defs::LengthUnit a_inUnit
    ) const;

    float
    getDocumentHeight(
      Common::Handle a_documentHandle,
      UILayer::AbstractModel::Defs::LengthUnit a_inUnit
    ) const;

    UILayer::AbstractModel::Defs::Color::ColorFormat
    getColorFormatOf(Common::Handle a_documentHandle) const;
  private:
    AbstractData::IImageRetriever<DomainObjects::Engine::Gil::Any_Image> *m_imageRepository;
  };
}

#endif
