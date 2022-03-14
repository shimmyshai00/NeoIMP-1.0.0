#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COMPONENTS_ICOMPONENT_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_COMPONENTS_ICOMPONENT_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    IComponent.hpp
 * PURPOSE: Defines the IComponent interface.
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

#include "../../../Exceptions.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine::Components {
  // Class:      IComponent
  // Purpose:    Defines the base interface for all image components. Note that components typically
  //             should not have a lot of logic in them. Simple logic like bounds/correctness
  //             checking and the like is okay - but don't put a whole image transform algorithm
  //             into the content component! Use the Algorithm folder in your engine implementation
  //             for that.
  // Parameters: ImplSpecT - The implementation traits type.
  template<class ImplSpecT>
  class IComponent {
  public:
    virtual ~IComponent() = default;

    // Function:   getType
    // Purpose:    Get the type of this component.
    // Parameters: None.
    // Returns:    The component type.
    EType
    getType() const = 0;
  };
}

#endif
