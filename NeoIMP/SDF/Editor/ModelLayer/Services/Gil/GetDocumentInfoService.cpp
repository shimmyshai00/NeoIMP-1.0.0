/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    GetDocumentInfoService.cpp
 * PURPOSE: Implements the GetDocumentInfoService class.
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

#include "GetDocumentInfoService.hpp"

#include "../../DomainObjects/Metrics/LengthConvertible.hpp"
#include "../../DomainObjects/Metrics/ResolutionConvertible.hpp"

namespace SDF::Editor::ModelLayer::Services::Gil {
  GetDocumentInfoService::GetDocumentInfoService(
    AbstractData::IImageRetriever<DomainObjects::Engine::Gil::Any_Image> *a_imageRepository
  )
    : m_imageRepository(a_imageRepository)
  {
  }

  std::string
  GetDocumentInfoService::getDocumentName(Common::Handle a_documentHandle) {
    return m_imageRepository->retrieve(a_documentHandle)->getName();
  }

  float
  GetDocumentInfoService::getDocumentWidth(
    Common::Handle a_documentHandle,
    UILayer::AbstractModel::Defs::LengthUnit a_inUnit
  ) const {
    using namespace UILayer::AbstractModel::Defs;
    using namespace DomainObjects::Engine;
    using namespace DomainObjects::Metrics;

    ImageMeasure widthPx = m_imageRepository->retrieve(a_documentHandle)->getWidthPx();
    float resolutionPpi = m_imageRepository->retrieve(a_documentHandle)->getResolutionPpi();
    return LengthConvertible(widthPx, LENGTH_UNIT_PIXEL, resolutionPpi, RESOLUTION_UNIT_PPI)
      .in(a_inUnit);
  }

  float
  GetDocumentInfoService::getDocumentHeight(
    Common::Handle a_documentHandle,
    UILayer::AbstractModel::Defs::LengthUnit a_inUnit
  ) const {
    using namespace UILayer::AbstractModel::Defs;
    using namespace DomainObjects::Engine;
    using namespace DomainObjects::Metrics;

    ImageMeasure heightPx = m_imageRepository->retrieve(a_documentHandle)->getHeightPx();
    float resolutionPpi = m_imageRepository->retrieve(a_documentHandle)->getResolutionPpi();
    return LengthConvertible(heightPx, LENGTH_UNIT_PIXEL, resolutionPpi, RESOLUTION_UNIT_PPI)
      .in(a_inUnit);
  }

  UILayer::AbstractModel::Defs::Color::ColorFormat
  GetDocumentInfoService::getColorFormatOf(Common::Handle a_documentHandle) const {
    using namespace UILayer::AbstractModel::Defs::Color;

    // TBA
    return COLOR_FMT_RGB24_888;
  }
}
