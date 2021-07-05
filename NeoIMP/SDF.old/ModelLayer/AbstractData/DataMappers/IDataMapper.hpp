#ifndef SDF_MODELLAYER_ABSTRACTDATA_DATAMAPPERS_IDATAMAPPER_HPP
#define SDF_MODELLAYER_ABSTRACTDATA_DATAMAPPERS_IDATAMAPPER_HPP

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

namespace SDF::ModelLayer::AbstractData::DataMappers {
  // Class:      IDataMapper
  // Purpose:    Defines an interface for persistent storage data mappers.
  // Parameters: EntityT - The entity type to be mapped by this mapper.
  template<class EntityT>
  class IDataMapper {
  public:
    virtual ~IDataMapper() = default;

    // Function:   persist
    // Purpose:    Persist an entity into persistent storage.
    // Parameters: id - The ID to persist under.
    //             entity - The entity to persist.
    // Returns:    None.
    virtual void
    persist(int id, EntityT *entity) = 0;

    // Function:   retrieve
    // Purpose:    Retrieve an entity from persistent storage.
    // Parameters: id - The ID of the entity to retrieve.
    // Returns:    An owning pointer to the retrieved entity instance.
    virtual std::unique_ptr<EntityT>
    retrieve(int id) = 0;
  };
}

#endif
