/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RenderingRepository.cpp
 * PURPOSE: Implements the RenderingRepository class.
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

#include <RenderingRepository.hpp>

#include <DataLayer/Exceptions/Exceptions.hpp>

#include <algorithm>

namespace SDF::DataLayer::Repositories {
  using namespace ModelLayer::Services;

  RenderingRepository::RenderingRepository() {}

  void
  RenderingRepository::create(std::unique_ptr<AbstractDomain::IRenderBuffer> object) {
    int objectId(object->getId());

    m_objectMap[objectId] = std::move(object);
  }

  AbstractDomain::IRenderBuffer *
  RenderingRepository::retrieve(int objectId) {
    if(m_objectMap.find(objectId) == m_objectMap.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(objectId);
    } else {
      return m_objectMap[objectId].get();
    }
  }

  void
  RenderingRepository::update(AbstractDomain::IRenderBuffer *object) {
    if(m_objectMap.find(object->getId()) == m_objectMap.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(object->getId());
    } else {
      // TBA
    }
  }

  std::unique_ptr<AbstractDomain::IRenderBuffer>
  RenderingRepository::deleteEntry(int objectId) {
    if(m_objectMap.find(objectId) == m_objectMap.end()) {
      throw DataLayer::Exceptions::ObjectNotFoundException(objectId);
    } else {
      m_objectMap.erase(objectId);
    }
  }
}
