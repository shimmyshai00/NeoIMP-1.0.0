#ifndef SDF_EDITOR_DATALAYER_COMPONENT_HPP
#define SDF_EDITOR_DATALAYER_COMPONENT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020-2022 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Component.hpp
 * PURPOSE: Defines the DI component for the whole data layer.
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

#include "../../Common/Data/IDataMapper.hpp"
#include "../../Common/Model/ICrudRepository.hpp"

#include "../ModelLayer/DomainObjects/Engine/Buffers/GridRendering.hpp"
#include "../ModelLayer/DomainObjects/Engine/Gil/ImageTypes.hpp"
#include "../ModelLayer/DomainObjects/State/DocumentViewState.hpp"

#include "../ModelLayer/AbstractData/IImageRepository.hpp"
#include "../ModelLayer/AbstractData/IImageFileInfoRequester.hpp"
#include "Repositories/Formats.hpp"

#include <fruit/fruit.h>

namespace SDF::Editor::DataLayer {
  typedef fruit::Component<
    ModelLayer::AbstractData::IImageRepository<ModelLayer::DomainObjects::Engine::Gil::Any_Image>,
    ModelLayer::AbstractData::IImageFileInfoRequester<
      ModelLayer::DomainObjects::Engine::Gil::Any_Image
    >,
    Common::Model::ICrudRepository<
      Common::Handle,
      ModelLayer::DomainObjects::Engine::Buffers::GridRendering
    >,
    Common::Model::ICrudRepository<
      Common::Handle,
      ModelLayer::DomainObjects::State::DocumentViewState
    >
  > Component;

  Component
  getComponent();
}

#endif
