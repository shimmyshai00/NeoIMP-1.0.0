#ifndef SDF_MODELLAYER_ABSTRACTDATA_ENTITY_GIL_ENTITYTRAITS_HPP
#define SDF_MODELLAYER_ABSTRACTDATA_ENTITY_GIL_ENTITYTRAITS_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    EntityTraits.hpp
 * PURPOSE: Defines traits for each implemented image entity type in the Boost.GIL-based engine.
 *          These should mirror the implementations in ImplTraits.hpp in the domain object sublayer.
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

#include "Component/Background.hpp"

#include <boost/gil/pixel.hpp>
#include <boost/gil/image.hpp>
#include <boost/gil/image_view.hpp>

namespace SDF::ModelLayer::AbstractData::Entity::Gil {
  struct RGB24_888_Entity_Spec {
    typedef Component::Background<boost::gil::rgb8_view_t> background_component_entity_t;
  };
}

#endif
