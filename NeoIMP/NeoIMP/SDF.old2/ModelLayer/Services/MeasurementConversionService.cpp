/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MeasurementConversionService.cpp
 * PURPOSE: Implements the MeasurementConversionService class.
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

#include "MeasurementConversionService.hpp"

#include "../Metrics/DimensionlessQuantity.hpp"
#include "../Metrics/LengthQuantity.hpp"
#include "../Metrics/ResolutionQuantity.hpp"
#include "../Metrics/makeLengthFromUi.hpp"
#include "../Metrics/makeResolutionFromUi.hpp"
#include "../Metrics/lengthInUi.hpp"
#include "../Metrics/resolutionInUi.hpp"

namespace SDF::ModelLayer::Services {
  MeasurementConversionService::MeasurementConversionService() {}

  float
  MeasurementConversionService::convertLength(float length,
                                              UILayer::AbstractModel::Data::LengthUnit lengthUnit,
                                              float resolution,
                                              UILayer::AbstractModel::Data::ResolutionUnit resolutionUnit,
                                              UILayer::AbstractModel::Data::LengthUnit inUnit
                                             )
  {
    if(lengthUnit == inUnit) {
      return length;
    } else {
      Metrics::length_quantity
        lengthQuantity(Metrics::makeLengthFromUi(length, lengthUnit, resolution, resolutionUnit));
      Metrics::resolution_quantity
        resolutionQuantity(Metrics::makeResolutionFromUi(resolution, resolutionUnit));

      return Metrics::lengthInUi(lengthQuantity, inUnit, resolutionQuantity);
    }
  }

  float
  MeasurementConversionService::convertResolution(float resolution,
                                                  UILayer::AbstractModel::Data::ResolutionUnit resolutionUnit,
                                                  UILayer::AbstractModel::Data::ResolutionUnit inUnit
                                                 )
  {
    if(resolutionUnit == inUnit) {
      return resolution;
    } else {
      Metrics::resolution_quantity resolutionQuantity(Metrics::makeResolutionFromUi(resolution, resolutionUnit));
      return Metrics::resolutionInUi(resolutionQuantity, inUnit);
    }
  }
}
