#ifndef SDF_MODELLAYER_SERVICES_BROKERID_HPP
#define SDF_MODELLAYER_SERVICES_BROKERID_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    BrokerId.hpp
 * PURPOSE: Enumerates the ID values for the services when attached to a message broker.
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

namespace SDF::ModelLayer::Services {
  enum BrokerId {
    SERVICE_DOCUMENT_CREATION,
    SERVICE_DOCUMENT_STORAGE,
    SERVICE_DOCUMENT_ACCESS,
    SERVICE_DOCUMENT_RENDER,
    SERVICE_DOCUMENT_VIEW_CONFIG,
    SERVICE_TOOL_BASED_EDITING,
    SERVICE_SELECT_TOOL_CONFIG,
    SERVICE_ZOOM_TOOL_CONFIG,
    SERVICE_MAX
  };
}

#endif
