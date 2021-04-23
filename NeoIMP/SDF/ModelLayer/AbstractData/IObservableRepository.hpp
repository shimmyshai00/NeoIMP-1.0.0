#ifndef SDF_MODELLAYER_ABSTRACTDATA_IOBSERVABLEREPOSITORY_HPP
#define SDF_MODELLAYER_ABSTRACTDATA_IOBSERVABLEREPOSITORY_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IObservableRepository.hpp
 * PURPOSE: Defines the IObservableRepository interface.
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

#include <memory>

#include <SDF/ModelLayer/AbstractData/IRepository.hpp>
#include <SDF/Interfaces/IObservable.hpp>

#include <SDF/ModelLayer/AbstractData/RepositoryEvent.hpp>

namespace SDF::ModelLayer::AbstractData {
  // Class:      IObservableRepository
  // Purpose:    Provides an interface for domain object repositories which can also be observed for changes.
  // Parameters: T - The domain object type held in the repository.
  template<class T>
  class IObservableRepository : public IRepository<T>,
                                public Interfaces::IObservable<RepositoryEvent<T>>
  {
  };
}

#endif
