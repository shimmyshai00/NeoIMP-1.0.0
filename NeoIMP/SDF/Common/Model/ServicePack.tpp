#ifndef SDF_COMMON_MODEL_SERVICEPACK_TPP
#define SDF_COMMON_MODEL_SERVICEPACK_TPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ServicePack.tpp
 * PURPOSE: Implements the ServicePack template.
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

#include <boost/mp11/integral.hpp>
#include <boost/mp11/list.hpp>
#include <boost/mp11/algorithm.hpp>

namespace SDF::Common::Model {
  template<class ... Ss>
  ServicePack<Ss...>::ServicePack(Ss *... as_services)
    : m_serviceTuple(as_services...)
  {
  }

  template<class ... Ss>
  template<class ... Supers>
  ServicePack<Ss...>::ServicePack(const ServicePack<Supers...> &superPack)
    : m_serviceTuple(
        std::get<boost::mp11::mp_find<tuple_t, Ss *>::value>(superPack.m_serviceTuple)...
      )
  {
  }

  template<class... Ss>
  template<class S>
  S *
  ServicePack<Ss...>::get() const {
    return std::get<boost::mp11::mp_find<tuple_t, S *>::value>(m_serviceTuple);
  }
}

#endif
