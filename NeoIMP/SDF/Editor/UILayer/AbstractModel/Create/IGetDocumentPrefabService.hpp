#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_CREATE_IGETDOCUMENTPREFABSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_CREATE_IGETDOCUMENTPREFABSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IGetDocumentPrefabService.hpp
 * PURPOSE: Defines the IGetDocumentPrefabService interface.
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

#include "../../../../Common/Handle.hpp"
#include "../Defs/ImageSpec.hpp"

#include <vector>
#include <string>

namespace SDF::Editor::UILayer::AbstractModel::Create {
  // Class:      IGetDocumentPrefabService
  // Purpose:    Defines a service interface to access document prefabs.
  // Parameters: None.
  class IGetDocumentPrefabService {
  public:
    virtual ~IGetDocumentPrefabService() = default;

    // Function:         getAvailablePrefabs
    // Purpose:          Gets the available document prefabs.
    // Parameters:       None.
    // Returns:          A list of the available prefabs as handles.
    // Throws (non-bug): None.
    virtual std::vector<Common::Handle>
    getAvailablePrefabs() const = 0;

    // Function:         getPrefabName
    // Purpose:          Gets the name of a prefab by handle.
    // Parameters:       handle - The handle of the prefab to get the name of.
    // Returns:          The name of the prefab.
    // Throws (non-bug): PrefabNotFoundException
    virtual std::string
    getPrefabName(Common::Handle handle) const = 0;

    // Function:         getPrefabSpec
    // Purpose:          Gets the complete document spec given by a prefab.
    // Parameters:       handle - The handle of the prefab to get the spec for.
    // Returns:          The spec for a document to be made to this prefab.
    // Throws (non-bug): PrefabNotFoundException
    virtual Defs::ImageSpec
    getPrefabSpec(Common::Handle handle) const = 0;
  };
}

#endif
