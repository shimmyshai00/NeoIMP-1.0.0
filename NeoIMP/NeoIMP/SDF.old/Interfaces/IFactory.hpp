#ifndef SDF_INTERFACES_IFACTORY_HPP
#define SDF_INTERFACES_IFACTORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IFactory.hpp
 * PURPOSE: Defines the IFactory interface.
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

namespace SDF::Interfaces {
  // Class:      IFactory
  // Purpose:    A general interface for object factories.
  // Parameters: ObjectT - The type of object the factory constructs (usually an interface or other abstract type).
  //             Args - Any arguments required by the construction.
  template<class ObjectT, class ... Args>
  class IFactory {
  public:
    virtual ~IFactory() = default;

    // Function:   create
    // Purpose:    Construct an object of type ObjectT.
    // Parameters: args - Arguments required for the construction.
    // Returns:    An owning pointer to the object.
    virtual std::unique_ptr<ObjectT> create(Args... args) = 0;
  };
}

#endif
