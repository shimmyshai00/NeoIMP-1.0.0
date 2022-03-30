#ifndef SDF_EDITOR_DATALAYER_DATAMAPPERS_GIL_SPNG_HPP
#define SDF_EDITOR_DATALAYER_DATAMAPPERS_GIL_SPNG_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    SPng.hpp
 * PURPOSE: Defines a traits struct for the PNG format as implemeted in the Boost.GIL subsystem.
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

#include "Persisters/Png.hpp"
#include "Validators/Png.hpp"
#include "Loaders/Png.hpp"

namespace SDF::Editor::DataLayer::DataMappers::Gil {
  struct SPng {
    typedef Persisters::Png persister_t;
    typedef Validators::Png validator_t;
    typedef Loaders::Png loader_t;
  };
}

#endif
