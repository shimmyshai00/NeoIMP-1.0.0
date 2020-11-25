#ifndef SDF_MODELLAYER_REPOSITORY_IVOLATILEREPOSITORY_HPP
#define SDF_MODELLAYER_REPOSITORY_IVOLATILEREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IVolatileRepository.hpp
 * PURPOSE: Definition of the interface for domain object repositories that hold objects in RAM only, i.e. non-
 *          persistent or volatile storage.
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

#include <SDF/ModelLayer/Handle.hpp>
#include <memory>

namespace SDF::ModelLayer::Repository {
  template<class ObjectType>
  class IVolatileRepository {
  public:
    virtual ~IVolatileRepository() = default;

    virtual Handle storeObject(std::unique_ptr<ObjectType> object) = 0;
    virtual ObjectType *accessObject(Handle handle) = 0;
    virtual void deleteObject(Handle handle) = 0;
  };
}

#endif
