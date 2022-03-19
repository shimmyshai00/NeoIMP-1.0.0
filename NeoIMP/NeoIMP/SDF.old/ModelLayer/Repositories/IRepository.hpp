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
  // Purpose:    Provides an interface for domain object repositories.
  // Parameters: T - The domain object type held in the repository.
  template<class T>
  class IRepository {
  public:
    virtual ~IRepository() = default;

    // Function:   insert
    // Purpose:    Insert a new object into the repository.
    // Parameters: obj - The object to insert.
    // Returns:    A non-owning pointer to the inserted object.
    virtual T *
    insert(std::unique_ptr<T> obj) = 0;

    // Function:   access
    // Purpose:    Access a domain object held in the repository.
    // Parameters: id - The ID of the domain object to access.
    // Returns:    None.
    virtual T *
    access(int id) = 0;

    // Function:   update
    // Purpose:    Notifies the repository of a change in a object so the backing store can be updated.
    // Parameters: obj - A non-owning pointer to the object that was changed.
    // Returns:    None.
    virtual void
    update(T *obj) = 0;

    // Function:   delete
    // Purpose:    Remove an object from the repository.
    // Parameters: id - The ID of the object to remove.
    // Returns:    An owning pointer to the removed object.
    virtual std::unique_ptr<T>
    delete(int id) = 0;
  };
}

#endif
