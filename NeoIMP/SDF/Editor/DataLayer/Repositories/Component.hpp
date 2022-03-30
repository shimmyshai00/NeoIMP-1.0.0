#ifndef SDF_EDITOR_DATALAYER_REPOSITORIES_COMPONENT_HPP
#define SDF_EDITOR_DATALAYER_REPOSITORIES_COMPONENT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020-2022 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Component.hpp
 * PURPOSE: Defines the DI component for the repository subsystem.
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

#include "../../../Common/Data/ICrudable.hpp"
#include "../../../Common/Data/IOwningCrudable.hpp"
#include "../../../Common/Data/IOwningRetrievable.hpp"

#include "../../ModelLayer/DomainObjects/Engine/Buffers/GridRendering.hpp"
#include "../../ModelLayer/DomainObjects/Engine/Gil/ImageTypes.hpp"
#include "../../ModelLayer/DomainObjects/State/SDocumentViewState.hpp"

#include "../../ModelLayer/AbstractData/IImageRetainer.hpp"
#include "../../ModelLayer/AbstractData/IImageFileInfoRequester.hpp"
#include "../../ModelLayer/AbstractData/IImageLoader.hpp"
#include "../../ModelLayer/AbstractData/IImagePersister.hpp"
#include "../../ModelLayer/AbstractData/IImageRetriever.hpp"

#include "Formats.hpp"

#include <fruit/fruit.h>
#include <string>

namespace SDF::Editor::DataLayer::Repositories {
  typedef fruit::Component<
    fruit::Required<
      fruit::Annotated<
        Formats::PNG,
        Common::Data::ICrudable<std::string, ModelLayer::DomainObjects::Engine::Gil::Any_Image>
      >
    >,
    ModelLayer::AbstractData::IImageRetainer<ModelLayer::DomainObjects::Engine::Gil::Any_Image>,
    ModelLayer::AbstractData::IImageFileInfoRequester<
      ModelLayer::DomainObjects::Engine::Gil::Any_Image
    >,
    ModelLayer::AbstractData::IImageLoader<ModelLayer::DomainObjects::Engine::Gil::Any_Image>,
    ModelLayer::AbstractData::IImagePersister<ModelLayer::DomainObjects::Engine::Gil::Any_Image>,
    ModelLayer::AbstractData::IImageRetriever<ModelLayer::DomainObjects::Engine::Gil::Any_Image>,
    Common::Data::IOwningRetrievable<
      Common::Handle,
      ModelLayer::DomainObjects::Engine::Gil::Any_Image
    >,
    Common::Data::IOwningCrudable<
      Common::Handle,
      ModelLayer::DomainObjects::Engine::Buffers::GridRendering
    >,
    Common::Data::ICrudable<
      Common::Handle,
      ModelLayer::DomainObjects::State::SDocumentViewState
    >
  > Component;

  Component
  getComponent();
}

#endif
