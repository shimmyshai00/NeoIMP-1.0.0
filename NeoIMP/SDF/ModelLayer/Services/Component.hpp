#ifndef SDF_MODELLAYER_SERVICES_COMPONENT_HPP
#define SDF_MODELLAYER_SERVICES_COMPONENT_HPP

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

#include "../../UILayer/AbstractModel/IDocumentPrefabsService.hpp"
#include "../../UILayer/AbstractModel/IDocumentRequirementsService.hpp"
#include "../../UILayer/AbstractModel/ICreateImageService.hpp"
#include "../../UILayer/AbstractModel/IMetricsService.hpp"
#include "../../UILayer/AbstractModel/IGetDocumentNameService.hpp"
#include "../../UILayer/AbstractModel/IRenderingService.hpp"
#include "../DomainObjects/Engine/Gil/ImageTypes.hpp"
#include "../DomainObjects/Engine/GridRendering.hpp"
#include "../Repositories/IRepository.hpp"

#include <fruit/fruit.h>

namespace SDF::ModelLayer::Services {
  fruit::Component<
    fruit::Required<
      Repositories::IRepository<DomainObjects::Engine::Gil::AnyGilImage>,
      Repositories::IRepository<DomainObjects::Engine::GridRendering>
    >,
    UILayer::AbstractModel::IDocumentPrefabsService,
    UILayer::AbstractModel::IDocumentRequirementsService,
    UILayer::AbstractModel::ICreateImageService,
    UILayer::AbstractModel::IGetDocumentNameService,
    UILayer::AbstractModel::IMetricsService,
    UILayer::AbstractModel::IRenderingService
  >
  getComponent();
}

#endif
