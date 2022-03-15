#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COMPONENTS_ICOMPONENT_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_COMPONENTS_ICOMPONENT_HPP

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

#include "../../../AbstractData/Entity/Layer.hpp"
#include "EFamily.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Engine::Components {
  // Class:      IComponent
  // Purpose:    Defines the base interface for all image components. This doesn't really do
  //             much except provide a header under which to aggregate them.
  // Parameters: ImplSpecT - The implementation traits type.
  template<class ImplSpecT>
  class IComponent {
  public:
    virtual ~IComponent() = default;

    // Function:   getFamily
    // Purpose:    Gets the family of components this component belongs to.
    // Parameters: None.
    // Returns:    The component family.
    virtual EFamily
    getFamily() const = 0;

    // Function:   addToLayerEntity
    // Purpose:    Adds this component to a layer entity for serialization.
    // Parameters: entity - The layer entity to add to.
    // Returns:    None.
    virtual void
    addToLayerEntity(AbstractData::Entity::Layer<typename ImplSpecT::entity_spec_t> &entity
                    ) const = 0;
  };
}

#endif
