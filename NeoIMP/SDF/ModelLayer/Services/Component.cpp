/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Component.hpp
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

#include <SDF/ModelLayer/Services/Component.hpp>

#include <DocumentCreationService.hpp>
#include <DocumentStorageService.hpp>
#include <DocumentAccessService.hpp>
#include <DocumentRenderService.hpp>
#include <UiStateModelService.hpp>
#include <DocumentViewConfigService.hpp>
#include <ToolApplicationService.hpp>

#include <DomainObjects/Component.hpp>
#include <DataLayer/Repositories/Component.hpp>

namespace SDF::ModelLayer::Services {
  Component getComponent() {
    return fruit::createComponent()
      .bind<UILayer::AbstractModel::IDocumentCreationService, DocumentCreationService>()
      .bind<UILayer::AbstractModel::IDocumentStorageService, DocumentStorageService>()
      .bind<UILayer::AbstractModel::IDocumentAccessService, DocumentAccessService>()
      .bind<UILayer::AbstractModel::IDocumentRenderService, DocumentRenderService>()
      .bind<UILayer::AbstractModel::IUiStateModelService<UILayer::AbstractModel::Handle>,
            UiStateModelService<UILayer::AbstractModel::Handle>
           >()
      .bind<UILayer::AbstractModel::IUiStateModelService<bool>,
            UiStateModelService<bool>
           >()
      .bind<UILayer::AbstractModel::IDocumentViewConfigService, DocumentViewConfigService>()
      .bind<UILayer::AbstractModel::IToolApplicationService, ToolApplicationService>()
      .install(DomainObjects::getComponent)
      .install(DataLayer::Repositories::getComponent);
  }
}
