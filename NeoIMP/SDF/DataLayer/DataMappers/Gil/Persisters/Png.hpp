#ifndef SDF_DATALAYER_DATAMAPPERS_GIL_PERSISTERS_HPP
#define SDF_DATALAYER_DATAMAPPERS_GIL_PERSISTERS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Png.hpp
 * PURPOSE: Defines a visitor-friendly algorithm-like object to persist Boost.GIL entities to PNG
 *          format.
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

#include "../../../../ModelLayer/AbstractData/Entity/Gil/Image.hpp"
#include "EDirection.hpp"

namespace SDF::DataLayer::DataMappers::Gil::Persisters {
  // Note: The PNG persister can only persist the background layer because PNG is a single-layer
  //       format. For clean persisting of multilayer images to PNG, preprocessing in the model
  //       is required to merge the layers (effectively a rendering operation).
  struct Png {
    std::string m_fileSpec;
    EDirection m_direction;

    Png(std::string fileSpec,
        EDirection direction
       ) : m_fileSpec(fileSpec),
           m_direction(direction)
    {}

    template<class GilBkgImageT, class GilImageT>
    void
    operator()(ModelLayer::AbstractData::Entity::Gil::Image<GilBkgImageT, GilImageT> &ent);
  };
}

#include "Png.tpp"

#endif
