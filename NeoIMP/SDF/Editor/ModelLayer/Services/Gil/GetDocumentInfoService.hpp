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
#include "../../../UILayer/AbstractModel/Color/IGetDocumentColorSpaceService.hpp"
#include "../../../UILayer/AbstractModel/Defs/ELengthUnit.hpp"
#include "../../../UILayer/AbstractModel/Defs/EColorModel.hpp"
#include "../../../UILayer/AbstractModel/Defs/EBitDepth.hpp"
#include "../../DomainObjects/Engine/Gil/ImageTypes.hpp"
#include "../../AbstractData/IImageRepository.hpp"

#include <fruit/fruit.h>

namespace SDF::Editor::ModelLayer::Services::Gil {
  // Class:      GetDocumentInfoService
  // Purpose:    Provides a service to get information about the properties of a document.
  // Parameters: None.
  class GetDocumentInfoService :
    public UILayer::AbstractModel::Editing::IGetDocumentNameService,
    public UILayer::AbstractModel::Metrics::IGetDocumentDimensionsService,
    public UILayer::AbstractModel::Color::IGetDocumentColorFormatService,
    public UILayer::AbstractModel::Color::IGetDocumentColorSpaceService
  {
  public:
    INJECT(GetDocumentInfoService(
      AbstractData::IImageRepository<DomainObjects::Engine::Gil::Any_Image> *imageRepository
    ));

    std::string
    getDocumentName(Common::Handle documentHandle);

    float
    getDocumentWidth(
      Common::Handle documentHandle,
      UILayer::AbstractModel::Defs::ELengthUnit inUnit
    ) const;

    float
    getDocumentHeight(
      Common::Handle documentHandle,
      UILayer::AbstractModel::Defs::ELengthUnit inUnit
    ) const;

    UILayer::AbstractModel::Defs::Color::EColorModel
    getColorModelOf(Common::Handle documentHandle) const;

    UILayer::AbstractModel::Defs::Color::EBitDepth
    getBitDepthOf(Common::Handle documentHandle) const;

    std::string
    getColorSpaceOf(Common::Handle documentHandle) const;
  private:
    AbstractData::IImageRepository<DomainObjects::Engine::Gil::Any_Image> *m_imageRepository;
  };
}
#endif
