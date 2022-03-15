#ifndef SDF_EDITOR_MODELLAYER_REPOSITORIES_IREPOSITORY_HPP
#define SDF_EDITOR_MODELLAYER_REPOSITORIES_IREPOSITORY_HPP

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

#include "../../../Common/Handle.hpp"
#include "../../../Common/IConnection.hpp"
#include "../../../Common/IListener.hpp"

#include <memory>
#include <vector>

namespace SDF::Editor::ModelLayer::Repositories {
  // Class:      IRepository
  // Purpose:    Defines an interface for repositories.
  // Parameters: ObjT - The type of object held in the repository. Should implement IMappable.
  template<class ObjT>
  class IRepository {
  public:
    virtual ~IRepository() = default;

    virtual std::vector<Common::Handle>
    getIds() const = 0;

    virtual bool
    has(Common::Handle uid) const = 0;

    virtual ObjT *
    insert(Common::Handle uid, std::unique_ptr<ObjT> obj) = 0;

    virtual ObjT *
    retrieve(Common::Handle uid) = 0;

    virtual void
    update(Common::Handle uid, ObjT *obj) = 0;

    virtual void
    erase(Common::Handle uid) = 0;

    /*
    // asynchrone access - generally for expensive databases and/or big objects requiring long
    // read/write operations
    virtual std::future<ObjT *>
    insertAsync(Common::Handle uid, std::unique_ptr<objT> obj) = 0;

    virtual std::future<ObjT *>
    retrieveAsync(Common::Handle uid) = 0;

    virtual std::future<void>
    updateAsync(Common::Handle uid, ObjT *obj) = 0;

    virtual std::future<void>
    eraseAsync(Common::Handle uid, ObjT *obj) = 0;
    */

    virtual Common::PIConnection
    addInsertListener(std::shared_ptr<Common::IListener<Common::Handle>> listener) = 0;

    virtual Common::PIConnection
    addUpdateListener(std::shared_ptr<Common::IListener<Common::Handle>> listener) = 0;

    virtual Common::PIConnection
    addEraseListener(std::shared_ptr<Common::IListener<Common::Handle>> listener) = 0;
  };
}

#endif
