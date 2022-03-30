#ifndef SDF_EDITOR_MODELLAYER_SERVICES_VALIDATORS_IMAGESPECVALIDATOR_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_VALIDATORS_IMAGESPECVALIDATOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ImageSpecValidator.hpp
 * PURPOSE: Defines the ImageSpecValidator class.
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

#include "../../../../Common/IValidator.hpp"

#include "../../../UILayer/AbstractModel/Defs/ImageSpec.hpp"

namespace SDF::Editor::ModelLayer::Services::Validators {
  struct SImageSpecValidationReport {
    bool isWidthValid;
    bool isWidthUnitValid;
    bool isHeightValid;
    bool isHeightUnitValid;
    bool isResolutionValid;
    bool isResolutionUnitValid;
    bool isColorFormatValid;

    SImageSpecValidationReport()
      : isWidthValid(false),
        isWidthUnitValid(false),
        isHeightValid(false),
        isHeightUnitValid(false),
        isResolutionValid(false),
        isResolutionUnitValid(false),
        isColorFormatValid(false)
    {
    }

    std::string describeProblem() {
      std::string problemStr;
      if(!isWidthValid) problemStr += "width ";
      if(!isWidthUnitValid) problemStr += "width unit ";
      if(!isHeightValid) problemStr += "height ";
      if(!isHeightUnitValid) problemStr += "height unit ";
      if(!isResolutionValid) problemStr += "resolution ";
      if(!isResolutionUnitValid) problemStr += "resolution unit ";
      if(!isColorFormatValid) problemStr += "color format ";

      return problemStr;
    }
  };

  // Class:      ImageSpecValidator
  // Purpose:    Validates an image spec.
  // Parameters: None.
  class ImageSpecValidator : public Common::IValidator<
                              UILayer::AbstractModel::Defs::ImageSpec,
                              SImageSpecValidationReport
                             >
  {
  public:
    bool
    validate(
      const UILayer::AbstractModel::Defs::ImageSpec &obj,
      SImageSpecValidationReport *report = nullptr
    ) const;
  };
}

#endif
