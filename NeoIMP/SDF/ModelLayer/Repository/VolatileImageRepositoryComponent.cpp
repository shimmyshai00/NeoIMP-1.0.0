/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    VolatileImageRepositoryComponent.cpp
 * PURPOSE: Implementation of the DI component for the volatile image repository.
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

#include <VolatileImageRepositoryComponent.hpp>
#include <DataLayer/Repositories/ConcreteVolatileRepository.hpp>

namespace SDF::ModelLayer::Repository {
  fruit::Component<IVolatileRepository<DomainObjects::Image::ImageVariant>> getVolatileImageRepositoryComponent() {
    return fruit::createComponent()
      .bind<
        IVolatileRepository<DomainObjects::Image::ImageVariant>,
        DataLayer::Repositories::ConcreteVolatileRepository<DomainObjects::Image::ImageVariant>
      >();
  }
}
