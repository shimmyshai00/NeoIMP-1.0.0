#ifndef SDF_EDITOR_MODELLAYER_SERVICES_GIL_GETDOCUMENTMETRICSSERVICE_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_GIL_GETDOCUMENTMETRICSSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GetDocumentMetricsService.hpp
 * PURPOSE: Defines the GetDocumentMetricsService class.
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
#include "../../../UILayer/AbstractModel/Defs/ELengthUnit.hpp"
#include "../../../UILayer/AbstractModel/Metrics/IGetDocumentDimensionsService.hpp"
#include "../../DomainObjects/Engine/Gil/ImageTypes.hpp"

#include "../../AbstractData/IImageRepository.hpp"

#include <fruit/fruit.h>
#include <string>

namespace SDF::Editor::ModelLayer::Services::Gil {
  // Class:      GetDocumentMetricsService
  // Purpose:    Implements the IGetDocumentMetricsService interface for the Boost.GIL framework.
  // Parameters: None.
  class GetDocumentMetricsService :
    public UILayer::AbstractModel::Metrics::IGetDocumentDimensionsService
  {
  public:
    INJECT(GetDocumentMetricsService(
      AbstractData::IImageRepository<DomainObjects::Engine::Gil::Any_Image> *imageRepository
    ));

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
  private:
    AbstractData::IImageRepository<DomainObjects::Engine::Gil::Any_Image> *m_imageRepository;
  };
}

#endif