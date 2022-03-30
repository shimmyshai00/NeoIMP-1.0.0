/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020-2022 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Component.hpp
 * PURPOSE: Implements the DI component for the repository subsystem.
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

#include "Component.hpp"

#include "../../../Common/Data/Repositories/MemoryOnlyRepository.hpp"
#include "../../../Common/Data/Repositories/MemoryOnlyValueRepository.hpp"
#include "ImageRepository.hpp"

#include <boost/gil/typedefs.hpp>

namespace SDF::Editor::DataLayer::Repositories {
  Component
  getComponent() {
    return fruit::createComponent()
      .bind<
        ModelLayer::AbstractData::IImageRetainer<ModelLayer::DomainObjects::Engine::Gil::Any_Image>,
        ImageRepository<ModelLayer::DomainObjects::Engine::Gil::Any_Image>
       >()
      .bind<
        ModelLayer::AbstractData::IImageFileInfoRequester<
          ModelLayer::DomainObjects::Engine::Gil::Any_Image
        >,
        ImageRepository<ModelLayer::DomainObjects::Engine::Gil::Any_Image>
       >()
      .bind<
        ModelLayer::AbstractData::IImageLoader<ModelLayer::DomainObjects::Engine::Gil::Any_Image>,
        ImageRepository<ModelLayer::DomainObjects::Engine::Gil::Any_Image>
       >()
      .bind<
        ModelLayer::AbstractData::IImagePersister<
          ModelLayer::DomainObjects::Engine::Gil::Any_Image
        >,
        ImageRepository<ModelLayer::DomainObjects::Engine::Gil::Any_Image>
       >()
      .bind<
        ModelLayer::AbstractData::IImageRetriever<
          ModelLayer::DomainObjects::Engine::Gil::Any_Image
        >,
        ImageRepository<ModelLayer::DomainObjects::Engine::Gil::Any_Image>
       >()
      .bind<
        Common::Data::IOwningRetrievable<
          Common::Handle,
          ModelLayer::DomainObjects::Engine::Gil::Any_Image
        >,
        ImageRepository<ModelLayer::DomainObjects::Engine::Gil::Any_Image>
       >()
      .bind<
        Common::Data::IOwningCrudable<
          Common::Handle,
          ModelLayer::DomainObjects::Engine::Buffers::GridRendering
        >,
        Common::Data::Repositories::MemoryOnlyRepository<
          Common::Handle,
          ModelLayer::DomainObjects::Engine::Buffers::GridRendering
        >
       >()
      .bind<
        Common::Data::ICrudable<
          Common::Handle,
          ModelLayer::DomainObjects::State::SDocumentViewState
        >,
        Common::Data::Repositories::MemoryOnlyValueRepository<
          Common::Handle,
          ModelLayer::DomainObjects::State::SDocumentViewState
        >
       >();
  }
}
