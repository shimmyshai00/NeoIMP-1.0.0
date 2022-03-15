/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FileRegistry.cpp
 * PURPOSE: Implements the FileRegistry class.
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

#include "FileRegistry.hpp"

#include "../Exceptions.hpp"

namespace SDF::Editor::DataLayer::Context {
  FileRegistry::FileRegistry() {
  }

  bool
  FileRegistry::hasFileUid(Common::Handle uid) const {
    return (m_fileSpecMap.find(uid) != m_fileSpecMap.end());
  }

  Common::Handle
  FileRegistry::getFileUid(std::string fileSpec) {
    // Note: This reverse lookup is not efficient, but should not matter for this use case.
    for(const auto &kvp : m_fileSpecMap) {
      if(kvp.second == fileSpec) {
        return kvp.first;
      }
    }

    // If no key was found, add one. Again: not efficient, but should not matter.
    Common::Handle newKey(0);
    while(m_fileSpecMap.find(newKey) != m_fileSpecMap.end()) {
      ++newKey;
    }

    m_fileSpecMap[newKey] = fileSpec;

    return newKey;
  }

  void
  FileRegistry::registerFileSpec(Common::Handle uid,
                                 std::string fileSpec
                                )
  {
    if(m_fileSpecMap.find(uid) != m_fileSpecMap.end()) {
      throw UidInUseException();
    }

    m_fileSpecMap[uid] = fileSpec;
  }

  void
  FileRegistry::updateFileSpec(Common::Handle uid,
                               std::string fileSpec
                              )
  {
    if(m_fileSpecMap.find(uid) == m_fileSpecMap.end()) {
      throw FileSpecNotFoundException();
    }

    m_fileSpecMap[uid] = fileSpec;
  }

  void
  FileRegistry::forgetFileSpec(Common::Handle uid) {
    if(m_fileSpecMap.find(uid) == m_fileSpecMap.end()) {
      throw FileSpecNotFoundException();
    }

    m_fileSpecMap.erase(uid);
  }
}
