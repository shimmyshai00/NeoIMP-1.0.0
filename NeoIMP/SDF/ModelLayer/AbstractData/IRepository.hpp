#ifndef SDF_MODELLAYER_ABSTRACTDATA_IREPOSITORY_HPP
#define SDF_MODELLAYER_ABSTRACTDATA_IREPOSITORY_HPP

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

namespace SDF::ModelLayer::AbstractData {
  // Class:      IRepository
  // Purpose:    Provides an interface for domain object repositories. These are the usual "CRUD" methods.
  // Parameters: T - The domain object type.
  template<class T>
  class IRepository {
  public:
    virtual ~IRepository() = default;

    // Function:  create
    // Purpose:   Create a new record in the repository with a given domain object.
    // Arguments: object - The domain object to add.
    // Returns:   None (swallows up the domain object).
    virtual void
    create(std::unique_ptr<T> object) = 0;

    // Function:  retrieve
    // Purpose:   Retrieve a domain object by its ID.
    // Arguments: objectId - The ID of the object to get.
    // Returns:   A non-owning pointer to the object, or nullptr if it does not exist in the database.
    virtual T *
    retrieve(int objectId) = 0;

    // Function:  update
    // Purpose:   Update a record in the database with a modified domain object.
    // Arguments: object - The non-owning pointer to the modified object.
    // Returns:   None.
    virtual void
    update(T *object) = 0;

    // Function:  deleteEntry
    // Purpose:   Deletes a domain object from the repository.
    // Arguments: objectId - The ID of the object to delete.
    // Returns:   An owning pointer to the instance, if such is desired.
    virtual std::unique_ptr<T>
    deleteEntry(int objectId) = 0;
  };
}

#endif
