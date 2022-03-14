#ifndef SDF_DATALAYER_DATAMAPPERS_GIL_COMPONENT_HPP
#define SDF_DATALAYER_DATAMAPPERS_GIL_COMPONENT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Component.hpp
 * PURPOSE: Defines the DI component for the Boost.GIL-based data mapper subsystem.
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

#include "../../../ModelLayer/AbstractData/Entity/Gil/EntityTypes.hpp"
#include "../../../ModelLayer/AbstractData/IDataMapper.hpp"
#include "../../../ModelLayer/AbstractData/Formats.hpp"

#include <fruit/fruit.h>

namespace SDF::DataLayer::DataMappers::Gil {
  typedef fruit::Component<
    fruit::Annotated<
      ModelLayer::AbstractData::Formats::PNG,
      ModelLayer::AbstractData::IDataMapper<ModelLayer::AbstractData::Entity::Gil::RGB24_888_Entity>
    >,
    fruit::Annotated<
      ModelLayer::AbstractData::Formats::PNG,
      ModelLayer::AbstractData::IDataMapper<ModelLayer::AbstractData::Entity::Gil::Any_Entity>
    >
  > Component;

  Component
  getComponent();
}

#endif
