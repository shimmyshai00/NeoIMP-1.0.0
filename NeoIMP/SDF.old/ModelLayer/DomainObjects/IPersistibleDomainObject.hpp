#ifndef SDF_MODELLAYER_DOMAINOBJECTS_IPERSISTIBLEDOMAINBOJECT_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_IPERSISTIBLEDOMAINBOJECT_HPP

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

#include <SDF/ModelLayer/DomainObjects/IDomainObject.hpp>

#include <memory>

namespace SDF::ModelLayer::DomainObjects {
  // Class:      IPersistibleDomainObject
  // Purpose:    Defines a common interface for MVC domain objects that can be stored in persistent storage.
  // Parameters: T - this type should CRTP-inherit this class.
  //             EntityT - the type of data layer-bridging entity used by this persistible object.
  template<class T, class EntityT>
  class IPersistibleDomainObject : public IDomainObject<T> {
  public:
    virtual ~IPersistibleDomainObject() = default;

    // Function:   createEntity
    // Purpose:    Create a mappable entity from this domain object.
    // Parameters: None.
    // Returns:    A new mappable entity representing the domain object.
    virtual std::unique_ptr<EntityT>
    createEntity() const = 0;
  };
}

#endif
