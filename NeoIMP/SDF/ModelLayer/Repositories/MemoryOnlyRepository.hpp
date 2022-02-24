#ifndef SDF_MODELLAYER_REPOSITORIES_MEMORYONLYREPOSITORY_HPP
#define SDF_MODELLAYER_REPOSITORIES_MEMORYONLYREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MemoryOnlyRepository.hpp
 * PURPOSE: Defines the MemoryOnlyRepository template.
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
#include "IRepository.hpp"

#include <fruit/fruit.h>

#include <memory>
#include <map>

namespace SDF::ModelLayer::Repositories {
  // Class:      MemoryOnlyRepository
  // Purpose:    Provides a purely in-memory repository.
  // Parameters: ObjT - The type of object to store.
  template<class ObjT>
  class MemoryOnlyRepository : public IRepository<ObjT> {
  public:
    INJECT(MemoryOnlyRepository());

    ObjT *
    insert(Common::Handle uid, std::unique_ptr<ObjT> obj);

    ObjT *
    retrieve(Common::Handle uid);

    void
    update(Common::Handle uid, ObjT *obj);

    void
    erase(Common::Handle uid);
  private:
    std::map<Common::Handle, std::unique_ptr<ObjT>> m_objMap;
  };
}

#include "MemoryOnlyRepository.tpp"

#endif
