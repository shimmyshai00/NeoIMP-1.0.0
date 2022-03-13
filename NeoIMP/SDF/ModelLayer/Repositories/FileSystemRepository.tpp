#ifndef SDF_MODELLAYER_REPOSITORIES_FILESYSTEMREPOSITORY_TPP
#define SDF_MODELLAYER_REPOSITORIES_FILESYSTEMREPOSITORY_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FileSystemRepository.tpp
 * PURPOSE: Implements the FileSystemRepository template.
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

namespace SDF::ModelLayer::Repositories {
  template<class ObjT, class EntityT>
  FileSystemRepository<ObjT, EntityT>::FileSystemRepository(AbstractData::IDataMapper<EntityT> *
                                                              dataMapper
                                                           )
    : m_fileMapper(dataMapper)
  {}

  template<class ObjT, class EntityT>
  std::vector<Common::Handle>
  FileSystemRepository<ObjT, EntityT>::getIds() const {
    std::vector<Common::Handle> rv;

    for(const auto &entry : m_objMap) {
      rv.push_back(entry.first);
    }

    return rv;
  }

  template<class ObjT, class EntityT>
  bool
  FileSystemRepository<ObjT, EntityT>::has(Common::Handle uid) const {
    return (m_objMap.find(uid) != m_objMap.end());
  }

  template<class ObjT, class EntityT>
  ObjT *
  FileSystemRepository<ObjT, EntityT>::insert(Common::Handle uid, std::unique_ptr<ObjT> obj) {
    if(m_objMap.find(uid) == m_objMap.end()) {
      ObjT *outPtr(obj.get());
      m_objMap[uid] = std::move(obj);

      // The cool bit
      m_fileMapper->insert(uid, outPtr);

      m_insertListeners.notify(uid);
      return outPtr;
    } else {
      return nullptr;
    }
  }

  template<class ObjT, class EntityT>
  ObjT *
  FileSystemRepository<ObjT, EntityT>::retrieve(Common::Handle uid) {
    // The file system copy is the "authoritative" copy.
    std::unique_ptr<ObjT> retrievedObj(m_fileMapper->retrieve(uid));
    if(!object) {
      throw ObjectNotFoundInRepositoryException();
    } else {
      ObjT *outPtr(retrievedObj.get());
      m_objMap[uid] = std::move(retrievedObj);
      return outPtr;
    }
  }

  template<class ObjT, class EntityT>
  void
  FileSystemRepository<ObjT, EntityT>::update(Common::Handle uid, ObjT *obj) {
    // Overwrite whatever is on the file system.
    if(m_objMap.find(uid) == m_objMap.end()) {
      throw ObjectNotFoundInRepositoryException();
    } else {
      m_fileMapper->update(uid, obj);
      m_updateListeners.notify(uid);
    }
  }

  template<class ObjT, class EntityT>
  void
  FileSystemRepository<ObjT, EntityT>::erase(Common::Handle uid) {
    // Note: this simply forgets about the object in memory; it does NOT delete the persistent copy.
    if(m_objMap.find(uid) == m_objMap.end()) {
      throw ObjectNotFoundInRepositoryException();
    } else {
      m_objMap.erase(uid);
      m_eraseListeners.notify(uid);
    }
  }

  template<class ObjT, class EntityT>
  Common::PIConnection
  FileSystemRepository<ObjT, EntityT>::addInsertListener(
    std::shared_ptr<Common::IListener<Common::Handle>> listener
  ) {
    return m_insertListeners.addListener(listener);
  }

  template<class ObjT, class EntityT>
  Common::PIConnection
  FileSystemRepository<ObjT, EntityT>::addUpdateListener(
    std::shared_ptr<Common::IListener<Common::Handle>> listener
  ) {
    return m_updateListeners.addListener(listener);
  }

  template<class ObjT, class EntityT>
  Common::PIConnection
  FileSystemRepository<ObjT, EntityT>::addEraseListener(
    std::shared_ptr<Common::IListener<Common::Handle>> listener
  ) {
    return m_eraseListeners.addListener(listener);
  }
}

#endif
