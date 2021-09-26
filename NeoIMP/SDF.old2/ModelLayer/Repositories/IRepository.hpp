#ifndef SDF_MODELLAYER_REPOSITORIES_IREPOSITORY_HPP
#define SDF_MODELLAYER_REPOSITORIES_IREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IRepository.hpp
 * PURPOSE: Defines the IRepository interface.
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

namespace SDF::ModelLayer::Repositories {
  // Class:      IRepository
  // Purpose:    Defines an interface for domain object repositories (collections).
  // Parameters: ObjectT - The domain object type to hold. This should inherit from DomainObjects::IDomainObject.
  template<class ObjectT>
  class IRepository {
  public:
    virtual ~IRepository() = default;

    // Function:   create
    // Purpose:    Create a new entry in the repository.
    // Parameters: object - The domain object to add.
    // Returns:    None.
    virtual void
    create(std::unique_ptr<ObjectT> object) = 0;

    // Function:   retrieve
    // Purpose:    Retrieve a domain object from the repository.
    // Parameters: id - The ID of the object to retrieve.
    // Returns:    A non-owning reference to the retrieved object.
    virtual ObjectT *
    retrieve(int id) = 0;

    // Function:   update
    // Purpose:    Signals the repository that a domain object was changed.
    // Parameters: id - The ID of the object that changed.
    // Returns:    None.
    virtual void
    update(int id) = 0;

    // Function:   del
    // Purpose:    Deletes a domain object from the repository.
    // Parameters: id - The ID of the object to delete.
    // Returns:    None.
    virtual void
    del(int id) = 0;
  };
}

#endif
