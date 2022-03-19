#ifndef SDF_DATALAYER_REPOSITORIES_ABSTRACTPERSISTENCE_IDATAMAPPER_HPP
#define SDF_DATALAYER_REPOSITORIES_ABSTRACTPERSISTENCE_IDATAMAPPER_HPP
/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IDataMapper.hpp
 * PURPOSE: Defines the IDataMapper interface.
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

namespace SDF::DataLayer::Repositories::AbstractPersistence {
  // Class:      IDataMapper
  // Purpose:    Defines a general interface for data mappers. A data mapper is responsible for persisting a single
  //             domain object to persistent storage by any method.
  // Parameters: T - The domain object type to persist.
  template<class T>
  class IDataMapper {
  public:
    virtual ~IDataMapper() = default;

    // Function:   persist
    // Purpose:    Persists an object to storage.
    // Parameters: obj - The object to persist.
    // Returns:    None.
    virtual void
    persist(T *obj) = 0;

    // Function:   retrieve
    // Purpose:    Retrieves an object from persistent storage.
    // Parameters: None.
    // Returns:    A copy of the retrieved object.
    virtual std::unique_ptr<T>
    retrieve() = 0;
  };
}

#endif
