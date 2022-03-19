#ifndef SDF_EDITOR_MODELLAYER_SERVICES_MESSAGECOMPONENT_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_MESSAGECOMPONENT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    MessageComponent.hpp
 * PURPOSE: Defines the DI component for the services' messaging system.
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

#include "../../../Common/MessageSystem/IChannel.hpp"
#include "Messages/Object.hpp"

#include <fruit/fruit.h>

namespace SDF::Editor::ModelLayer::Services {
  typedef fruit::Component<
    Common::MessageSystem::IChannel<Messages::ImageAdded>,
    Common::MessageSystem::IChannel<Messages::ImageRemoved>
  > MessageComponent;

  MessageComponent
  getMessageComponent();
}

#endif