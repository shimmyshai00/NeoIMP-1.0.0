#ifndef SDF_COMMON_IVALIDATOR_HPP
#define SDF_COMMON_IVALIDATOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IValidator.hpp
 * PURPOSE: Defines the IValidator interface.
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

#include <memory>

namespace SDF::Common {
  // Class:      IValidator
  // Purpose:    Defines an interface for objects which validate others.
  // Parameters: ObjT - The type of object to validate.
  //             ReportT - The type of validation reports to return.
  template<class ObjT, class ReportT>
  class IValidator {
  public:
    virtual ~IValidator() = default;

    // Function:   validate
    // Purpose:    Validates an object.
    // Parameters: obj - The object to validate.
    //             report - An optional pointer to a report object to receive extra information
    //                      about the validation.
    // Returns:    Whether the object is valid.
    virtual bool
    validate(const ObjT &a_obj, ReportT *a_report = nullptr) const = 0;
  };

  // Like the above, but returns no reports.
  template<class ObjT>
  class IValidator<ObjT, void> {
  public:
    virtual ~IValidator() = default;

    virtual bool
    validate(const ObjT &a_obj) const = 0;
  };
}

#endif
