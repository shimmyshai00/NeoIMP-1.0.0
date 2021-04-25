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

#include <SDF/UILayer/AbstractModel/IDocumentCreationService.hpp>
#include <SDF/UILayer/AbstractModel/IDocumentStorageService.hpp>
#include <SDF/UILayer/AbstractModel/IDocumentAccessService.hpp>
#include <SDF/UILayer/AbstractModel/IDocumentRenderService.hpp>
#include <SDF/UILayer/AbstractModel/IUiStateModelService.hpp>

#include <SDF/UILayer/AbstractModel/Handle.hpp>

#include <fruit/fruit.h>

namespace SDF::ModelLayer::Services {
  typedef fruit::Component<UILayer::AbstractModel::IDocumentCreationService,
                           UILayer::AbstractModel::IDocumentStorageService,
                           UILayer::AbstractModel::IDocumentAccessService,
                           UILayer::AbstractModel::IDocumentRenderService,
                           UILayer::AbstractModel::IUiStateModelService<UILayer::AbstractModel::Handle>
                          >
  Component;

  Component getComponent();
}

#endif
