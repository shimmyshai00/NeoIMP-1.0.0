#ifndef SDF_EDITOR_MODELLAYER_SERVICES_DOCUMENTPREFABSSERVICE_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_DOCUMENTPREFABSSERVICE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentPrefabsService.hpp
 * PURPOSE: Defines the DocumentPrefabsService class.
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
#include "../../UILayer/AbstractModel/Defs/ImageSpec.hpp"
#include "../../UILayer/AbstractModel/IDocumentPrefabsService.hpp"

#include <fruit/fruit.h>

#include <vector>
#include <string>
#include <map>

namespace SDF::Editor::ModelLayer::Services {
  // Class:      DocumentPrefabsService
  // Purpose:    Implements the IDocumentPrefabsService interface.
  // Parameters: None.
  class DocumentPrefabsService : public UILayer::AbstractModel::IDocumentPrefabsService {
  public:
    INJECT(DocumentPrefabsService());

    std::vector<Common::Handle>
    getAvailablePrefabs() const;

    std::string
    getPrefabName(Common::Handle prefab);

    UILayer::AbstractModel::Defs::ImageSpec
    getPrefabSpec(Common::Handle prefab);
  private:
    std::map<Common::Handle, std::string> m_prefabNames;
    std::map<Common::Handle, UILayer::AbstractModel::Defs::ImageSpec> m_prefabSpecs;
  };
}

#endif
