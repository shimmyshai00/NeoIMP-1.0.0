#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_INAMEABLE_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_INAMEABLE_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    INameable.hpp
 * PURPOSE: Defines the INameable interface.
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

#include <string>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine {
  // Class:      INameable
  // Purpose:    Defines an interface for nameable objects.
  // Parameters: None.
  class INameable {
  public:
    virtual ~INameable() = default;

    // Function:   setName
    // Purpose:    Sets the name of the nameable.
    // Parameters: name - The name to give.
    // Returns:    None.
    virtual void
    setName(std::string name) = 0;
  };
}

#endif
