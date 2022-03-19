#ifndef SDF_EDITOR_MODELLAYER_SERVICES_COMPONENT_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_COMPONENT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Component.hpp
 * PURPOSE: Defines the DI component for the services subsystem.
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

#include "../../../Common/Model/ICrudRepository.hpp"
#include "../../../Common/MessageSystem/IChannel.hpp"
#include "../../UILayer/AbstractModel/Create/IGetMemoryRequirementsService.hpp"
#include "../../UILayer/AbstractModel/Create/ICreateDocumentService.hpp"
#include "../../UILayer/AbstractModel/Create/IGetDocumentPrefabService.hpp"
#include "../../UILayer/AbstractModel/Storage/ISaveDocumentService.hpp"
#include "../../UILayer/AbstractModel/Metrics/IConvertLengthService.hpp"
#include "../../UILayer/AbstractModel/Metrics/IConvertResolutionService.hpp"
#include "../../UILayer/AbstractModel/Metrics/IGetDocumentDimensionsService.hpp"
#include "../../UILayer/AbstractModel/Viewing/IAddViewService.hpp"
#include "../../UILayer/AbstractModel/Viewing/IGetViewCoordinatesService.hpp"
#include "../../UILayer/AbstractModel/Viewing/ISetViewXCoordinateService.hpp"
#include "../../UILayer/AbstractModel/Viewing/ISetViewYCoordinateService.hpp"
#include "../../UILayer/AbstractModel/Viewing/ISetViewCoordinatesService.hpp"
#include "../../UILayer/AbstractModel/Viewing/IRenderingService.hpp"
#include "../../UILayer/AbstractModel/Editing/IGetActiveDocumentService.hpp"
#include "../../UILayer/AbstractModel/Editing/ISetActiveDocumentService.hpp"
#include "../../UILayer/AbstractModel/Editing/IGetDocumentNameService.hpp"
#include "../DomainObjects/Engine/Gil/ImageTypes.hpp"
#include "../DomainObjects/Engine/Buffers/GridRendering.hpp"
#include "../DomainObjects/State/DocumentViewState.hpp"
#include "../AbstractData/IImageRepository.hpp"
#include "Messages/Object.hpp"

#include <fruit/fruit.h>

namespace SDF::Editor::ModelLayer::Services {
  typedef fruit::Component<
    fruit::Required<
      AbstractData::IImageRepository<DomainObjects::Engine::Gil::Any_Image>,
      Common::Model::ICrudRepository<Common::Handle, DomainObjects::Engine::Buffers::GridRendering>,
      Common::Model::ICrudRepository<Common::Handle, DomainObjects::State::DocumentViewState>
    >,
    UILayer::AbstractModel::Create::IGetMemoryRequirementsService,
    UILayer::AbstractModel::Create::ICreateDocumentService,
    UILayer::AbstractModel::Create::IGetDocumentPrefabService,
    UILayer::AbstractModel::Storage::ISaveDocumentService,
    UILayer::AbstractModel::Metrics::IConvertLengthService,
    UILayer::AbstractModel::Metrics::IConvertResolutionService,
    UILayer::AbstractModel::Metrics::IGetDocumentDimensionsService,
    UILayer::AbstractModel::Viewing::IAddViewService,
    UILayer::AbstractModel::Viewing::IGetViewCoordinatesService,
    UILayer::AbstractModel::Viewing::ISetViewXCoordinateService,
    UILayer::AbstractModel::Viewing::ISetViewYCoordinateService,
    UILayer::AbstractModel::Viewing::ISetViewCoordinatesService,
    UILayer::AbstractModel::Viewing::IRenderingService,
    UILayer::AbstractModel::Editing::IGetActiveDocumentService,
    UILayer::AbstractModel::Editing::ISetActiveDocumentService,
    UILayer::AbstractModel::Editing::IGetDocumentNameService
  > Component;

  Component
  getComponent();
}

#endif
