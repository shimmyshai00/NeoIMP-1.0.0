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

#include "../../Common/Handle.hpp"

#include <memory>

namespace SDF::ModelLayer::Repositories {
  // Class:      IRepository
  // Purpose:    Defines an interface for repositories.
  // Parameters: ObjT - The type of object held in the repository. Should implement IMappable.
  template<class ObjT>
  class IRepository {
  public:
    virtual ~IRepository() = default;

    virtual ObjT *
    insert(Common::Handle uid, std::unique_ptr<ObjT> obj) = 0;

    virtual ObjT *
    retrieve(Common::Handle uid) = 0;

    virtual void
    update(Common::Handle uid, ObjT *obj) = 0;

    virtual void
    erase(Common::Handle uid) = 0;
  };
}

#endif
