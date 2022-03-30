#ifndef SDF_EDITOR_MODELLAYER_SERVICES_MESSAGES_OBJECTCHANGES_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_MESSAGES_OBJECTCHANGES_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    ObjectChanges.hpp
 * PURPOSE: Defines messages related to object creation and destruction.
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

#include "../../../../Common/Handle.hpp"

namespace SDF::Editor::ModelLayer::Services::Messages {
  struct SImageAdded {
    Common::Handle handle;

    SImageAdded(Common::Handle t_handle) : handle(t_handle) {}
  };

  struct SImageRemoved {
    Common::Handle handle;

    SImageRemoved(Common::Handle t_handle) : handle(t_handle) {}
  };
}

#endif
