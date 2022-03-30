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

#include "Components/AContentComponent.hpp"
#include "IMeasurable.hpp"
#include "IBoundable.hpp"
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
  class Layer : public IMeasurable,
                public IBoundable
  {
  public:
    // The content component must be added with this id to be properly recognized.
    static constexpr const char *c_contentComponentId = "content";
  public:
    // Function:   Layer
    // Purpose:    Constructs a new layer.
    // Parameters: None.
    Layer();

    ImageMeasure
    getWidthPx() const;

    ImageMeasure
    getHeightPx() const;

    ImageRect
    getDimensionsRect() const;

    ImageRect
    getBoundingRect() const;

    // Function:   setContentComponent
    // Purpose:    Sets the content component for this layer.
    // Parameters: component - The content component to set.
    // Returns:    None.
    void
    setContentComponent(std::unique_ptr<Components::AContentComponent<ImplSpecT>> component);

    // Function:   getContentComponent
    // Purpose:    Gets the content component for this layer.
    // Parameters: None.
    // Returns:    A pointer to the content component, which may be nullptr if none.
    Components::AContentComponent<ImplSpecT> *
    getContentComponent();
  private:
    std::map<std::string, std::unique_ptr<Components::IComponent<ImplSpecT>>> m_components;
    std::list<Components::IComponent<ImplSpecT> *> m_visitationList;
  };
}

#include "Layer.tpp"

#endif
