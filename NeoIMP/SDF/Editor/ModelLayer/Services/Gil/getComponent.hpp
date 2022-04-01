#ifndef SDF_EDITOR_MODELLAYER_SERVICES_GIL_GETCOMPONENT_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_GIL_GETCOMPONENT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    getComponent.hpp
 * PURPOSE: Defines the DI component for the Gil implementation's services.
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

#include "../../../../Common/Data/IOwningCrudable.hpp"
#include "../../../../Common/MessageSystem/IMessageDispatcher.hpp"
#include "../../../UILayer/AbstractModel/Create/IGetMemoryRequirementsService.hpp"
#include "../../../UILayer/AbstractModel/Create/ICreateDocumentService.hpp"
#include "../../../UILayer/AbstractModel/Storage/IGetDocumentFileInfoService.hpp"
#include "../../../UILayer/AbstractModel/Storage/ISaveDocumentService.hpp"
#include "../../../UILayer/AbstractModel/Storage/ILoadDocumentService.hpp"
#include "../../../UILayer/AbstractModel/Editing/IGetDocumentNameService.hpp"
#include "../../../UILayer/AbstractModel/Metrics/IGetDocumentDimensionsService.hpp"
#include "../../../UILayer/AbstractModel/Viewing/IRenderingService.hpp"
#include "../../DomainObjects/Engine/Gil/ImageTypes.hpp"
#include "../../DomainObjects/Engine/Buffers/GridRendering.hpp"
#include "../../AbstractData/IImageRetainer.hpp"
#include "../../AbstractData/IImageLoader.hpp"
#include "../../AbstractData/IImagePersister.hpp"
#include "../../AbstractData/IImageRetriever.hpp"
#include "../../AbstractData/IImageFileInfoRequester.hpp"
#include "../Messages/ObjectChanges.hpp"

#include <fruit/fruit.h>

namespace SDF::Editor::ModelLayer::Services::Gil {
  typedef fruit::Component<
    fruit::Required<
      AbstractData::IImageRetainer<DomainObjects::Engine::Gil::Any_Image>,
      AbstractData::IImageLoader<DomainObjects::Engine::Gil::Any_Image>,
      AbstractData::IImagePersister<DomainObjects::Engine::Gil::Any_Image>,
      AbstractData::IImageRetriever<DomainObjects::Engine::Gil::Any_Image>,
      AbstractData::IImageFileInfoRequester<DomainObjects::Engine::Gil::Any_Image>,
      Common::Data::IOwningCrudable<Common::Handle, DomainObjects::Engine::Buffers::GridRendering>,
      Common::MessageSystem::IMessageDispatcher<Messages::ImageAdded>,
      Common::MessageSystem::IMessageDispatcher<Messages::ImageRemoved>
    >,
    UILayer::AbstractModel::Create::IGetMemoryRequirementsService,
    UILayer::AbstractModel::Create::ICreateDocumentService,
    UILayer::AbstractModel::Storage::IGetDocumentFileInfoService,
    UILayer::AbstractModel::Storage::ISaveDocumentService,
    UILayer::AbstractModel::Storage::ILoadDocumentService,
    UILayer::AbstractModel::Metrics::IGetDocumentDimensionsService,
    UILayer::AbstractModel::Editing::IGetDocumentNameService,
    UILayer::AbstractModel::Viewing::IRenderingService
  > Component;

  Component
  getComponent();
}

#endif
