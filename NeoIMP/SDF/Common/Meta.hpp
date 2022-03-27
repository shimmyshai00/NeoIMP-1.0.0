#ifndef SDF_COMMON_META_HPP
#define SDF_COMMON_META_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Meta.hpp
 * PURPOSE: Defines some template meta-programming features for dealing with runtime access to
 *          compile-time template parameter packs. Note: presumably there is some way to do this
 *          with Boost::mp11 or even C++ builtins in latest versions however this author is
 *          unfamiliar with them right now. NB: NEEDS REVISITING
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

#include <cstddef>
#include <vector>

namespace SDF::Common::Meta {
  // Provides a dynamically-accessible version of the constant parameter pack passed.
  template<typename T, T ... Consts>
  struct dynamic_pack {
    static const std::size_t num_vals =
      boost::mp11::mp_size<boost::mp11::mp_list_c<T, Consts...>>::value;

    static const std::vector<T> vals;
  };

  template<typename T, T ... Consts>
  const std::vector<T> dynamic_pack<T, Consts...>::vals = { Consts ... };
}

#endif
