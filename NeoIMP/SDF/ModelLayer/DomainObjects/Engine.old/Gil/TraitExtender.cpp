/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    TraitExtender.cpp
 * PURPOSE: Extends GIL image traits to include NeoIMP-specific context such as color model types
 *          and entity (serialization) types. This just saves some redundancy/unsafety in the
 *          templates used elsewhere.
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

#include "TraitExtender.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::Gil {
  ColorModels::RGB24_888 ExtTraits<boost::gil::rgb8_image_t>::color_model =
    ColorModels::RGB24_888();
}