#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_IDOCUMENTPREFABSSERVICE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_IDOCUMENTPREFABSSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IDocumentPrefabsService.hpp
 * PURPOSE: Defines the IDocumentPrefabsService interface.
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
#include "Defs/ImageSpec.hpp"

#include <vector>
#include <string>

namespace SDF::Editor::UILayer::AbstractModel {
  // Class:      IDocumentPrefabsService
  // Purpose:    Defines the interface for an MVC service to provide preset document specifications
  //             for user convenience.
  // Parameters: None.
  class IDocumentPrefabsService {
  public:
    virtual ~IDocumentPrefabsService() = default;

    // Function:   getAvailablePrefabs
    // Purpose:    Get a list of the available prefab document specs.
    // Parameters: None.
    // Returns:    A list of handles to available prefabs.
    virtual std::vector<Common::Handle>
    getAvailablePrefabs() const = 0;

    // Function:   getPrefabName
    // Purpose:    Gets the name of a prefab with the given handle.
    // Parameters: prefab - The prefab to get the name of.
    // Returns:    The name of prefab "prefab".
    virtual std::string
    getPrefabName(Common::Handle prefab) = 0;

    // Function:   getPrefabSpec
    // Purpose:    Get the document spec corresponding to a given prefab.
    // Parameters: prefab - The prefab to get the spec of.
    // Returns:    The document spec for this prefab.
    virtual Defs::ImageSpec
    getPrefabSpec(Common::Handle prefab) = 0;
  };
}

#endif
