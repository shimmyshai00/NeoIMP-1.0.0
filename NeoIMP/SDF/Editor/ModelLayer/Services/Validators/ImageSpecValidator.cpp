/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageSpecValidator.cpp
 * PURPOSE: Implements the ImageSpecValidator class.
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

#include "ImageSpecValidator.hpp"

namespace SDF::Editor::ModelLayer::Services::Validators {
  bool
  ImageSpecValidator::validate(
    const UILayer::AbstractModel::Defs::ImageSpec &obj,
    SImageSpecValidationReport *report
  ) const {
    using namespace UILayer::AbstractModel::Defs;
    bool isValid = true;

    SImageSpecValidationReport localReport;
    isValid = (localReport.isWidthValid = (obj.width > 0.0f))
      & (localReport.isWidthUnitValid = (obj.widthUnit < LENGTH_UNIT_MAX))
      & (localReport.isHeightValid = (obj.height > 0.0f))
      & (localReport.isHeightUnitValid = (obj.heightUnit < LENGTH_UNIT_MAX))
      & (localReport.isResolutionValid = (obj.resolution > 0.0f))
      & (localReport.isResolutionUnitValid = (obj.resolutionUnit < RESOLUTION_UNIT_MAX))
      & (localReport.isColorFormatValid = (obj.colorFormat < Color::COLOR_FMT_MAX));

    if(report != nullptr) {
      *report = localReport;
    }

    return isValid;
  }
}
