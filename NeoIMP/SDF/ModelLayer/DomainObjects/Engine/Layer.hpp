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

#include "Components/IContent.hpp"
#include "Dimensions.hpp"

namespace SDF::ModelLayer::DomainObjects::Engine {
  // Class:      Layer
  // Purpose:    Defines a base class for layer objects.
  // Parameters: ImplSpecT - A traits struct defining the implementation parameters for this image.
  template<class ImplSpecT>
  class Layer {
  public:
    // Function:   Layer
    // Purpose:    Constructs a new layer to the specified parameters.
    // Parameters: widthPx - The width of the layer in pixels.
    //             heightPx - The height of the layer in pixels.
    Layer(ImageMeasure widthPx,
          ImageMeasure heightPx
         );

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

    // Function:   getContentComponent
    // Purpose:    Gets the content component for this layer.
    // Parameters: None.
    // Returns:    The layer's content component, or nullptr if none.
    virtual Components::IContent<ImplSpecT> *
    getContentComponent() = 0;

    virtual const Components::IContent<ImplSpecT> *
    getContentComponent() const = 0;

    // Function:   contentAs
    // Purpose:    Helper downcasting function.
    // Parameters: None.
    // Returns:    The downcast content component of the given type, or else throws if a bad cast.
    template<class U>
    U *contentAs();

    template<class U>
    const U *contentAs() const;
  private:
    ImageMeasure m_widthPx;
    ImageMeasure m_heightPx;
  };
}

#include "Layer.tpp"

#endif
