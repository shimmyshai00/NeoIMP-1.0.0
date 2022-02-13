#ifndef SDF_PATTERNS_IFACTORY_HPP
#define SDF_PATTERNS_IFACTORY_HPP

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

namespace SDF::Patterns {
  // Class:      IFactory
  // Purpose:    Defines an interface for objects which construct other objects.
  // Parameters: ObjT - The type of object constructed.
  //             Args - The arguments required for the construction.
  template<class ObjT, class ... Args>
  class IFactory {
  public:
    virtual ~IFactory() = default;

    // Function:   create
    // Purpose:    Create a new instance of the object.
    // Parameters: args - The arguments to use for the construction.
    // Returns:    A pointer to the new object.
    virtual ObjT *
    create(Args... args) = 0;

    std::unique_ptr<ObjT>
    createU(Args... args) { return std::unique_ptr<ObjT>(create(args...)); }

    std::shared_ptr<ObjT>
    createS(Args... args) { return std::shared_ptr<ObjT>(create(args...)); }
  };
}

#endif
