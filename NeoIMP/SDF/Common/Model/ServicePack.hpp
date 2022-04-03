#ifndef SDF_COMMON_MODEL_SERVICEPACK_HPP
#define SDF_COMMON_MODEL_SERVICEPACK_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ServicePack.hpp
 * PURPOSE: Defines the ServicePack template.
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

#include <fruit/fruit.h>

#include <tuple>

namespace SDF::Common::Model {
  // Class:      ServicePack
  // Purpose:    Provides a type-referenced container of types meant to be dependency-injected (DI)
  //             as services from a model layer. This allows to bundle together the dependency
  //             requirements for a UI layer client without having to respecify them again in DI
  //             components and especially factories.
  // Parameters: Ss - The service interfaces to inject.
  template<class ... Ss>
  class ServicePack {
  public:
    INJECT(ServicePack(Ss *... as_services));

    // Obtains a subset of a service pack.
    template<class ... Supers>
    ServicePack(const ServicePack<Supers...> &superPack);

    template<class S>
    S *
    get() const;
  private:
    typedef std::tuple<Ss *...> tuple_t;
    tuple_t m_serviceTuple;
  };
}

#include "ServicePack.tpp"

#endif
