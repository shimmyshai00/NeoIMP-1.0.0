#ifndef SDF_INTERFACES_IGENERATOR_HPP
#define SDF_INTERFACES_IGENERATOR_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IGenerator.hpp
 * PURPOSE: Defines the IGenerator interface.
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

namespace SDF::Interfaces {
  // Class:      IGenerator
  // Purpose:    Defines an interface for objects that generate values, like a random or sequential unique ID generator.
  // Parameters: ValueT - The type of value generated.
  template<class ValueT>
  class IGenerator {
  public:
    virtual ~IGenerator() = default;

    // Function:   get
    // Purpose:    Get a new value from the value generator.
    // Parameters: None.
    // Returns:    The newly-generated value.
    virtual ValueT
    get() = 0;
  };
}

#endif
