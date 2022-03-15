#ifndef SDF_EDITOR_DATALAYER_CONTEXT_FILEREGISTRY_HPP
#define SDF_EDITOR_DATALAYER_CONTEXT_FILEREGISTRY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    FileRegistry.hpp
 * PURPOSE: Defines the FileRegistry class.
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
#include "../../ModelLayer/AbstractData/IFileCoordinator.hpp"

#include <fruit/fruit.h>
#include <string>
#include <map>

namespace SDF::Editor::DataLayer::Context {
  // Class:      FileRegistry
  // Purpose:    Maintains a map between ID handles and file specs.
  // Parameters: None.
  class FileRegistry : public ModelLayer::AbstractData::IFileCoordinator {
  public:
    // Function:   FileRegistry
    // Purpose:    Creates a new file registry.
    // Parameters: None.
    INJECT(FileRegistry());

    // Function:   hasFileUid
    // Purpose:    Checks if a given uid is known to the registry.
    // Parameters: uid - The uid to check.
    // Returns:    Whether the uid is known.
    bool
    hasFileUid(Common::Handle uid) const;

    Common::Handle
    getFileUid(std::string fileSpec);

    // Function:   registerFileSpec
    // Purpose:    Associates a uid to a file spec in the file registry.
    // Parameters: uid - The uid to associate to.
    //             fileSpec - The file spec to associate.
    // Returns:    None.
    void
    registerFileSpec(Common::Handle uid,
                     std::string fileSpec
                    );

    // Function:   updateFileSpec
    // Purpose:    Updates an existing entry with a new file spec.
    // Parameters: uid - The uid to change.
    //             fileSpec - The new file spec.
    // Returns:    None.
    void
    updateFileSpec(Common::Handle uid,
                   std::string fileSpec
                  );

    // Function:   forgetFileSpec
    // Purpose:    Forgets a file spec in the registry.
    // Parameters: uid - The uid to forget.
    // Returns:    None.
    void
    forgetFileSpec(Common::Handle uid);
  private:
    std::map<Common::Handle, std::string> m_fileSpecMap;
  };
}

#endif
