#ifndef SDF_MODELLAYER_DOMAINOBJECTS_IFACTORY_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_IFACTORY_HPP

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

#include "IDomainObject.hpp"

#include <memory>

namespace SDF::ModelLayer::DomainObjects {
  // Class:      IFactory
  // Purpose:    Provides a factory interface for building new domain objects.
  // Parameters: ObjType - The type of domain object built.
  //             Args - Arguments passed to construct this type of object.
  template<class ObjType, class ... Args>
  class IFactory {
  public:
    virtual ~IFactory() = default;

    // Function:   create
    // Purpose:    Create a new domain object from the given arguments.
    // Parameters: args - The arguments to use for construction.
    // Returns:    An owning pointer to the new instance.
    virtual std::unique_ptr<ObjType>
    create(Args... args) = 0;
  };
}

#endif
