#ifndef SDF_MODELLAYER_ABSTRACTDATA_IDATAMAPPER_HPP
#define SDF_MODELLAYER_ABSTRACTDATA_IDATAMAPPER_HPP

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

namespace SDF::ModelLayer::AbstractData {
  // Class:      IDataMapper
  // Purpose:    Defines an interface for data mappers for a given entity type.
  // Parameters: EntityT - The type of entity mapped.
  template<class EntityT>
  class IDataMapper {
  public:
    virtual ~IDataMapper() = default;

    // Function:   save
    // Purpose:    Saves the entity in the external database.
    // Parameters: entity - The entity to save.
    // Returns:    None.
    virtual void
    save(const EntityT &entity) = 0;

    // Function:   load
    // Purpose:    Loads an entity from the external database.
    // Parameters: None.
    // Returns:    An owning pointer to the retrieved entity.
    virtual std::unique_ptr<EntityT>
    load(int id) = 0;
  };
}

#endif
