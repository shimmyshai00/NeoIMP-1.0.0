#ifndef SDF_MODELLAYER_SERVICES_EVENTS_REPOSITORYUPDATES_HPP
#define SDF_MODELLAYER_SERVICES_EVENTS_REPOSITORYUPDATES_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    RepositoryUpdates.hpp
 * PURPOSE: Defines events for reporting updates to domain object repositories.
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

namespace SDF::ModelLayer::Services::Events {
  template<class T>
  struct RepositoryUpdate { virtual ~RepositoryUpdate() = default; };

  template<class T>
  struct Created : public RepositoryUpdate<T> { int objectId; };

  template<class T>
  struct Updated : public RepositoryUpdate<T> { int objectId; };

  template<class T>
  struct Deleted : public RepositoryUpdate<T> { int objectId; };
}

#endif
