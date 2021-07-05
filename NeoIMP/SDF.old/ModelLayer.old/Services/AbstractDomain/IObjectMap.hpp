#ifndef SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IOBJECTMAP_HPP
#define SDF_MODELLAYER_SERVICES_ABSTRACTDOMAIN_IOBJECTMAP_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IObjectMap.hpp
 * PURPOSE: Defines the IObjectMap interface.
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

namespace SDF::ModelLayer::Services::AbstractDomain {
  template<class T>
  class IDomainObject;

  // NB: push down toward data layer? since does reference repositories and is not a service
  // Class:      IObjectMap
  // Purpose:    Defines an interface for creating a correspondence mapping between domain objects of two different
  //             types. Implementations will typically build on a Repository.
  // Parameters: T - The type of objects mapped from.
  //             U - The type of objects mapped to. Both of these should inherit from IDomainObject.
  template<class T, class U>
  class IObjectMap {
  public:
    virtual ~IObjectMap() = default;

    // Function:   linkTo
    // Purpose:    Links one domain object to another.
    // Parameters: key - The object acting as the "key", i.e. the object linked.
    //             value - The object acting as the "value", i.e. the object linked to.
    virtual void
    linkTo(IDomainObject<T> *key, std::unique_ptr<U> value) = 0;

    // Function:   breakLink
    // Purpose:    Unlinks the given key object, i.e. removes it from the map.
    // Parameters: key - The key to remove.
    // Returns:    None.
    virtual void
    breakLink(IDomainObject<T> *key) = 0;

    // Function:   get
    // Purpose:    Get the domain object associated through this mapping to another.
    // Parameters: key - The key object.
    // Returns:    The associated value object.
    virtual U *
    get(IDomainObject<T> *key) = 0;
  };
}

#endif
