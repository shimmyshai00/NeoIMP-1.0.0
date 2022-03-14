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

#include "Components/IComponent.hpp"
#include "Components/EType.hpp"
#include "Dimensions.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine {
  // Class:      Layer
  // Purpose:    Defines a base class for layer objects.
  // Parameters: ImplSpecT - A traits struct defining the implementation parameters for this image.
  template<class ImplSpecT>
  class Layer {
  public:
    // Function:   Layer
    // Purpose:    Constructs a new layer.
    // Parameters: None.
    Layer();

    // Function:   getWidthPx
    // Purpose:    Gets the width of the layer in pixels.
    // Parameters: None.
    // Returns:    The width of the layer in pixels.
    ImageMeasure
    getWidthPx() const;

    // Function:   getHeightPx
    // Purpose:    Gets the height of the layer in pixels.
    // Parameters: None.
    // Returns:    The height of the layer in pixels.
    ImageMeasure
    getHeightPx() const;

    // Function:   getContentRect
    // Purpose:    Gets the bounding rectangle of the layer content.
    // Parameters: None.
    // Returns:    The content bounding rectangle.
    ImageRect
    getContentRect() const;

    // Function:   attachComponent
    // Purpose:    Attaches a component to this layer.
    // Parameters: component - The component to attach. Note that not all component combinations are
    //                         compatible (e.g. you cannot add two content components to a layer and
    //                         expect it to work).
    // Returns:    None.
    void
    attachComponent(std::unique_ptr<Components::IComponent<ImplSpecT>> component);

    // Function:   removeComponent
    // Purpose:    Removes a component from this layer.
    // Parameters: type - The type of component to remove.
    // Returns:    An owning pointer to the removed component.
    std::unique_ptr<Components::IComponent<ImplSpecT>>
    removeComponent(Components::EType type);

    // Function:   getComponent
    // Purpose:    Retrieves a component of the given type.
    // Parameters: None. (Template method)
    // Returns:    The component with type U, if any.
    template<class U>
    U *
    getComponent();

    template<class U>
    const U *
    getComponent() const;
  private:
    std::map<Components::EType, std::unique_ptr<Components::IComponent<ImplSpecT>>> m_components;
  };
}

#include "Layer.tpp"

#endif
