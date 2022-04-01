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

#include "../../DomainObjects/Engine/Gil/ImageTypes.hpp"

#include "../GetFileInfoService.hpp"
#include "CreateImageService.hpp"
#include "GetDocumentInfoService.hpp"
#include "RenderingService.hpp"
#include "SaveDocumentService.hpp"
#include "LoadDocumentService.hpp"

namespace SDF::Editor::ModelLayer::Services::Gil {
  Component
  getComponent() {
    return fruit::createComponent()
      .bind<UILayer::AbstractModel::Create::IGetMemoryRequirementsService, CreateImageService>()
      .bind<UILayer::AbstractModel::Create::ICreateDocumentService, CreateImageService>()
      .bind<
        UILayer::AbstractModel::Storage::IGetDocumentFileInfoService,
        GetFileInfoService<DomainObjects::Engine::Gil::Any_Image>
       >()
      .bind<UILayer::AbstractModel::Storage::ISaveDocumentService, SaveDocumentService>()
      .bind<UILayer::AbstractModel::Storage::ILoadDocumentService, LoadDocumentService>()
      .bind<UILayer::AbstractModel::Editing::IGetDocumentNameService, GetDocumentInfoService>()
      .bind<UILayer::AbstractModel::Metrics::IGetDocumentDimensionsService, GetDocumentInfoService>()
      .bind<UILayer::AbstractModel::Viewing::IRenderingService, RenderingService>();
  }
}
