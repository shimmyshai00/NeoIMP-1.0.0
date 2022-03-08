/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentRequirementsService.cpp
 * PURPOSE: Implements the DocumentRequirementsService class.
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

#include "DocumentRequirementsService.hpp"

#include "../../DomainObjects/Engine/Gil/ImageTypes.hpp"
#include "../../Metrics/LengthConvertible.hpp"

namespace SDF::ModelLayer::Services::Gil {
  DocumentRequirementsService::DocumentRequirementsService() {
  }

  std::size_t
  DocumentRequirementsService::getMemoryRequiredForOneLayer(
    UILayer::AbstractModel::Defs::ImageSpec spec
  ) {
    using namespace UILayer::AbstractModel::Defs;
    using namespace Metrics;
    using namespace DomainObjects;

    // Input validation.
    if(spec.width == 0)
      throw InvalidImageWidthException(spec.width);

    if(spec.widthUnit == LENGTH_UNIT_MAX)
      throw InvalidLengthUnitException(spec.widthUnit);

    if(spec.height == 0)
      throw InvalidImageHeightException(spec.height);

    if(spec.heightUnit == LENGTH_UNIT_MAX)
      throw InvalidLengthUnitException(spec.heightUnit);

    if(spec.resolution <= 0.0f)
      throw InvalidImageResolutionException(spec.resolution);

    if(spec.resolutionUnit == RESOLUTION_UNIT_MAX)
      throw InvalidResolutionUnitException(spec.resolutionUnit);

    // Convert the dimensions to pixels.
    LengthConvertible width(spec.width, spec.widthUnit, spec.resolution, spec.resolutionUnit);
    LengthConvertible height(spec.height, spec.heightUnit, spec.resolution, spec.resolutionUnit);

    std::size_t widthPx(width.in(LENGTH_UNIT_PIXEL));
    std::size_t heightPx(height.in(LENGTH_UNIT_PIXEL));

    // What type to use depends on the combination of color model and bit depth parameters.
    if((spec.colorModel == COLOR_MODEL_RGB) && (spec.bitDepth == BIT_DEPTH_8)) {
      //return Engine::Gil::RGB888Image::getMemorySizeForOneLayer(widthPx, heightPx);
      return 0;
    } else {
      return 0;
    }
  }
}
