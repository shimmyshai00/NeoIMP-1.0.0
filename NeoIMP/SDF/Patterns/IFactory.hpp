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
  // Purpose:    Defines a factory interface.
  // Parameters: ConsT - The type of object constructed.
  //             Args - The construction arguments.
  template<class ConsT, class ... Args>
  class IFactory {
  public:
    virtual ~IFactory() = default;

    // Function:   makeUnique
    // Purpose:    Create a unique object according to the specified parameters.
    // Parameters: args - The arguments to use to create the object.
    // Returns:    A unique_ptr to a new object of the given type.
    std::unique_ptr<ConsT>
    makeUnique(Args... args) { return std::unique_ptr<ConsT>(create(args...)); }

    // Function:   makeShared
    // Purpose:    Create a shared object according to the specified parameters.
    // Parameters: args - The arguments to use to create the object.
    // Returns:    A shared_ptr to a new object of the given type.
    std::shared_ptr<ConstT>
    makeShared(Args... args) { return std::shared_ptr<ConsT>(create(args...)); }
  protected:
    // Function:   create
    // Purpose:    Create a raw pointer to the object according to the specified parameters.
    // Parameters: args - The arguments to use to create the object.
    // Returns:    A raw pointer to a new object of the given type.
    virtual ConsT *
    create(Args... args) = 0;
  };
}

#endif
