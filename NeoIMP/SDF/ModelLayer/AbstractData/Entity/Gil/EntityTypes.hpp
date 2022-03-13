#ifndef SDF_MODELLAYER_ABSTRACTDATA_ENTITY_GIL_ENTITYTYPES_HPP
#define SDF_MODELLAYER_ABSTRACTDATA_ENTITY_GIL_ENTITYTYPES_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    EntityTypes.hpp
 * PURPOSE: Defines a set of predefined image entity types.
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

#include "Image.hpp"
#include "ImageVariant.hpp"

#include <boost/gil/typedefs.hpp>
#include <boost/gil/image.hpp>

namespace SDF::ModelLayer::AbstractData::Entity::Gil {
  typedef Image<boost::gil::rgb8_image_t, boost::gil::rgba8_image_t> RGB24_888_Image;
  
  typedef ImageVariant<RGB24_888_Image> Any_Image;
}

#endif