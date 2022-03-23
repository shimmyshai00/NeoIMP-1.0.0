#ifndef SDF_EDITOR_MODELLAYER_SERVICES_VALIDATORS_EXCEPTIONS_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_VALIDATORS_EXCEPTIONS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Exceptions.hpp
 * PURPOSE: Defines the validation failure exceptions for the model layer services.
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

#include "../../../../Error/Exception.hpp"
#include "../../../../Error/ModelException.hpp"

namespace SDF::Editor::ModelLayer::Services::Validators {
  class ValidatorException : public Error::LikelyBug<Error::ModelException> {};

  struct WidthInvalidException : public ValidatorException {
    WidthInvalidException() { whatPrintf("Document spec width is invalid."); }
  };

  struct WidthUnitInvalidException : public ValidatorException {
    WidthUnitInvalidException() { whatPrintf("Document spec width unit is invalid."); }
  };

  struct HeightInvalidException : public ValidatorException {
    HeightInvalidException() { whatPrintf("Document spec height is invalid."); }
  };

  struct HeightUnitInvalidException : public ValidatorException {
    HeightUnitInvalidException() { whatPrintf("Document spec height unit is invalid."); }
  };

  struct ResolutionInvalidException : public ValidatorException {
    ResolutionInvalidException() { whatPrintf("Document spec resolution is invalid."); }
  };

  struct ResolutionUnitInvalidException : public ValidatorException {
    ResolutionUnitInvalidException() { whatPrintf("Document spec resolution unit is invalid."); }
  };

  struct ColorModelInvalidException : public ValidatorException {
    ColorModelInvalidException() { whatPrintf("Document spec color model is invalid."); }
  };

  struct BitDepthInvalidException : public ValidatorException {
    BitDepthInvalidException() { whatPrintf("Document spec bit depth is invalid."); }
  };
}

#endif
