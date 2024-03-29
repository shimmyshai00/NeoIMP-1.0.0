#ifndef SDF_EDITOR_DATALAYER_DATAMAPPERS_GIL_GETCOMPONENT_HPP
#define SDF_EDITOR_DATALAYER_DATAMAPPERS_GIL_GETCOMPONENT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    getComponent.hpp
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

#include "../../../../Common/Data/ICrudable.hpp"
#include "../../../ModelLayer/DomainObjects/Engine/Gil/ImageTypes.hpp"
#include "../../Repositories/Formats.hpp"

#include <fruit/fruit.h>

namespace SDF::Editor::DataLayer::DataMappers::Gil {
  typedef fruit::Component<
    fruit::Annotated<
      Repositories::Formats::PNG,
      Common::Data::ICrudable<
        std::string,
        ModelLayer::DomainObjects::Engine::Gil::RGB24_888_Image
      >
    >,
    fruit::Annotated<
      Repositories::Formats::PNG,
      Common::Data::ICrudable<std::string, ModelLayer::DomainObjects::Engine::Gil::Any_Image>
    >
  > Component;

  Component
  getComponent();
}

#endif
