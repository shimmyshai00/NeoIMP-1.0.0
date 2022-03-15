#ifndef SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IDATAMAPPER_HPP
#define SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IDATAMAPPER_HPP

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

#include "../../../Common/Handle.hpp"

#include <memory>

namespace SDF::Editor::ModelLayer::AbstractData {
  // Class:      IDataMapper
  // Purpose:    Defines an interface for a data mapper (object to move data between persistent
  //             storage and memory).
  // Parameters: EntityT - The type of entity mapped into the persistent storage.
  template<class EntityT>
  class IDataMapper {
  public:
    virtual ~IDataMapper() = default;

    // The usual database access methods (CRUD).
    virtual void
    insert(Common::Handle uid, EntityT *entity) = 0;

    virtual std::unique_ptr<EntityT>
    retrieve(Common::Handle uid) = 0;

    virtual void
    update(Common::Handle uid, EntityT *entity) = 0;

    virtual void
    erase(Common::Handle uid) = 0;
  };
}

#endif
