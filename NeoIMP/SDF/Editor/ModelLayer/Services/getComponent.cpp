/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    getComponent.cpp
 * PURPOSE: Implements the DI component for the services subsystem.
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

#include "../../../Common/MessageSystem/AllToAll.hpp"
#include "Messages/ObjectChanges.hpp"

#include "Gil/getComponent.hpp"
#include "UnitConversionService.hpp"
#include "DocumentPrefabsService.hpp"
#include "EditorStateModelService.hpp"
#include "DocumentViewStateService.hpp"
#include "DocumentNotificationService.hpp"

#include "getMessageComponent.hpp"

namespace SDF::Editor::ModelLayer::Services {
  Component
  getComponent() {
    return fruit::createComponent()
      .bind<UILayer::AbstractModel::Create::IGetDocumentPrefabService, Services::DocumentPrefabsService>()
      .bind<UILayer::AbstractModel::Metrics::IConvertLengthService, Services::UnitConversionService>()
      .bind<UILayer::AbstractModel::Metrics::IConvertResolutionService, Services::UnitConversionService>()
      .bind<UILayer::AbstractModel::Editing::IGetActiveDocumentService, Services::EditorStateModelService>()
      .bind<UILayer::AbstractModel::Editing::ISetActiveDocumentService, Services::EditorStateModelService>()
      .bind<UILayer::AbstractModel::DocumentMgmt::IDocumentAddedService, Services::DocumentNotificationService>()
      .bind<UILayer::AbstractModel::Viewing::IAddViewService, Services::DocumentViewStateService>()
      .bind<UILayer::AbstractModel::Viewing::IGetViewCoordinatesService, Services::DocumentViewStateService>()
      .bind<UILayer::AbstractModel::Viewing::ISetViewXCoordinateService, Services::DocumentViewStateService>()
      .bind<UILayer::AbstractModel::Viewing::ISetViewYCoordinateService, Services::DocumentViewStateService>()
      .bind<UILayer::AbstractModel::Viewing::ISetViewCoordinatesService, Services::DocumentViewStateService>()
      .install(getMessageComponent)
      .install(Gil::getComponent);
  }
}
