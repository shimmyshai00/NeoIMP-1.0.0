#ifndef SDF_MODELLAYER_REPOSITORIES_FILESYSTEMREPOSITORY_HPP
#define SDF_MODELLAYER_REPOSITORIES_FILESYSTEMREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FileSystemRepository.hpp
 * PURPOSE: Defines the FileSystemRepository template.
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
#include "../../Common/IConnection.hpp"
#include "../../Common/IListener.hpp"
#include "../../Common/ListenerContainer.hpp"
#include "../AbstractData/IDataMapper.hpp"
#include "IRepository.hpp"

#include <fruit/fruit.h>

#include <memory>
#include <map>
#include <vector>

namespace SDF::ModelLayer::Repositories {
  // Class:      FileSystemRepository
  // Purpose:    Provides a repository backed up with the computer's file system. All operations
  //             here will perform file system operations!
  // Parameters: ObjT - The type of object to store.
  //             EntityT - The type of entity to use to transfer data to/from the file system.
  template<class ObjT, class EntityT>
  class FileSystemRepository : public IRepository<ObjT> {
  public:
    INJECT(FileSystemRepository(AbstractData::IDataMapper<EntityT> *dataMapper));

    std::vector<Common::Handle>
    getIds() const;

    bool
    has(Common::Handle uid) const;

    ObjT *
    insert(Common::Handle uid, std::unique_ptr<ObjT> obj);

    ObjT *
    retrieve(Common::Handle uid);

    void
    update(Common::Handle uid, ObjT *obj);

    void
    erase(Common::Handle uid);

    Common::PIConnection
    addInsertListener(std::shared_ptr<Common::IListener<Common::Handle>> listener);

    Common::PIConnection
    addUpdateListener(std::shared_ptr<Common::IListener<Common::Handle>> listener);

    Common::PIConnection
    addEraseListener(std::shared_ptr<Common::IListener<Common::Handle>> listener);
  private:
    // Note: still keeps objects in memory so as to retain IRepository-mandated ownership semantics
    std::map<Common::Handle, std::unique_ptr<ObjT>> m_objMap;
    AbstractData::IDataMapper<EntityT> *m_fileMapper;

    Common::ListenerContainer<Common::Handle> m_insertListeners;
    Common::ListenerContainer<Common::Handle> m_updateListeners;
    Common::ListenerContainer<Common::Handle> m_eraseListeners;
  };
}

#include "FileSystemRepository.tpp"

#endif
