/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    getComponent.cpp
 * PURPOSE: Implements the DI component for the Boost.GIL-based data mapper subsystem.
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

#include "getComponent.hpp"

#include "../../../../Common/Data/Adapters/getComponent.hpp"
#include "../../../../Common/Data/ICrudable.hpp"

#include "../ImageMapper.hpp"
#include "../ImageVariantMapper.hpp"
#include "Png.hpp"

namespace SDF::Editor::DataLayer::DataMappers::Gil {
  Component
  getComponent() {
    using namespace ModelLayer::DomainObjects;

    return fruit::createComponent()
      .bind<
        fruit::Annotated<
          Repositories::Formats::PNG,
          Common::Data::ICrudable<std::string, Engine::Gil::RGB24_888_Image>
        >,
        ImageMapper<Png, Engine::Gil::RGB24_888_Image>
       >()
      .bind<
        fruit::Annotated<
          Repositories::Formats::PNG,
          Common::Data::ICrudable<std::string, Engine::Gil::Any_Image>
        >,
        ImageVariantMapper<Png, Engine::Gil::Any_Image>
       >()
      .install(Common::Data::Adapters::getComponent);
  };
}
