#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_LAYER_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_ENGINE_LAYER_HPP

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
#include "Dimensions.hpp"

#include <cstddef>
#include <string>
#include <memory>
#include <map>
#include <list>

namespace SDF::Editor::ModelLayer::DomainObjects::Engine {
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
    // The content component must be added with this id to be properly recognized.
    static constexpr const char *c_contentComponentId = "content";
  public:
    // Function:   Layer
    // Purpose:    Constructs a new layer.
    // Parameters: None.
    Layer();

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

    // Function:   attachComponent
    // Purpose:    Attaches a component to this layer.
    // Parameters: id - The string resource ID of the component to add.
    //             component - The component itself.
    // Returns:    None.
    void
    attachComponent(std::string id, std::unique_ptr<Components::IComponent<ImplSpecT>> component);

    // Function:   findComponentById
    // Purpose:    Obtains a component by its ID string.
    // Parameters: id - The ID of the component to obtain.
    //             Template parameter: The type to get it as.
    // Returns:    A non-owning reference to the component, or nullptr if none (or throw a bad cast
    //             if found but the wrong type).
    template<class U>
    U *
    findComponentById(std::string id);

    template<class U>
    const U *
    findComponentById(std::string id) const;

    // Function:   visitComponents
    // Purpose:    Visits each of the contained components with a visitor. The components are
    //             visited in the order in which they were added.
    // Parameters: visitor - The visitor to visit with.
    // Returns:    None.
    void
    visitComponents(typename ImplSpecT::component_visitor_t &visitor);

    void
    visitComponents(typename ImplSpecT::const_component_visitor_t &visitor) const;
  private:
    std::map<std::string, std::unique_ptr<Components::IComponent<ImplSpecT>>> m_components;
    std::list<Components::IComponent<ImplSpecT> *> m_visitationList;
  };
}

#include "Layer.tpp"

#endif
