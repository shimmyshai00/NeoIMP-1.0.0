/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    DocumentPrefabsService.cpp
 * PURPOSE: Implements the DocumentPrefabsService class.
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

#include "DocumentPrefabsService.hpp"

#include "../../UILayer/AbstractModel/Defs/ImageSpec.hpp"

namespace SDF::Editor::ModelLayer::Services {
  DocumentPrefabsService::DocumentPrefabsService() {
    using namespace UILayer::AbstractModel;

    // Builtin prefabs
    m_prefabNames[0] = "U.S. Letter, 8.5\" x 11\", 300 DPI";
    m_prefabSpecs[0] = Defs::ImageSpec {
        8.5f, // width
        Defs::LENGTH_UNIT_INCH,
        11.0f, // height
        Defs::LENGTH_UNIT_INCH,
        300.0f,
        Defs::RESOLUTION_UNIT_PPI,
        Defs::Color::COLOR_MODEL_RGB,
        Defs::Color::BIT_DEPTH_8,
        Defs::PRE_BACKGROUND_WHITE,
        std::make_shared<Defs::Color::RGB24_888>(255, 255, 255)
    };

    m_prefabNames[1] = "U.S. Letter, 8.5\" x 11\", 150 DPI";
    m_prefabSpecs[1] = Defs::ImageSpec {
        8.5f, // width
        Defs::LENGTH_UNIT_INCH,
        11.0f, // height
        Defs::LENGTH_UNIT_INCH,
        150.0f,
        Defs::RESOLUTION_UNIT_PPI,
        Defs::Color::COLOR_MODEL_RGB,
        Defs::Color::BIT_DEPTH_8,
        Defs::PRE_BACKGROUND_WHITE,
        std::make_shared<Defs::Color::RGB24_888>(255, 255, 255)
    };
  }

  std::vector<Common::Handle>
  DocumentPrefabsService::getAvailablePrefabs() const {
    std::vector<Common::Handle> rv;
    for(const auto &kvp : m_prefabNames) {
      rv.push_back(kvp.first);
    }

    return rv;
  }

  std::string
  DocumentPrefabsService::getPrefabName(Common::Handle handle) const {
    return m_prefabNames.at(handle);
  }

  UILayer::AbstractModel::Defs::ImageSpec
  DocumentPrefabsService::getPrefabSpec(Common::Handle handle) const {
    return m_prefabSpecs.at(handle);
  }
}
