#ifndef SDF_DATALAYER_REPOSITORIES_RENDERINGREPOSITORY_HPP
#define SDF_DATALAYER_REPOSITORIES_RENDERINGREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RenderingRepository.hpp
 * PURPOSE: Defines the RenderingRepository class.
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

#include <SDF/ModelLayer/Services/AbstractDomain/IRenderBuffer.hpp>

#include <fruit/fruit.h>

#include <memory>
#include <map>
#include <vector>

namespace SDF::DataLayer::Repositories {
  // Class:      RenderingRepository
  // Purpose:    Defines the in-memory repository for image renderings.
  // Parameters: None.
  class RenderingRepository : public ModelLayer::AbstractData::IRepository<ModelLayer::Services::AbstractDomain::IRenderBuffer> {
  public:
    INJECT(RenderingRepository());

    void
    create(std::unique_ptr<ModelLayer::Services::AbstractDomain::IRenderBuffer> object);

    ModelLayer::Services::AbstractDomain::IRenderBuffer *
    retrieve(int objectId);

    void
    update(ModelLayer::Services::AbstractDomain::IRenderBuffer *object);

    std::unique_ptr<ModelLayer::Services::AbstractDomain::IRenderBuffer>
    deleteEntry(int objectId);
  private:
    std::map<int, std::unique_ptr<ModelLayer::Services::AbstractDomain::IRenderBuffer>> m_objectMap;
  };
}

#endif
