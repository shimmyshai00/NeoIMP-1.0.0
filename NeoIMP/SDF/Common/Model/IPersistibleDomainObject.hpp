#ifndef SDF_COMMON_MODEL_IPERSISTIBLEDOMAINOBJECT_HPP
#define SDF_COMMON_MODEL_IPERSISTIBLEDOMAINOBJECT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IPersistibleDomainObject.hpp
 * PURPOSE: Defines the IPersistibleDomainObject interface.
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

#include "../IUUIDable.hpp"

#include <boost/uuids/uuid.hpp>

namespace SDF::Common::Model {
  // Class:      IPersistibleDomainObject
  // Purpose:    Defines a common interface for all domain objects.
  // Parameters: T - The user should CRTP-inherit this class.
  //             E - The type of entity struct to hold the state of this object (this must be
  //                 both sufficient and useful to completely reconstruct it from scratch).
  template<class T, class E>
  class IPersistibleDomainObject : public IUUIDable {
  public:
    virtual ~IPersistibleDomainObject() = default;

    // Function:   getStateEntity
    // Purpose:    Converts the domain object state into a persistible representation.
    // Parameters: None.
    // Returns:    The full state representation of this object.
    virtual E &
    getStateEntity() const = 0;
  };
}

#endif
