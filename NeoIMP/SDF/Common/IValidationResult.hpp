#ifndef SDF_COMMON_IVALIDATIONRESULT_HPP
#define SDF_COMMON_IVALIDATIONRESULT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IValidationResult.hpp
 * PURPOSE: Defines the IValidationResult interface.
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

#include "IThrower.hpp"

namespace SDF::Common {
  // Class:      IValidationResult
  // Purpose:    Represents the result of a validation operation.
  // Parameters: None.
  class IValidationResult : class IThrower {
  public:
    virtual ~IValidationResult() = default;

    // Function:   isValid
    // Purpose:    Returns if the result of the validation was that the object was valid.
    // Parameters: None.
    // Returns:    Whether the object is valid or not, according to the validator.
    virtual bool
    isValid() const = 0;
  };
}

#endif
