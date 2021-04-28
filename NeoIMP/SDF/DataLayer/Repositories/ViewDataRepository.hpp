#ifndef SDF_DATALAYER_REPOSITORIES_VIEWDATAREPOSITORY_HPP
#define SDF_DATALAYER_REPOSITORIES_VIEWDATAREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ViewDataRepository.hpp
 * PURPOSE: Defines the ViewDataRepository class.
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

#include <SDF/ModelLayer/Services/AbstractDomain/IDocumentViewParams.hpp>

#include <fruit/fruit.h>

#include <memory>
#include <map>
#include <vector>

namespace SDF::DataLayer::Repositories {
  // Class:      ViewDataRepository
  // Purpose:    Defines the in-memory repository for document viewport data.
  // Parameters: None.
  class ViewDataRepository : public ModelLayer::AbstractData::IRepository<ModelLayer::Services::AbstractDomain::IDocumentViewParams> {
  public:
    INJECT(ViewDataRepository());

    void
    create(std::unique_ptr<ModelLayer::Services::AbstractDomain::IDocumentViewParams> object);

    ModelLayer::Services::AbstractDomain::IDocumentViewParams *
    retrieve(int objectId);

    void
    update(ModelLayer::Services::AbstractDomain::IDocumentViewParams *object);

    std::unique_ptr<ModelLayer::Services::AbstractDomain::IDocumentViewParams>
    deleteEntry(int objectId);
  private:
    std::map<int, std::unique_ptr<ModelLayer::Services::AbstractDomain::IDocumentViewParams>> m_objectMap;
  };
}

#endif
