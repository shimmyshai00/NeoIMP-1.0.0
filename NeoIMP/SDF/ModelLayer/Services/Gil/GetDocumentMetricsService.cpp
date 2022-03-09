/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GetDocumentMetricsService.cpp
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

#include "GetDocumentMetricsService.hpp"

#include "../../Metrics/LengthConvertible.hpp"
#include "../../Metrics/ResolutionConvertible.hpp"
#include "../../Exceptions.hpp"

namespace SDF::ModelLayer::Services::Gil {
  GetDocumentMetricsService::GetDocumentMetricsService(
    Repositories::IRepository<DomainObjects::Engine::Gil::Any_Image> *imageRepository
  )
    : m_imageRepository(imageRepository)
  {
  }

  float
  GetDocumentMetricsService::getDocumentWidth(Common::Handle documentHandle,
                                              UILayer::AbstractModel::Defs::ELengthUnit inUnit
                                             )
  {
    using namespace UILayer::AbstractModel::Defs;
    using namespace DomainObjects::Engine;

    try {
      ImageMeasure widthPx = m_imageRepository->retrieve(documentHandle)->getWidthPx();
      float resolutionPpi = m_imageRepository->retrieve(documentHandle)->getResolutionPpi();
      return Metrics::LengthConvertible(widthPx, LENGTH_UNIT_PIXEL, resolutionPpi,
        RESOLUTION_UNIT_PPI).in(inUnit);
    } catch(OutOfRangeException) {
      throw ImageNotFoundException(documentHandle);
    }
  }

  float
  GetDocumentMetricsService::getDocumentHeight(Common::Handle documentHandle,
                                               UILayer::AbstractModel::Defs::ELengthUnit inUnit
                                              )
  {
    using namespace UILayer::AbstractModel::Defs;
    using namespace DomainObjects::Engine;

    try {
      ImageMeasure heightPx = m_imageRepository->retrieve(documentHandle)->getHeightPx();
      float resolutionPpi = m_imageRepository->retrieve(documentHandle)->getResolutionPpi();
      return Metrics::LengthConvertible(heightPx, LENGTH_UNIT_PIXEL, resolutionPpi,
        RESOLUTION_UNIT_PPI).in(inUnit);
    } catch(OutOfRangeException) {
      throw ImageNotFoundException(documentHandle);
    }
  }
}
