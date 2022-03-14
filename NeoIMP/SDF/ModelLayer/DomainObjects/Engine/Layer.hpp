#ifndef SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_LAYER_HPP
#define SDF_MODELLAYER_DOMAINOBJECTS_ENGINE_LAYER_HPP

/*
 * NeoIMP version 1.0.0 (STUB) - toward an easier-to-maintain GIMP alternative.
 * (C) 2020 Shimrra Shai. Distributed under both GPLv3 and MPL licenses.
 *
 * FILE:    Layer.hpp
 * PURPOSE: Defines the Layer template.
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

#include "../../AbstractData/Entity/Image.hpp"
#include "../IMappable.hpp"
#include "Components/IComponent.hpp"
#include "Dimensions.hpp"

#include <cstddef>
#include <string>
#include <memory>
#include <map>
#include <typeinfo>
#include <typeindex>

namespace SDF::ModelLayer::DomainObjects::Engine {
  // Class:      Layer
  // Purpose:    Defines a layer object. This is actually a fully-instantiatable class template.
  //             Layers are built up from components, similar to a common pattern used in computer
  //             games. These can be exchanged to change the different aspects of the layer and
  //             powerfully add functionality in a compositional manner instead of forming a complex
  //             inheritance hierarchy. It also eases layer conversions somewhat.
  // Parameters: ImplSpecT - A traits struct defining the implementation parameters for this image.
  template<class ImplSpecT>
  class Layer {
  public:
    // Function:   Layer
    // Purpose:    Constructs a new layer.
    // Parameters: None.
    Layer();

    // Function:   addToImageEntity
    // Purpose:    Adds this layer to an image entity for serialization.
    // Parameters: entity - The image entity to add to.
    // Returns:    None.
    void
    addToImageEntity(AbstractData::Entity::Image<typename ImplSpecT::entity_spec_t> &entity) const;

    // Function:   getContentWidth
    // Purpose:    Gets the width of this layer's content.
    // Parameters: None.
    // Returns:    The width of the content in pixels.
    ImageMeasure
    getContentWidth() const;

    // Function:   getContentHeight
    // Purpose:    Gets the height of this layer's content.
    // Parameters: None.
    // Returns:    The height of the content in pixels.
    ImageMeasure
    getContentHeight() const;

    // Function:   getContentRect
    // Purpose:    Gets the bounding rectangle of the layer content on the image.
    // Parameters: None.
    // Returns:    The bounding rectangle, suitably positioned and transformed.
    ImageRect
    getContentRect() const;

    // Function:   hasComponent
    // Purpose:    Returns if the layer has a component of a given type.
    // Parameters: None. (Template parameter)
    // Returns:    Whether the layer has a component of this type.
    template<class U>
    bool
    hasComponent();

    // Function:   attachComponent
    // Purpose:    Attaches a component to the layer.
    // Parameters: component - The component to attach.
    // Returns:    A non-owning pointer to the passed component.
    template<class U>
    U *
    attachComponent(std::unique_ptr<U> component);

    // Function:   getComponent
    // Purpose:    Gets the attached component of a given type, if one exists.
    // Parameters: None. (Template parameter)
    // Returns:    A pointer to the given component, or nullptr if none exists.
    template<class U>
    U *
    getComponent();

    template<class U>
    const U *
    getComponent() const;
  private:
    std::map<std::type_index, std::unique_ptr<Components::IComponent<ImplSpecT>>> m_components;

    template<class U>
    U *
    findFirstComponentByFamily(Components::EFamily family);
  };
}

#include "Layer.tpp"

#endif
