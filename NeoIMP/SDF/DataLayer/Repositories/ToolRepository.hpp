#ifndef SDF_DATALAYE_REPOSITORIES_TOOLREPOSITORY_HPP
#define SDF_DATALAYE_REPOSITORIES_TOOLREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ToolRepository.hpp
 * PURPOSE: Defines the ToolRepository class.
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

#include <SDF/ModelLayer/AbstractData/IRepository.hpp>

#include <SDF/ModelLayer/Services/AbstractDomain/ITool.hpp>

#include <fruit/fruit.h>

#include <memory>
#include <map>
#include <vector>

namespace SDF::DataLayer::Repositories {
  // Class:      ToolRepository
  // Purpose:    Defines the in-memory and persistent repository for image editing tools.
  // Parameters: None.
  class ToolRepository : public ModelLayer::AbstractData::IRepository<ModelLayer::Services::AbstractDomain::ITool> {
  public:
    INJECT(ToolRepository());

    void
    create(std::unique_ptr<ModelLayer::Services::AbstractDomain::ITool> object);

    ModelLayer::Services::AbstractDomain::ITool *
    retrieve(int objectId);

    void
    update(ModelLayer::Services::AbstractDomain::ITool *object);

    std::unique_ptr<ModelLayer::Services::AbstractDomain::ITool>
    deleteEntry(int objectId);
  private:
    std::map<int, std::unique_ptr<ModelLayer::Services::AbstractDomain::ITool>> m_objectMap;
  };
}

#endif
